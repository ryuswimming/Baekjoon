#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int array[1000000];

    int count;
    cin >> count;

    for (int i = 0; i < count; i++) {
        cin >> array[i];
    }

    sort(array, array+count);

    for (int i = 0; i < count; i++) {
        cout << array[i] << '\n';
    }
}