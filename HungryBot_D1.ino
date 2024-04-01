#include <Servo.h>

//#define ENABLE_SERVO_180    //Servo allow move to 0 degree to 180 degree. Disable to change to 90* servo.


#define NOW 1
#define REFRESH_PERIOD_MS 20
#ifdef ENABLE_SERVO_180
  #define FREE_ANGLE 100
#else
  #define FREE_ANGLE 180
#endif
  #define THROUGH_ANGLE 0

Servo ServoHand;

//Pin D4 là led mặc định
#define PIN_LED D1
#define PIN_SERVOHAND D3  
#define PIN_ECHO D2
#define PIN_TRIG D1  
#define DISTANCE 60  // Distance value
#define COVER_THREADHOLD 8

unsigned int idle_count;  // đếm số lần tĩnh lặng để tiết kiệm năng lượng

/*
 * Server di chuyen 1 goc nhat dinh
 * @param pos goc can di chuyen = 0 --> 180
 * @remark Bởi vì việc di chuyển cần thời gian, còn lâu hơn cả 1 chu kì điều khiển, nên phai lặp lại chu kì điều khiển trong nhiều lần mới bảo đảm.
 */
void ServoMove(int pos) {
  int stall = 14;
  for (; stall > 0; stall--) {
    ServoHand.write(pos);      // tell servo to go to position in variable 'pos'
    delay(REFRESH_PERIOD_MS);  // waits 20ms for refresh period
  }
}

// the setup routine runs once when you press reset:
void setup() {
  // initialize the digital pin as an output
  pinMode(PIN_LED, OUTPUT);  //LED on Model A  or Pro

  // Báo hiệu bắt đầu
  digitalWrite(PIN_LED, HIGH);
  delay(200);
  digitalWrite(PIN_LED, LOW);
  delay(200);
  digitalWrite(PIN_LED, HIGH);
  delay(200);
  digitalWrite(PIN_LED, LOW);

  ServoHand.attach(PIN_SERVOHAND);
  ServoMove(FREE_ANGLE);
  ServoHand.detach();

  pinMode(PIN_ECHO, INPUT);
  pinMode(PIN_TRIG, OUTPUT);

  idle_count = 0;
}

int GetDistance() {
  digitalWrite(PIN_TRIG, LOW);  // Set chan Trig xuong muc thap 2uS
  delayMicroseconds(2);
  digitalWrite(PIN_TRIG, HIGH);  //Gui mot xung 10uS muc cao vao chan Trig
  delayMicroseconds(10);
  digitalWrite(PIN_TRIG, LOW);                      // Gui lai muc thap vao chan Trig
  unsigned int distance = pulseIn(PIN_ECHO, HIGH);  // Doc thoi gian tra ve. Hay dung kieu unsign. Da ghi nhan co so am tra ve roi
  return distance / 58;                             // Tinh toan khoang cach
}

unsigned int dis;

// the loop routine runs over and over again forever:
void loop() {
  dis = GetDistance();
  if (idle_count < 2000) {
    delay(100);
  } else {
    delay(1000);
  }
  if (dis < COVER_THREADHOLD) {
    idle_count = 0;
    digitalWrite(PIN_LED, HIGH);
    delay(2000);

  ServoHand.attach(PIN_SERVOHAND);

    ServoMove(THROUGH_ANGLE);
    delay(500);
    ServoMove(FREE_ANGLE);
    digitalWrite(PIN_LED, LOW);
    //Fix-bug: Neu su dung nguon Adpater (khong su dung dung data usb cable) thi khoang cach do duoc tu lan thu 2 tro luon < nguong, lam cho BOT lien tuc do rac.
    //Nghi ngo nguyen nhan: do khong gui thong tin qua DigiKeyboard, viec lay do khoang cach dien ra nhanh qua, khi ma dong co servo chua ve dung vi tri,
    //Giai phap: them do tre
    delay(1000);
    ServoHand.detach();        
  } else {
    idle_count++;
  }
}
