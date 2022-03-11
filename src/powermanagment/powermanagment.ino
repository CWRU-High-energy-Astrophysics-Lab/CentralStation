#include <Wire.h>
#include <Adafruit_INA219.h>

Adafruit_INA219 ina219;
Adafruit_INA219 ina219_B(0x41);

Adafruit_INA219 ina219_C(0x44);
void setup(void) 
{
  Serial.begin(115200);
  while (!Serial) {
      // will pause Zero, Leonardo, etc until serial console opens
      delay(1);
  }

  uint32_t currentFrequency;
    
  Serial.println("Hello!");
  
  // Initialize the INA219.
  // By default the initialization will use the largest range (32V, 2A).  However
  // you can call a setCalibration function to change this range (see comments).
  if (! ina219.begin()) {
    Serial.println("Failed to find INA219 chip");
    while (1) { delay(10); }
  }

  ina219_B.begin();
  ina219_C.begin();
  Serial.println("Measuring voltage and current with INA219 ...");
}

void loop(void) 
{
  float shuntvoltage = 0;
  float busvoltage = 0;
  float current_mA = 0;
  float loadvoltage = 0;
  float power_mW = 0;

  shuntvoltage = ina219.getShuntVoltage_mV();
  busvoltage = ina219.getBusVoltage_V();
  current_mA = ina219.getCurrent_mA();
  power_mW = ina219.getPower_mW();
  loadvoltage = busvoltage + (shuntvoltage / 1000);
  
  Serial.print("Bus Voltage:   "); Serial.print(busvoltage); Serial.println(" V");
  Serial.print("Shunt Voltage: "); Serial.print(shuntvoltage); Serial.println(" mV");
  Serial.print("Load Voltage:  "); Serial.print(loadvoltage); Serial.println(" V");
  Serial.print("Current:       "); Serial.print(current_mA); Serial.println(" mA");
  Serial.print("Power:         "); Serial.print(power_mW); Serial.println(" mW");
  Serial.println("");

  delay(2000);
   shuntvoltage = ina219_B.getShuntVoltage_mV();
  busvoltage = ina219_B.getBusVoltage_V();
  current_mA = ina219_B.getCurrent_mA();
  power_mW = ina219_B.getPower_mW();
  loadvoltage = busvoltage + (shuntvoltage / 1000);
  
  Serial.print("Bus_B Voltage:   "); Serial.print(busvoltage); Serial.println(" V");
  Serial.print("Shunt_B Voltage: "); Serial.print(shuntvoltage); Serial.println(" mV");
  Serial.print("Load_B Voltage:  "); Serial.print(loadvoltage); Serial.println(" V");
  Serial.print("Current_B:       "); Serial.print(current_mA); Serial.println(" mA");
  Serial.print("Power_B:         "); Serial.print(power_mW); Serial.println(" mW");
  Serial.println("");

  delay(2000);
   shuntvoltage = ina219_C.getShuntVoltage_mV();
  busvoltage = ina219_C.getBusVoltage_V();
  current_mA = ina219_C.getCurrent_mA();
  power_mW = ina219_C.getPower_mW();
  loadvoltage = busvoltage + (shuntvoltage / 1000);
  
  Serial.print("Bus_C Voltage:   "); Serial.print(busvoltage); Serial.println(" V");
  Serial.print("Shunt_C Voltage: "); Serial.print(shuntvoltage); Serial.println(" mV");
  Serial.print("Load_C Voltage:  "); Serial.print(loadvoltage); Serial.println(" V");
  Serial.print("Current_C:       "); Serial.print(current_mA); Serial.println(" mA");
  Serial.print("Power_C:         "); Serial.print(power_mW); Serial.println(" mW");
  Serial.println("");

  delay(2000);
}
