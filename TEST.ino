#include <Adafruit_LiquidCrystal.h>
#define DC_MOTOR 10
#define TEMP_SENSOR A0
#define RED  13
#define BLUE  12
#define GREEN  11
Adafruit_LiquidCrystal lcd(0);

void setup(){
    Serial.begin(9600);
    pinMode(TEMP_SENSOR, INPUT);
    pinMode(RED, OUTPUT);
    pinMode(BLUE, OUTPUT);
    pinMode(GREEN, OUTPUT);
    pinMode(DC_MOTOR, OUTPUT);
}

int r,g,b;
int val = 255;

void loop(){
    float voltage = analogRead(TEMP_SENSOR) * 5.0 / 1024.0;
    float temperature = voltage * 100 - 50; 
    analogWrite(DC_MOTOR, val);

    if(temperature <= 20){
        r = 0; g = 0; b = 255;  
    }
    else if(temperature <= 30){
        r = 0; g = 255; b = 0; 
    }
    else{
        r = 255; g = 0; b = 0; 
    }

    analogWrite(RED, r);
    analogWrite(BLUE, b);
    analogWrite(GREEN, g);

    if(temperature <= 20) val = 0; 
    else if(temperature <= 40)  val = 80;
    else if(temperature <= 60)  val = 160;
    else  val = 255;

    analogWrite(DC_MOTOR, val);
}