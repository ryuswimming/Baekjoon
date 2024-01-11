#include <iostream>
using namespace std;

void dfs(int );

int N, M;
bool _array[1001][1001];
bool visited[1001];

int main() {
    cin >> N >> M;

    int temp1, temp2;
    for (int i = 0; i < M; i++) {
        cin >> temp1 >> temp2;
        _array[temp1][temp2] = true;
        _array[temp2][temp1] = true;
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

void dfs(int a) {
    if (visited[a] == true) return;
    else {
        visited[a] = true;
        for (int i = 1; i <= N; i++) {
            if (_array[a][i]) dfs(i);
        }
    }
}