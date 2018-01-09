<template>
  <div class="temperatureChart">
    <div class="container">
      <div class="card" style="width: 30rem; height:20.5rem; box-shadow: 3px 4px 10px black;">
        <br>
      <h3 style=" position : absolute ;top:5%; left:5%;">  อุณหภูมิ  </h3>
        <br>
            <div class="card-block" >
          <canvas id="temperatureChart" style="width:25px; position :relative; left:30%;"></canvas>
          <h1  style=" position : absolute ;top:30%; left:9%; font-size : 70px">{{useData[0]}}</h1>
          <br>
          <h3 style=" position : absolute ;top:38%; left:40%; font-size : 40px"> C</h3>
          <h7 style=" position : absolute ;top:36%; left:46%; "> o </h7>
          <h5 style=" position : absolute ;top:60%; left:10%;">ค่าอุณหภูมิปัจจุบัน</h5>
          <router-link to="temperatureGraph">
      <button type="button" class="btn btn-danger" @click="sendstatus(1)"  style=" position : absolute ;top:75%; left:10%;" >กราฟแสดงค่า</button>
</router-link>
      <div id="circletemperature" class="container-fluid">{{useData[0]}}</div>
    </div>
  </div>
</div>
</div>
</template>
<script>
import Chart from 'Chart.js'
import { db } from './firebase.js'
export default {
  name: 'temperatureChart',
  methods: {
    chart () {
      var oilCanvast = document.getElementById('temperatureChart')
      // Chart.defaults.global.defaultFontFamily = 'Lato'
      // Chart.defaults.global.defaultFontSize = 18
      var temperatureChart = new Chart(oilCanvast, {
        type: 'doughnut',
        data: {
          labels: ['อุณหภูมิ'],
          datasets: [{
            data: [this.useData[0], (100 - this.useData[0])],
            backgroundColor: [
              '#2b7cff',
              'white'],
            borderColor: [
              '#2072f7',
              '#2072f7']

          }]
        },
        options: {
          events: ['onHover']
        }
      })
      console.log(temperatureChart)
    }
  },
  data () {
    return {
      dataSensors: '',
      useData: ''
    }
  },
  mounted: function () {
    var vm = this
    // vm.$bindAsObject('dataSensors', db.ref('DataSensors').child('History'), null)
    vm.$bindAsObject('dataSensors', db.ref('DataSensors/Temperature'), null)
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
#circletemperature {
width: 100px;
height: 100px;
background: blue;
-moz-border-radius: 60px;
-webkit-border-radius: 60px;
border-radius: 60px;
font-size: 28px;
color: #fff;
 line-height: 100px;
text-align: center;
position: absolute;
top: 43.8%;
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
