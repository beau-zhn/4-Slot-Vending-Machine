#include <LiquidCrystal_I2C.h>        
LiquidCrystal_I2C lcd(0x27, 20, 4);   
#include <Servo.h>                    
//#define moneda 7                      
#define option1 8                     
#define option2 3                     
#define option3 4                     
#define option4 5     
#define option5 7   
//reverse the actions                
#define servout1 0 
#define servout2 1 
#define servout3 2 
#define servout4 A0 
#define max 200
int buttonPressed;                    
Servo servo1;                         
Servo servo2;                         
Servo servo3;                         
Servo servo4; 
int pos;
int firstSensorPin1 = 13;
int firstSensorPin2 = 12;
int firstSensor = 0;
int secondSensor = 0;
long distance, duration; 
bool triggered1 = false;
bool triggered2 = false;
int total = 2;
int total2= 2;
int total3 = 2;
int total4 = 2;

    bool temp = false;
    bool temp2 = false;
    bool temp3 = false;
    bool temp4 = false;
//NewPing sonar1(firstSensorPin1, firstSensorPin2, max);
//NewPing sonar2(firstSensorPin3, firstSensorPin4, max);

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH); // duration
  distance = duration * 0.0343/2;
  return duration;
}

void coinInsert();

void lcd_message(int count){
  //lcd.print("Inserted: ");
  //int count= 0;
  delay(100);
  lcd.clear();  
  lcd.print("Inserted: " );     //
  lcd.print(count);     //
}

void setup() {
  
  lcd.init();                         //
  lcd.backlight();                    //
  servo1.attach(6);                   //
  servo2.attach(9);                   //
  servo3.attach(10);                  //
  servo4.attach(11);                  //
  servo1.write(90);                   //
  servo2.write(90);                  //
  servo3.write(90);                   //
  servo4.write(90);                    //
  pinMode(servout1,OUTPUT);
  pinMode(servout2,OUTPUT);
  pinMode(servout3,OUTPUT);
  pinMode(servout4,OUTPUT);
  
  //pinMode(moneda,INPUT);              //
  pinMode(option1,INPUT_PULLUP);      //
  pinMode(option2,INPUT_PULLUP);      //
  pinMode(option3,INPUT_PULLUP);      //
  pinMode(option4,INPUT_PULLUP);      //
  pinMode(option5,INPUT_PULLUP);//reverse
}
void loop() {
  lcd.clear();                        //
  lcd.setCursor(1, 0);                //
  lcd.print("ainope_tarisu");            //
  lcd.setCursor(1, 1);                //
  lcd.print("VENDING MACHINE");          //
  delay(2000);                        //
  lcd.clear();                        //
  lcd.setCursor(1, 0);                //
  lcd.print("Insert Money");        //
  lcd.setCursor(4, 1);                //
  lcd.print(" 1 tenge");               //

    delay(100);                         //
  lcd.clear();                        //
  lcd.setCursor(0, 0);                //
  lcd.print("Choose product");     //
  lcd.setCursor(0, 1);                //
  lcd.print(" 1, 2, 3, 4?");         //

  int cost = 0;

//void pressed(){
  while (true ) {  

                   //
    if (digitalRead(option1) == LOW) {//
      buttonPressed = 1;  
           lcd.clear();              //

            lcd.print("Cost: 50");     //
            delay(2000);

      //lcd.clear();              //
      delay(2000);
      cost = 50;
      break;                          //
    }
    if (digitalRead(option2) == LOW) {//
      buttonPressed = 2; 
      lcd.clear();               //
      lcd.print("Cost: 100");     //
      delay(1000);
      cost = 100;
      break;                          //
    }
    if (digitalRead(option3) == LOW) {//
      buttonPressed = 3;              //
      lcd.clear();               //
      lcd.print("Cost: 200");     //
      delay(1000);
      cost = 200;
      break;                          //
    }
    if (digitalRead(option4) == LOW) {//
      buttonPressed = 4;              //
            lcd.clear();               //

      lcd.print("Cost: 150");     //
      delay(1000);
      cost = 150;
      break;                          //
    }
  }

  int count = 0;
 
  
  if(total <= 0 && buttonPressed == 1){
    lcd.clear();
    temp = false;
   //lcd.print("empty!!");
    //delay(1000);
    //break;
  }    
     
   // case 2:    
    else if(total2 <= 0 && buttonPressed == 2){
    lcd.clear();
    //lcd.print("empty!!");
    delay(1000);
    temp2 = true;
    lcd.clear();
   // break;
  }
     
   // case 3:    
     else if(total3 <= 0 && buttonPressed == 3){
    lcd.clear();
    //lcd.print("empty!!");
   // delay(1000);
   temp3 = true;
    lcd.clear();
    //break;
  }    
     
    //case 4:    
     else if(total4 <= 0 && buttonPressed == 4){
    lcd.clear();
    temp4 = true;
   // lcd.print("empty!!");
   // delay(1000);
    lcd.clear();
   // break;
  }
else{
  while(count < cost){ // && (total||total2||total3||total4
    //switch(total)
     //
      
   // case 1:         
        //secondSensor = 0.01723 * readUltrasonicDistance(firstSensorPin4, firstSensorPin3);
      // firstSensor = (0.343 * readUltrasonicDistance(firstSensorPin2, firstSensorPin3))/2;
    firstSensor = 0.1734* readUltrasonicDistance(firstSensorPin1, firstSensorPin2);
       // lcd.print("Inserted: \n" );     //
        // cutton 1         
    //  unsigned int dist = ping_cm();
        if (firstSensor < 50 ){          
           count+=50;
         /// break;  
          //lcd.print(count);     //    
          //  delay(100);   
            //triggered2=false;
            //break;
          }
          if (digitalRead(option5) == LOW) {
            break;
          }

  lcd_message(count);
  }
  }
  if (digitalRead(option5) == LOW) {
  loop();
  }
  delay(1000);
  lcd.clear();                        //
  lcd.setCursor(0, 0);                //
  lcd.print("wait...");         //
  delay(100);
     switch (buttonPressed) {          //
      
    case 1:         
    delay(100);  
       delay(100);
  if(total <= 0){
    lcd.clear();
    lcd.print("empty!!");
    delay(1000);
    lcd.clear();
    break;
  }           
          total--;
          //
    digitalWrite(servout1, HIGH);
    delay(1000);                      //
                    //


  for (pos = 0; pos <=180; pos += 1) {
    servo1.write(pos);
    delay(10);
    }

    digitalWrite(servout1, LOW); 

     count = 0;
                  //   total --;

    break;                            //
      
    case 2:    
      if(total2 <= 0){
    lcd.clear();
    lcd.print("empty!!");
    delay(1000);
    lcd.clear();
    break;
  }           
          //total--;                       //
    digitalWrite(servout2, HIGH);
      delay(100);
   
  for (pos = 0; pos <=180; pos += 1) {
    servo2.write(pos);
    delay(10);
    }

    delay(100);                      //
    digitalWrite(servout2, LOW);                 //
    delay(100);
          total2--;

    break;                            //
    count = 0;

    case 3:
      if(total3 <= 0){
    lcd.clear();
    lcd.print("empty!!");
    delay(1000);
    lcd.clear();
    break;
  }           
          //total3--;
    digitalWrite(servout3, HIGH);
    
          delay(100);
  for (pos = 0; pos <=540; pos += 1) {
    servo3.write(pos);
    delay(10);
    }

      total3--;


    digitalWrite(servout3, LOW);                 //

    delay(100);
    break;                            //

    case 4:   
      if(total4 <= 0){
    lcd.clear();
    lcd.print("empty!!");
    delay(1000);
    lcd.clear();
    break;
  }           
    digitalWrite(servout4, HIGH);               //

          delay(100);
  for (pos = 0; pos <=720; pos += 1) {
    servo4.write(pos);
    delay(10);
    }
                   //
        count = 0;
          total4--;                        //

    digitalWrite(servout4, LOW);                 //
    delay(100);
    break;                            //
  }  
}