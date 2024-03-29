#include <iostream>
#include <vector>
using namespace std;

void bfs();
void check_for_next_queue(int , int );

int N, M, result;
int _array[1000][1000];
vector<pair<int, int> > current_queue, next_queue;

int main() {
    cin >> M >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> _array[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (_array[i][j] == 1) {
                current_queue.push_back(make_pair(i, j));
            }
        }
    }

    bfs();

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (_array[i][j] == 0) {
                cout << -1 << '\n';
                return 0;
            }
        }
    }

    cout << result-1 << '\n';
}

// Always define what should be stored in a data structure before using it.
void bfs() {
    pair<int, int> temp;
    while (!current_queue.empty()) {
        for (int i = 0; i < current_queue.size(); i++) {
            temp = current_queue[i];
            check_for_next_queue(temp.first-1, temp.second);
            check_for_next_queue(temp.first+1, temp.second);
            check_for_next_queue(temp.first, temp.second-1);
            check_for_next_queue(temp.first, temp.second+1);
        }
        current_queue.clear();
        current_queue.swap(next_queue);
        result++;
    }
}

void check_for_next_queue(int a, int b) {
    if (a < 0 || a > N-1 || b < 0 || b > M-1) return;
    if (_array[a][b] != 0) return;
    next_queue.push_back(make_pair(a, b));
    _array[a][b] = 1;
}