"JellibiPin" class for Jellibi
===============

 [코드크런치 까페(네이버)](https://cafe.naver.com/codecrunch)   

 <TABLE>
 <TR><TD nowrap>
     <a href="https://smartstore.naver.com/robotnmore" target=new>
         <img src="https://dthumb-phinf.pstatic.net/?src=%22http%3A%2F%2Fwww.robotnmore.com%2Fdownload%2Fcodecrunch%2Fcafe_door_20190225_01.jpg%22&type=cafe_wa740">
     </a>    
     <a href="https://www.facebook.com/codecrunch.official/" target=new>
     <img src="https://dthumb-phinf.pstatic.net/?src=%22http%3A%2F%2Fwww.robotnmore.com%2Fdownload%2Fcodecrunch%2Fcafe_door_20190225_02.jpg%22&type=cafe_wa740">
     </a>
     <a href="https://www.instagram.com/codecrunch.official/" target=new>
     <img src="https://dthumb-phinf.pstatic.net/?src=%22http%3A%2F%2Fwww.robotnmore.com%2Fdownload%2Fcodecrunch%2Fcafe_door_20190225_03.jpg%22&type=cafe_wa740">
     </a>
     </TD></TR>
 </TABLE>

아두이노 나노와 호환되는 젤리비보드에는 네개의 버튼, 부져 및 몇 개의 켜고 끌 수 있는 LED 가 있습니다. 
그리고 그리퍼를 움직이는 두개의 서보모터를 연결할 수 있고 젤리비로봇으로는 DC 모터도 연결할 수 있습니다. 

이러한 동작을 문제없이 해내기 위해서 부품들이 젤리비 보드와 어떻게 연결 해야되는지 미리 정해두었습니다. 
JellibiPin 클래스는 이 연결정보를 편리하게 사용할 수 있게 도와줍니다.

버튼이 눌렸는지 알아보기 위해 아래와 같은 아두이노 코드를 작성하였습니다. 

```cpp
 if (LOW == digitalRead(A0)) {
   Serial.print("Button Pushed");
 }
```
**"JellibiPin"** 라이브러리를 사용하게 되면 위 코드는 아래 예처럼 작성됩니다. 

```cpp
JellibiPin _pin 

if (LOW == digitalRead(_pin.Button(R)) {
  Serial.print("Right Button Pushed");
}
```
두 코드의 차이점은 가독성(Readability) 에 있습니다. 

첫번째 코드는 ```A0 가 LOW 로 가 있는지 검사``` 로 이해 되지만    
두번째 코드는 ```오른쪽(R) 버튼이 눌려(LOW) 있는지 검사``` 로 이해 할 수 있습니다. 

이러한 차이로 인해서 긴 코드나 다른 사람이 작성한 코드를 읽을 때 가독성을 개선할 수 있습니다.

아래는 JellibiPin 라이브러리에서 사용할 수 있는 젤리비보드의 핀(포트) 정보입니다.



| 포트번호 | 기능 1                                    | 기능 2                                 | 기타 |
| :------: | ----------------------------------------- | -------------------------------------- | ---- |
|    A0    | 버튼 1(위)                                |                                        |      |
|    A1    | 버튼 2(아래)                              |                                        |      |
|    D2    | 버튼 3(왼쪽)                              | 서보모터 02 (오른쪽)                   |      |
|    D4    | 버튼 4(오른쪽)                            |                                        |      |
|    D6    | 오른쪽 주행모터 회전속도 제어(PWM)        |                                        |      |
|    D8    | 오른쪽 주행모터 회전방향제어              |                                        |      |
|    D5    | 왼쪽 주행모터 회전속도 제어(PWM)          |                                        |      |
|    D7    | 왼쪽 주행모터 회전방향제어                |                                        |      |
|    D9    | 서보모터 01 (왼쪽)                        |                                        |      |
|    A6    | 모터드라이버 IR 센서 (왼쪽)               | 센서보드 IR 센서 (왼쪽)                |      |
|    A7    | 모터드라이버 IR 센서 (오른쪽)             | 센서보드 IR 센서 (오른쪽)              |      |
|    A3    | 센서보드 IR 센서 (가운데)                 |                                        |      |
|   D11    | LED (오른쪽, 파란색)                      |                                        |      |
|   D10    | LED (왼쪽, 빨간색)                        |                                        |      |
|   D13    | LED (가운데, 녹색)                        | 소나 센서 Echo 입력(TBD, 추후업데이트) |      |
|    D3    | 부져 (피에죠 스피커)                      |                                        |      |
|    A2    | CDS 센서                                  |                                        |      |
|   D12    | 소나 센서 Trigger 출력(TBD, 추후업데이트) |                                        |      |



설치 및 사용 방법을 아래에서 간략히 설명합니다.



Installation
------------------

#### Windows 

아두이노를 설치 한 후 JellibiPin 과 같은 아두이노 라이브러리를 다운로드하여 사용하는 방법은 여러가지가 있습니다. 그 중 가장 간단한 방법을 설명합니다.

1. 라이브러리 다운로드하기 

   1. 웹브라우져에서 **JellibiPin** 라이브러리의 깃허브(https://github.com/signaled/JellibiPin)로  이동합니다.
   2. 깃허브의 Code 탭에서 [Clone or download] 버튼을 눌러 "zip" 파일로 다운로드를 선택합니다.   
      ![Download](http://www.robotnmore.com/matthew/jellibibutton/download_button2.png)

2. **JellibiPin** 라이브러리 적용하기 

   1. 아두이노 프로그램을 실행합니다.
   2. **메뉴 > 스케치 > 라이브러리 포함하기 > .ZIP 라이브러리 추가** 를 선택합니다. 
   3. 파일 선택 창에서 다운로드 받은 JellibiPin-master.zip 을 선택합니다.
   4. **메뉴 > 스케치 > 라이브러리 포함히기 > JellibiPin-master** 를 선택합니다. 

   

JellibiPin 라이브러리는 JellibiPin 클래스와 JellibiPos 열거자로 구성됩니다.  

### JellibiPos 열거자(ENUM)

``` 
enum JellibiPos 
{
    U = 0,
    D,
    L,
    R,
    C
};
```



##### Description 

JellibiPos 열거자는 JellibiPin 클래스의 메서드에서 인자로 사용하며 동일한 부품이 연결된 여러 포트에서 젤리비보드 상에서의 **위치**로 구분하여 핀번호를 가져오기 위해서 사용합니다. 

```U``` 는 "UP" 의 '위' 버튼의 핀번호가 필요할 때 인자로 사용합니다.  
```D``` 는 "Down" 의 의미로 '아래' 버튼의 핀번호가 필요할 때 인자로 사용합니다.  
```L``` 은 "Left" 의 의미로 '왼쪽' 버튼 이나, '왼쪽' Ir 센서, '왼쪽' 서보모터 포트를 가져올 때 인자로 사용합니다.  
```R``` 은 "Right" 의 의미로 '오른쪽' 버튼, '오른쪽' Ir 센서, '오른쪽' 서보모터 포트를 가져올 때 인자로 사용합니다.  
```C``` 는 "Center" 의 의미로 젤리비 센서보드의 '가운데'  Ir센서와 연결된 포트를 가져올 때 인자로 사용합니다.   

---



### JellibiPin 클래스 

#### Method

---

```c++
const int Button (JellibiPos pos);
```

#####  Description 

 젤리비보드의 버튼과 연결된 핀번호를 응답합니다.  
버튼은 총 네개로 상/하/좌/우 버튼으로 지칭합니다.  

##### Parameter 

>  **```JellibiPos pos```**
>    
>    ```JellibiPos::U``` : 'UP' 버튼의 포트 응답  
>  ```JellibiPos::D``` : 'Down' 버튼의 포트 응답  
>```JellibiPos::L``` : 'Left' 버튼의 포트 응답   
>```JellibiPos::R``` : 'Right' 버튼의 포트 응답       



---

```c++
const int Wheel(JellibiPos pos);
```

##### Description

젤리비 주행 로봇의 좌/우 모터의 회전속도를 제어하는 PWM(Pulse Width Modulation) 포트를 응답합니다.

##### Parameter

> **```JellibiPos pos```**
>
> ```JellibiPos::R``` : 오른쪽 모터의 회전속도 제어 포트 응답  
> ```JellibiPos::L``` : 왼쪽 모터의 회전속도 제어 포트 응답   



---

```c++ 
const int WheelDir(JellibiPos pos);
```

##### Description

젤리비 주행 로봇의 좌/우 모터의 회전방향을 제어하는 GPIO 포트를 응답합니다.

##### Parameter

>  **```JellibiPos pos```**
>
> ```JellibiPos::R``` : 오른쪽 모터의 회전방향 제어 포트 응답    
> ```JellibiPos::L``` : 왼쪽 모터의 회전방향 제어 포트 응답



---

```c++
const int Servo(JellibiPos pos);
```

##### Descriptoin

젤리비보드의 서보모터 제어 포트인 ```Servo 01```  과 ```Servo 02``` 포트를 응답합니다. 

##### Parameter 

> **```JellibiPos pos```**
>
> ```JellibiPos::L``` : 왼쪽 서보 제어 포트인  ```Servo 01``` 포트 응답  
> ```JellibiPos::R``` : 오른쪽 서보 제어 포트인 ```Servo 02``` 포트 응답



---

```c++
const int Ir(JellibiPos pos);
```

##### Description

젤리비모바일 보드와 젤리비 센서보드의 IR 센서와 연결된 포트를 응답합니다.   
젤리비모바일 보드에는 젤리비보드에서 사용할 IR 센서보드를 고를 수 있는 스위치가 있습니다.   
이 스위치를 ```Bottom``` 으로 선택하면 젤리비 모바일 보드의 IR 센서를 사용하고 ```Front``` 를 선택하면  젤리비 센서보드의 IR 센서를 사용할 수 있습니다. 

##### Parameter

> **```JellibiPos pos```**
>
> ```JellibiPos::L``` : 젤리비모바일 보드 또는 센서보드의 왼쪽 IR 센서와 연결된 포트 응답   
> ```JellibiPos::R``` : 젤리비모바일 보드 또는 센서보드의 오른쪽 IR 센서와 연결된 포트 응답   
> ```JellibiPos::C``` : 젤리비센서보드의 가운데 IR 센서와 연결된 포트 응답     



---

```c++
const int Led(JellibiPos pos);
```

##### Description

젤리비보드의 LED 와 연결된 포트를 응답합니다.   
젤리비보드에는 세개의 LED 가 연결되어 있습니다.  

##### Parameter

> **```JellibiPos pos```**
>
> ```JellibiPos::L``` : 젤리비보드의 왼쪽 LED 와 연결된 포트 응답   
> ```JellibiPos::R``` : 젤리비보드의 오른쪽 LED 와 연결된 포트 응답   
> ```JellibiPos::C``` : 젤리비보드의 가운데 LED 와 연결된 포트 응답 



---

```c++
const int Cds();
```

##### Description

젤리비보드의 CDS 센서와 연결된 포트를 응답합니다. 



---

```c++
const int Buzzer();
```

##### Description

젤리비보드의 부져와 연결된 포트를 응답합니다.



### Example

```c++
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
```

