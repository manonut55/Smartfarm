<template>
  <div class="fertilityChart">
    <div class="container">
      <div class="card" style="width: 30rem; height:20.5rem; box-shadow: 3px 4px 10px black;">
        <br>
      <h3 style=" position : absolute ;top:5%; left:5%;">  สารอาหารในดิน(NPK)  </h3>
        <br>
            <div class="card-block" >
          <canvas id="fertilityChart" style="width:25px; position :relative; left:30%;"></canvas>
          <h1  style=" position : absolute ;top:30%; left:9%; font-size : 70px">{{useData[0]}}%</h1>
          <br>
          <h5 style=" position : absolute ;top:60%; left:3%;"> ความชื้นที่มีอยู่ในอากาศ</h5>
      <button type="button" class="btn btn-danger" @click="sendstatus(1)"  style=" position : absolute ;top:75%; left:10%;" >กราฟแสดงค่า</button>
      <div id="circlefertility" class="container-fluid">{{useData[0]}}%</div>
    </div>
  </div>
</div>
</div>
</template>
<script>
import Chart from 'Chart.js'
import { db } from './firebase.js'
export default {
  name: 'fertilityChart',
  data () {
    return {
      dataSensors: '',
      useData: ''
    }
  },
  methods: {
    chart () {
      var oilCanvasf = document.getElementById('fertilityChart')
      // Chart.defaults.global.defaultFontFamily = 'Lato'
      // Chart.defaults.global.defaultFontSize = 18
      var fertilityChart = new Chart(oilCanvasf, {
        type: 'doughnut',
        data: {
          labels: ['NPK'],
          datasets: [{
            data: [this.useData[0], (100 - this.useData[0])],
            backgroundColor: [
              '#894F18',
              'white'],
            borderColor: [
              '#723F0E',
              '#723F0E']

          }]
        },
        options: {
           events: ['onHover']
        }
      })
      console.log(fertilityChart)
    }
  },
  mounted: function () {
    var vm = this
    // vm.$bindAsObject('dataSensors', db.ref('DataSensors').child('History'), null)
    vm.$bindAsObject('dataSensors', db.ref('DataSensors/Fertility'), null)
  },
  watch: {
    dataSensors () {
      delete this.dataSensors['.key']
      this.useData = Object.values(this.dataSensors)
      this.chart()
    }
  }
}
</script>
<style lang="css">
#circlefertility {
width: 100px;
height: 100px;
background: #FFCA2B;
-moz-border-radius: 60px;
-webkit-border-radius: 60px;
border-radius: 60px;
font-size: 28px;
color: #000;
 line-height: 100px;
text-align: center;
position: absolute;
top: 44%;
left:67.5%;
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
