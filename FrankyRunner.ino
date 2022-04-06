
/*************************************************************

  This is a simple demo of sending and receiving some data.
  Be sure to check out other examples!
 *************************************************************/

// Template ID, Device Name and Auth Token are provided by the Blynk.Cloud
// See the Device Info tab, or Template settings


// Comment this out to disable prints and save space
#define BLYNK_PRINT Serial

#define BLYNK_TEMPLATE_ID "XXXXXX add here your Blynk Template"
#define BLYNK_DEVICE_NAME "XXXXXX add here your Blynk device name"
#define BLYNK_AUTH_TOKEN "XXXXXX add here your Blynk Token"

bool toggleState_1 = LOW; //Define integer to remember the toggle state for relay 1
bool toggleState_2 = LOW; //Define integer to remember the toggle state for relay 2
bool toggleState_3 = LOW; //Define integer to remember the toggle state for relay 1
bool toggleState_4 = LOW; //Define integer to remember the toggle state for relay 2
bool toggleState_5 = LOW; //Define integer to remember the toggle state for relay 1
bool toggleState_6 = LOW; //Define integer to remember the toggle state for relay 2
bool toggleState_7 = LOW; //Define integer to remember the toggle state for relay 1
bool toggleState_8 = LOW; //Define integer to remember the toggle state for relay 2
bool toggleState_9 = LOW; //Define integer to remember the toggle state for relay 2
bool toggleState_10 = LOW; //Define integer to remember the toggle state for relay 2
bool toggleState_11 = LOW; //Define integer to remember the toggle state for relay 2
bool toggleState_12 = LOW; //Define integer to remember the toggle state for relay 2
bool toggleState_13 = LOW; //Define integer to remember the toggle state for relay 2
bool toggleState_14 = LOW; //Define integer to remember the toggle state for relay 2
bool toggleState_15 = LOW; //Define integer to remember the toggle state for relay 2
bool toggleState_16 = LOW; //Define integer to remember the toggle state for relay 2
bool toggleState_17 = LOW; //Define integer to remember the toggle state for relay 2
bool toggleState_18 = LOW; //Define integer to remember the toggle state for relay 2
bool toggleState_19 = LOW; //Define integer to remember the toggle state for relay 2
bool toggleState_20 = LOW; //Define integer to remember the toggle state for relay 2


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = BLYNK_AUTH_TOKEN;

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "XXXXXX add here your house WIFI SSID";
char pass[] = "XXXXXX add here your WIFI password";

BlynkTimer timer;
int timerID;
int counter1, counter2, counter3, runx, liftx, detener = 1;
int x=80; //run
int y=60; //rest
int z=30; //cycles
int w=5; //speed
int CurrentSpeed=0;
 
// This function is called every time the Virtual Pin 0 state changes
BLYNK_WRITE(V0)
{
  // Set incoming value from pin V0 to a variable
  int value = param.asInt();

  // Update state
  Blynk.virtualWrite(V1, value);
}

BLYNK_WRITE(V32)
{
  // Set incoming value from pin V0 to a variable
  w = param.asInt();
    Blynk.virtualWrite(V33, w);

}
BLYNK_WRITE(V24)
{
  // Set incoming value from pin V0 to a variable
  x = param.asInt();
}
BLYNK_WRITE(V25)
{
  // Set incoming value from pin V0 to a variable
  y = param.asInt();
}
BLYNK_WRITE(V26)
{
  // Set incoming value from pin V0 to a variable
  z = param.asInt();

  // Update state
  Blynk.virtualWrite(V27, z);
}

// This function is called every time the device is connected to the Blynk.Cloud
BLYNK_CONNECTED()
{
  // Change Web Link Button message to "Congratulations!"
  Blynk.setProperty(V3, "offImageUrl", "https://static-image.nyc3.cdn.digitaloceanspaces.com/general/fte/congratulations.png");
  Blynk.setProperty(V3, "onImageUrl",  "https://static-image.nyc3.cdn.digitaloceanspaces.com/general/fte/congratulations_pressed.png");
  Blynk.setProperty(V3, "url", "https://docs.blynk.io/en/getting-started/what-do-i-need-to-blynk/how-quickstart-device-was-made");

  // Request the latest state from the server

  Blynk.virtualWrite(V4, 1);
  Blynk.virtualWrite(V5, 1);
  Blynk.virtualWrite(V7, 1);
  Blynk.virtualWrite(V8, 1);
  Blynk.virtualWrite(V9, 1);
  Blynk.virtualWrite(V10, 1);
  Blynk.virtualWrite(V11, 1);
  Blynk.virtualWrite(V12, 0);
  Blynk.virtualWrite(V13, 0);
  Blynk.virtualWrite(V14, 0);
  Blynk.virtualWrite(V15, 0);
  Blynk.virtualWrite(V16, 0);
  Blynk.virtualWrite(V17, 0);
  Blynk.virtualWrite(V18, 0);
  Blynk.virtualWrite(V19, 0);
  Blynk.virtualWrite(V20, 0);
  Blynk.virtualWrite(V33, w);


  
  Blynk.syncVirtual(V1);
  Blynk.syncVirtual(V2);
  Blynk.syncVirtual(V4);
  Blynk.syncVirtual(V5);
  Blynk.syncVirtual(V6);
  Blynk.syncVirtual(V7);
  Blynk.syncVirtual(V8);
  Blynk.syncVirtual(V9);
  Blynk.syncVirtual(V10);
  Blynk.syncVirtual(V11);
  Blynk.syncVirtual(V12);
  Blynk.syncVirtual(V13);
  Blynk.syncVirtual(V14);
  Blynk.syncVirtual(V15);
  Blynk.syncVirtual(V16);
  Blynk.syncVirtual(V17);
  Blynk.syncVirtual(V18);
  Blynk.syncVirtual(V19);
  Blynk.syncVirtual(V20);
  Blynk.syncVirtual(V21);
  
}

// When App button is pushed - switch the state

BLYNK_WRITE(V22) {
   timer.restartTimer(timerID);
   timer.disable(timerID);
   counter1=0;
   counter2=0;
   counter3=0;
   runx=0;
   liftx=0;
   detener = 1;
   
   Blynk.virtualWrite(V21,counter1);
   Blynk.virtualWrite(V28,counter1);
   Blynk.virtualWrite(V29,counter2);
   Blynk.virtualWrite(V30,counter3);
   Blynk.virtualWrite(V27,z-counter3);
   //Blynk.virtualWrite(V27,readvalue(V26));

    

}
BLYNK_WRITE(V23) {
   timer.enable(timerID);
   timer.restartTimer(timerID);
runx=1;
liftx=0;
detener = 0;

//    Blynk.virtualWrite(V28, counter1);
//    Blynk.virtualWrite(V29, counter2);
//    Blynk.virtualWrite(V30, counter3);
  //  Blynk.virtualWrite(V27, V26-counter3);
Blynk.notify("Ready");
Speed3();
 }

BLYNK_WRITE(V4) {
  toggleState_1 = param.asInt();
  if(toggleState_1 == 1){
    digitalWrite(12, LOW);
  }
  else { 
    digitalWrite(12, HIGH);
  }
}

BLYNK_WRITE(V5) {
  toggleState_2 = param.asInt();
  if(toggleState_2 == 1){
    digitalWrite(13, LOW);
  }
  else { 
    digitalWrite(13, HIGH);
  }
}
BLYNK_WRITE(V6) {
  toggleState_3 = param.asInt();
  if(toggleState_3 == 1){
    digitalWrite(14, LOW);
  }
  else { 
    digitalWrite(14, HIGH);
  }
}
BLYNK_WRITE(V7) {
  toggleState_4 = param.asInt();
  if(toggleState_4 == 1){
    digitalWrite(16, LOW);
  }
  else { 
    digitalWrite(16, HIGH);
  }
}
BLYNK_WRITE(V8) {
  toggleState_5 = param.asInt();
  if(toggleState_5 == 1){
    digitalWrite(4, LOW);
  }
  else { 
    digitalWrite(4, HIGH);
  }
}
BLYNK_WRITE(V9) {
  toggleState_6 = param.asInt();
  if(toggleState_6 == 1){
    digitalWrite(5, LOW);
  }
  else { 
    digitalWrite(5, HIGH);
  }
}
BLYNK_WRITE(V10) {
  toggleState_7 = param.asInt();
  if(toggleState_7 == 1){
    digitalWrite(15, LOW);
  }
  else { 
    digitalWrite(15, HIGH);
  }
}
BLYNK_WRITE(V11) {
  toggleState_8 = param.asInt();
  if(toggleState_8 == 1){
    digitalWrite(10, LOW);
  }
  else { 
    digitalWrite(10, HIGH);
  }

}

BLYNK_WRITE(V12) {//speed3
  Speed3();
  CurrentSpeed=3;
}

BLYNK_WRITE(V13) {//speed4 v5,v4,v11
  Speed4();
  CurrentSpeed=4;
}

BLYNK_WRITE(V14) {//speed5 v5,v7,v11
  Speed5();
  CurrentSpeed=5;
}

BLYNK_WRITE(V15) { //speed6
  Speed6();
  CurrentSpeed=6;
}

BLYNK_WRITE(V16) { //stop
  detener = 1;
  Stop();
  CurrentSpeed=0;
}

BLYNK_WRITE(V17) { //Inc Up

  In_Up();
}
BLYNK_WRITE(V18) { //Inc Down

  In_Down();
}

BLYNK_WRITE(V19) { //Speed Up

Speed_Up();  
}

BLYNK_WRITE(V20) { //Speed down

Speed_Down();  
}


// This function sends Arduino's uptime every second to Virtual Pin 2.
void myTimerEvent()
{
if ((runx==1) and (liftx==0)){
  counter1 = counter1 + 1;
}
if ((runx==0) and (liftx==1)){
  counter2 = counter2 + 1;
}
    Blynk.virtualWrite(V21, counter1);
    Blynk.virtualWrite(V28, counter1);
    Blynk.virtualWrite(V29, counter2);
    Blynk.virtualWrite(V30, counter3);
    Blynk.virtualWrite(V27, z-counter3);

}

void myTimerEventx()
{
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  Blynk.virtualWrite(V2, millis() / 1000);
 // counter1 = counter1 + 1;
 //   Blynk.virtualWrite(V21, counter1);

}

void Reset_output()
{
     delay(500);
 digitalWrite(12, LOW);
  digitalWrite(13, LOW);
  digitalWrite(14, LOW);
  digitalWrite(16, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(15, LOW);
  digitalWrite(10, LOW);
digitalWrite(10, LOW);

}

void Speed3()
{
    CurrentSpeed=3;
    digitalWrite(13, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(10, HIGH);
//    Blynk.virtualWrite(V12, 1);
    Reset_output();
}

void Speed4()
{
    CurrentSpeed=4;
    digitalWrite(13, HIGH);
    digitalWrite(12, HIGH);
    digitalWrite(10, HIGH);
    Reset_output();
//    Blynk.virtualWrite(V13, 1);
}
void Speed5()
{
    CurrentSpeed=5;
    digitalWrite(13, HIGH);
    digitalWrite(16, HIGH);
    digitalWrite(10, HIGH);
    Reset_output();
//      Blynk.virtualWrite(V14, 1);
}
void Speed6()
{
    CurrentSpeed=6;
    digitalWrite(13, HIGH);
    digitalWrite(14, HIGH);
    digitalWrite(10, HIGH);
    Reset_output();
//    Blynk.virtualWrite(V15, 1);
}
void Stop()
{
    CurrentSpeed=0;
    digitalWrite(13, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    Reset_output();
}

void In_Up()
{
    digitalWrite(13, HIGH);
    digitalWrite(14, HIGH);
    digitalWrite(15, HIGH);
    Reset_output();

}

void In_Down()
{
    digitalWrite(13, HIGH);
    digitalWrite(16, HIGH);
    digitalWrite(15, HIGH);
    Reset_output();
}
void Speed_Up()
{
    digitalWrite(13, HIGH);
    digitalWrite(16, HIGH);
    digitalWrite(5, HIGH);
    Reset_output();

}
void Speed_Down()
{
    digitalWrite(13, HIGH);
    digitalWrite(12, HIGH);
    digitalWrite(5, HIGH);
    Reset_output();
}


void setup()
{
  // Debug console
  Serial.begin(115200);

  //Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 8080);
  //Blynk.begin(auth, ssid, pass, IPAddress(23,203,231,169), 8080);
Blynk.virtualWrite(V21,0);
//Seconds=0;
  // Setup a function to be called every second
 
 timer.setTimeout(3600000L, [] () {} ); // dummy/sacrificial Function
 timer.setInterval(1000L, myTimerEventx);
 timerID = timer.setInterval(1000L, myTimerEvent);
  timer.disable(timerID);
   timer.restartTimer(timerID);
    delay(100);
  
   pinMode(12, OUTPUT);
   pinMode(13, OUTPUT);
   pinMode(14, OUTPUT);
   pinMode(16, OUTPUT);  
   pinMode(4, OUTPUT);
   pinMode(5, OUTPUT);
   pinMode(15, OUTPUT);
   pinMode(10, OUTPUT); 

 // pinMode(wifiLed, OUTPUT);

 //
  //During Starting all Relays should TURN OFF
  digitalWrite(12, LOW);
  digitalWrite(13, LOW);
  digitalWrite(14, LOW);
  digitalWrite(16, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(15, LOW);
  digitalWrite(10, LOW);
digitalWrite(10, LOW);

Blynk.virtualWrite(V24, x);
  Blynk.virtualWrite(V25, y);
   Blynk.virtualWrite(V26, z);
   Blynk.virtualWrite(V32, w);
}

void loop()
{
  Blynk.run();
  timer.run();
  
if (detener == 0) {
 
if (counter1==(x-10)){
  if (CurrentSpeed == 0) {
    Stop();
  } else if (CurrentSpeed ==3){
    Speed3();
  } else if (CurrentSpeed==4){
    Speed4();
  } else if (CurrentSpeed==5){
    Speed5();
  } else if (CurrentSpeed==6){
    Speed6();
  }
}
if (counter1==(x-5)){
  if (CurrentSpeed == 0) {
    Stop();
  } else if (CurrentSpeed ==3){
    Speed3();
  } else if (CurrentSpeed==4){
    Speed4();
  } else if (CurrentSpeed==5){
    Speed5();
  } else if (CurrentSpeed==6){
    Speed6();
  }
}

if (counter2==(y-10)){
  if (CurrentSpeed == 0) {
    Stop();
  } else if (CurrentSpeed ==3){
    Speed3();
  } else if (CurrentSpeed==4){
    Speed4();
  } else if (CurrentSpeed==5){
    Speed5();
  } else if (CurrentSpeed==6){
    Speed6();
  }
}
if (counter2==(y-5)){
  if (CurrentSpeed == 0) {
    Stop();
  } else if (CurrentSpeed ==3){
    Speed3();
  } else if (CurrentSpeed==4){
    Speed4();
  } else if (CurrentSpeed==5){
    Speed5();
  } else if (CurrentSpeed==6){
    Speed6();
  }
}

  if (counter1>=x){
    runx=0;
    liftx=1;
    counter1=0;
    Blynk.notify("lift");
    Stop();
  }
  if (counter2>=y){
    runx=1;
    liftx=0;
    counter2=0;
    counter3=counter3+1;
    Blynk.virtualWrite(V30, counter3);
    Blynk.notify("run");
    if (counter3==1){ 
      Speed4(); }
    else if ((counter3>=2) and (w==3)){ 
      Speed3(); }
    else if ((counter3>=2) and (w==4)){ 
      Speed4(); }
    else if (((counter3>=2) and (w==5))or ((counter3==2) and (w==6))){ 
      Speed5(); }
      else if ((counter3>=3) and (w==6)){
        Speed6();
      }
    }
  if (counter3 > z){
     timer.restartTimer(timerID);
     timer.disable(timerID);
         liftx=0;
         runx=0;
    counter2=0;
    runx=0;
    Stop();
    Stop();
    CurrentSpeed=0;
    detener =1;
    //counter3=100;
  }
} else if (detener == 1){
  Stop();
  detener = 3;
}
  // You can inject your own code or combine it with other sketches.
  // Check other examples on how to communicate with Blynk. Remember
  // to avoid delay() function!
}

