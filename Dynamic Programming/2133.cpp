#include <iostream>
using namespace std;

int main() {
    int number;
    cin >> number;

    if (number%2 != 0) {
        cout << 0 << endl;
        return EXIT_SUCCESS;
    }

    int dp[31];
    dp[0] = 1;
    dp[2] = 3;
    
    for (int i = 4; i <= number; i+=2) {
        int temp = 0;
        temp += dp[i-2]*3;

        int j = i-4;
        while(j>=0) {
            temp += dp[j]*2;
            j -= 2;
        }
        dp[i] = temp;
    }

    cout << dp[number] << endl;
}