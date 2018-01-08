<template>
  <div class="soilGraph">
    <div class="row justify-content-start">
      <div class="col-md-6">
        <div class="card" style="width: 35rem; height:30.5rem; box-shadow: 3px 4px 10px black; position :relative; right :5%;">
          <br>
    <div class="container"  style="width: 35rem; height:30.5rem;">
    <canvas id="myLineChartsoil" style="width:520px; height : 450px; position :absolute;top:2px; left:1%;"></canvas>
  </div>
</div>
  </div>
      <div class="col-md-6">
      <table class="table table-info">
    <thead>
      <tr>
        <th>Date </th>
        <th>Time</th>
        <th>Soil</th>
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
            label: 'กราฟแสดงข้อมูล',
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
  top:5% ;
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
</style>
