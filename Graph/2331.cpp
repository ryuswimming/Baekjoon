#include <iostream>
#include <memory.h>
#include <math.h>
using namespace std;

int main() {
    int A, P;
    cin >> A >> P;

    int array[1000000];
    memset(array, -1, 1000000*sizeof(int));
    array[A] = 0;

    while (true) {
        int temp = 0;
        int B = A;
        while (B != 0) {
            temp += pow(B%10, P);
            B/=10;
        }
        if (array[temp] != -1) {
            A = temp;
            break;
        }
        else {
            array[temp] = array[A]+1;
            A = temp;
        }
    }

    cout << array[A] << '\n';
}