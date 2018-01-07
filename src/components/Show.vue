<template>
    <div class="container">
      <div class="row">
        <div class="col-md-12">
          <div id="show">
      <!-- <show-graph :number2="number" :number1="number2"></show-graph> -->
      <show-graph ></show-graph>
      </div>
      </div>
        </div>
          <div class="row">
        <div class="col-md-12">
          <div id="show">
            <humidity-graph ></humidity-graph>
      </div>
      </div>
      </div>

</div>
</template>
<script>
// import Chart from 'Chart.js'
import showGraph from './ShowGraph'
import humidityGraph from './HumidityGraph'
export default {
  components: {
    showGraph,
    humidityGraph
  },
  name: 'show',
  data () {
    return {
      number: 5,
      number2: 20
    }
  },
  methods: {
  },
  mounted: function () {
  }
}
</script>

<style lang="css">

</style>
