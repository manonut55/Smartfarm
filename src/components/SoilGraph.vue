<template>
  <div class="soilGraph">
    <div class="row justify-content-start">
      <div class="col-6">
        <div class="container">
          <div class="card" style="width: 73rem; height:20rem; box-shadow: 3px 4px 10px black; position : relative ;top:5%; left:10%;">
            <br>
          <h3 style=" position : absolute ;top:5%; left:5%;">  กราฟความชื้นในดิน  </h3>
            <br>
            <h1  style=" position : absolute ;top:30%; left:9%; font-size : 70px">{{soilData[6]}}%</h1>
            <canvas id="myLineChart" style="width:800px; height:220px; position :relative; left:0%;"  ></canvas>



        </div>
        </div>
        </div>
        </div>
        <br><br><br>
    <div class="row justify-content-start">
      <div class="col-md-6">
        <div class="card" style="width: 35rem; height:30.5rem; box-shadow: 3px 4px 10px black; position :relative; left:10%;">
          <br>
    <div class="container"  style="width: 35rem; height:30.5rem;">
    <canvas id="myLineChartsoil" style="width:520px; height : 450px; position :absolute;top:2px; left:1%;"></canvas>
  </div>
</div>
  </div>
      <div class="col-md-6">
        <div class="card" style="width:35rem; height:30.5rem; box-shadow: 3px 4px 10px black; position : relative ; left:15%;">
      <br>
    <h3 style=" position : absolute ;top:7%; left:5%;"> ตารางความชื้นในดิน  </h3>
      <br>
        <table class="table table-info" style=" position : absolute ;top:21%; ">
    <thead>
      <tr>
        <th>วัน/เดือน/ปี</th>
        <th>เวลา</th>
        <th>ค่าความชื้นในดิน</th>
      </tr>
    </thead>
    <tbody>
        <tr v-for="(history, key, index) in dataSensors">
          <td>{{history.Date}}</td>
          <td>{{history.Time}}</td>
          <td>{{history.Soil}}</td>
        </tr>
    </tbody>
  </table>
  </div>
  </div>
  </div>
</div>
</div>
</div>
</template>
<script>
import Chart from 'Chart.js'
import { db } from './firebase.js'
export default {
  name: 'soilGraph',
  data () {
    return {
      dataSensors: '',
      useData: '',
      soilData: [],
      timeData: [],
      dateData: []
    }
  },
  // props: ['number1', 'number2'],
  methods: {
    chart () {
      var ctxsoil = document.getElementById('myLineChartsoil').getContext('2d')
      var myLineChartsoil = new Chart(ctxsoil, {
        type: 'line',
        data: {
          labels: this.dateData,
          datasets: [{
            label: 'ความชื้นในดิน',
            data: this.soilData,
            backgroundColor: [
              'rgba(217, 237, 247, 0.4)'
            ],
            borderColor: [
              'rgba(38,144,255,1)'
            ],
            borderWidth: 1
          }]
        },
        options: {
          scales: {
            yAxes: [{
              stacked: true
            }]
          }
        }
      })
      console.log(myLineChartsoil)
    }
  },
  mounted: function () {
    var vm = this
    vm.$bindAsObject('dataSensors', db.ref('DataSensors/History').limitToLast(7), null)
  },
  watch: {
    dataSensors () {
      let newdata = []
      delete this.dataSensors['.key']
      newdata = Object.values(this.dataSensors)
      console.log(this.dateData)
      for (let index in newdata) {
        this.soilData[index] = newdata[index].Soil
        this.timeData[index] = newdata[index].Time
        this.dateData[index] = newdata[index].Date
      }
      this.chart()
    }
  }
}
</script>

<style lang="css">
table{
  position: absolute;
  top:20% ;
  left:0% ;
  }
  thead{
    background-color: #3956f9;
    background:-o-linear-gradient(90deg, #1E90FF, #3956f9);
	background:-moz-linear-gradient( center top, #1E90FF 5%, #3956f9 100% );
	background:-webkit-gradient( linear, left top, left bottom, color-stop(0.05, #1E90FF), color-stop(1, #7ebffe) );
	filter:progid:DXImageTransform.Microsoft.gradient(startColorstr='#1E90FF', endColorstr='#3956f9');
	color:#FFFFFF
  }
  tr:nth-child(even) {background-color: #fff;}
  .table-info{
     box-shadow: 3px 4px 10px black;
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
