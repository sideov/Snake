/*
 * (c) Cranium, aka Череп. 2014
 * GNU GPL
 *
 */

#include "SCoord.h"

SCoord& SCoord::operator +=(const SCoord& op) {
    x += op.x;
    y += op.y;
    return *this;
}

SCoord operator +(const SCoord& op1, const SCoord& op2) {
    return SCoord(op1.x + op2.x, op1.y + op2.y);
}

SCoord operator -(const SCoord& op1, const SCoord& op2) {
    return SCoord(op1.x - op2.x, op1.y - op2.y);
}

SCoord operator *(const SCoord& op1, const int& op2) {
    return SCoord(op1.x * op2, op1.y * op2);
}



bool operator ==(const SCoord& op1, const SCoord& op2) {
    return op1.x == op2.x && op1.y == op2.y;
}
