#include <iostream>
using namespace std;

int main() {
    int count;
    cin >> count;

    int *array = (int *)malloc((count+1)*sizeof(int));
    int *dp_for_increasing = (int *)malloc((count+1)*sizeof(int));
    int *dp_for_decreasing = (int *)malloc((count+1)*sizeof(int));
    for (int i = 1; i <= count; i++) {
        cin >> array[i];
    }
    dp_for_increasing[1] = 1;
    dp_for_decreasing[count] = 1;

    for (int i = 2; i <= count; i++) {
        int temp = 0;
        for (int j = 1; j < i; j++) {
            if (array[j] >= array[i]) continue;
            if (dp_for_increasing[j] > temp) temp = dp_for_increasing[j];
        }
        dp_for_increasing[i] = temp + 1;
    }

    for (int i = count-1; i >= 1; i--) {
        int temp = 0;
        for (int j = count; j > i; j--) {
            if (array[j] >= array[i]) continue;
            if (dp_for_decreasing[j] > temp) temp = dp_for_decreasing[j];
        }
        dp_for_decreasing[i] = temp + 1;
    }

    int result = 0;
    for (int i = 1; i <= count; i++) {
        if (result < dp_for_increasing[i] + dp_for_decreasing[i] - 1) result = dp_for_increasing[i] + dp_for_decreasing[i] - 1;
    }

    cout << result << endl;

    free(array);
    free(dp_for_increasing);
    free(dp_for_decreasing);
}