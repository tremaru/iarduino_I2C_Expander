// ДАННЫЙ ПРИМЕР ЧИТАЕТ АНАЛОГОВЫЙ УРОВЕНЬ С ВЫВОДА МОДУЛЯ:         // * Строки со звёздочкой являются необязательными.
// Требуется установить библиотеку <iarduino_I2C_Software.h>        //   https://iarduino.ru/file/627.html
                                                                    //
// Расширитель выводов, FLASH-I2C (Trema-модуль):                   //   https://iarduino.ru/shop/Expansion-payments/rasshiritel-vyvodov-i2c---flash-trema-modul.html
// Информация о подключении модулей к шине I2C:                     //   https://wiki.iarduino.ru/page/i2c_connection/
// Информация о модуле и описание библиотеки:                       //   https://wiki.iarduino.ru/page/trema-expander/
                                                                    //
#include <iarduino_I2C_Software.h>                                  //   Подключаем библиотеку для работы с программной шиной I2C, до подключения библиотеки iarduino_I2C_Expander.
SoftTwoWire sWire(3,4);                                             //   Создаём объект программной шины I2C указав выводы которым будет назначена роль линий: SDA, SCL.
                                                                    //
#include <iarduino_I2C_Expander.h>                                  //   Подключаем библиотеку для работы с расширителем выводов.
iarduino_I2C_Expander gpio(0x09);                                   //   Объявляем объект gpio для работы с функциями и методами библиотеки iarduino_I2C_Expander, указывая адрес модуля на шине I2C.
                                                                    //   Если объявить объект без указания адреса (iarduino_I2C_Expander gpio;), то адрес будет найден автоматически.
void setup(){                                                       //
    Serial.begin(9600);                                             //   Инициируем передачу данных в монитор последовательного порта на скорости 9600 бит/сек.
    while(!Serial){;}                                               // * Ждём завершения инициализации шины UART.
    delay(500);                                                     // * Ждём завершение переходных процессов связанных с подачей питания.
//  Готовим модуль к работе:                                        //
    gpio.begin(&sWire);                                             //   Инициируем работу с расширителем выводов, указав ссылку на объект для работы с шиной I2C на которой находится расширитель (по умолчанию &Wire).
    gpio.pinMode(4, INPUT, ANALOG);                                 // * Конфигурируем вывод 4 на работу в качестве аналогового входа.
}                                                                   //
                                                                    //
void loop(){                                                        //
    uint16_t pin4 = gpio.analogRead(4);                             //   Читаем аналоговый уровень с вывода №4 в переменную «pin4».
    Serial.println((String) "Pin_4="+pin4 );                        //
    delay(100);                                                     // * Ждём пол десятую долю секунды, чтоб не захламлять монитор последовательного порта.
}                                                                   //
                                                                    //
//  ПРИМЕЧАНИЕ:                                                     //
//  Для проверки работы скетча подключите потенциометр к 4 выводу.  //
//  Аналоговый уровень считывается из АЦП модуля и может принимать  //
//  значение от 0 (0В) до 4095 (3,3В).                              //
//  По умолчанию, значения АЦП усредняются, это подавляет скачки    //
//  показаний но увеличивает их инерционность, для отключения       //
//  или изменения усреднения обратитесь к функции analogAveraging() //