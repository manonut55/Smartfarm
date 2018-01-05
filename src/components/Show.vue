<template>
    <div class="container">
      <div class="row">
        <div class="col-md-12">
          <div id="show">
      <show-graph :number2="number" :number1="number2"></show-graph>
      </div>
      </div>
        </div>
          <div class="row">
            <div class="col-md-12">
              <div id="show">
              <gg></gg>
      </div>
     </div>
      </div>
      <div class="row">
        <div class="col-md-12">
          <div id="show">
        <graph></graph>
      </div>
      </div>
      </div>
</div>
</template>
<script>
// import Chart from 'Chart.js'
import showGraph from './ShowGraph'
import graph from './Graph'
import gg from './gg'
export default {
  components: {
    showGraph,
    gg,
    graph
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
