// Simple version

#include <iostream>
using namespace std;

int main() {
    int number;
    cin >> number;
    
    long long array[91];
    array[1] = 1;
    array[2] = 1;
    
    for (int i = 3; i <= number; i++) {
        // Divide the case by the possible end, which is 0 and 01.
        array[i] = array[i-1] + array[i-2];
    }

    cout << array[number] << endl;
}