#include <Servo.h>
#include <U8x8lib.h>

// 서보 모터 객체 생성
Servo base;
Servo shoulder;
Servo upperarm;
Servo forearm;
Servo gripper;

int baseAngle = 90;
int shoulderAngle = 90;
int upperarmAngle = 90;
int forearmAngle = 90;
int gripperAngle = 90;
int delay_time = 15;
int delay_time_setup = 0;
int motor_step = 1;
bool stop_flag = false;

String base_str;
String shoulder_str;
String upperarm_str;
String forearm_str;
String gripper_str;
String inString;

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

U8X8_SSD1306_128X64_NONAME_HW_I2C u8x8(/* reset=*/ U8X8_PIN_NONE);

void setup() {
  Serial.begin(115200);

  base.attach(3);
  shoulder.attach(5);
  upperarm.attach(6);
  forearm.attach(9);
  gripper.attach(10);
 
  u8x8.begin();
  u8x8.setPowerSave(0);
  u8x8.setFont(u8x8_font_chroma48medium8_r);
  u8x8.setCursor(0, 1);
  u8x8.print("          ");
  u8x8.setCursor(0, 2);
  u8x8.print("jdcobot 100");
  u8x8.setCursor(0, 3);
  u8x8.print("standby");
  u8x8.setCursor(0, 4);
  u8x8.print("          ");
}

void loop() {
  delay(100);
  if (Serial.available() > 0) {
    inString = Serial.readStringUntil('\n');
    char cmd = inString[0];
    if (cmd == '1') {
      clear_oled();
      u8x8.drawString(0, 0, "read angles");
      Serial.print('a');
      Serial.print(baseAngle);
      Serial.print('b');
      Serial.print(shoulderAngle);
      Serial.print('c');
      Serial.print(upperarmAngle);
      Serial.print('d');
      Serial.print(forearmAngle);
      Serial.print('e');
      Serial.print(gripperAngle);
      Serial.println('f');
    } else if (cmd == '2') {
      // 각도 값 파싱
      baseAngle = inString.substring(inString.indexOf('a') + 1, inString.indexOf('b')).toInt();
      shoulderAngle = inString.substring(inString.indexOf('b') + 1, inString.indexOf('c')).toInt();
      upperarmAngle = inString.substring(inString.indexOf('c') + 1, inString.indexOf('d')).toInt();
      forearmAngle = inString.substring(inString.indexOf('d') + 1, inString.indexOf('e')).toInt();
      gripperAngle = inString.substring(inString.indexOf('e') + 1, inString.indexOf('f')).toInt();

      Serial.print('a');
      Serial.print(baseAngle);
      Serial.print('b');
      Serial.print(shoulderAngle);
      Serial.print('c');
      Serial.print(upperarmAngle);
      Serial.print('d');
      Serial.print(forearmAngle);
      Serial.print('e');
      Serial.print(gripperAngle);
      Serial.println('f');

      stop_flag = false;
      while (!stop_flag) {
        bool done = true;
        done &= moveServo(base, baseAngle, motor_step);
        done &= moveServo(shoulder, shoulderAngle, motor_step);
        done &= moveServo(upperarm, upperarmAngle, motor_step);
        done &= moveServo(forearm, forearmAngle, motor_step);
        done &= moveServo(gripper, gripperAngle, motor_step);
        if (done) break;
        delay(delay_time);
      }
      display_angles();
    } else if (cmd == '3') {
      resetServos();
    } else if (cmd == '4') {
      clear_oled();
      u8x8.drawString(0, 0, "stop servo motors");
      stop_flag = true;
    }
  }
}

bool moveServo(Servo& servo, int targetAngle, int step) {
  if (stop_flag) {
    return true; // 정지 명령이 들어오면 현재 상태 유지
  }
  
  int currentAngle = servo.read();
  if (currentAngle < targetAngle) {
    servo.write(currentAngle + step);
    return false;
  } else if (currentAngle > targetAngle) {
    servo.write(currentAngle - step);
    return false;
  }
  return true;
}

void resetServos() {
  bool done;
  do {
    done = true;
    done &= moveServo(base, 90, motor_step);
    done &= moveServo(shoulder, 90, motor_step);
    done &= moveServo(upperarm, 90, motor_step);
    done &= moveServo(forearm, 90, motor_step);
    done &= moveServo(gripper, 90, motor_step);
    delay(delay_time);
  } while (!done);
}

void display_angles() {
  clear_oled();
  u8x8.setFont(u8x8_font_chroma48medium8_r);
  u8x8.drawString(0, 0, ("sig: " + inString.substring(0, 10)).c_str());
  u8x8.drawString(0, 1, ("     " + inString.substring(10)).c_str());
  u8x8.drawString(0, 2, ("base:      " + String(baseAngle)).c_str());
  u8x8.drawString(0, 3, ("shoulder:  " + String(shoulderAngle)).c_str());
  u8x8.drawString(0, 4, ("upperArm:  " + String(upperarmAngle)).c_str());
  u8x8.drawString(0, 5, ("foreArm:   " + String(forearmAngle)).c_str());
  u8x8.drawString(0, 6, ("gripper:   " + String(gripperAngle)).c_str());
  delay(100);
}

void clear_oled() {
  u8x8.setFont(u8x8_font_chroma48medium8_r);
  for (int i = 0; i < 7; i++) {
    u8x8.drawString(0, i, "                   ");
  }
  delay(100);
}
