<template>
  <div class="npkalert">
    <div class="" v-if="check()">
      <div class="container">
      <br><br>
        <div class="card" style="width: 16rem;">
  <div class="card-block">
    <h4 class="card-title">ค่าสารอาหารในดินต่ำ</h4>
    <p class="card-text">สารอาหารในแปลงมีค่าต่ำกรุณาใส่ปุ๋ยแล้วกด"ปุ่ม"ดำเนินการ</p>
    <button type="button" class="btn btn-danger" @click="sendstatus(1)">ดำเนินการ</button>
  </div>
  </div>
      </div>
    </div>
  </div>
</template>
<script>
import { db } from './firebase.js'
export default {
  name: 'npkalert',
  data () {
    return {
      dataSensors: '',
      useData: ''
    }
  },
  mounted: function () {
    var vm = this
    vm.$bindAsObject('dataSensors', db.ref('DataSensors'), null)
  },
  methods: {
    sendstatus (status) {
      this.$firebaseRefs.dataSensors.child('buttonstate').set(status)
    },
    check () {
      return this.useData[1] < 30 && this.useData[7] == 0
    }
},
watch: {
  dataSensors () {
    delete this.dataSensors['.key']
    this.useData = []
    this.useData = Object.values(this.dataSensors)
    check()
  }
}
}
</script>
<style lang="css">

</style>
