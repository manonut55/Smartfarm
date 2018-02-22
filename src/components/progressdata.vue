<template>
<div class="container-fluid">
        <div class="progressdata">
          <meta name="viewport" content="width=device-width, initial-scale=1, maximum-scale=1, user-scalable=no">
            <div class="row justify-content-start">
      <div class="col-md-6">
        <temperature-chart></temperature-chart>
          </div>
      <div class="col-md-6">
            <humidity-chart></humidity-chart>
              <br>
            </div>
      </div>
    <br><br>
    <div class="row justify-content-start">
      <div class="col-md-6">
        <fertility-chart></fertility-chart>
          </div>
      <div class="col-md-6">
            <soil-chart></soil-chart>
              <br>
            </div>
      </div>
    <br><br>
    <div class="row justify-content-start">
      <div class="col-md-6">
        <div class="card" style="width: 30rem; height:19.75rem;left:18%; box-shadow: 3px 4px 10px black;">
          <br>
          <h2 style="position : relative ; top:25;left:5%;">จำนวนครั้งในการให้น้ำ </h2>
          <div class="card-block">

               <div class="col-md-6" style="width:100px; position:absolute; top:35%;left:70%;">
                 <h2 style="font-size:60px; position : absolute ; top:30%;left:33%;">{{useData[0]}}</h2>
       <img src ="https://firebasestorage.googleapis.com/v0/b/smart-farm-78d34.appspot.com/o/21690962_1546281905409883_1000476843_n.png?alt=media&token=956f0cb1-01fd-4ee8-8deb-33e7e7f48db7" class="img-fluid" alt="Responsive image">
      </div>
        <div class="col-md-6" style="position : absolute; top:50%;left:5%;">
         <h2  > ครั้งที่ </h2>

</div>
</div>
<br>
  </div>
  </div>
  <div class="col-sm-6">
        <ph-Chart></ph-Chart>
          <br>
        </div>
      </div>
  </div>
 </div>
</template>
<script>
import temperatureChart from './TemperatureChart'
import fertilityChart from './FertilityChart'
import humidityChart from './HumidityChart'
import soilChart from './SoilChart'
import phChart from './phChart'
import { db } from './firebase.js'
export default {
  name: 'progressdata',
  components: {
    fertilityChart,
    humidityChart,
    temperatureChart,
    soilChart,
    phChart
  },
  data () {
    return {
      dataSensors: '',
      useData: ''
    }
  },
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
  background-color: #fff;
  max-width: 100%;
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
