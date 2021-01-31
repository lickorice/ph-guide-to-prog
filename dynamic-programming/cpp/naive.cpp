#include <iostream>
#include <climits>

using namespace std;
int calls = 0;

// Params: change  -> number of change needed to be converted
//         coins[] -> our array of coins
//         n       -> how many coins we have
// Returns: minimum amount of coins needed to provide change (n)
int get_min_coins(int change, int coins[], int n) {
    calls++; // Increment calls

    // Base case #1: If change is 0, then we use 0 coins
    if (!change) return 0;
    
    // Recursive steps, use each coin, then call it recursively
    int minimum_coins = INT_MAX; // Some big placeholder number

    for (int i = 0; i < n; ++i) { // For each coin:
        int new_change = change - coins[i];
        if (new_change < 0) continue; // We cannot have negative change

        // Plus one, because we're going to use a coin:
        int result = 1 + get_min_coins(new_change, coins, n);
        minimum_coins = min(minimum_coins, result);
    }

    return minimum_coins;
}

int main() {
    int n; cin >> n; // Get the number of coins
    int coins[n];

    for (int i = 0; i < n; ++i) {
        cin >> coins[i]; // Store coins in our coins[] array
    }

    int change; cin >> change;
    int result = get_min_coins(change, coins, n);
    
    if (result == INT_MAX) { // Meaning we cannot convert coins
                             // to change, exactly
        cout << "Cannot get exact change!\n";
    } else {
        cout << result << endl;
    }

    cout << "get_min_coins called " << calls << " times.\n";
}