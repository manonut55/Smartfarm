<template>
  <div id="app">
      <!-- <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no"> -->
      <div class="row" >
        <img src="\pic\top.jpg" class="img-fluid" alt="top.jpg" width= 100%  >
        </div>
      <div class="row no-gutters">
        <div class="col-12">
          <nav class="navbar navbar-toggleable-md navbar-inverse bg-primary" >
          <!-- <button class="navbar-toggler navbar-toggler-right" type="button" data-toggle="collapse" data-target="#navbarSupportedContent" aria-controls="navbarSupportedContent" aria-expanded="false" aria-label="Toggle navigation">
          <span class="navbar-toggler-icon"></span>
        </button> -->
        <router-link to="/">
          <a class="navbar-brand" href="">Smartfarm</a>
        </router-link>
        <div class="collapse navbar-collapse" id="navbarSupportedContent">
          <ul class="navbar-nav mr-auto">
            <router-link to="/">
            <li class="nav-item active">
              <a class="nav-link">Home <span class="sr-only">(current)</span></a>
            </li>
            </router-link>
          </ul>
          </div>
          </nav>
        </div>
          <br><br><br>
          <div class="row">
            <div class="col-sm-2">
              <router-link to="show">
                <button type="button" class="btn btn-primary col-xl">Primary</button>
              </router-link>
              <router-link to="gg">
                <button type="button" class="btn btn-primary col-xl">Primary</button>
              </router-link>
              <router-link to="npkalert">
                <button type="button" class="btn btn-primary col-xl">Primary</button>
              </router-link>
              <router-link to="home">
                <button type="button" class="btn btn-primary col-xl">Primary</button>
              </router-link>
              <router-link to="home">
                <button type="button" class="btn btn-primary col-xl">Primary</button>
              </router-link>
              <div class="" v-if="npk < 30">
                <div class="container">
                  gvghvjhcvugcytu
               <npkalert></npkalert>
             </div>
             </div>
            </div>
        <div class="col-sm-10" >
          <div class="container">
            <router-view></router-view>
          </div>
    </div>
  </div>
  </div>
  </div>
</template>
<script>
import Npkalert from '@/components/Npkalert.vue'
import 'bootstrap-vue/dist/bootstrap-vue.css'
export default {
  name: 'app',
  components: {
    Npkalert: Npkalert
  },
  data () {
    return {
      npk: 20
    }
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
.col-sm-2{
  background: blue;
  height: 100vh
}
</style>
