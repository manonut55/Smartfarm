<template>
  <div class="Gg">
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">
     <link rel="stylesheet" href="https://www.w3schools.com/w3css/4/w3.css">
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0-alpha.6/css/bootstrap.min.css" integrity="sha384-rwoIResjU2yc3z8GV/NPeZWAv56rSmLldC3R/AZzGRnGxQQKnKkoFVhFQhNUwEyJ" crossorigin="anonymous">
    <div class="row" >
      <img src="\pic\top.jpg" class="img-fluid" alt="top.jpg" width= 100%  >
      </div>
    <div class="row no-gutters">
      <div class="col-12">
        <nav class="navbar navbar-toggleable-md navbar-inverse bg-primary">
        <button class="navbar-toggler navbar-toggler-right" type="button" data-toggle="collapse" data-target="#navbarSupportedContent" aria-controls="navbarSupportedContent" aria-expanded="false" aria-label="Toggle navigation">
        <span class="navbar-toggler-icon"></span>
        </button>
        <a class="navbar-brand" href="#">Smartfarm</a>
        <div class="collapse navbar-collapse" id="navbarSupportedContent">
        <ul class="navbar-nav mr-auto">
          <li class="nav-item active">
            <a class="nav-link" href="#">Home <span class="sr-only">(current)</span></a>
          </li>
        </ul>
        <!-- <form class="form-inline my-2 my-lg-0">
          <input class="form-control mr-sm-2" type="text" placeholder="Search">
          <button class="btn btn-outline-success my-2 my-sm-0" type="submit">Search</button>
        </form> -->
        </div>
        </nav>
      </div>
        <br><br><br><br>
        <div class="row">
          <div class="col-sm-2" >
            <button type="button" class="btn btn-primary col-xl">Primary</button>
            <button type="button" class="btn btn-primary col-xl">Primary</button>
            <button type="button" class="btn btn-primary col-xl">Primary</button>
            <button type="button" class="btn btn-primary col-xl">Primary</button>
          </div>
      <div class="col-sm-10" >
        <div class="container">
    <div class="row justify-content-start">
      <div class="col-6">
        <div class="container">
   <h2>Fertility Progress Bars</h2>
    <p>Fertility :{{useData[0]}}%</p>
   <div class="progress">
  <div class="progress-bar progress-bar-danger progress-bar-striped" role="progressbar"
  aria-valuenow="70" aria-valuemin="0" aria-valuemax="100" :style="'width:'+useData[0]+'%'">
  {{useData[0]}}% Complete (info)
  </div>
</div>
<br>
 </div>
      </div>
      <div class="col-6">
        <div class="container">
   <h2>Humidity Progress Bars</h2>
   <p>Humidity :{{useData[1]}}% </p>
   <div class="progress">
  <div class="progress-bar progress-bar-danger progress-bar-striped" role="progressbar"
  aria-valuenow="70" aria-valuemin="0" aria-valuemax="100" :style="'width:'+useData[1]+'%'">
  {{useData[1]}}% Complete (info)
  </div>
</div>
  </div>
      </div>
    </div>
    <br><br>
    <div class="row justify-content-start">
      <div class="col-6">
        <div class="container">
   <h2>Ph Progress Bars</h2>
   <p> Ph :{{useData[2]}}% </p>
   <div class="progress">
  <div class="progress-bar progress-bar-danger progress-bar-striped" role="progressbar"
  aria-valuenow="70" aria-valuemin="0" aria-valuemax="100" :style="'width:'+useData[2]+'%'">
  {{useData[2]}}% Complete (info)
  </div>
</div>
 </div>
      </div>
      <div class="col-6">
        <div class="container">
   <h2>Temperature Progress Bars</h2>
   <p>Temperature :{{useData[3]}}% </p>
   <div class="progress">
  <div class="progress-bar progress-bar-danger progress-bar-striped" role="progressbar"
  aria-valuenow="70" aria-valuemin="0" aria-valuemax="100" :style="'width:'+useData[3]+'%'">
  {{useData[3]}}% Complete (info)
  </div>
</div>
  </div>
      </div>
    </div>
    <br><br><br>
    <div class="row justify-content-start">
      <div class="col-6">
        <div class="container">
   <h2>Soil Progress Bars</h2>
   <p>Soil:1 :{{useData[3]}}%</p>
   <div class="progress">
  <div class="progress-bar progress-bar-danger progress-bar-striped" role="progressbar"
  aria-valuenow="70" aria-valuemin="0" aria-valuemax="100" :style="'width:'+useData[3]+'%'">
  {{useData[3]}}% Complete (info)
  </div>
</div>
  </div>
      </div>
    </div>
    </div>
        <!-- Fertility  {{datas.Fertility}} <br>
        Humidity  {{datas.Humidity}}  <br>
        Temperature  {{datas.Temperature}} <br>
        ph  {{datas.ph}} <br> -->
        <!-- {{datas.Temperature}} -->
        <br><br>
      </div>
      <!-- <div class="col-3">.col-4<br>
        <canvas id="myChart" width="100" height="50vh"></canvas>
      </div> -->
        </div>
    </div>
    </div>
</template>
<script>
import 'bootstrap-vue/dist/bootstrap-vue.css'
import Chart from 'Chart.js'
import firebase from 'firebase'
var config = {
  apiKey: 'AIzaSyCtnb0c4yQwPeBVv5k4nSZM8MPFJsDmYs8',
  authDomain: 'smart-farm-78d34.firebaseapp.com',
  databaseURL: 'https://smart-farm-78d34.firebaseio.com',
  projectId: 'smart-farm-78d34',
  storageBucket: 'smart-farm-78d34.appspot.com',
  messagingSenderId: '783930334800'
}
var vuefires = firebase.initializeApp(config)
var db = vuefires.database()
export default {
  name: 'gg',
  data () {
    return {
      dataSensors: '',
      useData: '',
      Temperature: ''
    }
  },
  methods: {
    chart () {
      var ctx = document.getElementById('myChart').getContext('2d')
      var myChart = new Chart(ctx, {
        type: 'bar',
        data: {
          labels: ['Fertility', 'Humidity', 'ph', 'Temperature'],
          datasets: [{
            label: '# of Votes',
            data: this.useData,
            backgroundColor: [
              'rgba(255, 99, 132, 0.2)',
              'rgba(54, 162, 235, 0.2)',
              'rgba(255, 206, 86, 0.2)',
              'rgba(75, 192, 192, 0.2)'
            ],
            borderColor: [
              'rgba(255,99,132,1)',
              'rgba(54, 162, 235, 1)',
              'rgba(255, 206, 86, 1)',
              'rgba(75, 192, 192, 1)'
            ],
            borderWidth: 1
          }]
        },
        options: {
          scales: {
            yAxes: [{
              ticks: {
                beginAtZero: true
              }
            }]
          }
        }
      })
      console.log(myChart)
    }
  },
  mounted: function () {
    var vm = this
    vm.$bindAsObject('dataSensors', db.ref('DataSensors'), null, () => {
      delete this.dataSensors['.key']
      this.useData = Object.values(this.dataSensors)
      console.log(this.useData[0])
      this.chart()
    })
  }
}
</script>
<style lang="css">
.col-sm-2{
  background: blue;
}
</style>
