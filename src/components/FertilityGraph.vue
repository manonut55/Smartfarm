<template>
  <div class="fertilityGraph">
  <div class="container">
<canvas id="myDoughnutChart" width="10px" height="10px"></canvas>
</div>
</div>
</template>
<script>
import Chart from 'Chart.js'
import { db } from './firebase.js'
export default {
  name: 'fertilityGraph',
  methods: {
    chart () {
      var oilCanvas = document.getElementById('myDoughnutChart')
      Chart.defaults.global.defaultFontFamily = 'Lato'
      Chart.defaults.global.defaultFontSize = 18
      var myDoughnutChart = new Chart(oilCanvas, {
        type: 'doughnut',
        data: {
          labels: ['Saudi Arabia'],
          datasets: [{
            data: [50, 50],
            backgroundColor: [
              '#FF6384',
              'white'
            ]
          }]
        },
        options: {
        }
      })
      console.log(myDoughnutChart)
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
