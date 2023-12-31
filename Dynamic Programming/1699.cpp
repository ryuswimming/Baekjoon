// Cannot be solved in Greedy way.

#include <iostream>
#include <limits.h>
#include <cmath>
using namespace std;

int f(int );
int min(int , int );

int *dp;

int main() {
    int number;
    cin >> number;
    
    dp = (int *)calloc((number+1), sizeof(int));

    cout << f(number) << endl;

    free(dp);
}

int f(int a) {
    if (sqrt(a) == trunc(sqrt(a))) return 1;

    int count = trunc(sqrt(a));
    int result = INT_MAX;
    for (int i = 1; i <= count; i++) {
        int next_argument = a - pow(i, 2);
        if (dp[next_argument] != 0) {
            result = min(result, dp[next_argument] + 1);
        }
        else result = min(result, f(a - pow(i, 2)) + 1);
    }
    
    return dp[a] = result;
}

int min(int a, int b) {
    return (a < b) ? a : b;
}