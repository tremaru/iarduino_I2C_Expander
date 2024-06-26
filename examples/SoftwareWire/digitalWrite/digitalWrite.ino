// ДАННЫЙ ПРИМЕР МЕНЯЕТ ЛОГИЧЕСКИЕ УРОВНИ НА ВЫВОДЕ МОДУЛЯ:         // * Строки со звёздочкой являются необязательными.
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
    gpio.pinMode(7, OUTPUT, DIGITAL);                               // * Конфигурируем вывод 7 на работу в качестве цифрового выхода.
}                                                                   //
                                                                    //
void loop(){                                                        //
    gpio.digitalWrite(7, HIGH);                                     //   Устанавливаем высокий логический уровень на выводе 7.
    delay(500);                                                     //   Ждём пол секунды.
    gpio.digitalWrite(7, LOW);                                      //   Устанавливаем низкий логический уровень на выводе 7.
    delay(500);                                                     //   Ждём пол секунды.
}                                                                   //
                                                                    //
//  ПРИМЕЧАНИЕ:                                                     //
//  Для проверки работы скетча подключите светодиод к 7 выводу.     //

