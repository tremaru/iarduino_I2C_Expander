// ДАННЫЙ ПРИМЕР ПОЗВОЛЯЕТ КОНФИГУРИРОВАТЬ ВЫВОДЫ:                  // * Строки со звёздочкой являются необязательными.
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
    gpio.pinMode(0, OUTPUT, DIGITAL);                               // * Конфигурируем вывод 0 на работу в качестве цифрового выхода.
    gpio.pinMode(1, OUTPUT, ANALOG );                               // * Конфигурируем вывод 1 на работу в качестве аналогового выхода.
    gpio.pinMode(2, OUTPUT, SERVO  );                               // * Конфигурируем вывод 2 на работу в качестве выхода для сервопривода.
    gpio.pinMode(3, INPUT , DIGITAL);                               // * Конфигурируем вывод 3 на работу в качестве цифрового входа.
    gpio.pinMode(4, INPUT , ANALOG );                               // * Конфигурируем вывод 4 на работу в качестве аналогового входа.
    gpio.pinPull(3, PULL_DOWN);                                     // * Прижимаем вывод 3 к уровню GND через внутренний резистор.
}                                                                   //
                                                                    //
void loop(){                                                        //
    bool     d = gpio.digitalRead(3);                               //   Читаем логический уровень со входа 3 в переменную «d» (значение LOW или HIGH).
    uint16_t a = gpio.analogRead(4);                                //   Читаем аналоговый уровень со входа 4 в переменную «a» (значение от 0 до 4095).
    gpio.digitalWrite(0, d);                                        //   Устанавливаем на 0 выходе логический уровень из переменной «d».
    gpio.analogWrite(1, a);                                         //   Устанавливаем на 1 выходе аналоговый уровень из переменной «a».
    gpio.servoWrite(2, map(a,0,4095,0,180));                        //   Поворачиваем сервопривод на угол пропорциональный значению переменной a.
}                                                                   //
                                                                    //
//  ПРИМЕЧАНИЕ:                                                     //
//  Для проверки работы скетча подключите:                          //
//  • к выводу 0 - светодиод.                                       //
//  • к выводу 1 - светодиод.                                       //
//  • к выводу 2 - сервопривод.                                     //
//  • к выводу 3 - кнопку.                                          //
//  • к выводу 4 - потенциометр.                                    //
//  При нажатии на кнопку - будет светиться светодиод подключённый  //   Сигналы ШИМ поддерживают только выводы 0,1,2,3, а значит только эти выводы
//  к выводу 0, а поворот потенциометра приведёт к повороту сервы и //   можно сконфигурировать в качестве аналоговых выходов или для сервоприводов.
//  изменению яркости свечения второго светодиода.                  //
//  Функция pinMode() в данной библиотеке является необязательной!  //
//  Если закомментировать все строки с функцией pinMode(), то,      //
//  например, при первом обращении к функции gpio.analogWrite(1, a) //
//  библиотека «поймёт» что вывод нужно переконфигурировать в режим //
//  аналогового выхода и сделает это за Вас. Но это значит что      //
//  первое обращение к функции gpio.analogWrite(1,a) займёт немного //
//  больше времени, чем остальные обращения к этой функции.         //
//  Допускается вызывать функцию pinMode() указав только 1 аргумент //
//  (направление INPUT/OUTPUT) тогда тип вывода останется без изм.  //
//  При конфигурировании хотя бы одного вывода на работу с серво,   //
//  частота ШИМ на всех выводах поддерживающих ШИМ упадёт до 50 Гц. //
//  Значит в данном примере на первом выводе формируется сигнал ШИМ //
//  с заданным уровнем из переменной «a», с частотой всего 50 Гц.   //

