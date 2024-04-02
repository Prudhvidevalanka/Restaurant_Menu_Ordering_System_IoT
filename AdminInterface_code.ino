#include <SoftwareSerial.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <ESP8266WiFi.h>
#define LEDonBoard 2  
String apiKey = "LGBVSVJ1ERQR0VA0"; 
const char* ssid = "cat";
const char* password = "12345678";
const char* server = "api.thingspeak.com";

WiFiClient client;

SoftwareSerial BTSerial(14, 12); // RX (D6) and TX (D5) pins on the NodeMCU
LiquidCrystal_I2C lcd(0x27, 16, 2);


void setup() {
  Serial.begin(38400);
  BTSerial.begin(38400); // Set the baud rate to match your Bluetooth module
  WiFi.begin(ssid, password); //--> Connect to your WiFi router
  Serial.println("");
    
  pinMode(LEDonBoard,OUTPUT); //--> On Board LED port Direction output
  digitalWrite(LEDonBoard, HIGH); //--> Turn off Led On Board
  
  //----------------------------------------Wait for connection
  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    //----------------------------------------Make the On Board Flashing LED on the process of connecting to the wifi router.
    digitalWrite(LEDonBoard, LOW);
    delay(250);
    digitalWrite(LEDonBoard, HIGH);
    delay(250);
    //----------------------------------------
  }
  //----------------------------------------
  digitalWrite(LEDonBoard, HIGH); //--> Turn off the On Board LED when it is connected to the wifi router.
  //----------------------------------------If connection successful show IP address in serial monitor
  Serial.println("");
  Serial.print("Successfully connected to : ");
  Serial.println(ssid);


  pinMode(16,OUTPUT);
  lcd.begin();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("hello");
}
char receivedChar;

float sum;
float item;


void loop()
 {
   


   if(BTSerial.available()) {
     receivedChar = BTSerial.read();
    Serial.print(receivedChar);
   

   if(receivedChar=='1')
     {
      lcd.clear();
       lcd.setCursor(1,0);
       sum=sum+40;
       item++;
       Serial.println("IDLY ORDERED");
      lcd.print("IDLY ORDERED");
      delay(1000);

     }
     else if(receivedChar=='2')
     {
      Serial.println("DOSA OREDERED");
      sum=sum+50;
      item++;
      lcd.clear();
      lcd.setCursor(1,0);
      lcd.print("DOSA OREDERED");
      delay(1000);
     }

     else if(receivedChar=='3')
     {
      Serial.println("BONDA ORDERED");
      sum=sum+40;
      item++;
      lcd.clear();
      lcd.setCursor(1,0);
      lcd.print("BONDA ORDERED");
      delay(1000);
     }

     else if(receivedChar=='4')
     {
      Serial.println("PULKA ORDERED");
      sum=sum+20;
      item++;
      lcd.clear();
      lcd.setCursor(1,0);
      lcd.print("PULKA ORDERED");
      delay(1000);
     }

     else if(receivedChar=='5')
     {
      Serial.println("PUHA ORDERED");
      sum=sum+30;
      item++;
      lcd.clear();
      lcd.setCursor(1,0);
      lcd.print("PUHA ORDERED");
      delay(1000);
     }


     else if(receivedChar=='6')
     {
      Serial.println("PURI ORDERED");
      sum=sum+40;
      item++;
      lcd.clear();
      lcd.setCursor(1,0);
      lcd.print("PURI ORDERED");
      delay(1000);
     }

     else if(receivedChar=='7')
     {
      Serial.println("MEALS ORDERED");
      sum=sum+70;
      item++;
      lcd.clear();
      lcd.setCursor(1,0);
      lcd.print("MEALS ORDERED");
      delay(1000);
     }

     else if(receivedChar=='8')
     {
      Serial.println("CURD ORDERED");
      sum=sum+20;
      item++;
      lcd.clear();
      lcd.setCursor(1,0);
      lcd.print("CURD ORDERED");
      delay(1000);
     }


     else if(receivedChar=='9')
     {
      Serial.println("RICE ORDERED");
      sum=sum+40;
      item++;
      lcd.clear();
      lcd.setCursor(1,0);
      lcd.print("RICE ORDERED");
      delay(1000);
     }

     

     else if(receivedChar=='B')
     {
      Serial.println("BOTTLE ORDERED");
      sum=sum+20;
      item++;
      lcd.clear();
      lcd.setCursor(1,0);
      lcd.print("BOTTLE ORDERED");
       for(int i=0;i<3;i++)
       {
      digitalWrite(16,HIGH);
      delay(500);
      digitalWrite(16,LOW);
      delay(500);
       }
     }


     else if(receivedChar=='D')
     {
      Serial.println("CALLING WAITER");
      lcd.clear();
      lcd.setCursor(1,0);
      lcd.print("WAITER......");
      
      for(int i=0;i<9;i++){
      digitalWrite(16,HIGH);
      delay(150);
      digitalWrite(16,LOW);
      delay(150);
       
      }
     }




      else if(receivedChar=='A')
      {
        lcd.clear();
        lcd.print("connecting");
        lcd.setCursor(0,1);
        lcd.print("to server..");
        Serial.print("amount ");
        Serial.print(sum);
        if (isnan(sum) || isnan(item)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

        if (client.connect(server,80))
          {   //--> "184.106.153.149" or api.thingspeak.com  
              String postStr = apiKey;
              postStr +="&field1=";
              postStr += String(sum);
              postStr +="&field2=";
              postStr += String(item);
              postStr += "\r\n\r\n";
 
            client.print("POST /update HTTP/1.1\n");
            client.print("Host: api.thingspeak.com\n");
            client.print("Connection: close\n");
            client.print("X-THINGSPEAKAPIKEY: "+apiKey+"\n");
            client.print("Content-Type: application/x-www-form-urlencoded\n");
            client.print("Content-Length: ");
            client.print(postStr.length());
            client.print("\n\n");
            client.print(postStr);
            Serial.println("%. Send to Thingspeak.");
         }
             delay(500);
            client.stop();
            lcd.clear();
            lcd.print("Success");
            Serial.println("Waiting...");
           digitalWrite(LEDonBoard, LOW);
           delay(250);
           digitalWrite(LEDonBoard, HIGH);
           delay(750);
           sum=0;
           item=0;
           
      }
      

      delay(100);
     }

     
   }


