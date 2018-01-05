<template>
  <div class="tabledata">
    <table class="table table-warning">
  <thead class="thead-inverse">
    <tr>
      <th>Date</th>
      <th>Time</th>
      <th>Fertility</th>
      <th>Soil</th>
      <th>Humidity</th>
      <th>Temperature</th>
      <th>Amountwater</th>
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
