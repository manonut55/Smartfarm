import Vue from 'vue'
import Router from 'vue-router'
import HelloWorld from '@/components/HelloWorld'
import Gg from '@/components/Gg'
import Show from '@/components/Show'
import Home from '@/components/Home'
Vue.use(Router)

export default new Router({
  routes: [
    {
      path: '/',
      name: 'home',
      component: Home
    },
    {
      path: '/helloWorld',
      name: 'helloWorld',
      component: HelloWorld
    },
    {
      path: '/gg',
      name: 'gg',
      component: Gg
    },
    {
      path: '/show',
      name: 'show',
      component: Show
    }
  ]
})
