/*
 * Project: DES_Implementation
 * File: main.cpp
 * Purpose:
 * Author: Scott Derbes
 */
#include <iostream>
#include <bitset>
#include "Initial_Permutation.h"

//0x3a456b73 0xe24d2537
int main() {
    Initial_Permutation hex1(0x3a456b73, 0xE24d2537);
    hex1.hexToBin();
    hex1.permutationTable();
    //hex1.initialTable();

    return 0;
}


/*
int initArray[8][8] = {{58, 50, 42, 34, 26, 18, 10, 2},
                       {60, 52, 44, 36, 28, 20, 12, 4},
                       {62, 54, 46, 38, 30, 22, 14, 6},
                       {64, 56, 48, 40, 32, 24, 16, 8},
                       {},
                       {},
                       {},
                       {},
};
*/