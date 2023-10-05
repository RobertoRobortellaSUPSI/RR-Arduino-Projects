#include <SensirionI2CScd4x.h>
#include <OPTISPACE_SENSORS.h>
#include <Wire.h>
#include <Arduino.h>

/*
OPTISPACE_SENSORS_03
20.09.2023
Roberto Robortella
*/

SensirionI2CScd4x scd4x;
int ledState = LOW;  // ledState used to set the LED
const int ledPin = LED_BUILTIN;  // the number of the LED pin
int sample_time = 20; //delay di misura in secondi

void printUint16Hex(uint16_t value) {
    Serial.print(value < 4096 ? "0" : "");
    Serial.print(value < 256 ? "0" : "");
    Serial.print(value < 16 ? "0" : "");
    Serial.print(value, HEX);
}

void printSerialNumber(uint16_t serial0, uint16_t serial1, uint16_t serial2) {
    Serial.print("Serial: 0x");
    printUint16Hex(serial0);
    printUint16Hex(serial1);
    printUint16Hex(serial2);
    Serial.println();
}

void setup() {
    Wire.begin();
    Serial.begin(115200);
    //**** START TSL2561 code ****
    TSL2561.init();

   //**** START SCD41 code ****
    uint16_t error;
    char errorMessage[256];

    scd4x.begin(Wire);

    // stop potentially previously started measurement
    error = scd4x.stopPeriodicMeasurement();
    if (error) {
        Serial.print("Error trying to execute stopPeriodicMeasurement(): ");
        errorToString(error, errorMessage, 256);
        Serial.println(errorMessage);
    }

    uint16_t serial0;
    uint16_t serial1;
    uint16_t serial2;
    error = scd4x.getSerialNumber(serial0, serial1, serial2);
    if (error) {
        Serial.print("Error trying to execute getSerialNumber(): ");
        errorToString(error, errorMessage, 256);
        Serial.println(errorMessage);
    } else {
        // Serial.print("SCD41: ");
        // printSerialNumber(serial0, serial1, serial2);
    }

    // Start Measurement
    error = scd4x.startPeriodicMeasurement();
    if (error) {
        Serial.print("Error trying to execute startPeriodicMeasurement(): ");
        errorToString(error, errorMessage, 256);
        Serial.println(errorMessage);
    }

    //Serial.println("Waiting for first measurement... (5 sec)");

    //LED
    pinMode(ledPin, OUTPUT);
}

void loop() {
    //Change LED Status
    if (ledState == LOW) {
        ledState = HIGH;
    } else {
        ledState = LOW;
    }
    delay(100);
    // set the LED with the ledState of the variable:
    digitalWrite(ledPin, ledState);

    //**** START SCD41 code ****
    uint16_t error;
    char errorMessage[256];
    delay(100);
    // Read Measurement
    uint16_t co2 = 0;
    float temperature = 0.0f;
    float humidity = 0.0f;
    bool isDataReady = false;
    error = scd4x.getDataReadyFlag(isDataReady);
    if (error) {
        Serial.print("Error trying to execute getDataReadyFlag(): ");
        errorToString(error, errorMessage, 256);
        Serial.println(errorMessage);
        return;
    }
    if (!isDataReady) {
        return;
    }
    error = scd4x.readMeasurement(co2, temperature, humidity);
    if (error) {
        Serial.print("Error trying to execute readMeasurement(): ");
        errorToString(error, errorMessage, 256);
        Serial.println(errorMessage);
    } else if (co2 == 0) {
        Serial.println("Invalid sample detected, skipping.");
    } else {
        //**** START SCD41 code ****
        // Serial.println("SCD41 Data: ");
        // Serial.print("Co2:");
        // Serial.print(co2);
        // Serial.print("\t");
        // Serial.print("Temperature:");
        // Serial.print(temperature);
        // Serial.print("\t");
        // Serial.print("Humidity:");
        // Serial.println(humidity);
        // Serial.println("  "); 
        
        //**** START TSL2561 code ****
        // Serial.println("TSL2561 Data: ");
        // Serial.print("The Light value is: ");
        // Serial.print(TSL2561.readVisibleLux());
        //  Serial.print("\t");
        // Serial.print("The IR value is: ");
        // Serial.println(TSL2561.readIRLuminosity());
        // Serial.println("  "); 
      
      // Impacchettamento dati per l'invio seriale
      // SCD41_co2;SCD41_temperature;SCD41_humidity;TSL2561_VisibleLux;TSL2561_IRLux
      //Serial.println(co2,";",temperature,";",humidity,";",TSL2561.readVisibleLux(),";",TSL2561.readIRLuminosity());
       Serial.print(co2);
       Serial.print(",");
       Serial.print(temperature);
       Serial.print(",");
       Serial.print(humidity);
       Serial.print(",");
       Serial.print(TSL2561.readVisibleLux());
       Serial.print(",");
       Serial.println(TSL2561.readIRLuminosity());
       delay(sample_time*1000); //Delay di misura in secondi
    }
}


