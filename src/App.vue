<template>
  <div class="Home">
     <meta name="viewport" content="width=device-width, initial-scale=1">
     <link rel="stylesheet" href="https://www.w3schools.com/w3css/4/w3.css">
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0-alpha.6/css/bootstrap.min.css" integrity="sha384-rwoIResjU2yc3z8GV/NPeZWAv56rSmLldC3R/AZzGRnGxQQKnKkoFVhFQhNUwEyJ" crossorigin="anonymous">
    <div class="row no-gutters">
      <div class="col-12">
        <nav class="navbar navbar-toggleable-md navbar-inverse bg-primary">
        <button class="navbar-toggler navbar-toggler-right" type="button" data-toggle="collapse" data-target="#navbarSupportedContent" aria-controls="navbarSupportedContent" aria-expanded="false" aria-label="Toggle navigation">
        <span class="navbar-toggler-icon"></span>
        </button>
        <a class="navbar-brand" href="#">Navbar</a>
        <div class="collapse navbar-collapse" id="navbarSupportedContent">
        <ul class="navbar-nav mr-auto">
          <li class="nav-item active">
            <a class="nav-link" href="#">Home <span class="sr-only">(current)</span></a>
          </li>
          <li class="nav-item">
            <a class="nav-link" href="#">Link</a>
          </li>
          <li class="nav-item">
            <a class="nav-link disabled" href="#">Disabled</a>
          </li>
        </ul>
        <form class="form-inline my-2 my-lg-0">
          <input class="form-control mr-sm-2" type="text" placeholder="Search">
          <button class="btn btn-outline-success my-2 my-sm-0" type="submit">Search</button>
        </form>
        </div>
        </nav>
      </div>
      <div class="col-4">.col-4<br>
        <input type="button" name="" value="+++" @click="getData()">
        <h1>{{npk}}</h1>
      </div>
      <div class="col-6">.col-6<br>
        <canvas id="myChart" width="100" height="50vh"></canvas>
      </div>
    </div>
  </div>
</template>
<script>
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
firebase.initializeApp(config)
let db = firebase.database()
export default {
  name: 'app',
  data () {
    return {
      npk: ''
    }
  },
  methods: {
    getData () {
      let that = this
      db.ref('/tree1').child('npk').on('value', function (snapshot) {
        that.npk = snapshot.val()
      })
    }
  },
  mounted: function () {
    var ctx = document.getElementById('myChart').getContext('2d')
    var myChart = new Chart(ctx, {
      type: 'bar',
      data: {
        labels: ['Red', 'Blue', 'Yellow', 'Green', 'Purple', 'Orange'],
        datasets: [{
          label: '# of Votes',
          data: [5, 19, 3, 5, 2, 3],
          backgroundColor: [
            'rgba(255, 99, 132, 0.2)',
            'rgba(54, 162, 235, 0.2)',
            'rgba(255, 206, 86, 0.2)',
            'rgba(75, 192, 192, 0.2)',
            'rgba(153, 102, 255, 0.2)',
            'rgba(255, 159, 64, 0.2)'
          ],
          borderColor: [
            'rgba(255,99,132,1)',
            'rgba(54, 162, 235, 1)',
            'rgba(255, 206, 86, 1)',
            'rgba(75, 192, 192, 1)',
            'rgba(153, 102, 255, 1)',
            'rgba(255, 159, 64, 1)'
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
}
</script>

<style>

</style>
