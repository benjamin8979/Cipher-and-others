#include "prog3.h"


// This function takes 3 integers and adds them together.
// If a NULL pointer is given, it does not
// sum the integers.
void sum3(int a, int b, int c, int *sum)
{
	int d = 0;
	if (!sum)
		sscanf("0", "%d", &d);	
	else
		*sum = a + b + c;
}

void testSum3(void)
{
	// Test Case #1
	int sum = 0;
	sum3(5, 8, 19, &sum);
	assert(sum == 32);

	// Test Case #2
	sum3(-5, 20, 0, &sum);
	assert(sum == 15);
	
	// Test Case #3
	sum3(14, 17, 18, NULL);

	fprintf(stderr, "testSum3(): All test cases passed!\n");
}


// This function compares 2 float arrays.
// If the arrays are the same it returns 1.
// If they are different it tells the last place
// that they differ and returns 0.
// If a NULL pointer is given,
// it returns -1.
int compareArrays(float *arr1, float *arr2, int arrLen, int *pos)
{ 
	if (!arr1 || !arr2 || !pos)
		return -1;
	for (int i = arrLen-1; i >= 0; --i)
	{
		if (arr1[i] != arr2[i])
		{
			*pos = i;
		}
		if (arr1[i] != arr2[i])
		{
			return 0;
		}
	}
	for (int i = 0; i < arrLen; ++i)
	{
		if (arr1[i] == arr2[i])
		{
			*pos = -1;
			return 1;
		}
	}
	return 0;
}


void testCompareArrays(void)
{
	// Test Case #1
	float arr1[] = {4.2, 2.4, -0.001, 0.0};
	float arr2[] = {4.2, 2.4, -0.001, 0.0};
	int pos = -2;
	assert(compareArrays(arr1, arr2, 4, &pos) == 1);

	// Test Case #2
	float arr3[] = {2.34, 4, 1.0};
	float arr4[] = {2.34, 4, 1.0};
	pos = 100;
	compareArrays(arr3, arr4, 3, &pos);
	assert(pos == -1);

	// Test Case #3
	float arr5[] = {3.14};
	float arr6[] = {-2.01};
	pos = -8;
	assert(compareArrays(arr5, arr6, 1, &pos) == 0);

	// Test Case #4
	float arr7[] = {4.5};
	float arr8[] = {3.0};
	pos = 19;
	compareArrays(arr7, arr8, 1, &pos);
	assert(pos == 0);

	// Test Case #5
	float arr9[] = {5.5, 6.6, 7.7};
	float arr10[] = {5.5, 6.6, 8.8};
	pos = 21;
	assert(compareArrays(arr9, arr10, 3, &pos) == 0);

	// Test Case #6
	float arr11[] = {21, 3.3, 1.2};
	float arr12[] = {21, 3.3, -7.8};
	pos = -3;
	compareArrays(arr11, arr12, 3, &pos);
	assert(pos == 2);

	// Test Case #7
	float arr13[] = {3.2, -4, 1, 7.3};
	float arr14[] = {3.2, -5, 1, 3.7};
	pos = 33;
	assert(compareArrays(arr13, arr14, 4, &pos) == 0);

	// Test Case #8
	float arr15[] = {3.2, -4, 1, 7.3, 3.3, 6.1};
	float arr16[] = {3.2, -5, 1, 3.7, 3.3, 1.6};
	pos = -59;
	compareArrays(arr15, arr16, 6, &pos);
	assert(pos == 5);

	// Test Case #9
	float arr17[] = {1, 2, 3};
	pos = 5;
	assert(compareArrays(NULL, arr17, 3, &pos) == -1);

	// Test Case #10
	float arr18[] = {3, 2, 1};
	pos = -2;
	assert(compareArrays(arr18, NULL, 3, &pos) == -1);

	// Test Case #11
	float arr19[] = {4, 5, 6};
	float arr20[] = {4, 5, 6};
	assert(compareArrays(arr19, arr20, 3, NULL) == -1);

	fprintf(stderr, "testCompareArrays(): All test cases passed!\n");
}



// This function deciphers or enciphers
// a message by shifting the letters in the
// message k places in the alphabet.
// If the input is valid it returns 1.
// If it is invalid it returns 0.
int performShiftCipher(char *inputText, int k, char *outputText)
{
	if (!inputText || !outputText || k > MAX_SHIFT_CIPHER_KEY || k < -MAX_SHIFT_CIPHER_KEY)
		return 0;
	int len = strlen(inputText);
	for (int i = 0; i < len; ++i)
	{
		char ch = inputText[i];
		if (isalpha(ch))
		{
			int val = (ch + k);
			if (k >= 0)
			{
				if(isupper(ch))
				{
					if ((val - 'Z') > ALPHABET_SIZE)
					{
						while ((val - ALPHABET_SIZE) > 'Z')
							val = val - ALPHABET_SIZE;
						val = val - ALPHABET_SIZE;
						outputText[i] = val;
					}
					else if (val > 'Z')
					{
						val = val - ALPHABET_SIZE;
						outputText[i] = val;
					}	
					else
					{
						outputText[i] = val;
					}
				}
				else if (val > 'z')
				{
					if ((val - 'z') > ALPHABET_SIZE)
					{
						while ((val - ALPHABET_SIZE) > 'z')
							val = val - ALPHABET_SIZE;
					}
					val = val - ALPHABET_SIZE;
					outputText[i] = val;
				}
				else
				{
				outputText[i] = ch + k;
				}
			}
			else if (k < 0)
			{
				if(isupper(ch))
				{
					if (('A' - val) > ALPHABET_SIZE)
					{
						while((val + ALPHABET_SIZE) < 'A')
							val = val + 26;
						val = val + 26;
						outputText[i] = val;
					}
					else if (val < 'A')
					{
						val = val + 26;
						outputText[i] = val;
					}
					else
					{
						outputText[i] = ch + k;
					}
				}
				else if(islower(ch))
				{
					if (('a' - val) > 26)
					{
						while((val + 26) < 'a')
							val = val + 26;
						val = val + 26;
						outputText[i] = val;
					}
					else if (val < 'a')
					{
						val = val + 26;
						outputText[i] = val;
					}
					else
					{
						outputText[i] = ch + k;
					}
				}

			}
		}	
		else
			outputText[i] = ch;
	}
	outputText[len] = '\0';
	return 1;
}

void testPerformShiftCipher(void)
{
	// Test Case #1
	char plainText1[] = "Hello";
	char cipherText1[100];
	assert(performShiftCipher(plainText1, 5, cipherText1) == 1);

	// Test Case #2
	char str1[] = "Mjqqt";
	performShiftCipher(plainText1, 5, cipherText1);
	assert(strcmp(str1, cipherText1) == 0);	

	// Test Case #3
	char str2[] = "Mjqqt, kwnjsi!";
	char plainText2[] = "Hello, friend!";
	char cipherText2[100];
	performShiftCipher(plainText2, 5, cipherText2);
	assert(strcmp(str2, cipherText2) == 0);

	// Test Case #4
	char str3[] = "$Mm$";
	char plainText3[] = "$Bb$";
	char cipherText3[100];
	performShiftCipher(plainText3, 11, cipherText3);
	assert(strcmp(str3, cipherText3) == 0);

	// Test Case #5
	char str4[] = "TlT #8";
	char plainText4[] = "WoW #8";
	char cipherText4[100];
	performShiftCipher(plainText4, -3, cipherText4);
	assert(strcmp(str4, cipherText4) == 0);

	// Test Case #6
	char str5[] = "w1x2Y3&";
	char plainText5[] = "a1b2C3&";
	char cipherText5[100];
	performShiftCipher(plainText5, -30, cipherText5);
	assert(strcmp(str5, cipherText5) == 0);

	// Test Case #7
	char str6[] = "iehuxm@23F";
	char plainText6[] = "cyborg@23Z";
	char cipherText6[100];
	performShiftCipher(plainText6, 6, cipherText6);
	assert(strcmp(str6, cipherText6) == 0);

	// Test Case #8 
	char str7[] = "99xyw0 XYX!";
	char plainText7[] = "99nom0 NON!";
	char cipherText7[100];
	performShiftCipher(plainText7, 10, cipherText7);
	assert(strcmp(str7, cipherText7) == 0);

	// Test Case #9
	char cipherText8[100];
	assert(performShiftCipher(NULL, 3, cipherText8) == 0);

	// Test Case #10
	char plainText8[] = "4cboboBt";
	assert(performShiftCipher(plainText8, 1, NULL) == 0);

	// Test Case #11
	char plainText9[] = "X2J hr GDQD!";
	char cipherText9[100];
	assert(performShiftCipher(plainText9, 600, cipherText9) == 0);

	// Test Case #12
	char plainText10[] = "jvsk";
	char cipherText10[100];
	assert(performShiftCipher(plainText10, -600, cipherText10) == 0);

	// Test Case #13
	char str11[] = "!@#$%^&*";
	char plainText11[] = "!@#$%^&*";
	char cipherText11[100];
	performShiftCipher(plainText11, 24, cipherText11);
	assert(strcmp(str11, cipherText11) == 0);

	// Test Case #14
	char str12[] = "1234";
	char plainText12[] = "1234";
	char cipherText12[100];
	performShiftCipher(plainText12, 12, cipherText12);
	assert(strcmp(str12, cipherText12) == 0);

	// Test Case #15
	char str13[] = "1@3$5Pp";
	char plainText13[] = "1@3$5Ww";
	char cipherText13[100];
	performShiftCipher(plainText13, -7, cipherText13);
	assert(strcmp(str13, cipherText13) == 0);

	// Test Case #16
	char str14[] = " T C E G E C T ";
	char plainText14[] = " R A C E C A R ";
	char cipherText14[100];
	performShiftCipher(plainText14, 54, cipherText14);
	assert(strcmp(str14, cipherText14) == 0);

	// Test Case #17
	char str15[] = "alPHa";
	char plainText15[] = "alPHa";
	char cipherText15[100];
	performShiftCipher(plainText15, 26, cipherText15);
	assert(strcmp(str15, cipherText15) == 0);

	fprintf(stderr, "testPerformShiftCipher(): All test cases passed!\n");
}
