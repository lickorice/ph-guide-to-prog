#include <iostream>

using namespace std;

int main() {
    // Our five items
    int item1, item2, item3, item4, item5;

    cin >> item1;
    cin >> item2;
    cin >> item3;
    cin >> item4;
    cin >> item5;

    int position; cin >> position;
    int our_item = -1; // -1 if position is out of bounds

    if (position == 1) {
        our_item = item1;
    } else if (position == 2) {
        our_item = item2;
    } else if (position == 3) {
        our_item = item3;
    } else if (position == 4) {
        our_item = item4;
    } else if (position == 5) {
        our_item = item5;
    }

    // Print the integer at index:
    cout << our_item << endl;
}