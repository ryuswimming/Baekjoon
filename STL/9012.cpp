#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    // cin doesn't assign memory into pointer
    string temp;
    int stack;
    bool result;
    for (int i = 0; i < N; i++) {
        stack = 0;
        result = true;
        cin >> temp;
        for (int j = 0; temp[j] != '\0'; j++) {
            if (temp[j] == '(') stack++;
            else {
                if (stack == 0) {
                    result = false;
                    break;
                }
                else stack--;
            }
        }
        if (!result || stack != 0) cout << "NO\n";
        else cout << "YES\n";
    }
}