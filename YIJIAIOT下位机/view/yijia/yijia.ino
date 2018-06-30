
#include<ESP8266WiFi.h>
String ssidd="dachuangzhonogxin";
const char* ssid = "dachuangzhongxin";
const char* password = "1234567890";
const char* host="47.95.114.213";
const int port = 5009;
WiFiClient client;
String str_recive="";
String s_ip="";
String s_login="";
String s_message="";
int f=1;
//SoftwareSerial serial(5,4);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial1.begin(115200);
  delay(10);
  WiFi.disconnect();
  WiFi.begin(ssid,password);
  while(WiFi.status() != WL_CONNECTED)
  {
    delay(500);
   }
   //Serial.println(WiFi.localIP());
   s_ip="*"+ssidd;
   Serial.println(s_ip);
   delay(50);
   //Serial.print("connecting to ");
   //Serial.println(host);
   if(!client.connect(host,port))
   {
      Serial.println("connected failed!");
      return;
    }
    client.println("//123//");
}

void loop() {
  while(client.available())
  {
 
      str_recive += (char)client.read();
 
   }
   if(str_recive!="")
   {
    if(f==1)
    {
      s_login="l";
      f++;
      Serial.println(s_login);
    }else{
      if(str_recive[0]=='1')
      {
        s_message="1";
        }
       if(str_recive[0]=='2')
      {
        s_message="2";
        }
       if(str_recive[0]=='3')
      {
        s_message="3";
        }
       if(str_recive[0]=='4')
      {
        s_message="4";
        }
      if(str_recive[0]=='5')
      {
        s_message="5";
        }
      if(str_recive[0]=='6')
      {
        s_message="6";
        }
      if(str_recive[0]=='7')
      {
        s_message="7";
        }
      if(str_recive[0]=='8')
      {
        s_message="8";
        }
      
      Serial.println(s_message);
      }
   }
   s_message="";
str_recive="";
}
