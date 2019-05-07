#include <JellibiPin.h>

#define WARN()    if(Serial) {Serial.print("Warning : Not Available Pos");Serial.println(__FUNCTION__);}

JellibiPin::JellibiPin()
{
}

const int JellibiPin::Button(JellibiPos pos)
{
    if (pos == U) {
        return JellibiPin::BUTTON_UP;
    } else if (pos == D) {
        return JellibiPin::BUTTON_DOWN;
    } else if (pos == R) {
        return JellibiPin::BUTTON_RIGHT;
    } else if (pos == L) {
		return JellibiPin::BUTTON_LEFT;
	} else {
        WARN();
        return JellibiPin::NONE;
    }
}

const int JellibiPin::Wheel(JellibiPos pos)
{
    if (pos == R) {
        return JellibiPin::WHEEL_PWM_RIGHT;
    } else if (pos == L) {
        return JellibiPin::WHEEL_PWM_LEFT;
    } else {
        WARN();
        return JellibiPin::NONE;
    }
}

const int JellibiPin::WheelDir(JellibiPos pos)
{
    if (pos == R) {
        return JellibiPin::WHEEL_DIR_RIGHT;
    } else if (pos == L) {
        return JellibiPin::WHEEL_DIR_LEFT;
    } else {
        WARN();
        return JellibiPin::NONE;
    }
}

const int JellibiPin::Servo(JellibiPos pos)
{
    if (pos == R) {
        return JellibiPin::SERVO_GRIP;
    } else if (pos == L) {
        return JellibiPin::SERVO_LIFT;
    } else {
        WARN();
        return JellibiPin::NONE;
    }
}

const int JellibiPin::Ir(JellibiPos pos)
{
    if (pos == R) {
        return JellibiPin::IR_RIGHT;
    } else if (pos == L) {
        return JellibiPin::IR_LEFT;
    } else if (pos == C) {
        return JellibiPin::IR_CENTER;
    } else {
        WARN();
        return JellibiPin::NONE;
    }
}

const int JellibiPin::Led(JellibiPos pos)
{
    if (pos == L) {
        return JellibiPin::LED_LEFT;
    } else if (pos == R) {
        return JellibiPin::LED_RIGHT;
    } else if (pos == C) {
        return JellibiPin::LED_STATUS;
    } else {
        WARN();
        return JellibiPin::NONE;
    }
}

const int JellibiPin::Cds()
{
    return JellibiPin::CDS_SENSOR;
}

const int JellibiPin::Buzzer()
{
    return JellibiPin::BUZZER;
}

