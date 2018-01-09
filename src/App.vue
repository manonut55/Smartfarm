<template>
  <div id="app">
    <img src ="https://firebasestorage.googleapis.com/v0/b/smart-farm-78d34.appspot.com/o/picheard.jpg?alt=media&token=04212ba4-041b-471b-9ce4-91ca2b423df0" class="img-fluid" alt="Responsive image">
    <div id="nav">
      <nav class="navbar navbar-toggleable-md navbar-inverse bg-faded" style="background-color: #222222;">
        <button class="navbar-toggler navbar-toggler-right" type="button" data-toggle="collapse" data-target="#navbarNavDropdown" aria-controls="navbarNavDropdown" aria-expanded="false" aria-label="Toggle navigation">
          <span class="navbar-toggler-icon"></span>
        </button>
        <h2 class="navbar-brand" href="#">Smartfarm</h2>
        <div class="collapse navbar-collapse" id="navbarNavDropdown">
          <ul class="navbar-nav">
            <router-link to="/">
              <li>
                
                <a class="nav-link" href="#">Home <span class="sr-only">(current)</span></a>
              </li>
            </router-link>
            <router-link to="tabledata">
              <li>
                <a class="nav-link" href="#">ตารางข้อมูล</a>
              </li>
            </router-link>
            <router-link to="showGraph">
              <li class="nav-item">
                <a class="nav-link" href="#">กราฟเปรียบเทียบ</a>
              </li>
            </router-link>
            <li class="nav-item dropdown">
              <a class="nav-link dropdown-toggle" href="http://example.com" id="navbarDropdownMenuLink" data-toggle="dropdown" aria-haspopup="true" aria-expanded="false">กราฟแสดงข้อมูล</a>
              <div class="dropdown-menu" aria-labelledby="navbarDropdownMenuLink">
                <router-link to="soilGraph">
                  <a class="dropdown-item" href="#">ความชื้นในดิน</a>
                </router-link>
                <router-link to="humidityGraph">
                  <a class="dropdown-item" href="#">ความชื้นในอากาศ</a>
                </router-link>
                <router-link to="temperatureGraph">
                  <a class="dropdown-item" href="#">อุณหภูมิ</a>
                </router-link>
                <router-link to="fertilityGraph">
                  <a class="dropdown-item" href="#">ค่า NPK</a>
                </router-link>
              </div>
            </li>
          </ul>
        </div>
      </nav>
    </div>
    <div class="row" style="background-color:  #e2e0e0;">
      <div class="container" style="background-color: #e2e0e0;">
        <br><br>
        <npkalert></npkalert>
        <router-view></router-view>
        <br><br><br><br>
      </div>
    </div>
  </div>
</template>
<script>
import Npkalert from '@/components/Npkalert.vue'
export default {
  name: 'app',
  components: {
    Npkalert
  }
}
</script>
<style>

/*#app {
  font-family: 'Avenir', Helvetica, Arial, sans-serif;
  -webkit-font-smoothing: antialiased;
  -moz-osx-font-smoothing: grayscale;
  color: #17484C;
}
* {
  padding: 0px;
  margin: 0px;
}*/
/* .navbar-toggleable-md .navbar-nav>li>a:hover,
.navbar-toggleable-md .navbar-nav>li>a:focus {
    color: #ffffff;
    background-color: #17484C;
}
.navbar-toggleable-md .navbar-nav>.active>a,
.navbar-toggleable-md .navbar-nav>.active>a:hover,
.navbar-toggleable-md .navbar-nav>.active>a:focus {
    color: #ffffff;
    background-color: #17484C !important;
    display:block;
} */
#nav a:focus {
  color: #000;
  background: #A1C734;
}
#nav a:link, a:visited {
    font-weight: bold;
    text-decoration: none;
    text-transform: uppercase;
}
#nav a:hover, a:active {
    display: block;
    background-color: #17484C;
    color: #fff;
}
#nav a.selected:link, a.selected:visited{
    display: block;
    background-color: #17484C;
    color: #fff;
}

#nav a.selected:hover, a.selected:active {
    display: block;
    background-color: #17484C;
    color: #fff;
}


</style>
