//
// Created by Scott Derbes on 9/27/18.
//

#ifndef DES_IMPLEMETATATION_INITIAL_PERMUTATION_H
#define DES_IMPLEMETATATION_INITIAL_PERMUTATION_H

#include <iostream>
#include <bitset>
#include <string>
#include <sstream>

class Initial_Permutation {
private:
   int hexOne, hexTwo;//Initial hex before it has been converted
   std::string binOne, binTwo;
   int counter = 1;
   std::bitset<1> singleBin[64];
   std::bitset<1> permutation[64];
public:
    Initial_Permutation();
    Initial_Permutation(int hexInputOne, int hexInputTwo);
    void hexToBin();
    void splitter(std::bitset<8> splitBin);
    void permutationTable();
    void binToHex();
    void joinBits();
    void stringToBit();
};


#endif //DES_IMPLEMETATATION_INITIAL_PERMUTATION_H
