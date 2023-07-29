#include <iostream>
using namespace std;

// left shift operator generally multiplies by 2 (small numbers case).

// right shift operator generally divides by 2 (small numbers case).

int getBit(int n, int pos) {
/*
    For Example: n = 5 (0101)
    pos = 2 (works in reverse order ...3210)

    so, 1 << 2 is 0100
    and, 0101 & 0100 = 0100 means got 2nd bit & every other bit is 0.
*/
    return (n & (1 << pos));
}

int setBit(int n, int pos) { //  add 1 to the position
/*
    For Example: n = 3 (0011)
    pos = 2 (works in reverse order ...3210)

    so, 1 << 2 is 0100
    and, 0011 | 0100 = 0111 means set 2nd bit.
*/
    return (n | (1 << pos));
}

int clearBit(int n, int pos) {
/*
    For Example: n = 5 (0101)
    pos = 2 (works in reverse order ...3210)

    so, 1 << 2 is 0100
    do the masking, means ~0100 = 1011
    and, 0101 & 1011 = 0001 means cleard 2nd bit.
*/
    int mask = ~(1<<pos);
    return n & mask;
}

int updateBit(int n, int pos, int value) {
    // update is clearBit and then setBit
    n = clearBit(n, pos);
    return (n | (value << pos));
}