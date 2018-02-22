import Vue from 'vue'
import Router from 'vue-router'
import HumidityGraph from '@/components/HumidityGraph'
import progressdata from '@/components/progressdata'
import TemperatureGraph from '@/components/TemperatureGraph'
import FertilityGraph from '@/components/FertilityGraph'
import Show from '@/components/Show'
import SoilGraph from '@/components/SoilGraph'
import tabledata from '@/components/tabledata'
import Npkalert from '@/components/Npkalert'
import ShowGraph from '@/components/ShowGraph'
import Clock from '@/components/Clock'
Vue.use(Router)
export default new Router({
  routes: [
    {
      path: '/tabledata',
      name: 'tabledata',
      component: tabledata
    },
    {
      path: '/ShowGraph',
      name: 'ShowGraph',
      component: ShowGraph
    },
    {
      path: '/humidityGraph',
      name: 'humidityGraph',
      component: HumidityGraph
    },
    {
      path: '/temperatureGraph',
      name: 'temperatureGraph',
      component: TemperatureGraph
    },
    {
      path: '/fertilityGraph',
      name: 'fertilityGraph',
      component: FertilityGraph
    },
    {
      path: '/soilGraph',
      name: 'soilGraph',
      component: SoilGraph
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
    },
    {
      path: '/clock',
      name: 'clock',
      component: Clock
    }
  ]
})
