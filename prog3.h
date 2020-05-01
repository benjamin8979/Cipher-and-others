#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define ALPHABET_SIZE 26
#define MAX_SHIFT_CIPHER_KEY 500

void sum3(int a, int b, int c, int *sum);
void testSum3(void);
int compareArrays(float *arr1, float *arr2, int arrLen, int *pos);
void testCompareArrays(void);
int performShiftCipher(char *inputText, int k, char *outputText);
void testPerformShiftCipher(void);
