#include <iostream>
#include <cstdio>
using namespace std;

int dp[5001] = {1, 1, 2, };

int can_be_connected(int , int );
int fibonacci(int );

int main() {
    int previous_number, current_number, temp = 1, can;
    long long result = 1;
    current_number = getchar() - '0';
    if (current_number == 0) {
        cout << 0 << endl;
        return 0;
    }

    while (true) {
        previous_number = current_number;
        current_number = getchar() - '0';
        if (current_number == '\n' - '0' || current_number == '\0' - '0') break;

        can = can_be_connected(previous_number, current_number);
        if (can == 0) {
            cout << 0 << endl;
            return 0;
        }
        else if (can == 1) {
            result *= fibonacci(temp);
            result %= 1000000;
            temp = 1;
        }
        else if (can == 2) {
            temp++;
        }
        else {
            temp--;
            result *= fibonacci(temp);
            result %= 1000000;
            temp = 1;
        }
    }
    result *= fibonacci(temp);
    result %= 1000000;

    cout << result << endl;
}

// If two numbers can be interpreted in 0 numbers, return 0. 1 numbers, return 1. 2 numbers, return 2.
// For exceptional cases such as 10 that reduce the number of cases of previous numbers, return 3.
int can_be_connected(int a, int b) {
    if (b == 0) {
        if (a == 1 || a == 2) return 3;
        else return 0;
    }
    if (a == 1) return 2;
    if (a == 2 &&  b < 7) return 2;
    return 1;
}

int fibonacci(int a) {
    if (dp[a] != 0) return dp[a];
    else return dp[a] = (fibonacci(a-1) + fibonacci(a-2)) % 1000000;
}