// Copyright 2022 UNN-IASR
#include "fun.h"
#include <Math.h>

unsigned int faStr1(const char* str) {
    bool inWord = false, isGoodWord = true;
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ' && !inWord)
            inWord = true;
        if (str[i] >= '0' && str[i] <= '9' && inWord && isGoodWord)
            isGoodWord = false;
        if (str[i] == ' ' && inWord) {
            if (isGoodWord)
                count++;
            inWord = false;
            isGoodWord = true;
        }
    }
    if (inWord && isGoodWord)
        count++;
    return count;
}

unsigned int faStr2(const char *str) {
    bool inWord = false, isGoodWord = true;
    int count = 0, firstLetterGood = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ' && !inWord)
            inWord = true;
        if (str[i] >= 'A' && str[i] <= 'Z' && inWord && firstLetterGood == 0) {
            firstLetterGood = 1;
            continue;
        }
        if (str[i] >= 33 && str[i] <= 64 && inWord && isGoodWord)
            isGoodWord = false;
        if (str[i] >= 'A' && str[i] <= 'Z' && firstLetterGood == 1)
            firstLetterGood = 2;
        if (str[i] == ' ' && inWord) {
            if (isGoodWord && firstLetterGood == 1)
                count++;
            inWord = false;
            isGoodWord = true;
            firstLetterGood = 0;
        }
    }
    if (inWord && isGoodWord && firstLetterGood == 1)
        count++;
    return count;
}

unsigned int faStr3(const char *str) {
    bool lastWasLetter = false;
    int wordsCount = 0, lettersCount = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            lastWasLetter = true;
            lettersCount++;
        }
        if (str[i] == ' ' && lastWasLetter) {
            wordsCount++;
            lastWasLetter = false;
        }
    }
    if (lastWasLetter)
        wordsCount++;
    return round(lettersCount / wordsCount);
}
