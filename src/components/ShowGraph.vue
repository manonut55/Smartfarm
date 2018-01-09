<template>
   <div class="showGraph">
  <!-- {{number1}}  {{number2}} -->
    <div class="container">
      <div class="row justify-content-start">
        <div class="col-6">
          <div class="container">
            <div class="card" style="width: 66.5rem; height:36rem; box-shadow: 3px 4px 10px black; position : relative ;top:5%; left:2%;">
              <br>
            <h3 style=" position : absolute ;top:5%; left:5%;">  กราฟการเปรียบเทียบข้อมูล  </h3>
              <br><br>
                  <!-- <div class="card-block" > -->
            <canvas id="myLineChart" style="width:800px; height:360px; position :relative; left:0%;"  ></canvas>
          <!-- </div> -->
          </div>

          </div>
        </div>
      </div>
      <br><br>
      <div class="row justfy-content-start">
        <div class="col-6">
                <div class="card" style="width:33rem; height:31rem; box-shadow: 3px 4px 10px black; position : relative ;top:5%; left:5%;">
              <br>
            <h3 style=" position : absolute ;top:7%; left:5%;"> ตารางข้อมูลแปลงที่ปลูกแบบควบคุม  </h3>
              <br>
                  <table class="table table-info" style="left:0%;">
                  <thead>
                    <tr>
                      <th>วัน/เดือน/ปี</th>
                      <th>เวลา</th>
                      <th>ค่าNPK</th>
                      <th>ค่าความชื้นในดิน</th>
                    </tr>
                  </thead>
                  <tbody>
                      <tr v-for="(history, key, index) in dataSensors">
                        <td>{{history.Date}}</td>
                        <td>{{history.Time}}</td>
                        <td>{{history.Soil}}</td>
                        <td>{{history.Fertility}}</td>
                      </tr>
                  </tbody>
                </table>
                </div>
        </div>
        <div class="col-6">
                <div class="card" style="width: 33rem; height:31rem; box-shadow: 3px 4px 10px black; position : relative ;top:5%; left:2%;">
              <br>
            <h3 style=" position : absolute ;top:7%; left:5%;"> ตารางข้อมูลแปลงที่ปลูกแบบชาวบ้าน  </h3>
              <br>
                  <table class="table table-info" style="left:0%;">
                  <thead>
                    <tr>
                      <th>วัน/เดือน/ปี</th>
                      <th>เวลา</th>
                      <th>ค่าNPK</th>
                      <th>ค่าความชื้นในดิน</th>
                    </tr>
                  </thead>
                  <tbody>
                      <tr v-for="(history, key, index) in dataSensors">
                        <td>{{history.Date}}</td>
                        <td>{{history.Time}}</td>
                        <td>{{history.Soil_compare}}</td>
                        <td>{{history.Fertility_compare}}</td>
                      </tr>
                  </tbody>
                </table>

                    </div>
        </div>
      </div>
    </div>
  </div>
</template>
<script>
import { db } from './firebase.js'
import Chart from 'Chart.js'
export default {
  name: 'showGraph',
  props: ['number1', 'number2'],
  data () {
    return {
      dataSensors: '',
      useData: '',
      soilData: [],
      ferData: [],
      soilcData: [],
      fercData: [],
      timeData: [],
      dateData: []
    }
  },
  methods: {
    chart () {
      var ctx = document.getElementById('myLineChart').getContext('2d')
      var myLineChart = new Chart(ctx, {
        type: 'line',
        data: {
          labels: this.dateData,
          datasets: [{
            label: '# of Votes',
            data: this.ferData,
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
            data: this.soilData,
            backgroundColor: [
              'rgba(161, 199, 52, 0.2)'
            ],
            borderColor: [
              'rgba(25,75,22,1)'
            ],
            borderWidth: 1
          },
          {
            label: '# of Votes2',
            data: this.fercData,
            backgroundColor: [
              'rgba(161, 199, 52, 0.2)'
            ],
            borderColor: [
              'rgba(25,75,22,1)'
            ],
            borderWidth: 1
          },
          {
            label: '# of Votes2',
            data: this.soilcData,
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
        this.ferData[index] = newdata[index].Fertility
        this.soilData[index] = newdata[index].Soilc
        this.fercData[index] = newdata[index].Fertility_compare
        this.soilcData[index] = newdata[index].Soil_compare
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
  top:21% ;
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
  #g2{
    margin-top: 10px;
     margin-right: 5px;
     margin-bottom: 5px;
     margin-left: 5px;
     padding:10px 10px 10px 10px;
     border-style: groove;
  }
    </style>
