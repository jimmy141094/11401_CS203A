/*
   ========================================
   hash_fn.c — implement your hash functions
   ========================================

   Description:
    This file contains the hash functions for integer and string keys.

   Development History:
    - 2025/11/17: Initial implementation
    - 2025/11/24: Complete a C language program using C++ methods.

   Developer: Chen-Yao-Xiang <jimmy141094@gmail.com>
 */

#include "hash_fn.h"

int myHashInt(int key, int m) {
    unsigned int ukey = (unsigned int)key;
    ukey *= 6813;
    ukey += ukey / 3;
    ukey += ukey % 7;
    return key % m;  // division method example
}

int myHashString(const char* str, int m) {
    unsigned long hash = 0;
    const int p = 41;
    size_t len = strlen(str);
    for (size_t i = 0; i < len; i++) {
        char c = str[i];
        hash = (hash * p) + c;
    }
    return (int)(hash % m); // basic division method
}