#include <iostream>
using namespace std;

int max(int , int );
int max(int , int , int);

int main() {
    int array[2][100001];
    int dp[2][100001];

    int count;
    cin >> count;

    for (int i = 0; i < count; i++) {
        int number;
        cin >> number;
        
        for (int j = 1; j <= number; j++) {
            cin >> array[0][j];
        }
        for (int j = 1; j <= number; j++) {
            cin >> array[1][j];
        }
        dp[0][0] = 0;
        dp[0][0] = 0;
        dp[0][1] = array[0][1];
        dp[1][1] = array[1][1];

        for (int i = 2; i <= number; i++) {
            dp[0][i] = max(dp[1][i-1], dp[1][i-2], dp[0][i-2]) + array[0][i];
            dp[1][i] = max(dp[0][i-1], dp[0][i-2], dp[1][i-2]) + array[1][i];
        }

        int result = 0;
        for (int i = 0; i < 2; i++) {
            for (int j = number-1; j <= number; j++) {
                result = max(result, dp[i][j]);
            }
        }

        cout << result << endl;
    }
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int max(int a, int b, int c) {
    if (a < b) a = b;
    if (a < c) a = c;
    return a;
}