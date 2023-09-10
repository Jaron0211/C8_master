#include "C8_master.h"

//sensor pin, base on SoftwareSerial
int C8_tx = 16; //tx pin
int C8_rx = 17; //rx pin
int timeout = 1000; //SoftwareSerial timeout

C8_master C8(C8_tx,C8_rx,timeout); //create sensor object

void setup(){
    Serial.begin(9600);
    C8.init(9600);
}

void loop(){

    float CO2_Value = C8.ReadCO2(); //if the data is not available, if will return -1
    Serial.print("The CO2 Value: ");
    Serial.println(CO2_Value);

    delay(100);
}

/*
If the passitive read got problem, try the active method:

void loop(){

    float CO2_Value = C8.ActiveReadCO2();
    Serial.print("The CO2 Value: ");
    Serial.println(CO2_Value);

    delay(1000);
}



*/