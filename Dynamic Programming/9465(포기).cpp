#include <iostream>
using namespace std;

int main() {
    int array[2][100000];

    int count;
    cin >> count;

    for (int i = 0; i < count; i++) {
        int number;
        cin >> number;
        
        for (int j = 0; j < number; j++) {
            cin >> array[0][j];
        }
        for (int j = 0; j < number; j++) {
            cin >> array[1][j];
        }

        
        

        cout << array[number] << endl;
    }
}