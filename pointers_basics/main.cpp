#include <iostream>

using namespace std;

void multiply_first(int* address_of_a, int b) { 
    (*address_of_a) = (*address_of_a) * b;
}

int main() {
    int x = 3, y = 4;
    int* address_of_x = &x;
    int value_at_address = *address_of_x;

    printf("Address:        %d\n", address_of_x);
    printf("Value before:   %d\n", x);

    multiply_first(address_of_x, y);

    printf("Value after:    %d\n", x);
    // But we want this to be 12!
}