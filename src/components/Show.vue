<template>
  <div class="Show">
  <meta name="viewport" content="width=device-width, initial-scale=1">
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
        <canvas id="myLineChart" width="400" height="400"></canvas>
   </div>
</template>
<script>
import Chart from 'Chart.js'
export default {
  name: 'show',
  methods: {
    chart () {
      var ctx = document.getElementById('myLineChart').getContext('2d')
      var myLineChart = new Chart(ctx, {
        type: 'line',
        data: {
          labels: ['10', '20'],
          datasets: [{
            label: '# of Votes',
            data: [20, 10],
            backgroundColor: [
              'rgba(255, 99, 132, 0.2)'
            ],
            borderColor: [
              'rgba(255,99,132,1)'
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
      console.log(myLineChart)
    }
  },
  mounted: function () {
    this.chart()
  }
}
</script>

<style lang="css">
</style>
