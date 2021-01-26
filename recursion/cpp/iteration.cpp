#include <iostream>

using namespace std;

int factorial(int n) {
    int result = 1;
    for (int i = 0; i < n; ++i) {
        result *= i+1;
    }
    return result;
}

int main() {
    int test_cases; cin >> test_cases;
    for (int tc = 0; tc < test_cases; ++tc) {
        int n; cin >> n;
        cout << factorial(n) << endl;
    }
}