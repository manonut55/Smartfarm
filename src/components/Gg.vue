<template>
  <div class="gg">
<div class="container">
<canvas id="oilChart" width="600" height="400">
rgrtguinfuigergu
</canvas>
</div>
</div>
</template>
<script>
import Chart from 'Chart.js'
import { db } from './firebase.js'
export default {
  name: 'gg',
  methods: {
    chart () {
      var oilCanvas = document.getElementById('oilChart')
      Chart.defaults.global.defaultFontFamily = 'Lato'
      Chart.defaults.global.defaultFontSize = 18
      var oilChart = new Chart(oilCanvas, {
        type: 'pie',
        data: {
          labels: ['Saudi Arabia', 'Russia', 'Iraq', 'United Arab Emirates', 'Canada'],
          datasets: [{
            data: [133.3, 86.2, 52.2, 51.2, 50.2],
            backgroundColor: [
              '#FF6384',
              '#63FF84',
              '#84FF63',
              '#8463FF',
              '#6384FF'
            ]
          }]
        },
        options: {
        }
      })
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
