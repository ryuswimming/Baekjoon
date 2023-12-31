// Dynamic Programming version

#include <iostream>
#include <limits.h>
using namespace std;

int max(int , int );

int main() {
    int count;
    cin >> count;

    int *array = (int *)malloc((count+1)*sizeof(int));
    int *dp = (int *)malloc((count+1)*sizeof(int));
    for (int i = 1; i <= count; i++) {
        cin >> array[i];
    }
    dp[1] = array[1];

    for (int i = 2; i <= count; i++) {
        dp[i] = max(dp[i-1] + array[i], array[i]);
    }
    // Use INT_MIN in case of negative outputs.
    int result = INT_MIN;
    for (int i = 1; i <= count; i++) {
        result = max(result, dp[i]);
    }

    cout << result << endl;

    free(array);
}

int max(int a, int b) {
    return (a > b) ? a : b;
}