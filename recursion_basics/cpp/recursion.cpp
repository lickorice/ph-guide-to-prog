#include <iostream>

using namespace std;

int factorial(int n) {
    if (n == 1) return 1;
    return n * factorial(n-1);
}

int main() {
    int test_cases; cin >> test_cases;
    for (int tc = 0; tc < test_cases; ++tc) {
        int n; cin >> n;
        cout << factorial(n) << endl;
    }
}