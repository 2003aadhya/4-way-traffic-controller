//FOUR WAY TRAFFIC CONTROLLER
//All the LEDs and resistors are labelled according to the signal they are in
int time_slot;//declaring time_slot variable
int rl1=5;//signal 1 red led
int yl1=6;//signal 1 yellow led
int gl1=7;//signal 1 green led
int rl2=2;//signal 2 red led
int yl2=3;//signal 2 yellow led
int gl2=4;//signal 2 green led
int rl3=8;//signal 3 red led
int yl3=9;//signal 3 yellow led
int gl3=10;//signal 3 green led
int rl4=11;//signal 4 red led
int yl4=12;//signal 4 yellow led
int gl4=13;//signal 4 green led

void setup()
{
  Serial.begin(9600);
  //setting all the pins to output mode
  pinMode(rl1, OUTPUT);
  pinMode(yl1, OUTPUT);
  pinMode(gl1, OUTPUT);
  pinMode(rl2, OUTPUT);
  pinMode(yl2, OUTPUT);
  pinMode(gl2, OUTPUT);
  pinMode(rl3, OUTPUT);
  pinMode(yl3, OUTPUT);
  pinMode(gl3, OUTPUT);
  pinMode(rl4, OUTPUT);
  pinMode(yl4, OUTPUT);
  pinMode(gl4, OUTPUT);  
  Serial.println("Enter the corresponding timeslot:");
  Serial.println("1. 3 am to 6 am : Light traffic");
  Serial.println("2. 6 am to 9 am : Medium Traffic");
  Serial.println("3. 9 am to 9 pm : Heavy Traffic");
  Serial.println("4. 9 pm to 3 am : Medium Traffic");
}

void loop()
{
  int time_slot;
  while(Serial.available()==0){//wait for the input
  }
  time_slot=Serial.parseInt();//assigning the entered value to time_slot
  
  //code to be executed when entered choice is 1
  while(time_slot==1){
    //yellow LEDs blink at all signals
    digitalWrite(yl1,1);//setting the signal 1 yellow LED to on
    digitalWrite(yl2,1);
    digitalWrite(yl3,1);
    digitalWrite(yl4,1);
    delay(500);         //time gap
    digitalWrite(yl1,0);
    digitalWrite(yl2,0);
    digitalWrite(yl3,0);
    digitalWrite(yl4,0);
    delay(500);
  }
  
  //code to be executed when entered choice is 2 or 4
  while(time_slot==2 || time_slot==4){
    //green LED in signal 1 is on and red LEDs of other three signals are on
    digitalWrite(rl1,0);
    digitalWrite(gl1,1);
    digitalWrite(rl2,1);
    digitalWrite(rl3,1);
    digitalWrite(rl4,1);
    delay(3000);//green LED delay
    //green LED is off and yellow LED is on 
    digitalWrite(gl1,0);
    digitalWrite(yl1,1);
    delay(1000);//yellow LED delay
    digitalWrite(yl1,0);
    //green LED in signal 2 is on and red LEDs of other three signals are on
    digitalWrite(rl2,0);
    digitalWrite(gl2,1);
    digitalWrite(rl1,1);
    digitalWrite(rl3,1);
    digitalWrite(rl4,1);
    delay(3000);//green LED delay
    //green LED is off and yellow LED is on 
    digitalWrite(gl2,0);
    digitalWrite(yl2,1);
    delay(1000);//yellow LED delay
    digitalWrite(yl2,0);
     //green LED in signal 3 is on and red LEDs of other three signals are on
    digitalWrite(rl3,0);
    digitalWrite(gl3,1);
    digitalWrite(rl1,1);
    digitalWrite(rl2,1);
    digitalWrite(rl4,1);
    delay(3000);//green LED delay
    //green LED is off and yellow LED is on 
    digitalWrite(gl3,0);
    digitalWrite(yl3,1);
    delay(1000);//yellow LED delay
    digitalWrite(yl3,0);
    //green LED in signal 4 is on and red LEDs of other three signals are on
    digitalWrite(rl4,0);
    digitalWrite(gl4,1);
    digitalWrite(rl1,1);
    digitalWrite(rl3,1);
    digitalWrite(rl2,1);
    delay(3000);//green LED delay
    //green LED is off and yellow LED is on 
    digitalWrite(gl4,0);
    digitalWrite(yl4,1);
    delay(1000);//yellow LED delay
    digitalWrite(yl4,0);
  }
  
  //code to be executed when entered choice is 3
  while(time_slot==3){
    //signal 2 and 4 have green LEDs on while signal 1 and 3 have red LEDs on
    digitalWrite(gl4,1);
    digitalWrite(rl1,1);
    digitalWrite(rl3,1);
    digitalWrite(gl2,1);
    delay(8000);//green LED delay
    //green LEDs are off and yellow LEDs are on 
    digitalWrite(gl4,0);
    digitalWrite(yl4,1);
    digitalWrite(gl2,0);
    digitalWrite(yl2,1);
    delay(5000);//yellow LED delay
    digitalWrite(yl2,0);
    digitalWrite(yl4,0);
    digitalWrite(rl1,0);
    digitalWrite(rl3,0);
    //signal 1 and 3 have green LEDs on while signal 2 and 4 have red LEDs on
    digitalWrite(gl1,1);
    digitalWrite(rl2,1);
    digitalWrite(rl4,1);
    digitalWrite(gl3,1);
    delay(8000);//green LED delay
    //green LEDs are off and yellow LEDs are on 
     digitalWrite(gl1,0);
    digitalWrite(yl1,1);
    digitalWrite(gl3,0);
    digitalWrite(yl3,1);
    delay(5000);//yellow LED delay
    digitalWrite(yl3,0);
    digitalWrite(yl1,0);
    digitalWrite(rl2,0);
    digitalWrite(rl4,0);
  }
}