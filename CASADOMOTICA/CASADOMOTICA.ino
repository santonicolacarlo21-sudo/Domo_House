#include "DHT.h"
#define DHTPIN A1    // what digital pin we're connected to
#define DHTTYPE DHT11   // DHT 11
#define SOGGIORNO 10
#define CUCINA 11
#define LETTO 12
#define PIR 3
#define BUZZER 4
#define MAXVALUE 50
#define GIARDINO 13
#define GAS    A3
#define GaSoglia 800
#define FOTORESISTENZA 9
long v,v1;
bool val=false;
int buz=0;
int cont=0;
int mode=0;
DHT dht(DHTPIN, DHTTYPE);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);//INIZIALIZZO SERIALE
  pinMode(SOGGIORNO,OUTPUT);
  pinMode(CUCINA,OUTPUT);
  pinMode(LETTO,OUTPUT);
  pinMode(PIR,INPUT);
  pinMode(BUZZER,OUTPUT);
  pinMode(GAS,INPUT);
  pinMode(GIARDINO,OUTPUT);
  pinMode(FOTORESISTENZA,INPUT);
   dht.begin();

}

void loop() {
  // put your main code here, to run repeatedly:
  char c=Serial.read();//LEGGO DA SERIALE
  analizza(c);//CONTROLLO LUCI
  antifurto();//CONTROLLO PIR
  controllo_Gas();//CONTROLLO GAS
  controllo_DHT();//CONTROLLO TEMPERATURA
  controllo_Fotoresistenza();//CONTROLLO LUCI GIARDINO

  
}

void controllo_Fotoresistenza(){
  if(mode==0){
  if(digitalRead(FOTORESISTENZA)==1){
    digitalWrite(GIARDINO,HIGH);
  }else{
    digitalWrite(GIARDINO,LOW);
  }
  }
                               
                               
                               }
void controllo_DHT(){

  float t = dht.readTemperature();
  
  
  
}
void controllo_Gas(){
  if(!val){
    Serial.println(analogRead(GAS));
        if(analogRead(GAS)>GaSoglia){//supero la soglia del gas
            val=true;
            v=millis();
            
                                    }
  }

        else{
          v1=millis();
          if(v1<v+5000){
          digitalWrite(BUZZER,HIGH);
          delay(100);
          digitalWrite(BUZZER,LOW);
          delay(100);
          }else{
            if(buz==1){
              digitalWrite(BUZZER,HIGH);
            }
            val=false;
          }
        }
                    
                     
                     
                     
                     }




void antifurto(){
    if(check_PIR()){
    cont++;
    if(cont==MAXVALUE){
      //OSTACOLO
      buz=1;
      digitalWrite(BUZZER,HIGH);
      cont=0;
    }
  }else{
    cont=0;
  }
}

void analizza(char c){

switch(c){//SE C(VALORE LETTO DA SERIALE)
  case 'a':
  digitalWrite(SOGGIORNO,HIGH);//SOGGIORNO ON
  break;
  case 'b':
  digitalWrite(SOGGIORNO,LOW);//SOGGIORNO OFF
  break;
  case 'c':
  digitalWrite(CUCINA,HIGH);//CUCINA ON
  break;
  case 'd':
  digitalWrite(CUCINA,LOW);//CUCINA OFF
  break;
  case 'e':
  digitalWrite(LETTO,HIGH);//LETTO ON
  break;
  case 'f':
  digitalWrite(LETTO,LOW);//LETTO OFF
  break;
  case 'g':
  mode=1;
  digitalWrite(GIARDINO,HIGH);
  break;
  case 'h':
  mode=1;
  digitalWrite(GIARDINO,LOW);
  break;
  case 'i':
  mode=0;
  break;




}
}

bool check_PIR(){
//LEGGO SUL PIN 3 0=NIENTE 1=OSTACOLO
if(digitalRead(PIR)==1){
  return true;
}else {
  return false;
}
  
}



