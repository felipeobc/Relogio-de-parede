#include <DS3231.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

//Configuração do LCD
LiquidCrystal_I2C lcd(0x3f,2,1,0,4,5,6,7,3, POSITIVE); //(SCL SDA) = (A4, A5) como padrao. 

//Configuração da biblioteca do DS3231
DS3231 Clock(A4, A5); //(SCL SDA) 



void setup() {
  // Iniciar o Interface I2C 
  Clock.begin();
  //Funcoes de Ajustes
//Clock.setDOW(WEDNESDAY); // Set Day-of-Week to SUNDAY
//Clock.setTime(00, 03, 0); // Set the time to 12:00:00 (24hr format)
//Clock.setDate(1, 11, 2017); // Set the date to January 1st, 2014

  // Iniciar o serial
  Serial.begin(115200);

  //Iniciar o LCD
  lcd.begin(16, 2);
  //Liga Led
  lcd.setBacklight(HIGH);
  //Desliga o Led
  //lcd.setBacklight(LOW);
        

 
}
void loop(){
  
  //Joga as variaveis na Serial
  // Send Day-of-Week
Serial.print(Clock.getDOWStr());
Serial.print(" ");

// Send date
Serial.print(Clock.getDateStr());
Serial.print(" — ");

// Send time
Serial.println(Clock.getTimeStr());

//Temperatura
Serial.print("Temperature: ");
Serial.print(Clock.getTemp());
Serial.println(" C");
delay(1000);
 
  
  //Primeira Linha do LCD
  lcd.setCursor(0,0);             // Seta a posição no LCD (coluna,linha)
  lcd.print(Clock.getTimeStr());      // imprime a mensagem no LCD (lembrando que cada caracter usa um espaço do LCD)
  lcd.setCursor(8,0);
  lcd.print(Clock.getDOWStr()); 

  //Segunda linha do LCD
  lcd.setCursor(0,1);
  lcd.print(Clock.getDateStr()); 

  //Temperatura
  lcd.setCursor(11,1);
  lcd.print("T:");
  lcd.setCursor(12,1);
  lcd.print(Clock.getTemp()); 

}
