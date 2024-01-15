#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void dfs(int , int );

int N;
bool _array[25][25];
bool visited[25][25];
vector<int> _result;

int main() {
    cin >> N;

    char temp;
    for (int i = 0; i < N; i++) {
        getchar();
        for (int j = 0; j < N; j++) {
            if (getchar() == '1') _array[i][j] = true;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (_array[i][j] && !visited[i][j]) {
                _result.push_back(0);
                dfs(i, j);
            }
        }
    }

    sort(_result.begin(), _result.end());

    cout << _result.size() << '\n';
    for (auto& i : _result) {
        cout << i << '\n';
    }
}

void dfs(int a, int b) {
    if (a < 0 || a > N-1 || b < 0 || b > N-1) return;
    if (_array[a][b] == false) return;
    if (visited[a][b] == true) return;
    else {
        visited[a][b] = true;
        _result.back()++;
        dfs(a-1, b);
        dfs(a+1, b);
        dfs(a, b-1);
        dfs(a, b+1);
    }
}