// ДАННЫЙ ПРИМЕР ПОЗВОЛЯЕТ УСТАНАВЛИВАТЬ УГОЛ СЕРВОПРИВОДА:         // * Строки со звёздочкой являются необязательными.
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
    delay(500);                                                     // * Ждём завершение переходных процессов связанных с подачей питания.
//  Готовим модуль к работе:                                        //
    gpio.begin(&sWire);                                             //   Инициируем работу с расширителем выводов, указав ссылку на объект для работы с шиной I2C на которой находится расширитель (по умолчанию &Wire).
    gpio.pinMode(3, OUTPUT, SERVO);                                 // * Конфигурируем вывод 3 на работу в качестве выхода для сервопривода.
}                                                                   //
                                                                    //
void loop(){                                                        //
    gpio.servoWriteMicroseconds(3, 500);                            //   Подаём на сервопривод ШИМ с длительностью импульсов 500 мкс.
    delay(500);                                                     //   Ждём пол секунды.
    gpio.servoWriteMicroseconds(3, 1500);                           //   Подаём на сервопривод ШИМ с длительностью импульсов 1500 мкс.
    delay(500);                                                     //   Ждём пол секунды.
    gpio.servoWriteMicroseconds(3, 2500);                           //   Подаём на сервопривод ШИМ с длительностью импульсов 2500 мкс.
    delay(500);                                                     //   Ждём пол секунды.
}                                                                   //
                                                                    //
//  ПРИМЕЧАНИЕ:                                                     //
//  Для проверки работы скетча подключите сервопривод к 3 выводу.   //
//  Угол поворота сервоприводов зависит от длительности импульсов   //
//  подаваемого сигнала ШИМ. У большинства сервоприводов угол в 0°  //
//  соответствует длительности импульсов 500 мкс, а угол в 180°     //
//  соответствует длительности импульсов 2500 мкс.                  //
//  Если Вы не знаете соотношение длительности импульсов к углу     //
//  поворота Вашего сервопривода, функция servoWriteMicroseconds()  //
//  поможет Вам его найти, перебором значений длительностей.        //
//  Обращение к функции servoWriteMicroseconds() устанавливает      //
//  частоту ШИМ в 50 Гц на всех выводах поддерживающих ШИМ: 0,1,2,3 //
//  Значит если сконфигурировать любой другой вывод, поддерживающий //
//  ШИМ, на работу в качестве аналогового выхода, его сигнал так же //
//  снизится до 50 Гц.                                              //

