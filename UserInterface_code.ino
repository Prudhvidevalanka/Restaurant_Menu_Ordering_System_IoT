#include <SoftwareSerial.h>
#include <LiquidCrystal.h>
#include <Keypad.h>
#include <Servo.h>

const int rs = 4, en = A1, d4 = A5, d5 = A4, d6 = A3, d7 = A2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
Servo myservo;  // create servo object to control a servo

const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},                               // master          SLAVE    +ADDR:FCA8:9A:334
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {6,7,8,9};
byte colPins[COLS] = {10,11,12,13};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

String enteredDigits = "";

SoftwareSerial BTSerial(2, 3); // RX (2) and TX (3) pins on the Arduino
int sum=0;

void setup() {
  lcd.begin(16, 2);
  Serial.begin(38400);
  BTSerial.begin(38400);
  myservo.attach(5);       // attaches the servo on pin 9 to the servo object

   // Set the baud rate to match your Bluetooth module
}

void loop() {
  // Your data to send

  char key = keypad.getKey();
  
  if (key) {
    if (key == '#') { // Enter key
      if (enteredDigits.length() > 0) {
        Serial.println("Entered Digits: " + enteredDigits);
        BTSerial.println(enteredDigits);
    if(enteredDigits=="1")
   {
      
       lcd.clear();
       lcd.setCursor(0,0);
       lcd.print("IDLY ODERED");
       sum=sum+40;
       delay(2000);
       lcd.clear();
       lcd.print("ORDER DONE...");

   }
    else if(enteredDigits=="2"){
      lcd.clear();
       lcd.setCursor(0,0);
       lcd.print("DOSA ODERED");
       sum=sum+50;
       delay(2000);
       lcd.clear();
       lcd.print("ORDER DONE...");
       }



        else if(enteredDigits=="3"){
      lcd.clear();
       lcd.setCursor(0,0);
       lcd.print("BONDA ODERED");
       sum=sum+40;
       delay(2000);
       lcd.clear();
       lcd.print("ORDER DONE...");
       }

       else if(enteredDigits=="4"){
      lcd.clear();
       lcd.setCursor(0,0);
       lcd.print("PULKA ODERED");
       sum=sum+20;
       delay(2000);
       lcd.clear();
       lcd.print("ORDER DONE...");
       }


       else if(enteredDigits=="5"){
      lcd.clear();
       lcd.setCursor(0,0);
       lcd.print("POHA ODERED");
       sum=sum+30;
       delay(2000);
       lcd.clear();
       lcd.print("ORDER DONE...");
       }


       else if(enteredDigits=="6"){
      lcd.clear();
       lcd.setCursor(0,0);
       lcd.print("PURI ODERED");
       sum=sum+40;
       delay(2000);
       lcd.clear();
       lcd.print("ORDER DONE...");
       }


        else if(enteredDigits=="7"){
      lcd.clear();
       lcd.setCursor(0,0);
       lcd.print("MEALS ODERED");
       sum=sum+70;
       delay(2000);
       lcd.clear();
       lcd.print("ORDER DONE...");
       }


        else if(enteredDigits=="8"){
      lcd.clear();
       lcd.setCursor(0,0);
       lcd.print("CURD ODERED");
       sum=sum+20;
       delay(2000);
       lcd.clear();
       lcd.print("ORDER DONE...");
       }

        else if(enteredDigits=="9"){
      lcd.clear();
       lcd.setCursor(0,0);
       lcd.print("RICE ODERED");
       sum=sum+40;
       delay(2000);
       lcd.clear();
       lcd.print("ORDER DONE...");
       }

        

        else if(enteredDigits=="123"){   //TO START THE ORDER
        lcd.clear();
       lcd.setCursor(0,0);
       lcd.print("WELCOME ");
        for (int pos = 0; pos <=90; pos += 1) { // goes from 0 degrees to 180 degrees
         myservo.write(pos);              // tell servo to go to position in variable 'pos'
          delay(15);                       // waits 15 ms for the servo to reach the position
        }
       
       }

       else if(enteredDigits=="*"){
      lcd.clear();
       lcd.setCursor(0,0);
       lcd.print("PAY TO");
       lcd.setCursor(0,1);
       lcd.print("9494795794");
       }

       else if(enteredDigits=="*04560*"){
      lcd.clear();
       lcd.setCursor(0,0);
       lcd.print("Opening");
       lcd.setCursor(0,1);
       lcd.print("the gate...");
       delay(3000);
       lcd.clear();
       lcd.print("Thank you");
       lcd.setCursor(0,1);
       lcd.print("Visit Again");
       for (int pos = 90; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);   
       }

       
       }






       else if(enteredDigits=="A"){   //EXIT 
      lcd.clear();
       sum=0;
       lcd.print("Section");
       lcd.setCursor(0,1);
       lcd.print("closed..");
       delay(2000);
       
       }

       else if(enteredDigits=="B"){
      lcd.clear();
       lcd.setCursor(0,0);
       lcd.print("WATER BOTTLE");
       sum=sum+20;
       delay(2000);
       lcd.clear();
       lcd.print("ORDER DONE...");
       }

       else if(enteredDigits=="C"){
      lcd.clear();
       lcd.setCursor(0,0);
       lcd.print("CASH");
       lcd.setCursor(0,1);
       lcd.print(sum);
       delay(2000);
       lcd.clear();
       lcd.print("DONE..");
       }


       else if(enteredDigits=="D"){
      lcd.clear();
       lcd.setCursor(0,0);
       lcd.print("calling waiter");
       delay(2000);
       lcd.clear();
       lcd.print("DONE...");
       }

       

        enteredDigits = ""; // Reset for the next entry
      }
    } else {
      enteredDigits += key;
    }
  }


  delay(10); // Adjust the delay as needed to control the sending rate
}
