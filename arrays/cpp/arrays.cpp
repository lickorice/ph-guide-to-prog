#include <iostream>

using namespace std;

int main() {
    // An array of 5 integers:
    int numbers[5];

    cin >> numbers[0];
    cin >> numbers[1];
    cin >> numbers[2];
    cin >> numbers[3];
    cin >> numbers[4];

    int index = 3;
    
    // Print the integer at index:
    cout << numbers[index] << endl;
}