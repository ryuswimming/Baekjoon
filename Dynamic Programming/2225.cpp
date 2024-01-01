#include <iostream>
using namespace std;

int main() {
    int N, K;
    cin >> N;
    cin >> K;
    
    int dp[201][201];
    for (int i = 0; i <= 200; i++) {
        dp[0][i] = 1;
    }
    for (int i = 0; i <= 200; i++) {
        dp[i][1] = 1;
    }
    
    for (int i = 2; i <= K; i++) {
        for (int j = 1; j <= N; j++) {
            dp[j][i] = (dp[j-1][i] + dp[j][i-1]) % 1000000000;
        }
    }

    cout << dp[N][K] << endl;
}