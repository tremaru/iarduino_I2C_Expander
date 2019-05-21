// Данный пример меняет усреднение АЦП при чтении аналоговых данных.// * Строки со звёздочкой являются необязательными.
                                                                    //
#include <Wire.h>                                                   // * Подключаем библиотеку для работы с аппаратной шиной I2C.
#include <iarduino_I2C_Expander.h>                                  //   Подключаем библиотеку для работы с расширителем выводов.
iarduino_I2C_Expander gpio(0x09);                                   //   Объявляем объект gpio для работы с функциями и методами библиотеки iarduino_I2C_Expander, указывая адрес модуля на шине I2C.
                                                                    //   Если объявить объект без указания адреса (iarduino_I2C_Expander gpio;), то адрес будет найден автоматически.
void setup(){                                                       //
    Serial.begin(9600);                                             //   Инициируем передачу данных в монитор последовательного порта на скорости 9600 бит/сек.
    while(!Serial){;}                                               // * Ждём завершения инициализации шины UART.
    delay(500);                                                     // * Ждём завершение переходных процессов связанных с подачей питания.
//  Готовим модуль к работе:                                        //
    gpio.begin();                                                   //   Инициируем работу с расширителем выводов.
    gpio.analogAveraging(255);                                      //   Указываем максимальный коэффициент усреднения показаний АЦП.
    gpio.pinMode(4, INPUT, ANALOG);                                 // * Конфигурируем вывод 4 на работу в качестве аналогового входа.
}                                                                   //
                                                                    //
void loop(){                                                        //
    uint16_t pin4 = gpio.analogRead(4);                             //   Читаем аналоговый уровень с вывода №4 в переменную «pin4».
    Serial.println((String) "Pin_4="+pin4 );                        //
    delay(100);                                                     // * Ждём десятую долю секунды, чтоб не захламлять монитор последовательного порта.
}                                                                   //
                                                                    //
//  ПРИМЕЧАНИЕ:                                                     //
//  Для проверки работы скетча подключите потенциометр к 4 выводу.  //
//  Коэффициент усреднения АЦП задаётся функцией analogAveraging()  //
//  которая в качестве аргумента принимает значение от 0 до 255.    //
//  По умолчанию 127. Усреднение применяется для всех выводов.      //
//  Чем выше коэффициент усреднения, тем плавнее будут меняться     //
//  показания считанных аналоговых уровней.                         //
//  Для отключения усреднения укажите значение 0 или 1.             //
