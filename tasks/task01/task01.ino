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
const int interval9 = 100;  
const int interval10 = 50;

unsigned long previousMillis3 = 0; 
unsigned long previousMillis5 = 0; 
unsigned long previousMillis6 = 0; 
unsigned long previousMillis9 = 0; 
unsigned long previousMillis10 = 0; 

int ledStatePin3 = LOW;
int ledStatePin5 = LOW;
int ledStatePin6 = LOW;
int ledStatePin9 = LOW;
int ledStatePin10 = LOW;
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

void toggleLED(unsigned long currentMillis, unsigned long& previousMillis, unsigned long interval, int pin, int& ledState) {
  if (currentMillis * 1000 - previousMillis >= interval) {
    previousMillis = currentMillis * 1000;
    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }
    digitalWrite(pin, ledState);
  }
}

void loop() {
   unsigned long currentMillis = millis();

  toggleLED(currentMillis, previousMillis3, interval3, ledPin3, ledStatePin3);
  toggleLED(currentMillis, previousMillis5, interval5, ledPin5, ledStatePin5);
  toggleLED(currentMillis, previousMillis6, interval6, ledPin6, ledStatePin6);
  toggleLED(currentMillis, previousMillis9, interval9, ledPin9, ledStatePin9);
  toggleLED(currentMillis, previousMillis10, interval10, ledPin10, ledStatePin10);

}
