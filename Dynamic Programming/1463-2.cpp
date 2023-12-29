// Recursive version

#include <iostream>
using namespace std;

int f(int number);

int main() {
    int number;
    // Don't forget & in scanf().
    scanf("%d", &number);
    printf("%d\n", f(number));
}

int f(int number) {
    // Write the base case first.
    // In the base case, the number can be smaller than 1.
    if (number <= 1) return 0;

    int a, b;

    // Reduce 3 cases to 2 cases.
    // Important point that makes Recursive version more efficient than Dynamic Programming version.
    // 모르겠다...
    a = f(number/3) + number%3 + 1;
    b = f(number/2) + number%2 + 1;
    
    return a<b ? a:b;
}