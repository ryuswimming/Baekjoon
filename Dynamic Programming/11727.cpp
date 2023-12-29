// Dynmaic Programming version

#include <iostream>
using namespace std;

int main() {
    int number;
    cin >> number;

    int *array = (int *)malloc((number+1)*sizeof(int));
    array[1] = 1;
    array[2] = 3;

    for (int i = 3; i <= number; i++) {
        array[i] = (array[i-1] + 2*array[i-2])%10007;
    }

    cout << array[number] << endl;
    
    free(array);
}