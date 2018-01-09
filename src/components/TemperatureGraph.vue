<template>
  <div class="temperatureGraph">
    <div class="row justify-content-start">
      <div class="col-6">
        <div class="container">
          <div class="card" style="width: 73rem; height:20rem; box-shadow: 3px 4px 10px black; position : relative ;top:5%; right:8%;">
            <br>
          <h3 style=" position : absolute ;top:5%; left:5%;">  อุณหภูมิ  </h3>
            <br>
            <canvas id="myLineChart" style="width:800px; height:220px; position :relative; left:0%;"  ></canvas>
            <div class="container" style="width:150px; position :absolute; top:10%;left:80%;" >
            <img src ="https://firebasestorage.googleapis.com/v0/b/smart-farm-78d34.appspot.com/o/%E0%B8%9F%E0%B8%9F%E0%B8%9F%E0%B8%9F%E0%B8%9F.png?alt=media&token=4822f28c-82f6-44a5-8767-33162f574d8d" class="img-fluid" alt="Responsive image">
          </div>
          <div class="container" style="position :absolute; top:5%;left:55%;">
            <img src ="https://firebasestorage.googleapis.com/v0/b/smart-farm-78d34.appspot.com/o/ssss.png?alt=media&token=c1fe5347-b9c3-42bf-8a0d-6be7db13a564" class="img-fluid" alt="Responsive image" style="width:300px; position:absolute;top:5%;">
            </div>
            <div class="container" style="position :absolute; top:25%;left:6.5%;">
            <center><h6  style="color: #fff; position :absolute; top:25%;left:55%; font-size:24px;">เกณฑ์การประเมินค่า<br>ที่เหมาะสม<br>สำหรับแปลงปลูก</h6></center>
          </div>
  <div class="container" style="position :absolute; top:70%;left:60%;">
  <!-- Trigger the modal with a button -->
  <button type="button" class="btn btn-info btn-lg" data-toggle="modal" data-target="#myModal">กดเพื่อดูเกณฑ์</button>

  <!-- Modal -->
  <div class="modal fade" id="myModal" role="dialog">
    <div class="modal-dialog modal-lg">
      <div class="modal-content">
        <div class="modal-header">
          <button type="button" class="close" data-dismiss="modal">&times;</button>
          <h4 class="modal-title">ค่าที่เหมาะสมสำหรับแปลงปลูก</h4>
        </div>
        <div class="modal-body">
          <p>ใส่ข้อความที่นี่</p>
        </div>
        <div class="modal-footer">
          <button type="button" class="btn btn-default" data-dismiss="modal">ปิด</button>
        </div>
      </div>
    </div>
  </div>
</div>

        </div>
        </div>
        </div>
        </div>
        <br><br><br>
    <div class="row justify-content-start">
      <div class="col-md-6">
        <div class="card" style="width: 35rem; height:30.5rem; box-shadow: 3px 4px 10px black; position :relative; right :5%;">
          <br>
    <div class="container"  style="width: 35rem; height:30.5rem;">
    <canvas id="myLineCharttem" style="width:520px; height : 450px; position :absolute;top:2px; left:1%;"></canvas>
  </div>
</div>
  </div>
      <div class="col-md-6">
        <div class="card" style="width:35rem; height:30.5rem; box-shadow: 3px 4px 10px black; position : relative ; left:3%;">
      <br>
    <h3 style=" position : absolute ;top:7%; left:5%;"> ตารางอุณหภูมิ  </h3>
      <br>
      <table class="table table-info">
    <thead>
      <tr>
        <th>วัน/เดือน/ปี</th>
        <th>เวลา</th>
        <th>อุณหภูมิ</th>
      </tr>
    </thead>
    <tbody>
        <tr v-for="(history, key, index) in dataSensors">
          <td>{{history.Date}}</td>
          <td>{{history.Time}}</td>
          <td>{{history.Temperature}}</td>
        </tr>
    </tbody>
  </table>
  </div>
</div>
</div>
</div>
</template>
<script>
import Chart from 'Chart.js'
import { db } from './firebase.js'
export default {
  name: 'temperatureGraph',
  data () {
    return {
      dataSensors: '',
      useData: '',
      temData: [],
      timeData: [],
      dateData: []
    }
  },
  // props: ['number1', 'number2'],
  methods: {
    chart () {
      var ctxtem = document.getElementById('myLineCharttem').getContext('2d')
      var myLineCharttem = new Chart(ctxtem, {
        type: 'line',
        data: {
          labels: this.dateData,
          datasets: [{
            label: 'กราฟแสดงข้อมูล',
            data: this.temData,
            backgroundColor: [
              'rgba(217, 237, 247, 0.4)'
            ],
            borderColor: [
              'rgba(38,144,255,1)'
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
      console.log(myLineCharttem)
    }
  },
  mounted: function () {
    var vm = this
    vm.$bindAsObject('dataSensors', db.ref('DataSensors/History').limitToLast(7), null)
  },
  watch: {
    dataSensors () {
      let newdata = []
      delete this.dataSensors['.key']
      newdata = Object.values(this.dataSensors)
      console.log(this.dateData)
      for (let index in newdata) {
        this.temData[index] = newdata[index].Temperature
        this.timeData[index] = newdata[index].Time
        this.dateData[index] = newdata[index].Date
      }
      this.chart()
    }
  }
}
</script>

<style lang="css">
table{
  position: absolute;
  top:5% ;
  }
  thead{
    background-color: #3956f9;
    background:-o-linear-gradient(90deg, #1E90FF, #3956f9);
	background:-moz-linear-gradient( center top, #1E90FF 5%, #3956f9 100% );
	background:-webkit-gradient( linear, left top, left bottom, color-stop(0.05, #1E90FF), color-stop(1, #7ebffe) );
	filter:progid:DXImageTransform.Microsoft.gradient(startColorstr='#1E90FF', endColorstr='#3956f9');
	color:#FFFFFF
  }
  tr:nth-child(even) {background-color: #fff;}
  .table-info{
     box-shadow: 3px 4px 10px black;
  }
</style>
