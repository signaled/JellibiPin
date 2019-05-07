#include <JellibiPin.h>

JellibiPin _pin;

// setup() 함수는 젤리비 보드가 켜질 때 한번 실행 된다. 
void setup()
{ 
    Serial.begin(115200);
    // 각 버튼에 연결된 포트속성을 INPUT(입력) 으로 설정하여 
    // 버튼에서 입력되는 값을 읽어 들인 수 있도록 한다.
    pinMode(_pin.Button(R), INPUT);
    pinMode(_pin.Button(L), INPUT);
    pinMode(_pin.Button(U), INPUT);
    pinMode(_pin.Button(D), INPUT);
    // 각 LED에 연결된 포트속성을 OUTPUT(출력) 으로 설정하여 
    // LED 를 켜고 끌 수 있도록 한다.
    pinMode(_pin.Led(R), OUTPUT);
    pinMode(_pin.Led(L), OUTPUT);
    pinMode(_pin.Led(C), OUTPUT);
}

// loop() 함수는 젤리비 보드가 켜져 있는 동안 계속적으로 실행 됨 
void loop() 
{
    // 오른쪽 버튼을 누르면
    if (LOW == digitalRead(_pin.Button(R))) {
        // 오른쪽 LED 를 켬
        digitalWrite(_pin.Led(R), HIGH);
    } else { // 오른쪽 버튼을 누르지 않으면
        // 오른쪽 LED 를 끔 
        digitalWrite(_pin.Led(R), LOW);
    }
    if (LOW == digitalRead(_pin.Button(L))) {
        digitalWrite(_pin.Led(L), HIGH);
    } else {
        digitalWrite(_pin.Led(L), LOW);
    }
    if (LOW == digitalRead(_pin.Button(U))) {
        digitalWrite(_pin.Led(C), HIGH);
    }
    if (LOW == digitalRead(_pin.Button(D))) {
      digitalWrite(_pin.Led(C), LOW);
    }
}
