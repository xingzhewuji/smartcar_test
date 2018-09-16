#include <Servo.h>
Servo myservo;  // 定义舵机对象，最多八个 
int ledpin=11;//定义数字接口11（PWM 输出）
int ledpin_1=12;//定义数字接口12
int ledpin_2=13;//定义数字接口12

int ledpin_3=10;//定义数字接口11（PWM 输出）
int ledpin_4=9;//定义数字接口12
int ledpin_5=8;//定义数字接口12
int val=0;// 暂存来自传感器的变量数值
int pos = 0;    // 定义舵机转动位置
int label=0;
void forward(int speed)
{
  digitalWrite(ledpin_1,HIGH);
  digitalWrite(ledpin_2,LOW);
  digitalWrite(ledpin_4,HIGH);
  digitalWrite(ledpin_5,LOW);
  analogWrite(ledpin,speed);
  analogWrite(ledpin_3,speed);
}
void backward(int speed)
{
  digitalWrite(ledpin_2,HIGH);
  digitalWrite(ledpin_1,LOW);
  digitalWrite(ledpin_5,HIGH);
  digitalWrite(ledpin_4,LOW);
  analogWrite(ledpin,speed);
  analogWrite(ledpin_3,speed);
}
void turn_left(int speed)
{
  digitalWrite(ledpin_2,HIGH);
  digitalWrite(ledpin_1,LOW);
  digitalWrite(ledpin_4,HIGH);
  digitalWrite(ledpin_5,LOW);
  analogWrite(ledpin,speed);
  analogWrite(ledpin_3,speed);
}
void turn_right(int speed)
{
  digitalWrite(ledpin_1,HIGH);
  digitalWrite(ledpin_2,LOW);
  digitalWrite(ledpin_5,HIGH);
  digitalWrite(ledpin_4,LOW);
  analogWrite(ledpin,speed);
  analogWrite(ledpin_3,speed);
}
void stop()
{  
  analogWrite(ledpin,1);
  analogWrite(ledpin_3,1);
  
}
void setup()
{
pinMode(ledpin,OUTPUT);//定义数字接口11 为输出
pinMode(ledpin_1,OUTPUT);//定义数字接口11 为输出
pinMode(ledpin_2,OUTPUT);//定义数字接口11 为输出
pinMode(ledpin_3,OUTPUT);//定义数字接口11 为输出
pinMode(ledpin_4,OUTPUT);//定义数字接口11 为输出
pinMode(ledpin_5,OUTPUT);//定义数字接口11 为输出
myservo.attach(6);  // 设置舵机控制针脚
Serial.begin(9600);//设置波特率为9600

//注意：模拟接口自动设置为输入
}

void loop()
{
  for(pos = 0; pos < 180; pos += 1)  
   {  
      myservo.write(pos);  
      delay(15); 
    }
    // 180到0旋转舵机，每次延时15毫秒 
    for(pos = 180; pos>=1; pos-=1)
    {                               
      myservo.write(pos);
      delay(15);
    }

    
    if(label==1)
    {
    forward(200);
    delay(3000);
    backward(200);
    delay(3000);
    turn_left(200);
    delay(3000);
    turn_right(200);
    delay(3000);
    stop();
    delay(3000);
    }


//delay(10);//延时0.01 秒
}

