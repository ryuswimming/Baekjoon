#include <iostream>
using namespace std;

int main() {
    int number;
    cin >> number;
    
    int array[1001][10];
    for (int i = 0; i <= 9; i++) {
        array[1][i] = 1;
    }
    
    for (int i = 2; i <= number; i++) {
        array[i][0] = array[i-1][0];
        for (int j = 1; j <= 9; j++) {
            array[i][j] = (array[i][j-1] + array[i-1][j]) % 10007;
        }
    }

    int result = 0;
    for (int i = 0; i <= 9; i++) {
        result += array[number][i];
    }
    result %= 10007;

    cout << result << endl;
}