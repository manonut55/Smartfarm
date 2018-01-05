import Vue from 'vue'
import Router from 'vue-router'
import Graph from '@/components/Graph'
import progressdata from '@/components/progressdata'
import Show from '@/components/Show'
import tabledata from '@/components/tabledata'
import Npkalert from '@/components/Npkalert'
Vue.use(Router)

export default new Router({
  routes: [
    {
      path: '/tabledata',
      name: 'tabledata',
      component: tabledata
    },
    {
      path: '/graph',
      name: 'graph',
      component: Graph
    },
    {
      path: '/',
      name: 'progressdata',
      component: progressdata
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
