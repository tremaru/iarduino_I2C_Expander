// ДАННЫЙ ПРИМЕР МЕНЯЕТ АДРЕС МОДУЛЯ НА УКАЗАННЫЙ В NEWADDRESS:     // * Строки со звёздочкой являются необязательными.
// Требуется установить библиотеку <iarduino_I2C_Software.h>        //   https://iarduino.ru/file/627.html
                                                                    //
// Расширитель выводов, FLASH-I2C (Trema-модуль):                   //   https://iarduino.ru/shop/Expansion-payments/rasshiritel-vyvodov-i2c---flash-trema-modul.html
// Информация о подключении модулей к шине I2C:                     //   https://wiki.iarduino.ru/page/i2c_connection/
// Информация о модуле и описание библиотеки:                       //   https://wiki.iarduino.ru/page/trema-expander/
                                                                    //
// Данный скетч демонстрирует не только возможность смены адреса    //
// на указанный в переменной newAddress, но и обнаружение, и вывод  //
// текущего адреса модуля на шине I2C.                              //
                                                                    //
// Библиотека <iarduino_I2C_Expander.h> предназначена для работы с  //
// расширителями выводов и меняет только их адреса.                 //
// Но, в разделе Файл/Примеры/.../findSortDevices находятся примеры //
// смены и сортировки адресов любых модулей iarduino серии FlashI2C.//
                                                                    //
uint8_t newAddress = 0x09;                                          //   Назначаемый модулю адрес (0x07 < адрес < 0x7F).
                                                                    //
#include <iarduino_I2C_Software.h>                                  //   Подключаем библиотеку для работы с программной шиной I2C, до подключения библиотеки iarduino_I2C_Expander.
SoftTwoWire sWire(3,4);                                             //   Создаём объект программной шины I2C указав выводы которым будет назначена роль линий: SDA, SCL.
                                                                    //
#include <iarduino_I2C_Expander.h>                                  //   Подключаем библиотеку для работы с расширителем выводов.
iarduino_I2C_Expander gpio;                                         //   Объявляем объект gpio для работы с функциями и методами библиотеки iarduino_I2C_Expander.
                                                                    //   Если при объявлении объекта указать адрес, например, gpio(0xBB), то пример будет работать с тем модулем, адрес которого был указан.
void setup(){                                                       //
    Serial.begin(9600);                                             //
    while(!Serial){;}                                               // * Ждём завершения инициализации шины UART.
    delay(500);                                                     // * Ждём завершение переходных процессов связанных с подачей питания.
    if( gpio.begin(&sWire) ){                                       //   Инициируем работу с расширителем выводов, указав ссылку на объект для работы с шиной I2C на которой находится расширитель (Wire, Wire1, Wire2 ...).
        Serial.print("На шине I2C найден модуль с адресом 0x");     //
        Serial.print( gpio.getAddress(), HEX );                     //   Выводим текущий адрес модуля.
        Serial.print(" который является расширителем выводов\r\n"); //
        if( gpio.changeAddress(newAddress) ){                       //   Меняем адрес модуля на newAddress.
            Serial.print("Адрес модуля изменён на 0x");             //
            Serial.println( gpio.getAddress(), HEX );               //   Выводим текущий адрес модуля.
        }else{                                                      //
            Serial.println("Адрес модуля изменить не удалось!");    //
        }                                                           //
    }else{                                                          //
        Serial.println("Расширитель выводов не найден!");           //
    }                                                               //
}                                                                   //
                                                                    //
void loop(){                                                        //
}                                                                   //
