<template>
  <div class="gg">
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
<br>
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
<br>
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
<br>
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
  <br>
  </div>
</div>
<br>
  </div>
  <button type="button" name="button" @click="sendstatus(1)">55555</button>
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
      useData: '',
      Temperature: ''
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
    vm.$bindAsObject('dataSensors', db.ref('DataSensors'), null, () => {
      delete this.dataSensors['.key']
      this.useData = Object.values(this.dataSensors)
      console.log(this.useData[0])
      // this.chart()
    })
  },
  methods: {
    sendstatus (status) {
      this.$firebaseRefs.dataSensors.child('Amountwater').set(status)
    }
  }
}
</script>
<style lang="css">

</style>
