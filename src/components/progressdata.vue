<template>
  <div class="gg">
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">
        <div class="container-fluid">
    <div class="row justify-content-start">
      <div class="col-6">

        <div class="card" style="width: 30rem; box-shadow: 3px 4px 10px black;">
          <div class="card-block">

<h2>Fertility</h2> </tr>
   <p>Fertility :{{useData[1]}}% </p>
   <div class="progress">
  <div class="progress-bar progress-bar-danger progress-bar-striped" role="progressbar"
  aria-valuenow="70" aria-valuemin="0" aria-valuemax="100" :style="'width:'+useData[1]+'%'">
  {{useData[1]}}%
  </div>
</div>
<br>

  </div>
  </div>

      </div>


      <div class="col-6">
        <div class="card" style="width: 30rem; box-shadow: 3px 4px 10px black; ">
          <div class="card-block">
   <h2>Humidity </h2>
   <p>Humidity :{{useData[3]}}% </p>
   <div class="progress">
  <div class="progress-bar progress-bar-danger progress-bar-striped" role="progressbar"
  aria-valuenow="70" aria-valuemin="0" aria-valuemax="100" :style="'width:'+useData[3]+'%'">
  {{useData[3]}}%
  </div>
</div>
<br>
  </div>
  </div>
      </div>
    </div>
    <br><br>
    <div class="row justify-content-start">
      <div class="col-6">
        <div class="card" style="width: 30rem; box-shadow: 3px 4px 10px black; ">
          <div class="card-block">
   <h2>Temperature </h2>
   <p>Temperature :{{useData[5]}}% </p>
   <div class="progress">
  <div class="progress-bar progress-bar-danger progress-bar-striped" role="progressbar"
  aria-valuenow="70" aria-valuemin="0" aria-valuemax="100" :style="'width:'+useData[5]+'%'">
  {{useData[5]}}%
  </div>
</div>
<br>
  </div>
  </div>
      </div>
    <br><br><br>
      <div class="col-6">
        <div class="card" style="width: 30rem; box-shadow: 3px 4px 10px black; ">
          <div class="card-block">
   <h2>Soil Progress Bars</h2>
   <p>Soil:1 :{{useData[4]}}%</p>
   <div class="progress">
  <div class="progress-bar progress-bar-danger progress-bar-striped" role="progressbar"
  aria-valuenow="70" aria-valuemin="0" aria-valuemax="100" :style="'width:'+useData[4]+'%'">
  {{useData[4]}}%
  <br>
  </div>
</div>
<br>
  </div>
  </div>
      </div>
    </div>
    <br><br>
    <div class="row justify-content-start">
      <div class="col-6">
        <div class="card" style="width: 30rem; box-shadow: 3px 4px 10px black;">
          <div class="card-block">
   <h2>Amountwater </h2>
     <h2> Round {{useData[0]}}</h2>
</div>
<br>
  </div>
  </div>
      </div>
    </div>
  </div>

      <!-- <div class="col-3">.col-4<br>
        <canvas id="myChart" width="100" height="50vh"></canvas>
      </div> -->
        </div>
    </div>
    </div>
</template>
<script>
// import Chart from 'Chart.js'
import { db } from './firebase.js'
export default {
  name: 'gg',
  data () {
    return {
      dataSensors: '',
      useData: ''
    }
  },
  // methods: {
  //   chart () {
  //     var ctx = document.getElementById('myChart').getContext('2d')
  //     var myChart = new Chart(ctx, {
  //       type: 'bar',
  //       data: {
  //         labels: ['Fertility', 'Humidity', 'ph', 'Temperature'],
  //         datasets: [{
  //           label: '# of Votes',
  //           data: this.useData,
  //           backgroundColor: [
  //             'rgba(255, 99, 132, 0.2)',
  //             'rgba(54, 162, 235, 0.2)',
  //             'rgba(255, 206, 86, 0.2)',
  //             'rgba(75, 192, 192, 0.2)'
  //           ],
  //           borderColor: [
  //             'rgba(255,99,132,1)',
  //             'rgba(54, 162, 235, 1)',
  //             'rgba(255, 206, 86, 1)',
  //             'rgba(75, 192, 192, 1)'
  //           ],
  //           borderWidth: 1
  //         }]
  //       },
  //       options: {
  //         scales: {
  //           yAxes: [{
  //             ticks: {
  //               beginAtZero: true
  //             }
  //           }]
  //         }
  //       }
  //     })
  //     console.log(myChart)
  //   }
  // },
  mounted: function () {
    var vm = this
    // vm.$bindAsObject('dataSensors', db.ref('DataSensors').child('History'), null)
    vm.$bindAsObject('dataSensors', db.ref('DataSensors'), null)
  },
  watch: {
    dataSensors () {
      delete this.dataSensors['.key']
      this.useData = []
      this.useData = Object.values(this.dataSensors)
    }
  }
}
</script>
<style lang="css">

.card{
  background-color: #e2fc94;

}

/*h2{
  background-color: #A1C734;
  width: 30rem;
}*/

</style>
