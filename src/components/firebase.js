import { initializeApp } from 'firebase'
const app = initializeApp({
  apiKey: 'AIzaSyCtnb0c4yQwPeBVv5k4nSZM8MPFJsDmYs8',
  authDomain: 'smart-farm-78d34.firebaseapp.com',
  databaseURL: 'https://smart-farm-78d34.firebaseio.com',
  projectId: 'smart-farm-78d34',
  storageBucket: 'smart-farm-78d34.appspot.com',
  messagingSenderId: '783930334800'
})

export const db = app.database()
export const npkref = db.ref('npk')
