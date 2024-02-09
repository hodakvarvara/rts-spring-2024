// HIGH обозначает логическую единицу или напряжение в высоком состоянии 
// а LOW обозначает логический ноль или напряжение в низком состоянии 
// digitalWrite - для записи цифрового значения (HIGH или LOW) на конкретный цифровой пин микроконтроллера.
const int ledPin3 = 3;  
const int ledPin5 = 5;  
const int ledPin6 = 6;  
const int ledPin9 = 9;  
const int ledPin10 = 10;  

const int interval3 = 10000;  
const int interval5 = 1000;  
const int interval6 = 500;  
const int interval9 = 9;  
const int interval10 = 10;

unsigned long previousMillis3 = 0; 
unsigned long previousMillis5 = 0; 
unsigned long previousMillis6 = 0; 
unsigned long previousMillis9 = 0; 
unsigned long previousMillis10 = 0; 
//int ledState = LOW;  // ledState used to set the LED
//unsigned long previousMillis = 0;  // will store last time LED was updated
//const long interval = 10;  // interval at which to blink (milliseconds)

void setup() {
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin5, OUTPUT);
  pinMode(ledPin6, OUTPUT);
  pinMode(ledPin9, OUTPUT);
  pinMode(ledPin10, OUTPUT);
}

int func(unsigned long previousTime, long interval, int ledState, int ledPin)
{
  unsigned long currentMillis = millis() * 1000;
  if (currentMillis - previousTime >= interval) {
    previousTime = currentMillis;
    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }
    digitalWrite(ledPin, ledState);
  }
  return previousTime;
}

void loop() {
  previousMillis3 = func(previousMillis3, interval3, LOW, ledPin3);
  previousMillis5 = func(previousMillis5, interval5, LOW, ledPin5);
  previousMillis6 =func(previousMillis6, interval6, LOW, ledPin6);
  previousMillis9 = func(previousMillis9, interval9, LOW, ledPin9);
  previousMillis10 = func(previousMillis10, interval10, LOW, ledPin10);
}
