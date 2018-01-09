<template>
  <div class="humidityChart">
    <div class="container">
      <div class="card" style="width: 30rem; height:20.5rem; box-shadow: 3px 4px 10px black;">
        <br>
      <h3 style=" position : absolute ;top:5%; left:5%;">  ความชื้นในอากาศ  </h3>
        <br>
            <div class="card-block" >
          <canvas id="myDoughnutChart2" style="width:25px; position :relative; left:30%;"></canvas>
          <h1  style=" position : absolute ;top:30%; left:10%; font-size : 70px">{{useData[0]}}%</h1>
          <br>
          <h5 style=" position : absolute ;top:60%; left:4.5%;">  ความชื้นในอากาศ</h5>
          <router-link to="humidityGraph">
      <button type="button" class="btn btn-danger" @click="sendstatus(1)"  style=" position : absolute ;top:75%; left:10%;" >กราฟแสดงค่า</button>
    </router-link>
      <div class="container-fluid" id="circlehumidity">{{useData[0]}}</div>
    </div>
  </div>
</div>
</div>
</template>
<script>
import Chart from 'Chart.js'
import { db } from './firebase.js'
export default {
  name: 'humidityChart',
  data () {
    return {
      dataSensors: '',
      useData: ''
    }
  },
  methods: {
    chart () {
      var oilCanvas2 = document.getElementById('myDoughnutChart2')
      // Chart.defaults.global.defaultFontFamily = 'Lato'
      // Chart.defaults.global.defaultFontSize = 18
      var myDoughnutChart2 = new Chart(oilCanvas2, {
        type: 'doughnut',
        data: {
          labels: ['ความชื้นในอากาศ'],
          datasets: [{
            data: [this.useData[0], (100 - this.useData[0])],
            backgroundColor: [
              '#A1C734',
              'white'],
            borderColor: [
              '#8cb21a',
              '#8cb21a']
          }]
        },
        options: {
          events: ['onHover']
        }
      })
      console.log(myDoughnutChart2)
    }
  },
  mounted: function () {
    var vm = this
    // vm.$bindAsObject('dataSensors', db.ref('DataSensors').child('History'), null)
    vm.$bindAsObject('dataSensors', db.ref('DataSensors/Humidity'), null)
  },
  watch: {
    dataSensors () {
      delete this.dataSensors['.key']
      this.useData = Object.values(this.dataSensors)
      this.chart()
    }
  }
}
</script>
<style lang="css">
#circlehumidity {
width: 100px;
height: 100px;
background: #17484C;
-moz-border-radius: 60px;
-webkit-border-radius: 60px;
border-radius: 60px;
font-size: 28px;
color: #fff;
 line-height: 100px;
text-align: center;
position: absolute;
top: 44%;
left:67%;
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
