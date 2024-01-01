#include <iostream>
using namespace std;

long long f(int );

long long dp[101] = { 0, 1, 1, 1, 2, 2, };

int main() {
    int count;
    cin >> count;

    for (int i = 0; i < count; i++) {
        int number;
        cin >> number;
        cout << f(number) << endl;
    }
}

long long f(int a) {
    if (dp[a] != 0) return dp[a];
    return dp[a] = f(a-1) + f(a-5);
}