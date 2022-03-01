/*
 * (c) Cranium, aka Череп. 2014
 * GNU GPL
 *
 */

#ifndef __SCOORD_H__
#define __SCOORD_H__

struct SCoord {
    int x, y;
    SCoord() : x(0), y(0) {}
    SCoord(int _x, int _y) : x(_x), y(_y) {}
    SCoord& operator +=(const SCoord& op);
};

SCoord operator +(const SCoord& op1, const SCoord& op2);
bool operator ==(const SCoord& op1, const SCoord& op2);

#endif // __SCOORD_H__
