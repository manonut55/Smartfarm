<template>
  <div id="app">
         <!-- <img src="src="\pic\picheard.jpg"" class="img-fluid" alt="Responsive image" > -->
        <img src="\pic\picheard.jpg" class="img-fluid" alt="Responsive image" width= 100% height=150 >
        <nav class="navbar navbar-toggleable-md navbar-light bg-faded" style="background-color: #e3f2fd;">
          <button class="navbar-toggler navbar-toggler-right" type="button" data-toggle="collapse" data-target="#navbarSupportedContent" aria-controls="navbarSupportedContent" aria-expanded="false" aria-label="Toggle navigation">
            <span class="navbar-toggler-icon"></span>
          </button>
          <a class="navbar-brand" href="/">SmartFarm</a>

          <div class="collapse navbar-collapse" id="navbarSupportedContent">
            <ul class="navbar-nav mr-auto">
              <li class="nav-item active">
                <a class="nav-link " href="/">Home <span class="sr-only">(current)</span></a>
              </li>
            </ul>
          </div>
        </nav>
        <br>
  <div class="row">
    <div class="col-2" style="background-color: #e3f2fd;">
      <nav class="nav flex-column"  style="background-color: rgb(227, 242, 253);width: 200px; border-radius: 5px;">
        <router-link to="show">
          <a class="nav-link active" >Grape</a>
        </router-link>
        <router-link to="/">
          <a class="nav-link active" >ShowData</a>
        </router-link>
        <router-link to="home">
          <a class="nav-link active" >Table</a>
        </router-link>
        <router-link to="gg">
          <a class="nav-link active" >Active</a>
        </router-link>
        </nav>
        <div class="container">
          <npkalert></npkalert>
        </div>
    </div>
    <div class="col-8" style="border:2 ;">
      <router-view></router-view>
    </div>
  </div>
</div>
</template>
<script>
import Npkalert from '@/components/Npkalert.vue'
export default {
  name: 'app',
  components: {
     Npkalert: Npkalert
   }
}
</script>
<style>
#app {
  font-family: 'Avenir', Helvetica, Arial, sans-serif;
  -webkit-font-smoothing: antialiased;
  -moz-osx-font-smoothing: grayscale;
  color: #2c3e50;
}
* {
  padding: 0px;
  margin: 0px;
}
</style>
