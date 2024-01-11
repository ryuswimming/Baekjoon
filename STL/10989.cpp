#include <iostream>
using namespace std;

int main() {
    int array[10001] = {0, };

    int count;
    cin >> count;

    int temp;
    for (int i = 0; i < count; i++) {
        scanf("%d", &temp);
        array[temp]++;
    }

    for (int i = 1; i <= 10000; i++) {
        for (int j = 0; j < array[i]; j++) {
            printf("%d\n", i);
        }
    }
}