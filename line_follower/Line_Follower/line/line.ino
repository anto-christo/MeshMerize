#define sen1 2
#define sen2 3
#define sen3 11
#define sen4 A0
#define sen5 A1
#define Lp 7 //left pin of positive motor
#define Ln 4 // left negative
#define El 5 // Enable pin of left motor
#define Rp 8 //right motor positive pin
#define Rn 12 //pin no of right negative motor
#define Er 6 //Enable pin of right motor. if it is 0 right motor is always off
#define led 13

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(sen1,INPUT);
  pinMode(sen2,INPUT);
  pinMode(sen3,INPUT);
  pinMode(sen4,INPUT);
  pinMode(sen5,INPUT);
  pinMode(Lp,OUTPUT);
  pinMode(Ln,OUTPUT);
  pinMode(El,OUTPUT);
  pinMode(Er,OUTPUT);
  pinMode(Rp,OUTPUT);
  pinMode(Rn,OUTPUT);
  
  digitalWrite(El,HIGH);
  digitalWrite(Er,HIGH);
}

/*
  10001
  11001
  10011
  11100
  00111
  11110
  01111 
*/

void loop() {
  
  if(digitalRead(sen1) && !digitalRead(sen2) && !digitalRead(sen3) && !digitalRead(sen4) && digitalRead(sen5)){
    //straight 
    MotorControl(1,1); 
  }
  
  else if(digitalRead(sen1) && !digitalRead(sen2) && !digitalRead(sen3) && !digitalRead(sen4) && digitalRead(sen5)){
     //Slight right
     digitalWrite(El,HIGH);
     
     digitalWrite(Er,HIGH);
     delay();     
     digitalWrite(Er,LOW);
     delay();
  }
  
  else if(digitalRead(sen1) && !digitalRead(sen2) && !digitalRead(sen3) && !digitalRead(sen4) && digitalRead(sen5)){
      //Slight left
      digitalWrite(Er,HIGH);
     digitalWrite(El,HIGH);
     delay();
     
     digitalWrite(Er,HIGH);
     digitalWrite(El,HIGH);
     delay();
  }
  
  else if(digitalRead(sen1) && !digitalRead(sen2) && !digitalRead(sen3) && !digitalRead(sen4) && digitalRead(sen5)){
      //Hard right
       digitalWrite(El,HIGH);
     
     digitalWrite(Er,HIGH);
     delay();     
     digitalWrite(Er,LOW);
     delay();
  }
  
  else if(digitalRead(sen1) && !digitalRead(sen2) && !digitalRead(sen3) && !digitalRead(sen4) && digitalRead(sen5)){
      //Hard left
      digitalWrite(Er,HIGH);
     digitalWrite(El,HIGH);
     delay();
     
     digitalWrite(Er,HIGH);
     digitalWrite(El,HIGH);
     delay();
  }
  
  else if(digitalRead(sen1) && !digitalRead(sen2) && !digitalRead(sen3) && !digitalRead(sen4) && digitalRead(sen5)){
      //Extreme right
       digitalWrite(El,HIGH);
     
     digitalWrite(Er,HIGH);
     delay();     
     digitalWrite(Er,LOW);
     delay();
  }
  
  else if(digitalRead(sen1) && !digitalRead(sen2) && !digitalRead(sen3) && !digitalRead(sen4) && digitalRead(sen5)){
     //Extreme left
     digitalWrite(Er,HIGH);
     digitalWrite(El,HIGH);
     delay();
     
     digitalWrite(Er,HIGH);
     digitalWrite(El,HIGH);
     delay();
  }
}

void MotorControl(int driveL,int driveR)
{
  switch(driveL)
  {
    case 0: 
      digitalWrite(Ln,LOW);
      digitalWrite(Lp,LOW);
      break;
    case 1:
      digitalWrite(Ln,HIGH);
      digitalWrite(Lp,LOW);
      break;
    case 2:
      digitalWrite(Ln,LOW);
      digitalWrite(Lp,HIGH);
      break;
    default: 
      break;
  }
  
  switch(driveR)
  {
    case 0:
      digitalWrite(Rn,LOW);
      digitalWrite(Rp,LOW);
      break;
    case 1:
      digitalWrite(Rn,HIGH);
      digitalWrite(Rp,LOW);
      break;
    case 2:
      digitalWrite(Rn,LOW);
      digitalWrite(Rp,HIGH);
      break;
    default: 
      break;
  }
  
}
