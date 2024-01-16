#include <iostream>
#include <vector>
using namespace std;

void bfs();
bool check_for_next_queue(int , int );

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

void bfs() {
    pair<int, int> temp;
    while (!current_queue.empty()) {
        for (int i = 0; i < current_queue.size(); i++) {
            temp = current_queue[i];
            if (check_for_next_queue(temp.first-1, temp.second)) {
                next_queue.push_back(make_pair(temp.first-1, temp.second));
                _array[temp.first-1][temp.second] = 1;
            }
            if (check_for_next_queue(temp.first+1, temp.second)) {
                next_queue.push_back(make_pair(temp.first+1, temp.second));
                _array[temp.first+1][temp.second] = 1;
            }
            if (check_for_next_queue(temp.first, temp.second-1)) {
                next_queue.push_back(make_pair(temp.first, temp.second-1));
                _array[temp.first][temp.second-1] = 1;
            }
            if (check_for_next_queue(temp.first, temp.second+1)) {
                next_queue.push_back(make_pair(temp.first, temp.second+1));
                _array[temp.first][temp.second+1] = 1;
            }
        }
        current_queue.clear();
        current_queue.swap(next_queue);
        result++;
    }
}

bool check_for_next_queue(int a, int b) {
    if (a < 0 || a > N-1 || b < 0 || b > M-1) return false;
    if (_array[a][b] != 0) return false;
    return true;
}