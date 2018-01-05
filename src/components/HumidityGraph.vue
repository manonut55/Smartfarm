<template>
  <div class="humidityGraph">
    <div class="container">
      <canvas id="myDoughnutChart2" width="30" height="30"></canvas>
    </div>
  </div>
</template>
<script>
import Chart from 'Chart.js'
import { db } from './firebase.js'
export default {
  name: 'humidityGraph',
  methods: {
    chart () {
      var oilCanvas2 = document.getElementById('myDoughnutChart2')
      Chart.defaults.global.defaultFontFamily = 'Lato'
      Chart.defaults.global.defaultFontSize = 18
      var myDoughnutChart2 = new Chart(oilCanvas2, {
        type: 'doughnut',
        data: {
          labels: ['Saudi Arabia'],
          datasets: [{
            data: [70, 30],
            backgroundColor: [
              'bla',
              'white'
            ]
          }]
        },
        options: {
        }
      })
      console.log(myDoughnutChart2)
    }
  },
  data () {
    return {
      dataSensors: ''
    }
  },
  mounted: function () {
    var vm = this
    vm.$bindAsObject('dataSensors', db.ref('DataSensors').child('History'), null)
    // vm.$bindAsObject('dataSensors', db.ref('DataSensors').child('History').limitToLast(3), null)
    this.chart()
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
