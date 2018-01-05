<template>
  <div class="graph">
    <div class="row justify-content-start">
      <div class="col-6">
    <div class="container">
    <canvas id="myLineChart2" width="500" height="500"></canvas>
  </div>
  </div>
  </div>
  <div class="row justify-content-start">
    <div class="col-6">

  </div>
  </div>
</div>
</template>

<script>
import Chart from 'Chart.js'
export default {
  name: 'graph',
  props: ['number1', 'number2'],
  methods: {
    chart () {
      var ctx2 = document.getElementById('myLineChart2').getContext('2d')
      var myLineChart2 = new Chart(ctx2, {
        type: 'line',
        data: {
          labels: [10, 20, 30],
          datasets: [{
            label: '# of Votes',
            data: [10, 20, 30],
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
      console.log(myLineChart2)
    }
  },
  mounted: function () {
    this.chart()
  }
}
</script>

<style lang="css">
</style>
