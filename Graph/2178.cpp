#include <iostream>
#include <vector>
using namespace std;

void bfs();
void check_for_next_queue(int , int );

int N, M, stage;
int _array[100][100];
vector<pair<int, int> > current_queue, next_queue;

int main() {
    cin >> N >> M;

    char temp;
    for (int i = 0; i < N; i++) {
        getchar();
        for (int j = 0; j < M; j++) {
            if (getchar() == '1') _array[i][j] = 1;
        }
    }

    current_queue.push_back(make_pair(0, 0));

    bfs();

    cout << _array[N-1][M-1] << '\n';
}

void bfs() {
    pair<int, int> temp;
    stage = 1;
    while (_array[N-1][M-1] == 1) {
        stage++;
        for (int i = 0; i < current_queue.size(); i++) {
            temp = current_queue[i];
            check_for_next_queue(temp.first-1, temp.second);
            check_for_next_queue(temp.first+1, temp.second);
            check_for_next_queue(temp.first, temp.second-1);
            check_for_next_queue(temp.first, temp.second+1);
        }
        current_queue.clear();
        current_queue.swap(next_queue);
    }
}

void check_for_next_queue(int a, int b) {
    if (a == 0 && b == 0) return;
    if (a < 0 || a > N-1 || b < 0 || b > M-1) return;
    if (_array[a][b] != 1) return;
    next_queue.push_back(make_pair(a, b));
    _array[a][b] = stage;
}