<template>
  <div class="phChart">
    <div class="container">
      <div class="card" style="width: 30rem; height:20.5rem; box-shadow: 3px 4px 10px black;">
        <br>
      <h3 style=" position : absolute ;top:5%; left:5%;">  ค่าPhในน้ำปุ๋ยจากมูลไก่  </h3>
        <br>
            <div class="card-block" >
          <canvas id="phChart" style="width:25px; position :relative; left:30%;"></canvas>
          <h1  style=" position : absolute ;top:30%; left:9%; font-size : 70px">{{useData[0]}}</h1>
          <br>
          <!-- <h5 style=" position : absolute ;top:60%; left:3%;"> ความชื้นในดิน</h5> -->
      <!-- <button type="button" class="btn btn-danger" style=" position : absolute ;top:75%; left:10%;" >กราฟแสดงค่า</button> -->
      <div id="circleph" class="container-fluid">{{useData[0]}}</div>
    </div>
  </div>
</div>
</div>
</template>
<script>
import Chart from 'Chart.js'
import { db } from './firebase.js'
export default {
  name: 'phChart',
  data () {
    return {
      dataSensors: '',
      useData: ''
    }
  },
  methods: {
    chart () {
      var oilCanvasp = document.getElementById('phChart')
      var phChart = new Chart(oilCanvasp, {
        type: 'doughnut',
        data: {
          labels: ['ค่าPhในน้ำปุ๋ยจากมูลไก่'],
          datasets: [{
            data: [this.useData[0], (100 - this.useData[0])],
            backgroundColor: [
              '#ff6666',
              'white'],
            borderColor: [
              '#ff4d4d',
              '#ff4d4d']

          }]
        },
        options: {
          events: ['onHover']
        }
      })
      console.log(phChart)
    }
  },
  mounted: function () {
    var vm = this
    // vm.$bindAsObject('dataSensors', db.ref('DataSensors').child('History'), null)
    vm.$bindAsObject('dataSensors', db.ref('DataSensors/Water_pH1'), null)
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
#circleph {
width: 100px;
height: 100px;
background: 	#d24dff;
-moz-border-radius: 60px;
-webkit-border-radius: 60px;
border-radius: 60px;
font-size: 28px;
color: #fff;
 line-height: 100px;
text-align: center;
position: absolute;
top: 44%;
left:67.3%;
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
