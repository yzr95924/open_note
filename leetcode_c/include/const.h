/**
 * @file const.h
 * @author Zuoru YANG (zryang@cse.cuhk.edu.hk)
 * @brief https://leetcode.cn/problems/two-sum/
 * @version 0.1
 * @date 2023-01-30
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef LEETCODE_C_CONST_H
#define LEETCODE_C_CONST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <limits.h>

#define MIN(a,b) (((a) <= (b)) ? (a) : (b))
#define MAX(a,b) (((a) >= (b)) ? (a) : (b))

int** ConvertTwoDemArrayToPtr(int* startPos, int size, int* itemSize) {
    int** ret = NULL;
    ret = (int**)calloc(size, sizeof(int*));
    int curIdx = 0;

    for (int i = 0; i < size; i++) {
        ret[i] = (int*)calloc(itemSize[i], sizeof(int));
        for (int j = 0; j < itemSize[i]; j++) {
            ret[i][j] = startPos[curIdx];
            curIdx++;
        }
    }

    return ret;
}

uint8_t** ConvertFixedTwoArrayToPtr(uint8_t* startPtr, size_t rowCnt,
    size_t colCnt, size_t itemByteSize) {
    uint8_t** retPtr = NULL;
    retPtr = (uint8_t**)malloc(rowCnt * sizeof(uint8_t*));

    size_t readByteOffset = 0;

    for (size_t i = 0; i < rowCnt; i++) {
        retPtr[i] = (uint8_t*)malloc(colCnt * itemByteSize);
        for (size_t j = 0; j < colCnt; j++) {
            memcpy(&retPtr[i][j * itemByteSize], startPtr + readByteOffset, itemByteSize);
            readByteOffset += itemByteSize;
        }
    }

    return retPtr;
}

void FreeFixedTwoArray(uint8_t** inputArray, size_t rowCnt) {
    for (int i = 0; i < rowCnt; i++) {
        free(inputArray[i]);
    }
    free(inputArray);
    return ;
}

void FreeTwoDemArray(int** inputArray, int size) {
    for (int i = 0; i < size; i++) {
        free(inputArray[i]);
    }
    free(inputArray);
    return ;
}

uint64_t GetFactorial(int inputVal) {
    uint64_t ret = 1;
    for (int i = inputVal; i > 0; i--) {
        ret *= i;
    }

    return ret;
}

#endif