#include <Servo.h>  
Servo myservoA;  
Servo myservoB;
Servo myservoC;
Servo myservoD;
Servo myservoE;
Servo myservoF;
int i,pos,myspeed,myshow;
int sea,seb,sec,sed,see,sef;
static int v=0;

#define segA 3
#define segB 5
#define segC 6
#define segD 9
#define segE 10
#define segF 11

String mycommand="";  //#auto： do stuff as code states  #com：do stuff as serial in orders u to     #stop： guess it
static int mycomflag=2; 


void myservosetup()  //set up servos
{
   sea=myservoA.read();
   seb=myservoB.read();
   sec=myservoC.read();
   sed=myservoD.read();
   see=myservoE.read();
   sef=myservoF.read();
   
   myspeed=500;
   for(pos=0;pos<=myspeed;pos+=1)
   {
    myservoA.write(int(map(pos,1,myspeed,sea,66)));
    myservoB.write(int(map(pos,1,myspeed,seb,90)));
    myservoC.write(int(map(pos,1,myspeed,sec,50)));
    myservoD.write(int(map(pos,1,myspeed,sed,90)));
    myservoE.write(int(map(pos,1,myspeed,see,120)));
    myservoF.write(int(map(pos,1,myspeed,sef,90)));    
    delay(1);
   }
}

void setup() 
{ 
  pinMode(13,INPUT); serial communication
  pinMode(12,INPUT);  serial communication
  Serial.begin(9600);
  myshow=0;
  mycomflag=2; // com flag ：2  do stuff in code
  myservoA.attach(segA); // initialise segment A
  myservoB.attach(segB); // initialise segment B
  myservoC.attach(segC); // initialise segment C
  myservoD.attach(segD); // initialise segment D
  myservoE.attach(segE); // initialise segment E
  myservoF.attach(segF); // initialise segment F
  
  myservoA.write(66);
  myservoB.write(90);
  myservoC.write(50);
  myservoD.write(90);
  myservoE.write(120);
  myservoF.write(90);    //starting position

}

void loop() 
{ 
  while (Serial.available() > 0)  
    {
        mycommand += char(Serial.read());
        delay(2);
    }
    if (mycommand.length() > 0)
    {
        if(mycommand=="#auto")
        {
          mycomflag=2;
          Serial.println("auto station");
          mycommand="";
        }
        if(mycommand=="#com")
        {
          mycomflag=1;
          Serial.println("computer control station");
          mycommand="";
          myservosetup();
        }
        if(mycommand=="#stop")
        {
          mycomflag=0;
          Serial.println("stop station");
          mycommand="";
        }
        
    }
  
  
  if(mycomflag==1)  //com flag 1
  {      
 
   for(int m=0;m<mycommand.length();m++) // 
  {
    char ch = mycommand[m];   //parse command from serial in
    switch(ch)
    {
      case '0'...'9':
      v = v*10 + ch - '0';   //state machine
      break;
      
      
      
      case 'a':   //state a，do stuff，set 85a
      if(v >= 5 || v <= 175 ) myservoA.write(v); //servos move between 0 and 180 degrees
      v = 0;
      break;

      case 'b':   //case b, do stuff

      myservoB.write(v);   //servos move between 0 and 180 degrees
      v = 0;
      break;
      case 'c':   
      if(v >= 20 ) myservoC.write(v);   
      v = 0;
      break;
      case 'd':  
      myservoD.write(v);   
      v = 0;
      break;
      case 'e':  
      myservoE.write(v);   
      v = 0;
      break;
      case 'f':  
      myservoF.write(v);   
      v = 0;
      break;
    }
   
    }  
   mycommand="";
  }  // end if(mycomflag=2)
  
  if(mycomflag==2)  //com flag 2 
  {    
   delay(3000); 
   //Serial.println("auto station"); 
   myservosetup();
   myspeed=500;
    for(pos = 0; pos <=myspeed; pos += 1)  
  {                                
    myservoA.write(int(map(pos,1,myspeed,66,90))); // lovely 66
    myservoB.write(int(map(pos,1,myspeed,90,40))); // seg b to 90 / 40
    delay(1);                       
  }
   delay(1000);
   myspeed=500;
  for(pos = 0; pos <=myspeed; pos += 1)  
  {                                
    myservoC.write(int(map(pos,1,myspeed,50,65))); // 
    myservoD.write(int(map(pos,1,myspeed,90,170))); //
    myservoE.write(int(map(pos,1,myspeed,90,5))); 
    delay(1);                       
   }
  myspeed=1000;
  for(pos = 0; pos <=myspeed; pos += 1)  
  {                                
    myservoB.write(int(map(pos,1,myspeed,40,70))); // 
    myservoC.write(int(map(pos,1,myspeed,65,50))); //
    delay(1);                       
   }
   myspeed=500;
  for(pos = 0; pos <=myspeed; pos += 1)  
  {                                
    myservoC.write(int(map(pos,1,myspeed,50,45))); // 
    myservoD.write(int(map(pos,1,myspeed,170,90))); //
    myservoE.write(int(map(pos,1,myspeed,5,27)));
    myservoF.write(int(map(pos,1,myspeed,90,40)));
    delay(1);                       
   }
   myspeed=1000;
  for(pos = 0; pos <=myspeed; pos += 1)  
  {                                
    myservoA.write(int(map(pos,1,myspeed,90,140))); // 
    myservoF.write(int(map(pos,1,myspeed,40,130)));    
    delay(1);                       
   }  
    myspeed=500;
    for(pos = 0; pos <=myspeed; pos += 1)  
  {                                
    myservoA.write(int(map(pos,1,myspeed,140,90))); // 
    myservoC.write(int(map(pos,1,myspeed,45,50))); // 
    myservoB.write(int(map(pos,1,myspeed,70,50))); //
    myservoE.write(int(map(pos,1,myspeed,27,120))); //
    delay(1);                       
  } 
  }
  
  if(mycomflag==0) // state 0 kill all stizzle
  {
   myservosetup();
  }
}
