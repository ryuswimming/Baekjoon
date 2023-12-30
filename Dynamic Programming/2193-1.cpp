// intuitive idea, but complicate implementation

#include <iostream>
using namespace std;

int main() {
    int number;
    cin >> number;
    
    // Make the array type long long to avoid int overflow.
    long long array[91][2];
    array[1][0] = 0;
    array[1][1] = 1;
    
    for (int i = 2; i <= number; i++) {
        array[i][0] = array[i-1][0] + array[i-1][1];
        array[i][1] = array[i-1][0];
    }

    cout << array[number][0] + array[number][1] << endl;
}