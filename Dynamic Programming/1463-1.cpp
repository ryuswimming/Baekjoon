// Dynamic Programming version

#include <iostream>
#include <limits.h>
using namespace std;

int main() {
    int number;
    cin >> number;

    int *array = (int *)malloc((number+1)*sizeof(int));
    for (int i = 0; i <= number; i++) array[i] = INT_MAX;
    array[1] = 0;

    for (int i = 1; i < number; i++) {
        if (3*i <= number) if (array[3*i] > array[i]+1) array[3*i] = array[i]+1;
        if (2*i <= number) if (array[2*i] > array[i]+1) array[2*i] = array[i]+1;
        if (array[i+1] > array[i]+1) array[i+1] = array[i]+1;
    }

    cout << array[number] << endl;
    
    free(array);
}