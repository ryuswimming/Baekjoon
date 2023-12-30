#include <iostream>
using namespace std;

int main() {
    int number;
    cin >> number;
    
    int array[101][10];
    array[1][0] = 0;
    for (int i = 1; i <= 9; i++) {
        array[1][i] = 1;
    }
    
    for (int i = 2; i <= number; i++) {
        array[i][0] = array[i-1][1];
        for (int j = 1; j <= 8; j++) {
            array[i][j] = (array[i-1][j-1] + array[i-1][j+1]) % 1000000000;
        }
        array[i][9] = array[i-1][8];
    }

    int result = 0;
    for (int i = 0; i <= 9; i++) {
        result += array[number][i];
        // The limit must be ensured in every step of calculation.
        result %= 1000000000;
    }

    cout << result << endl;
}