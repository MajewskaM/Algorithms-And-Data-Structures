#include <iostream>
#include <math.h>
#include <string>

using namespace std;

int checkSymmetry(string number);
string toBinaryNumber(int number, int length);
void recursiveSearching(int maxNumber, int length);

int main()
{
	int bitsNumber, maxNumber;
	while (cin >> bitsNumber) {
		maxNumber = pow(2, bitsNumber) - 1;
		recursiveSearching(maxNumber, bitsNumber);
	}
		
	return 0;
}

// checks if number passed as a string is palindrome
int checkSymmetry(string number) {

	int i = 0, j = number.size() - 1;

	for (i, j; i < j; i++, j--) {
		// comparision of first and last letter
		if (number[i] != number[j]) return 0;
	}
	return 1;

}

// return given number as string - its binary representation
string toBinaryNumber(int number, int length) {
	int x;
	string inBinary = "";

	// generating number using bit shifts
	for (int b = length - 1; b >= 0; b--) {
		x = ((number & (1U << b)) >> b);
		inBinary += char('0' + x);
	}

	return inBinary;
}

// searching for numbers that are palindromes in recursive way
void recursiveSearching(int maxNumber, int length) {

	string bits;

	if (maxNumber >= 1) {

		bits = toBinaryNumber(maxNumber, length);
		if (checkSymmetry(bits)) {
			cout << bits;
		}
		recursiveSearching(maxNumber - 1, length);
	}
	else {
		// 0 written in binary system is always symmetric!
		bits = toBinaryNumber(maxNumber, length);
		cout << bits << endl;

	}

}