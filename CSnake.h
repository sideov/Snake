/*
 * (c) Cranium, aka Череп. 2014
 * GNU GPL
 *
 */

#ifndef __CSNAKE_H__
#define __CSNAKE_H__

#include <vector>

#include "SCoord.h"
#include "CScreen.h"

using namespace std;

typedef vector<SCoord> CoordVector;

class CSnake {
public:
    CSnake();
    void reset(SCoord start_pos);                   // "сброс" змеи
    void draw(CScreen& scr);                        // первичная отрисовка змеи на экране
    void move(const SCoord& delta, CScreen& scr);   // передвижение змеи на приращение координат
    void grow(const SCoord& pos, int growbits);     // увеличение длины змеи
    bool into(const SCoord& pos);                   // проверка попадания координаты в тело змеи
    SCoord head();                                  // метод возвращает координаты головы змеи
    int size();                                     // метод возвращает длину змеи

private:
    CoordVector worm;       // вектор координат сегментов тела змеи
    char head_mark;         // символ, которым отрисовывается голова змеи
    unsigned int drawn;     // длина отрисованного тела змеи
};

#endif // __CSNAKE_H__
