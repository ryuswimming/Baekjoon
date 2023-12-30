#include <iostream>
using namespace std;

int main() {
    int count;
    cin >> count;

    int *array = (int *)malloc((count+1)*sizeof(int));
    int *dp = (int *)malloc((count+1)*sizeof(int));
    for (int i = 1; i <= count; i++) {
        cin >> array[i];
    }
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= count; i++) {
        int temp = 0;
        int j = i;
        // "while (j--) {}" is an easy template.
        while (j--) {
            if (array[j] >= array[i]) continue;
            if (dp[j] > temp) temp = dp[j];
        }
        dp[i] = temp + 1;
    }

    int result = 0;
    for (int i = 1; i <= count; i++) {
        if (result < dp[i]) result = dp[i];
    }

    cout << result << endl;

    free(array);
    free(dp);
}