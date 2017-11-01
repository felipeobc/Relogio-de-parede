#include <DS3231.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Inicializa o display no endereco 0x27
LiquidCrystal_I2C lcd(0x3f,2,1,0,4,5,6,7,3, POSITIVE);
// Init the DS3231 using the hardware interface
DS3231  rtc(A1, A2); //DS3231  rtc(SDA, SCL);

void setup() {
  // Setup Serial connection
  Serial.begin(115200);
  // Initialize the rtc object
  rtc.begin();
  // The following lines can be uncommented to set the date and time
  //rtc.setDOW(WEDNESDAY);     // Set Day-of-Week to SUNDAY
  //rtc.setTime(16, 46, 0);     // Set the time to 12:00:00 (24hr format)
  //rtc.setDate(1, 11, 2017);   // Set the date to (Dias ,Mes, Ano)
  //inicia o display
  lcd.begin (16,2);
//  brilho
  lcd.setBacklight(HIGH);
 
  
}

void loop() {
  //horas
  lcd.setCursor(0,0);
  lcd.print("Horas: ");
  lcd.print(rtc.getTimeStr());
   
  //Data
  lcd.setCursor(0,1);
  lcd.print("Date: ");
  lcd.print(rtc.getDateStr());
  
  
  /*//Temperatura
  lcd.setCursor(0,1);
  lcd.print("Temp: ");
  lcd.print(rtc.getTemp());
  lcd.print(" *C");
  */
  
  
 
}
