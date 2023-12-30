#include <iostream>
using namespace std;

int max(int , int , int );

int main() {
    int count;
    cin >> count;

    int *array = (int *)malloc((count+1)*sizeof(int));
    int *dp = (int *)malloc((count+1)*sizeof(int));
    for (int i = 1; i <= count; i++) {
        cin >> array[i];
    }
    dp[0] = 0;
    dp[1] = array[1];
    dp[2] = array[1] + array[2];

    for (int i = 3; i <= count; i++) {
        // Divide into 8 cases, whether the last three element is chosen or not.
        // Then aggregate 8 cases into 3 cases.
        // We can also directly divide into 3 cases by the latest location of X(not chosen drink).
        dp[i] = max(dp[i-1], dp[i-2] + array[i], dp[i-3] + array[i-1] + array[i]); 
    }

    cout << dp[count] << endl;

    free(array);
    free(dp);
}

int max(int a, int b, int c) {
    if (a < b) a = b;
    if (a < c) a = c;
    return a;
}