<template>
  <div class="humidityGraph">
    <div class="container">
      <div class="card" style="width: 30rem; box-shadow: 3px 4px 10px black;">
        <br>
      <h2>  ความชื้นในอากาศ  </h2>
        <br><br>
        <canvas id="myDoughnutChart2" style="width:40px"></canvas>
        <div class="card-block">
      <button type="button" class="btn btn-danger" @click="sendstatus(1)">ดำเนินการ</button>
      <div id="circle">70%</div>
    </div>
  </div>
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
h2{
  position: absolute;
  top: 5%;
  left: 5%;
}
canvas {
  width: 250px;
  height: 250px;
}
#circle {

width: 110px;
height: 110px;
background: #222;
-moz-border-radius: 60px;
-webkit-border-radius: 60px;
border-radius: 60px;
font-size: 28px;
color: #fff;
 line-height: 110px;
text-align: center;
position: absolute;
top: 40%;
left:38.5%;
}
</style>
