<template>
  <div class="humidityGraph">
    <div class="container">
      <div class="card" style="width: 30rem; height:20.5rem; box-shadow: 3px 4px 10px black;">
        <br>
      <h3 style=" position : absolute ;top:5%; left:5%;">  สารอาหารในดิน(NPK)  </h3>
        <br>
            <div class="card-block" >
          <canvas id="myDoughnutChart2" style="width:25px; position :relative; left:30%;"></canvas>
          <h1  style=" position : absolute ;top:30%; left:9%; font-size : 70px">70%</h1>
          <br>
          <h5 style=" position : absolute ;top:60%; left:3%;"> ความชื้นที่มีอยู่ในอากาศ</h5>
      <button type="button" class="btn btn-danger" @click="sendstatus(1)"  style=" position : absolute ;top:75%; left:10%;" >กราฟแสดงค่า</button>
      <div id="circlehumidity">70%</div>
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
      // Chart.defaults.global.defaultFontFamily = 'Lato'
      // Chart.defaults.global.defaultFontSize = 18
      var myDoughnutChart2 = new Chart(oilCanvas2, {
        type: 'doughnut',
        data: {
          labels: ['Saudi Arabia'],
          datasets: [{
            data: [70, 30],
            backgroundColor: [
              '#78e028',
              'white'],
              borderColor:
              ['#75db27',
            '#75db27']

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
#circlehumidity {
width: 100px;
height: 100px;
background: #4073c4;
-moz-border-radius: 60px;
-webkit-border-radius: 60px;
border-radius: 60px;
font-size: 28px;
color: #fff;
 line-height: 100px;
text-align: center;
position: absolute;
top: 44%;
left:67.5%;
}
.card-block{
  margin-top: 10px;
   margin-right: 5px;
   margin-bottom: 5px;
   margin-left: 5px;
   padding:10px 10px 10px 10px;
   border-style: groove;
}
</style>
