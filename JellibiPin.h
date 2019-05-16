#ifndef __JELLIBIPIN_H__
#define __JELLIBIPIN_H__

#include <Arduino.h>
enum JellibiPos
{
    U = 0, // UP
    D,     // Down
    L,     // Left
    R,     // Right
    C,     // Center
};

class JellibiPin
{
public:

    static const int NONE               = -1;

    static const int BUTTON_RIGHT       = 4;
    static const int BUTTON_LEFT        = 2;  // conflict with SERVO_GRIP 
    static const int BUTTON_UP          = A0;
    static const int BUTTON_DOWN        = A1;

    static const int WHEEL_PWM_RIGHT    = 6;
    static const int WHEEL_DIR_RIGHT    = 8;  // HIGH : backward, LOW : forward 

    static const int WHEEL_PWM_LEFT     = 5;
    static const int WHEEL_DIR_LEFT     = 7;  // HIGH : forward , LOW : backward

    static const int SERVO_GRIP         = 2;  // conflict with BUTTON_LEFT
    static const int SERVO_LIFT         = 9;

    static const int IR_LEFT            = A6;
    static const int IR_RIGHT           = A7;
    static const int IR_CENTER          = A3;

    static const int LED_RIGHT          = 11;
    static const int LED_LEFT           = 10;
    static const int LED_STATUS         = 13;

    static const int BUZZER             = 3;
    static const int CDS_SENSOR         = A2;

public:

    JellibiPin();
    const int Button(JellibiPos pos);
    const int Wheel(JellibiPos pos);
    const int WheelDir(JellibiPos pos);
    const int Servo(JellibiPos pos);
    const int Ir(JellibiPos pos);
    const int Led(JellibiPos pos);
    const int Cds();
    const int Buzzer();
};

#endif//___JELLIBIPIN_H__

