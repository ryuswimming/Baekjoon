#include <iostream>
using namespace std;

void dfs(int , int );

int W, H;
bool _array[50][50];
bool visited[50][50];

int main() {
    while (true) {
        cin >> W >> H;
        if (W == 0 && H == 0) break;

        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                cin >> _array[i][j];
                visited[i][j] = false;
            }
        }

        int result = 0;
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if (_array[i][j] && !visited[i][j]) {
                    result++;
                    dfs(i, j);
                }
            }
        }

        cout << result << '\n';
    }
}

void dfs(int a, int b) {
    if (a < 0 || a > H-1 || b < 0 || b > W-1) return;
    if (_array[a][b] == false) return;
    if (visited[a][b] == true) return;
    else {
        visited[a][b] = true;
        dfs(a-1, b-1);
        dfs(a-1, b);
        dfs(a-1, b+1);
        dfs(a, b-1);
        dfs(a, b+1);
        dfs(a+1, b-1);
        dfs(a+1, b);
        dfs(a+1, b+1);
    }
}