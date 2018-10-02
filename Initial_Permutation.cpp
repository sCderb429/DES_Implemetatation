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
        std::cout << holder ;
        Initial_Permutation::splitter(holder);
        divisor /= 0x100;
    }

    divisor = 0x1000000;

    for(int j = 0; j < 4; j++){
        holder = hexTwo / divisor; //Gets the two digits of hexTwo to become binary
        hexTwo %= divisor;
        std::cout << holder; //Why is this one higher than it needs to be?
        Initial_Permutation::splitter(holder);
        divisor /= 0x100;
    }
    std::cout << "\n";

}

void Initial_Permutation::splitter(std::bitset<8> splitBin) {
    int bit;
    for (int i = 0; i < 8; ++i) {
        bit = splitBin[i];
        singleBin[counter] = bit;
        counter++;
    }
}

void Initial_Permutation::permutationTable() {
    int findLocation;

    auto location = new int[64] {58, 50, 42, 34, 26, 18, 10, 2,
                                 60, 52, 44, 36, 28, 20, 12, 4,
                                 62, 54, 46, 38, 30, 22, 14, 6,
                                 64, 56, 48, 40, 32, 24, 16, 8,
                                 57, 49, 41, 33, 25, 17, 9,  1,
                                 59, 51, 43, 35, 27, 19, 11, 3,
                                 61, 53, 45, 37, 29, 21, 13, 5,
                                 63, 55, 47, 39, 31, 23, 15, 7 };

    for (int i = 0; i < 64; ++i) {
        findLocation = location[i];
        permutation[i] = singleBin[findLocation];
        std::cout << permutation[i];
    }
    std::cout << "\n";
}

void Initial_Permutation::binToHex() {

    Initial_Permutation::joinBits();
    Initial_Permutation::stringToBit();
}

void Initial_Permutation::joinBits() {
    std::bitset<1> holder;

    for (int i = 0; i < 32; ++i) {
        holder = permutation[i];
        binOne = binOne + holder.to_string();
    }

    for (int i = 32; i < 64; ++i) {
        holder = permutation[i];
        binTwo = binTwo + holder.to_string();
    }

    std::cout << binOne <<"\n";
    std::cout << binTwo <<"\n";
}

void Initial_Permutation::stringToBit() {
    std::bitset<32> holdOne(binOne);
    std::bitset<32> holdTwo(binTwo);

    std::stringstream ss;
    std::stringstream sp;
    std::string number;
    std::string number2;

    ss << std::hex << std::uppercase << holdOne.to_ullong();
    ss >> number;
    std::cout << number << "\n";

    sp << std::hex << std::uppercase << holdTwo.to_ullong();
    sp >> number2;
    std::cout << number2 << "\n \n";

}