<template>
  <div class="Show">
    <div class="container">
      <div class="row justify-content-start">
        <div class="col-6">
          <div class="container">
            <canvas id="myLineChart" width="400" height="400"></canvas>
          </div>
        </div>
        <div class="col-6">
          <div class="container">
            <canvas id="myLineChart" width="400" height="400"></canvas>
          </div>
        </div>
      </div>
      <div class="row justify-content-start">
        <div class="col-6">
          <div class="container">
            <canvas id="myLineChart" width="400" height="400"></canvas>
          </div>
        </div>
        <div class="col-6">
          <div class="container">
            <canvas id="myLineChart" width="400" height="400"></canvas>
          </div>
        </div>
      </div>
    </div>
  </div>
</div>
</div>
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
