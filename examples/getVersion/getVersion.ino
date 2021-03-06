// Данный пример демонстрирует версию прошивки модуля.              // * Строки со звёздочкой являются необязательными.
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
    Serial.print( "ПО модуля версии " );                            //   Выводим текст.
    Serial.println( gpio.getVersion() );                            //   Выводим версию прошивки модуля.
}                                                                   //
                                                                    //
void loop(){                                                        //
}                                                                   //
                                                                    //
//  ПРИМЕЧАНИЕ:                                                     //
//  Чтение версии прошивки из модуля выполняется при инициализации  //
//  функцией begin(), а функция getVersion() только возвращет ранее //
//  прочитанное значение.                                           //
