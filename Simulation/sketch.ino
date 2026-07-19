#include <Wire.h>
#include <RTClib.h>
#include <LiquidCrystal_I2C.h>

RTC_DS1307 rtc;
LiquidCrystal_I2C lcd(0x27, 16, 2);

const int buttonPin = 18;

bool timerRunning = false;
bool lastButtonState = HIGH;

int countdownTime = 30;
int remainingTime = 30;

unsigned long previousMillis = 0;
const long interval = 1000;   // 1 second

void setup() {
  Serial.begin(115200);

  pinMode(buttonPin, INPUT_PULLUP);

  Wire.begin(21, 22);

  lcd.init();
  lcd.backlight();

  if (!rtc.begin()) {
    lcd.print("RTC ERROR");
    while (1);
  }

  if (!rtc.isrunning()) {
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }

  remainingTime = countdownTime;
}

void loop() {

  bool currentButtonState = digitalRead(buttonPin);

  // Detect button press (edge detection)
  if (lastButtonState == HIGH && currentButtonState == LOW) {
    delay(50);  // debounce

    timerRunning = !timerRunning;   // TOGGLE

    if (timerRunning) {
      lcd.clear();
    }
  }

  lastButtonState = currentButtonState;

  if (timerRunning) {

    unsigned long currentMillis = millis();

    if (currentMillis - previousMillis >= interval) {
      previousMillis = currentMillis;

      if (remainingTime > 0) {
        remainingTime--;
      }
    }

    lcd.setCursor(0,0);
    lcd.print("Court Timer     ");
    lcd.setCursor(0,1);
    lcd.print("Left: ");
    lcd.print(remainingTime);
    lcd.print(" sec   ");

    if (remainingTime == 0) {
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("TIME OVER!");
      timerRunning = false;
      remainingTime = countdownTime;
      delay(2000);
    }

  } else {
    // Show RTC time when stopped
    DateTime now = rtc.now();

    lcd.setCursor(0,0);
    lcd.print("Time: ");
    lcd.print(now.hour());
    lcd.print(":");
    lcd.print(now.minute());
    lcd.print(":");
    lcd.print(now.second());
    lcd.print("   ");

    lcd.setCursor(0,1);
    lcd.print("Press to Start ");
  }

}
