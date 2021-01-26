#include <iostream>

using namespace std;

int factorial(int n) {
    if (n == 1) return 1;
    return n * factorial(n-1);
}

void solve(int test_cases) {
    if (test_cases == 0) return;

    int n; cin >> n;
    cout << factorial(n) << endl;
    solve(test_cases-1);
}

int main() {
    int test_cases; cin >> test_cases;
    solve(test_cases);
}