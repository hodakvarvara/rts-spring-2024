#include <TaskManagerIO.h>;
const int ledPin3 = 3;  
const int ledPin5 = 5;  
const int ledPin6 = 6;  
const int ledPin9 = 9;  
const int ledPin10 = 10;  

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

void toggleLed(int pin, int &ledStatePin) {
  	if (ledStatePin == LOW)
      {
        ledStatePin =  HIGH;
      }
      else 
      {
        ledStatePin = LOW;
      }
      digitalWrite(pin, ledStatePin);
}


void setup() {
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin5, OUTPUT);
  pinMode(ledPin6, OUTPUT);
  pinMode(ledPin9, OUTPUT);
  pinMode(ledPin10, OUTPUT);

taskManager.scheduleFixedRate(interval3, [] {
    toggleLed(ledPin3, ledStatePin3);
	}, TIME_MICROS);

taskManager.scheduleFixedRate(interval5, [] {
		toggleLed(ledPin5, ledStatePin5);
	}, TIME_MICROS);

taskManager.scheduleFixedRate(interval6, [] {
		toggleLed(ledPin6, ledStatePin6);
	}, TIME_MICROS);

taskManager.scheduleFixedRate(interval9, [] {
		toggleLed(ledPin9, ledStatePin9);
	}, TIME_MICROS);

taskManager.scheduleFixedRate(interval10, [] {
		toggleLed(ledPin10, ledStatePin10);
	}, TIME_MICROS);
}


void loop() {
  taskManager.runLoop();
}
