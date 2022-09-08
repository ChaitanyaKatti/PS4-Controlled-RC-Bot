#include <PS4Controller.h>
#include "analogWrite.h"

// These pins are the Enable pins of the L293D motor driver which connects to esp32 gpio pins to implement the PWM function
int enable1_2 = 32;
int enable3_4 = 33; 

// These pins are the input pins of l293d on the left side
int inp1 = 25; //Fornt left motor
int inp2 = 26; //Back left motor


// These pins are the input pins of l293d on the right side
int inp3 = 27; //Back right motor
int inp4 = 14; //Front right motor

//Default Mode is Button
bool joystick_mode = false;

void onEvent(){
  //Reset State
  digitalWrite(inp1, LOW);
  digitalWrite(inp2, LOW);
  digitalWrite(inp4, LOW);
  digitalWrite(inp3, LOW);

  //Change modes
  if( PS4.event.button_down.touchpad ){
    joystick_mode = !joystick_mode;
    //Serial.println("Switching Modes");
  }
  
  //Mapping Controls
  if( joystick_mode ){ //Joystick contorls
    
    if( PS4.data.analog.stick.ly > 10 ){//LEFT FORWARD
      digitalWrite(inp1, HIGH);
      digitalWrite(inp2, LOW);
      //Serial.print("L+  ");
    }
    else if( PS4.data.analog.stick.ly < -10 ) {//LEFT BACK
      digitalWrite(inp1, LOW);
      digitalWrite(inp2, HIGH);
      //Serial.print("L-  ");
    }
    else{
      //Serial.print("L0  ");
    }
    
    if( PS4.data.analog.stick.ry > 10 ){//RIGHT FORWARD
      digitalWrite(inp4, HIGH);
      digitalWrite(inp3, LOW);
      //Serial.print("R+  ");
    }
    else if( PS4.data.analog.stick.ry < -10 ){//RIGHT BACK
      digitalWrite(inp4, LOW);
      digitalWrite(inp3, HIGH);
      //Serial.print("R-  ");
    }
    else{
      //Serial.print("R0  ");
    }
    
    //PWM
    analogWrite(enable1_2, abs(PS4.data.analog.stick.ly), 127);
    analogWrite(enable3_4, abs(PS4.data.analog.stick.ry), 127);
    //Serial.print("LS:");
    //Serial.print(abs(PS4.data.analog.stick.ly));
    //Serial.print(" , RS:");
    //Serial.print(abs(PS4.data.analog.stick.ry));
    //Serial.println();
  }
  
  else{//Button Controls
    //Forwards
    if ( PS4.data.button.triangle ){
      
      if( PS4.data.button.square ){//Forward Left
        digitalWrite(inp1, LOW);
        digitalWrite(inp2, LOW);
        digitalWrite(inp4, HIGH);
        digitalWrite(inp3, LOW);
        //Serial.print("FL");
      }
      else if( PS4.data.button.circle ){//Forward Right
        digitalWrite(inp1, HIGH);
        digitalWrite(inp2, LOW);
        digitalWrite(inp4, LOW);
        digitalWrite(inp3, LOW);
        //Serial.print("FR");
      }
      else{//Forward
        digitalWrite(inp1, HIGH);
        digitalWrite(inp2, LOW);
        digitalWrite(inp4, HIGH);
        digitalWrite(inp3, LOW);
        //Serial.print("FF");
      }
    }
    //Back
    else if ( PS4.data.button.cross ){    
      if( PS4.data.button.square ){//Back Left
        digitalWrite(inp1, LOW);
        digitalWrite(inp2, LOW);
        digitalWrite(inp4, LOW);
        digitalWrite(inp3, HIGH);
        //Serial.print("BL");
      }
      else if( PS4.data.button.circle ){//Back Right
        digitalWrite(inp1, LOW);
        digitalWrite(inp2, HIGH);
        digitalWrite(inp4, LOW);
        digitalWrite(inp3, LOW);
        //Serial.print("BR");
      }
      else{
        digitalWrite(inp1, LOW);
        digitalWrite(inp2, HIGH);
        digitalWrite(inp4, LOW);
        digitalWrite(inp3, HIGH);
        //Serial.print("BB");
      }
    }
    //Left
    else if ( PS4.data.button.square ){
      digitalWrite(inp1, LOW);
      digitalWrite(inp2, HIGH);
      digitalWrite(inp4, HIGH);
      digitalWrite(inp3, LOW);
      //Serial.print("LL");
    }
    //Right
    else if ( PS4.data.button.circle ){
      digitalWrite(inp1, HIGH);
      digitalWrite(inp2, LOW);
      digitalWrite(inp4, LOW);
      digitalWrite(inp3, HIGH);
      //Serial.print("RR");
    }
    //Neutral 
    else{
      //Serial.print("00");
    }
    if( PS4.data.button.l1 ){
      analogWrite(enable1_2, 160, 255);
      analogWrite(enable3_4, 160, 255);
    }
    else if(PS4.data.button.r1 ){
      analogWrite(enable1_2, 200, 255);
      analogWrite(enable3_4, 200, 255);
    }
    else{
      analogWrite(enable1_2, PS4.data.analog.button.l2, 255);
      analogWrite(enable3_4, PS4.data.analog.button.l2, 255);      
    }
    //Serial.print("   Speed:");
    //Serial.print(PS4.data.analog.button.l2);
    //Serial.println();
  }
  
}

void onConnect() {
  if ( PS4.isConnected() ) {
    //Serial.println("Connected.");
  }
  //Serial.print("Battey = ");
  //Serial.print(PS4.data.status.battery);
  //Serial.println("/ 16");
}
 
void setup(){
  //Serial.begin(115200);

  pinMode(enable1_2, OUTPUT);
  pinMode(enable3_4,OUTPUT);
  pinMode(inp1, OUTPUT);
  pinMode(inp2, OUTPUT);
  pinMode(inp3, OUTPUT);
  pinMode(inp4, OUTPUT);
  
  analogWrite(enable1_2, 255); 
  analogWrite(enable3_4, 255);
  
  //Reset State
  digitalWrite(inp1, LOW);
  digitalWrite(inp2, LOW);
  digitalWrite(inp4, LOW);
  digitalWrite(inp3, LOW);  

  if (!PS4.begin( "5c:96:56:1f:a4:db")) {
    //Serial.println("Initialization failed");
    return;
  }

  //Serial.println("Initialization finished.");
 
  PS4.attachOnConnect(onConnect);
  PS4.attach(onEvent);
}
 
void loop(){
  if( PS4.isConnected() ){
    //Set Rumble if bumper sensor is activated
    if(touchRead(T0) < 30){
      PS4.setRumble(PS4.data.analog.button.l2, 255);
      PS4.sendToController();
      delay(10);
    }
    else{
      PS4.setRumble(PS4.data.analog.button.l2, 0);
      delay(10);
    }
    //Change LED light based on left and right stick position
    if( joystick_mode ){
      PS4.setLed( PS4.data.analog.button.l2, min(2*abs(PS4.data.analog.stick.ly), 255) , min(2*abs(PS4.data.analog.stick.ry), 255));
      PS4.setFlashRate(0, 0);
      PS4.sendToController();
      delay(30);
    }
    else{
      PS4.setLed(100 + (PS4.data.analog.button.l2*155/255), 100 - (PS4.data.analog.button.l2*100/255) , 100 - (PS4.data.analog.button.l2*100/255));
      PS4.setFlashRate(100, 100);
      PS4.setRumble(PS4.data.analog.button.l2, 0);
      PS4.sendToController();
      delay(10);
    }
  }
}
