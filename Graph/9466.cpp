#include <iostream>
using namespace std;

int dfs(int );
void clear_dfs(int , int );

int T, N;
int _array[100001];
int visited[100001];

int main() {
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> N;

        int temp1;
        for (int i = 1; i <= N; i++) {
            cin >> temp1;
            _array[i] = temp1;
            visited[i] = -1;
        }

        int temp2;
        for (int i = 1; i <= N; i++) {
            if (visited[i] == -1) {
                temp2 = dfs(i);
                if (i != temp2) clear_dfs(i, temp2);
            }
        }

        int result = 0;
        for (int i = 1; i <= N; i++) {
            if (visited[i] == 0) result++;
        }

        cout << result << '\n';
    }
}

int dfs(int a) {
    if (visited[a] != -1) return a;
    else {
        visited[a] = 1;
        return dfs(_array[a]);
    }
}

void clear_dfs(int a, int b) {
    if (a == b) return;
    else {
        visited[a] = 0;
        clear_dfs(_array[a], b);
    }
}