import Vue from 'vue'
import Router from 'vue-router'
import HelloWorld from '@/components/HelloWorld'
import gg from '@/components/gg'
import Show from '@/components/Show'
import Home from '@/components/Home'
import Npkalert from '@/components/Npkalert'
Vue.use(Router)

export default new Router({
  routes: [
    {
      path: '/home',
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
      component: gg
    },
    {
      path: '/show',
      name: 'show',
      component: Show
    },
    {
      path: '/npkalert',
      name: 'npkalert',
      component: Npkalert
    }
  ]
})
