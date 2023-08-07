#include <iostream>
#include <vector>
#define MAX_SIZE 15
using namespace std;

void generateBinaryVector(int maxNumber, int length, vector<string>* numbers);
int calculateMaxProfit(int* payments, int* weights, int maxMass, int size, vector<string> numbers);
string toBinaryNumber(int number, int length);

int main()
{   
    int* payments = new int[MAX_SIZE];
    int* weights = new int[MAX_SIZE];
    vector<string> binaryNumbers;

    int n, maxMass;

    // reading number of items
    while (cin >> n) {
        binaryNumbers.clear();
        generateBinaryVector(pow(2, n) - 1, n, &binaryNumbers);

        for (int i = 0; i < n; i++) {
            cin >> payments[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> weights[i];
        }

        cin >> maxMass;
        cout << calculateMaxProfit(payments, weights, maxMass, n, binaryNumbers) << endl;
    }

    delete[] payments;
    delete[] weights;
}

// generating all possible binary strings with specified length
void generateBinaryVector(int maxNumber, int length, vector<string>* numbers) {

    string binaryNumber;
    
    // we start with the greatest possible number
    while (maxNumber) {
        binaryNumber = toBinaryNumber(maxNumber, length);
        numbers->push_back(binaryNumber);
        maxNumber--;
    }

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

// checking all options from vector and return the highest possible profit
int calculateMaxProfit(int* payments, int* weights, int maxMass, int size, vector<string> numbers) {
    int totalWeight, totalPayment, maxPayment = 0;
    string sequence;
    // check each combination of items
    // 1 if we should take this item, 0 if not
    for (size_t i = 0; i < numbers.size(); i++) {
        totalWeight = 0; totalPayment = 0;
        sequence = numbers[i];
        for (int j = 0; j < size; j++) {
            if (sequence[j] == '1') {
                totalWeight += weights[j];
                totalPayment += payments[j];
            }
        }
        if (totalPayment > maxPayment && totalWeight <= maxMass) {
            maxPayment = totalPayment;
        }
    }
    
    return maxPayment;
}