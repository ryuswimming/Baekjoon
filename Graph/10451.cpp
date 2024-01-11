#include <iostream>
using namespace std;

void dfs(int );

int T, N;
int _array[1001];
bool visited[1001];

int main() {
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> N;

        int temp;
        for (int i = 1; i <= N; i++) {
            cin >> temp;
            _array[i] = temp;
            visited[i] = false;
        }

        int result = 0;
        for (int i = 1; i <= N; i++) {
            if (!visited[i]) {
                dfs(i);
                result++;
            }
        }

        cout << result << '\n';
    }
}

void dfs(int a) {
    if (visited[a] == true) return;
    else {
        visited[a] = true;
        dfs(_array[a]);
    }
}