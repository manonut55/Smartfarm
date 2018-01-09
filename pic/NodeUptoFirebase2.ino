#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#include "DHT.h"
#include <Adafruit_Sensor.h>
#include <time.h>

#define WIFI_SSID       "AMARA"
#define WIFI_PASSWORD   "liphan36"
#define FIREBASE_HOST "smart-farm-78d34.firebaseio.com"
#define FIREBASE_KEY  "A2ijqTTzXJQ0q9KZHnf0c1r7RrVdIS8fcBjKp2V8"

//Mux control pins
#define s0 16 //D0
#define s1 5 //D1
#define s2 4 //D2
#define s3 0 //D3

#define Offset 0.00            //deviation compensate
#define samplingInterval 20
#define printInterval 800
#define ArrayLenth  40    //times of collection

#define DHTPIN 14 // D5
#define relay1 12 // D6 รดน้ำ
#define relay2 13 // D7 รดปุ๋ย
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

float h, t, PH_F;
int  Fertility, PH, amountwater, Fertility2;
const String DataSensors = "DataSensors";
int timezone = 7 * 3600; //ตั้งค่า TimeZone ตามเวลาประเทศไทย
int dst = 0; //กำหนดค่า Date Swing Time
int hours;
int fertilizerState;
int pHArray[ArrayLenth];   //Store the average value of the sensor feedback
int pHArrayIndex = 0;    
int count = 0, c_awt = 0, c_wt = 0;
static float pHValue, voltage, percentage, percentage2;

 
void setup() 
{
  pinMode(relay1, OUTPUT); //รดน้ำ
  pinMode(relay2, OUTPUT); //NPK

  Serial.begin(115200);
  Serial.println(WiFi.localIP());
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
   while (WiFi.status() != WL_CONNECTED) 
   {
     Serial.print(".");
     delay(500);
   }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
    
  Firebase.begin(FIREBASE_HOST, FIREBASE_KEY);

  configTime(timezone, dst, "pool.ntp.org", "time.nist.gov"); //ดึงเวลาจาก Server
  Serial.println("\nLoading time");
    while (!time(nullptr))
    {
      Serial.print("*");
      delay(10000);
    }
  
  dht.begin();
  hours = timehours();
  Serial.print("Time Hours :");
  Serial.println(hours);

  pinMode(s0, OUTPUT);
  pinMode(s1, OUTPUT);
  pinMode(s2, OUTPUT);
  pinMode(s3, OUTPUT);

  digitalWrite(s0, LOW);
  digitalWrite(s1, LOW);
  digitalWrite(s2, LOW);
  digitalWrite(s3, LOW); 

  digitalWrite(relay1, LOW);
  digitalWrite(relay2, LOW);

}
  

void loop() 
{ 
//  ------------------------JsonUpTofirebase--------------------------

  Firebase.set("DataSensors/Temperature",t);
  Firebase.set("DataSensors/Humidity",h);
  Firebase.set("DataSensors/Fertility",Fertility); 
  Firebase.set("DataSensors/Amountwater",amountwater);
  Firebase.set("DataSensors/Soil",percentage);
  Firebase.set("DataSensors/Water_pH",pHValue);

  String newtime = ntimeString();
  Serial.print("time : ");
  Serial.println(newtime);

  if(newtime == "2:32" || newtime == "12:0" || newtime == "16:0")
  {
    if(count == 0){
      StaticJsonBuffer<200> jsonBuffer;
      JsonObject& history = jsonBuffer.createObject();
      history["Time"] = timeString();
      history["Date"] = dateString();
      history["Temperature"] = t;
      history["Humidity"] = h;
      history["Fertility"] = Fertility;
      history["Amountwater"] = amountwater;
      history["Soil"] = percentage;
//      history["Fertility2"] = Fertility2;
//      history["Soil2"] = Soil2;
      Firebase.push("DataSensors/History",history);
      count = count + 1;
    }

  }
  
   if(newtime == "2:33" || newtime == "12:1" || newtime == "16:1")
  {
    count = 0;
    Serial.println("count = 0");
  }

//  ----------------------------NPK Ph-----------------------------------
  
  Fertility = Read_Fertility();

  Serial.print("Fertility : ");
  Serial.print(Fertility);
  Serial.println("%");
  Serial.println(" ");
    if((hours >= 1) && (hours <= 17) && fertilizerState)
    {
    
      if (Fertility >= 47)
            {
            Serial.println("FertilizerValve Off");
            digitalWrite(relay2, LOW);
            }
              else if (Fertility < 20 && fertilizerState == true)
              {
                  Serial.println("FertilizerValve On");
                  digitalWrite(relay2, HIGH);
              }
     }

// Read DHT
  h = dht.readHumidity();
  t = dht.readTemperature();


  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.println(" %\t");
  Serial.println("");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print(" *C ");  
  Serial.println(" "); 

//  -------------------------------Soil------------------------------

  Serial.print("Moisture Sensor Value: ");
  Serial.print(percentage);
  Serial.println("%");
  if((hours >= 1) && (hours <= 17))
  {
    if ( percentage >= 60)
    {
      c_wt = 0;
      Serial.println("WaterValve Off 1");
      digitalWrite(relay1, LOW);
    }
      else if (percentage < 35)
      {
        c_wt = 1;
        amountwater += 1;
        Serial.println("WaterValve On 1");
        digitalWrite(relay1, HIGH);
      }
  }
  
  if(percentage >= 35 && percentage <= 60)
  {
    if(c_wt == 1)
    {
      Serial.println("WaterValve On");
      digitalWrite(relay1, HIGH);
    }
  }

  if( percentage >= 60)
  {
    c_wt = 0;
    Serial.println("WaterValve Off 2");
    digitalWrite(relay1, LOW);
  }
  
  if(newtime == "0:0" && c_awt == 0)
  { 
    c_awt = c_awt + 1;
    amountwater = 0;
  }
  if(newtime == "0:1")
  {
    c_awt = 0;
  }
  
//  show water pH
  ph();
  soil();


  Serial.println(" ");

  int Fertility2 = Read_Fertility();
  
}
// Read Ph Water
float ph()
{
      pHArray[pHArrayIndex++]= Read_ch1();
      if(pHArrayIndex==ArrayLenth)pHArrayIndex=0;
      voltage = avergearray(pHArray, ArrayLenth)*5.0/1024;
      pHValue = 3.5*voltage+Offset;
      Serial.print(" pH value: ");
      Serial.println(pHValue);
}
// Read soil sensor 1
float soil()
{
   int Soil = Read_ch3();
   percentage = ( 100 - ( (Soil/1023.00) * 100 ) );
   Serial.print(" soil value: ");
   Serial.println(percentage);
}
// Read soil sensor 2
float soil2()
{
   int Soil2 = Read_ch4();
   percentage2 = ( 100 - ( (Soil2/1023.00) * 100 ) );
   Serial.print(" soil value: ");
   Serial.println(percentage2);
}
//NPK 1
int Read_Fertility()
{
  int i,Fertility;
   Fertility = 0; 
   for(i=0;i<10;i++){Fertility = Fertility + Read_ch2();delay(10);}
   Fertility = Fertility/10;
   if(Fertility >= 480){Fertility = ((Fertility - 480)/10) + 93;}else
   if(Fertility >= 360){Fertility = ((Fertility - 360)/7.5) + 77;}else
   if(Fertility >= 275){Fertility = ((Fertility - 275)/5) + 59;}else
   if(Fertility >= 200){Fertility = ((Fertility - 200)/6.25) + 47;}else
   if(Fertility >= 125){Fertility = ((Fertility - 125)/5.3) + 31;}else
   if(Fertility >= 65){Fertility = ((Fertility - 65)/4) + 16;}else
   if(Fertility >=  0){Fertility = ((Fertility - 0)/3.75) + 0;}
   Serial.print("NPK :");
   Serial.println(Fertility);
   return(Fertility);
}
//NPK 2
int Read_Fertility2()
{
  int i,Fertility2;
   Fertility2 = 0; 
   for(i=0;i<10;i++){Fertility2 = Fertility2 + Read_ch5();delay(10);}
   Fertility2 = Fertility2/10;
   if(Fertility2 >= 480){Fertility2 = ((Fertility2 - 480)/10) + 93;}else
   if(Fertility2 >= 360){Fertility2 = ((Fertility2 - 360)/7.5) + 77;}else
   if(Fertility2 >= 275){Fertility2 = ((Fertility2 - 275)/5) + 59;}else
   if(Fertility2 >= 200){Fertility2 = ((Fertility2 - 200)/6.25) + 47;}else
   if(Fertility2 >= 125){Fertility2 = ((Fertility2 - 125)/5.3) + 31;}else
   if(Fertility2 >= 65){Fertility2 = ((Fertility2 - 65)/4) + 16;}else
   if(Fertility2 >=  0){Fertility2 = ((Fertility2 - 0)/3.75) + 0;}
   Serial.print("NPK :");
   Serial.println(Fertility2);
   return(Fertility2);
}
void NumToChar(unsigned long Num, char  *Buffer,unsigned char Digit)
{
  char i;
   for(i=(Digit-1);i>= 0;i--)
    { Buffer[i] =  (Num % 10) + '0';  // 234 , 23 , 2
      Num = Num / 10;
    }  
   for(i=0;i<(Digit-1);i++)
    { if(Buffer[i] == '0'){Buffer[i] =  ' ';}else{i =100;}
                         
    }   
}

int timehours()
{ 
  int timehour;              
  time_t now = time(nullptr);
  struct tm* p_tm = localtime(&now);
  timehour = p_tm->tm_hour;
  return(timehour);
}

String dateString()
{ 
  time_t now = time(nullptr);
  struct tm* newtime = localtime(&now);

    String tmpNow = "";
    tmpNow += String(newtime->tm_mday);
    tmpNow +="/";
    tmpNow += String(newtime->tm_mon+1);
    tmpNow +="/";
    tmpNow += String(newtime->tm_year).substring(1);
    return(tmpNow);
}

String ntimeString()
{             
  time_t now = time(nullptr);
  struct tm* newtime = localtime(&now);
  String tmpNow = "";
    tmpNow += String(newtime->tm_hour);
    tmpNow +=":";
    tmpNow += String(newtime->tm_min);
    return(tmpNow);
}


// Chanel Analog
int Read_ch0(void)
{
  digitalWrite(s0, LOW);
  digitalWrite(s1, LOW);
  digitalWrite(s2, LOW);
  digitalWrite(s3, LOW);
  delay(10);
  return (analogRead(A0));
}
int Read_ch1()
{
  digitalWrite(s0, HIGH);
  digitalWrite(s1, LOW);
  digitalWrite(s2, LOW);
  digitalWrite(s3, LOW);
  delay(10);
  return (analogRead(A0));
}
int Read_ch2()
{
  digitalWrite(s0, LOW);
  digitalWrite(s1, HIGH);
  digitalWrite(s2, LOW);
  digitalWrite(s3, LOW);
  delay(10);
  return (analogRead(A0));
}
int Read_ch3()
{
  digitalWrite(s0, HIGH);
  digitalWrite(s1, HIGH);
  digitalWrite(s2, LOW);
  digitalWrite(s3, LOW);
  delay(10);
  return (analogRead(A0));
}
//soil2
int Read_ch4()
{
  digitalWrite(s0, LOW);
  digitalWrite(s1, LOW);
  digitalWrite(s2, HIGH);
  digitalWrite(s3, LOW);
  delay(10);
  return (analogRead(A0));
}
//NPK2
int Read_ch5()
{
  digitalWrite(s0, HIGH);
  digitalWrite(s1, LOW);
  digitalWrite(s2, HIGH);
  digitalWrite(s3, LOW);
  delay(10);
  return (analogRead(A0));
}
// function paramettor Ph
double avergearray(int* arr, int number)
{
  int i;
  int max,min;
  double avg;
  long amount=0;
  if(number<=0){
    Serial.println("Error number for the array to avraging!/n");
    return 0;
  }
  if(number<5){   //less than 5, calculated directly statistics
    for(i=0;i<number;i++){
      amount+=arr[i];
    }
    avg = amount/number;
    return avg;
  }else{
    if(arr[0]<arr[1]){
      min = arr[0];max=arr[1];
    }
    else{
      min=arr[1];max=arr[0];
    }
    for(i=2;i<number;i++){
      if(arr[i]<min){
        amount+=min;        //arr<min
        min=arr[i];
      }else {
        if(arr[i]>max){
          amount+=max;    //arr>max
          max=arr[i];
        }else{
          amount+=arr[i]; //min<=arr<=max
        }
      }//if
    }//for
    avg = (double)amount/(number-2);
  }//if
  return avg;
}

