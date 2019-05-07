#include <JellibiPin.h>

JellibiPin _pin;
/*
 * 상/하/좌/우 버튼을 눌렀을 때 모터를 제어하도록 한다.
 * 상 : 전진 방향으로 좌/우 모터의 회전 방향을 제어함
 * 하 : 후진 방향으로 좌/우 모터의 회전방향을 제어함 
 * 우 : 모터의 회전 속도를 올림
 * 좌 : 모터의 회전 속도를 내림 
 * 
 * 모터의 회전 속도는 0 ~ 255 까지 
 */

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  // 각 버튼에 연결된 포트속성을 INPUT(입력) 으로 설정하여 
  // 버튼에서 입력되는 값을 읽어 들인 수 있도록 한다.
  pinMode(_pin.Button(R), INPUT);
  pinMode(_pin.Button(L), INPUT);
  pinMode(_pin.Button(U), INPUT);
  pinMode(_pin.Button(D), INPUT);
  // 서보모터의 회전방향을 제어하기 위하여 OUTPUT 속성으로 설정한다. 
  pinMode(_pin.WheelDir(R), OUTPUT);
  pinMode(_pin.WheelDir(L), OUTPUT);
  // analog pin 을 analog 타입으로 제어(ADC, PWM) 시에는 pinMode 로 입출력 설정을 하지 않아도 된다. 
  // pinMode(_pin.Wheel(R), OUTPUT); 
  // pinMode(_pin.Wheel(L), OUTPUT);
  digitalWrite(_pin.WheelDir(R), LOW);
  digitalWrite(_pin.WheelDir(L), HIGH);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  if (LOW == digitalRead(_pin.Button(R))) {
    analogWrite( _pin.Wheel(R), 200);
    analogWrite( _pin.Wheel(L), 200); 
  }
  if (LOW == digitalRead(_pin.Button(L))) {
    analogWrite( _pin.Wheel(R), 70 );
    analogWrite( _pin.Wheel(L), 70);
  }
  if (LOW == digitalRead(_pin.Button(U))) {
    digitalWrite( _pin.WheelDir(R), LOW);
    digitalWrite( _pin.WheelDir(L), HIGH);
  }
  if (LOW == digitalRead(_pin.Button(D))) {
    digitalWrite( _pin.WheelDir(R), HIGH);
    digitalWrite( _pin.WheelDir(L), LOW);    
  }
}
