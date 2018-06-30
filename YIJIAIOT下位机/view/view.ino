#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_TFTLCD.h> // Hardware-specific library
#include <dht11.h>
#include <LM75.h>
LM75 sensor;  // initialize an LM75 object
dht11 myDHT_7;
byte buffer[7] = {};
int count = 0;
bool bufferComplete = false;
int flag_usefull=0;
int flag_gprs=0;
String ip="";
String ok="";
String message="";
int countr=0,counte=0,ocounte=0,JISHU=0;
#define OLED_RESET 4

#define  BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF
Adafruit_TFTLCD tft;

//#define PM2_5Serial Serial1 //鐢ㄤ簬鎺ユ敹PM2.5鏁版嵁
int pulsePin = 12;                 // Pulse Sensor purple wire connected to analog pin 0
String ReciveBuffer="";
String ReciveB="";
String Recive="";
volatile int BPM;                   // used to hold the pulse rate
volatile int Signal;                // holds the incoming raw data
volatile int IBI = 600;             // holds the time between beats, must be seeded! 
volatile boolean Pulse = false;     // true when pulse wave is high, false when it's low
volatile boolean QS = false;        // becomes true when Arduoino finds a beat.
void setup() {
  //PM2_5Serial.begin(9600);
  Wire.begin();
  Serial3.begin(115200);
  //Serial.begin(9600);
  tft.reset();
  uint16_t identifier = tft.readID();
  tft.begin(0x9341);
  tft.setRotation(1);
   tft.setTextColor(GREEN);
        tft.setTextSize(4);
        tft.println("");tft.println("");tft.println("");
        tft.println("  YIJIAIOT");tft.println("");tft.println("");
   tft.setTextColor(WHITE);
        tft.setTextSize(2);
         tft.println("loading...");
         interruptSetup();
}
void loop() {
view();
JISHU++;
 delay(10);
}

void view()
{
  ReciveB="";
  while(Serial3.available())
  {
      ReciveB+=(char)Serial3.read();
      delay(10);
   }
   if(ReciveB[0] == '*'||ReciveB[0] == 'l'||ReciveB[0] == '1'||ReciveB[0] == '2'||ReciveB[0] == '3'||ReciveB[0] == '4'||ReciveB[0] == '5'||ReciveB[0] == '6'||ReciveB[0] == '7'||ReciveB[0] == '8')
   {
    if(ReciveB[0]=='l')
    {
      ok = "Success";
      //ip = "dachuangzhongxin";
    }
    if(ReciveB[0]=='*')
    {
      for(int i=1;i<ReciveB.length();i++){
        ip+=ReciveB[i];
        tft.fillScreen(BLACK); 
    }
      //ip=ReciveB;
      }
    if(ReciveB[0]=='1')
    {
      message="open light!";
     }
    if(ReciveB[0]=='2')
    {
      message="shut light!";
     }
    if(ReciveB[0]=='3')
    {
      message="open fan!";
     }
    if(ReciveB[0]=='4')
    {
      message="shut fan!";
     }
     if(ReciveB[0]=='5')
    {
      message="open tv!";
     }
    if(ReciveB[0]=='6')
    {
      message="shut tv!";
     }
     if(ReciveB[0]=='7')
    {
      message="open air conditioner!";
     }
     if(ReciveB[0]=='8')
    {
      message="shut air conditioner!";
     }
    //tft.fillScreen(BLACK); 
    tft.setRotation(1);
    unsigned long start = micros();
    tft.setCursor(0, 0);
        tft.setTextColor(GREEN);
        tft.setTextSize(2);
        tft.print("WiFi:");tft.println(ip);
        tft.setTextColor(WHITE);
        tft.setTextSize(3);
        tft.print("Login:");tft.println(ok);
        tft.setTextColor(RED);
        tft.setTextSize(3);
        tft.println("Message:");
        tft.setCursor(0,80);
        tft.fillRect(0,80, 360, 40, BLACK);
        tft.setTextColor(CYAN);
        tft.setTextSize(2);
        tft.println(message);
         message="";
         ocounte++;
         return micros() - start;
    ReciveB="";
   }
   if(ok!=""&&JISHU>100)
   {
     tft.setRotation(1);
    tft.setCursor(0,160); 
    tft.setTextColor(BLUE);  
    tft.setTextSize(2);
    tft.fillRect(0,160, 360, 60, BLACK);
    tft.print("TEMP:");
    tft.print(sensor.temp());
    tft.println(" C");
    JISHU=0;
    }
 if (QS == true){ 
  if(BPM>=50&&BPM<=200&&ok!="") {
     tft.setRotation(1);
    tft.setCursor(0,120); tft.fillRect(0,120,360,40, BLACK);
    tft.setTextColor(GREEN);
        tft.setTextSize(2);
        tft.print("BPM:");
        tft.setTextColor(WHITE);
        tft.setTextSize(2);
        tft.println(BPM);
        tft.setTextColor(GREEN);
        tft.setTextSize(2);
        tft.print("IBI:");
        tft.setTextColor(WHITE);
        tft.setTextSize(2);
        tft.print(IBI);
        tft.println("ms");   
  }
  QS = false;
 }
}

