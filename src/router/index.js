import Vue from 'vue'
import Router from 'vue-router'
import HelloWorld from '@/components/HelloWorld'
import Gg from '@/components/Gg'
import Show from '@/components/Show'

Vue.use(Router)

export default new Router({
  routes: [
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
