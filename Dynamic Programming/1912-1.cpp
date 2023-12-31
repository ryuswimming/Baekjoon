// Brute Force version

#include <iostream>
using namespace std;

int main() {
    int count;
    cin >> count;

    int *array = (int *)malloc((count+1)*sizeof(int));
    for (int i = 1; i <= count; i++) {
        cin >> array[i];
    }
    array[0] = 0;
    for (int i = 1; i <= count; i++) {
        array[i] += array[i-1];
    }

    int result = 0;
    for (int i = 1; i <= count; i++) {
        for (int j = i; j <= count; j++) {
            int partialSum = array[j] - array[i-1];
            if (result < partialSum) result = partialSum;
        }
    }

    cout << result << endl;

    free(array);
}