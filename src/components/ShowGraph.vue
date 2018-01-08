<template>
   <div class="showGraph">
  <!-- {{number1}}  {{number2}} -->
    <div class="container">
      <div class="row justify-content-start">
        <div class="col-6">
          <div class="container">
            <div class="card" style="width: 60rem; height:30.5rem; box-shadow: 3px 4px 10px black; position : relative ;top:5%; left:10%;">
              <br>
            <h3 style=" position : absolute ;top:5%; left:5%;">  กราฟ  </h3>
              <br>
                  <div class="card-block" >
            <canvas id="myLineChart" style="width:800px; height:360px; position :relative; left:0%;"  ></canvas>
          </div>
          </div>
          </div>
        </div>
      </div>
      <br><br>
      <div class="row justfy-content-start">
        <div class="col-6">
                <div class="card" style="width: 29rem; height:30rem; box-shadow: 3px 4px 10px black; position : relative ;top:5%; left:12%;">
              <br>
            <h3 style=" position : absolute ;top:5%; left:5%;">  1  </h3>
              <br>
                  <div class="card-block" >
                    </div>
                    </div>
        </div>
        <div class="col-6">
                <div class="card" style="width: 29rem; height:30rem; box-shadow: 3px 4px 10px black; position : relative ;top:5%; left:1.5%;">
              <br>
            <h3 style=" position : absolute ;top:5%; left:5%;">  2  </h3>
              <br>
                  <div class="card-block" >
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
  name: 'showGraph',
  props: ['number1', 'number2'],
  methods: {
    chart () {
      var ctx = document.getElementById('myLineChart').getContext('2d')
      var myLineChart = new Chart(ctx, {
        type: 'line',
        data: {
          labels: [10, 20, 5],
          datasets: [{
            label: '# of Votes',
            data: [20, 10, 5],
            backgroundColor: [
              'rgba(255, 99, 132, 0.2)'
            ],
            borderColor: [
              'rgba(255,99,132,1)'
            ],
            borderWidth: 1
          },
          {
            label: '# of Votes2',
            data: [15, 5, 20],
            backgroundColor: [
              'rgba(161, 199, 52, 0.2)'
            ],
            borderColor: [
              'rgba(25,75,22,1)'
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
