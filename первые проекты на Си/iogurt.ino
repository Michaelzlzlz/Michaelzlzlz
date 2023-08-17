  #include <OneWire.h>                 
  #include <DallasTemperature.h>        
  #include <LiquidCrystal.h>
 
  #define ONE_WIRE_BUS 8 /*создаем идентификаторы*/
  #define term_power 7  
  OneWire oneWire(ONE_WIRE_BUS);   /*выход подключен к 8 пин*/     
  DallasTemperature sensors(&oneWire);  
  LiquidCrystal lcd(12, 11, 5, 4, 3, 2);/*подключен пин 12,11,5,4,3,2*/
 
void setup(void){
    Serial.begin(9600); 
  sensors.begin(); /*запуск вывод данных на дисплей и датчика*/
  pinMode(term_power, OUTPUT); /*пин питания датчика*/
  lcd.begin(16, 2); /*размер экрана*/
}
 
float t1;
float temperature() { // Измеряем температуру 3 секунды
   digitalWrite(term_power, HIGH); // Вкл. питание датчика температуры
    delay(100); // Задержка перед первым измерением 
    sensors.requestTemperatures();// Запрос на измерение температуры 
  /*(1-й ошибочный)*/
    delay(500); // Задержка перед повторным измерением
    sensors.requestTemperatures();// Запрос на измерение температуры 
    float t = float(sensors.getTempCByIndex(0));// значение температуры
    digitalWrite(term_power, LOW); // Откл. питание датчика температуры
    delay(3000); // Чтобы датчик не сломался от частых измерений
    return(t); // Возвращаем значение температуры 
}
 
  void loop(void){ 
     t1 = temperature();
      lcd.setCursor(0, 0);
      lcd.print(t1,1);// Выводим значение температуры датчика
      lcd.print("C    ");
  }
 
