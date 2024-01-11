#include <iostream>
#include <queue>
using namespace std;

void dfs(int );
void bfs(int );

int N, M, V;
bool _array[1001][1001];
bool dfs_visited[1001];
bool bfs_visited[1001];
queue<int> _queue;

int main() {
    cin >> N >> M >> V;

    int temp1, temp2;
    for (int i = 0; i < M; i++) {
        cin >> temp1 >> temp2;
        _array[temp1][temp2] = true;
        _array[temp2][temp1] = true;
    }
    dfs(V);
    cout << '\n';
    bfs(V);
}

void dfs(int a) {
    if (dfs_visited[a] == true) return;
    else {
        dfs_visited[a] = true;
        cout << a << ' ';
        for (int i = 1; i <= N; i++) {
            if (_array[a][i]) dfs(i);
        }
    }
}

void bfs(int a) {
    bfs_visited[a] = true;
    _queue.push(a);

    int b;
    while (!_queue.empty()) {
        b = _queue.front();
        _queue.pop();
        cout << b << ' ';
        for (int i = 1; i <= N; i++) {
            if (_array[b][i] && !bfs_visited[i]) {
                bfs_visited[i] = true;
                _queue.push(i);
            }
        }
    }
}