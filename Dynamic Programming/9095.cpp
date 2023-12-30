#include <iostream>
using namespace std;

int main() {
    int array[11];
    array[1] = 1;
    array[2] = 2;
    array[3] = 4;
    for (int i = 4; i < 11; i++) {
        array[i] = array[i-1] + array[i-2] + array[i-3];
    }

    int count;
    cin >> count;

    for (int i = 0; i < count; i++) {
        int number;
        cin >> number;
        // Use endl to separate multiple outputs.
        cout << array[number] << endl;
    }
}