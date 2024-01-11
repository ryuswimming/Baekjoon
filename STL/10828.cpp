#include <iostream>
#include <stack>
using namespace std;

int main() {
    int N;
    cin >> N;

    stack<int> array;

    string temp1;
    int temp2;
    for (int i = 0; i < N; i++) {
        cin >> temp1;
        if (temp1 == "push") {
            cin >> temp2;
            array.push(temp2);
        }
        else if (temp1 == "pop") {
            if (array.size() == 0) cout << -1 << '\n';
            else {
                cout << array.top() << '\n';
                array.pop();
            }
        }
        else if (temp1 == "size") {
            cout << array.size() << '\n';
        }
        else if (temp1 == "empty") {
            cout << array.empty() << '\n';
        }
        else {
            if (array.size() == 0) cout << -1 << '\n';
            else cout << array.top() << '\n';
        }
    }
}