/*
   ========================================
   hash_fn.cpp — implement your hash functions
   ========================================

   Description:
    This file contains the hash functions for integer and string keys.

   Development History:
    - 2025/11/17: Initial implementation
    - 2025/11/18: add myhashint Since the last digit is the same, 
    making only ordinary changes within 30 cycles will still result
     in the same outcome. Therefore, we need to disrupt its pattern 
     by adding the first few digits and the remainders.
    - 2025/11/24:Perform string hash calculations using a base-41 base-1000 
    system to obtain a hash number, which is used for quick string comparison.
   Developer: Chen-Yao-Xiang <jimmy141094@gmail.com>
 */
#include "hash_fn.hpp"

int myHashInt(int key, int m) {
    unsigned int ukey = (unsigned int)key;
    ukey*=6813;
    ukey+=ukey/3;
    ukey+=ukey%7;
    return ukey % m;
}

int myHashString(const std::string& str, int m) {
    unsigned long hash = 0;
    const int p = 41;
    for (size_t i = 0; i < str.length(); ++i) {
        char c = str[i];
        hash = (hash * p) + c; 
    }
    return static_cast<int>(hash % m);  // basic division method
}