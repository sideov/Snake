/*
 * (c) Cranium, aka Череп. 2014
 * GNU GPL
 *
 */

#ifndef __CSCREEN_H__
#define __CSCREEN_H__

#include <windows.h>

/*
Класс исключения для класса CScreen
*/

class CSScreenException {
public:
    CSScreenException(int _err) : err(_err) {}
    const char *what();         // возвращает строку с описанием ошибки
    int err;                    // код ошибки
};

/*
Класс CScreen содержит системозависимые вызовы для вывода на консоль.

Данная реализация предназначена для ОС MS Windows 2000 Professional
и более поздних.

Система координат:
    (0, 0)  - левый верхний угол экрана
    ось X   - горизонтально вправо
    ось Y   - вертикально вниз (положительное направление)
*/

class CScreen {
public:
    CScreen();
    ~CScreen();
    void cursor_show(bool visible);                 // показать/скрыть курсор
    void text_attr(WORD attr);                      // установить цвет текста/фона
    void pos(int x, int y, char ch = 0);            // позиционирование курсора и
                                                    // вывод символа, если ch != 0
    void pos_str(int x, int y, const char *str);    // позиционирование курсора
                                                    // и вывод строки
    void cls();                                     // очистка экрана

private:
    HANDLE hConsoleOutput;
    CONSOLE_CURSOR_INFO oldCursorInfo, curCursorInfo;
    WORD oldTextAttr;
};

#endif // __CSCREEN_H__
