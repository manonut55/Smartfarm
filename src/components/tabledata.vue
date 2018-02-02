<template>
  <div class="tabledata">
    <table class="table table-warning" style="position: relative; top: 5px;left:25%;">
  <thead class="thead-inverse">
    <tr>
      <th>วัน/เดือน/ปี</th>
      <th>เวลา</th>
      <th>ค่าNPK</th>
      <th>ค่าความชื้นในดิน</th>
      <th>ค่าความชื้นในอากาศ</th>
      <th>อุณหภูมิ</th>
      <th>จำนวนครั้งในการให้น้ำ</th>
    </tr>
  </thead>
  <tbody>
      <tr v-for="(history, key) in dataSensors">
        <td>{{history.Date}}</td>
        <td>{{history.Time}}</td>
        <td>{{history.Fertility}}</td>
        <td>{{history.Soil}}</td>
        <td>{{history.Humidity}}</td>
        <td>{{history.Temperature}}</td>
        <td>{{history.Amountwater}}</td>
      </tr>
  </tbody>
</table>
</div>
</template>

<script>
import { db } from './firebase.js'

export default {
  name: 'tabledata',
  data () {
    return {
      dataSensors: ''
    }
  },
  mounted: function () {
    var vm = this
    // vm.$bindAsObject('dataSensors', db.ref('DataSensors').child('History').limitToLast(2), null)
    vm.$bindAsObject('dataSensors', db.ref('DataSensors').child('History'), null)
  },
  watch: {
    dataSensors () {
      delete this.dataSensors['.key']
    }
  }
}
</script>

<style lang="css">
</style>
