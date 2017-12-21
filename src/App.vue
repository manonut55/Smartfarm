<template>
  <div id="app">
        <img src="\pic\picheard.jpg" class="img-fluid" alt="picheard.jpg" width= 100% height=200  >
        <nav class="navbar navbar-toggleable-md navbar-light bg-faded" style="background-color: #e3f2fd;">
          <button class="navbar-toggler navbar-toggler-right" type="button" data-toggle="collapse" data-target="#navbarSupportedContent" aria-controls="navbarSupportedContent" aria-expanded="false" aria-label="Toggle navigation">
            <span class="navbar-toggler-icon"></span>
          </button>
          <a class="navbar-brand" href="#">Navbar</a>

          <div class="collapse navbar-collapse" id="navbarSupportedContent">
            <ul class="navbar-nav mr-auto">
              <li class="nav-item active">
                <a class="nav-link" href="#">Home <span class="sr-only">(current)</span></a>
              </li>
              <li class="nav-item">
                <a class="nav-link" href="#">Link</a>
              </li>
              <li class="nav-item">
                <a class="nav-link disabled" href="#">Disabled</a>
              </li>
            </ul>
            <form class="form-inline my-2 my-lg-0">
              <input class="form-control mr-sm-2" type="text" placeholder="Search">
              <button class="btn btn-outline-success my-2 my-sm-0" type="submit">Search</button>
            </form>
          </div>
        </nav>
        <br>
  <div class="row">
    <div class="col-2" style="background-color: #e3f2fd;">
      <nav class="nav flex-column"  style="background-color: rgb(227, 242, 253);width: 200px; border-radius: 5px;">
        <router-link to="show">
          <a class="nav-link active" href="#">Active</a>
        </router-link>
        <router-link to="gg">
          <a class="nav-link active" href="#">Active</a>
        </router-link>
        <router-link to="Npkalert">
          <a class="nav-link active" href="#">Active</a>
        </router-link>
        <router-link to="gg">
          <a class="nav-link active" href="#">Active</a>
        </router-link>
</nav>
    </div>
    <div class="col-8">
      <router-view></router-view>
    </div>
  </div>
</div>
</template>
<script>
export default {
  name: 'app'
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
