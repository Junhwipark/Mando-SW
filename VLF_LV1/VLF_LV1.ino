#include <NewPing.h>

#define L_InPin_2 3 
#define L_InPin_1 2  
#define R_InPin_2 7  
#define R_InPin_1 4  

#define F_Sonar 8  
#define R_Sonar 10 
#define L_Sonar 11 

#define L_en 5 
#define R_en 6 
#define MAX_DISTANCE 350

NewPing F_sensor(F_Sonar, F_Sonar, MAX_DISTANCE);
double UltraSonicData_F = 0.0;
NewPing L_sensor(L_Sonar, L_Sonar, MAX_DISTANCE);
double UltraSonicData_L = 0.0;
NewPing R_sensor(R_Sonar, R_Sonar, MAX_DISTANCE);
double UltraSonicData_R = 0.0;


void read_sonar_sensor(void) 
{
    UltraSonicData_R = R_sensor.ping_cm()*10.0;
    UltraSonicData_L = L_sensor.ping_cm()*10.0;
    UltraSonicData_F = F_sensor.ping_cm()*10.0;
    
    if(UltraSonicData_L == 0)
    {
      UltraSonicData_L = MAX_DISTANCE * 20;
    }

    if(UltraSonicData_F == 0)
    {
      UltraSonicData_F =  MAX_DISTANCE * 20;
    }

    if(UltraSonicData_R == 0)
    {
      UltraSonicData_R =  MAX_DISTANCE * 20;
    }
}

bool condition = false;
int te = 0;

void setup() {
  pinMode(L_InPin_2, OUTPUT);
  pinMode(L_InPin_1, OUTPUT);
  pinMode(R_InPin_2, OUTPUT);
  pinMode(R_InPin_1, OUTPUT);
  read_sonar_sensor();
}


int read_line_sensor(void)
{
 int i;
 int sum=0;
 int line_index = 0;
 int line_sensor[5]={0,0,0,0,0};
 
 for(i=0;i<5;i++)
 {
   line_sensor[i]=(digitalRead(A0+i));
   sum += line_sensor[i];
 }
 if(sum==0) line_index = 100;
 if(sum==5) line_index = -10;
 if(sum==1)
 {
   if(line_sensor[0]==1) line_index = -4;
   if(line_sensor[1]==1) line_index = -2;
   if(line_sensor[2]==1) line_index = 10;
   if(line_sensor[3]==1) line_index = 2;
   if(line_sensor[4]==1) line_index = 4;
 }
 if(sum==2)
 {
   if(line_sensor[0]==1 && line_sensor[1]==1) line_index = -3;
   if(line_sensor[1]==1 && line_sensor[2]==1) line_index = -1;
   if(line_sensor[2]==1 && line_sensor[3]==1) line_index = 1;
   if(line_sensor[3]==1 && line_sensor[4]==1) line_index = 3;
 }
 if(sum==3 || sum==4)
 {
   if(line_sensor[0]==0) line_index = 5;
   if(line_sensor[4]==0) line_index = -5;
 };

 return line_index;
}

void keep_line_going(void) // 라인에 따른 주행
{
  int te = read_line_sensor();
  switch(te)
  {
    case -5 : Motor_Control_left(1,200); break;
    case -4 : Motor_Control_left(1,200); break;
    case -3 : Motor_Control(1,0,100*2); break;
    case -2 : Motor_Control(1,21*2,100*2); break;     
    case -1 : Motor_Control(1,55*2,100*2); break;
    case 10 : Motor_Control(1,200*2,112*2); break;
    case 100 : Motor_Control(1,84*2,100*2); break;
    case 1 : Motor_Control(1,84*2,65*2); break;
    case 2 : Motor_Control(1,84*2,25*2); break;
    case 3 : Motor_Control(1,84*2,0); break;
    case 4 : Motor_Control_right(1,200); break;     
    case 5 : Motor_Control_right(1,200); break;
    case -10 : Stop(1); break;
  }


}


void keep_sensor_going(void) 
{
  int te = read_line_sensor();
  
  if(te == 100)
  {

    if(UltraSonicData_F <= 700 && UltraSonicData_F >= 500 && UltraSonicData_R > 1000 ) 
    {
      Motor_Control(1,77*2,10*2);
      delay(2000);
      Motor_Control(1,90*2,100*2);
      delay(1000);
    }

    else
    {
      if(UltraSonicData_R + UltraSonicData_L <= 1170 && UltraSonicData_R - 70 <= UltraSonicData_L && UltraSonicData_R + 70 >= UltraSonicData_L) 
      {
        Motor_Control(1,80*2,70*2);
      
      }
    
      else if( UltraSonicData_L < UltraSonicData_R) 
      {
        Motor_Control(1,90*2,70*2);
        if(UltraSonicData_L < 200) 
        {
         Motor_Control(1,10*2,0);
        }  
      }

      else if( UltraSonicData_L > UltraSonicData_R ) 
      {
        Motor_Control(1,57*2,110*2);
      
        if(UltraSonicData_R < 200)
        {
          Motor_Control(1,0,100*2);
        }   
      }

      else
      {
        Motor_Control(1,90*2,100*2);
      }
    }
  } 
}

///////////////////////////////////////////////////////////
void Motor_Control_left(int Time, int Speed)
{
    digitalWrite(L_InPin_2,HIGH);
    digitalWrite(L_InPin_1,LOW);
    digitalWrite(R_InPin_2,HIGH);
    digitalWrite(R_InPin_1,LOW);
    analogWrite(L_en,Speed);
    analogWrite(R_en,Speed);
    delay(Time);
}

void Motor_Control_right(int Time, int Speed)
{
    digitalWrite(L_InPin_1,HIGH);
    digitalWrite(L_InPin_2,LOW);
    digitalWrite(R_InPin_1,HIGH);
    digitalWrite(R_InPin_2,LOW);
    analogWrite(L_en,Speed);
    analogWrite(R_en,Speed);
    delay(Time);
}

void Stop(int Time)
{
  digitalWrite(L_InPin_1,LOW);
  digitalWrite(L_InPin_2,LOW);
  digitalWrite(R_InPin_2,LOW);
  digitalWrite(R_InPin_1,LOW);
  delay(Time);
}
  
void Motor_Control(int Direction, int Speed1, int Speed2)
{
  switch(Direction){
  case -1: // 후진
    digitalWrite(L_InPin_2,HIGH);
    digitalWrite(L_InPin_1,LOW);
    digitalWrite(R_InPin_2,HIGH);
    digitalWrite(R_InPin_1,LOW);
    analogWrite(L_en, Speed1);
    analogWrite(R_en, Speed2);
  break;
  
  case 1: // 직진 
    digitalWrite(L_InPin_1,HIGH);
    digitalWrite(L_InPin_2,LOW);
    digitalWrite(R_InPin_2,HIGH);
    digitalWrite(R_InPin_1,LOW);
    analogWrite(L_en, Speed1);
    analogWrite(R_en, Speed2);
  break;

  case 0: // 정지
    digitalWrite(L_InPin_1,HIGH);
    digitalWrite(L_InPin_2,LOW);
    digitalWrite(R_InPin_1,HIGH);
    digitalWrite(R_InPin_2,LOW);
    analogWrite(L_en, Speed1);
    analogWrite(R_en, Speed2);
  break;

  case 2: // 우회전
    digitalWrite(L_InPin_1,HIGH); 
    digitalWrite(L_InPin_2,LOW);
    digitalWrite(R_InPin_1,LOW);
    digitalWrite(R_InPin_2,HIGH);
    analogWrite(L_en, Speed1);
    analogWrite(R_en, Speed2);
  break;

  case -2: // 좌회전
    digitalWrite(L_InPin_1,LOW);
    digitalWrite(L_InPin_2,HIGH);
    digitalWrite(R_InPin_1,HIGH);
    digitalWrite(R_InPin_2,LOW);
    analogWrite(L_en, Speed1);
    analogWrite(R_en, Speed2);
  break;
  }
}

void loop() 
{
  read_sonar_sensor();
  keep_line_going();
  keep_sensor_going();
  if (!condition && te != 100 && UltraSonicData_F < 450 && UltraSonicData_F > 0)// 한 번만 실행하도록 조건을 체크
  {
    condition = true;

    Motor_Control(1, 87 * 2, 22 * 2);
    delay(1500);
    Motor_Control(1, 15 * 2, 94 * 2);
    delay(2150);
  }
}
