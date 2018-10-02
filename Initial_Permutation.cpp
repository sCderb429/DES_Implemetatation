//
// Created by Scott Derbes on 9/27/18.
//

#include "Initial_Permutation.h"


Initial_Permutation::Initial_Permutation() {

}

Initial_Permutation::Initial_Permutation(int hexInputOne, int hexInputTwo) {
    hexOne = hexInputOne;
    hexTwo = hexInputTwo;
}

void Initial_Permutation::hexToBin() {
    std::bitset<8> holder;
    int divisor = 0x1000000;

    for(int i = 0; i < 4; i++){
        holder = hexOne / divisor;//Gets the two digits of hexOne to become binary
        hexOne %= divisor;
        Initial_Permutation::splitter(holder);
        divisor /= 0x100;
    }

    divisor = 0x1000000;

    for(int j = 0; j < 4; j++){
        holder = hexTwo / divisor; //Gets the two digits of hexTwo to become binary
        hexTwo %= divisor;
        std::cout << holder << "\n"; //Why is this one higher than it needs to be?
        Initial_Permutation::splitter(holder);
        divisor /= 0x100;
    }

}

void Initial_Permutation::splitter(std::bitset<8> splitBin) {
    int bit;
    for (int i = 0; i < 8; ++i) {
        bit = splitBin[i];
        singleBin[counter] = bit;
        counter++;
    }
}

void Initial_Permutation::initialTable() {
    int i = 0;
    int j = 0;
    std::bitset<1> bit;
    std::bitset<1> array[i][j];

    auto counter = 1;
    for ( i = 0; i < 8; ++i) {
        for (j = 0; j < 8; ++j) {
            bit = singleBin[counter];
            array[i][j] = bit;
            std::cout<< array[i][j];
            counter++;
        }
    }
    //Initial_Permutation::permutationTable();

}

void Initial_Permutation::permutationTable() {
    std::bitset<1> *row;
    std::bitset<1> *col;
    std::bitset<1> bit;
    for (int i = 0; i < 46; i += 6) {
        bit = singleBin[i];
        row[i] = bit;
        bit = singleBin[i + 8];
        row[i + 1] = bit;
        for (int j = 0; j < 4; ++j) {
            bit = singleBin[i + j];
            col[j] = bit;
        }
    }
}

void Initial_Permutation::binToHex() {

}



