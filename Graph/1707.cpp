#include <iostream>
#include <list>
using namespace std;

void dfs(int);

int K, N, M;
list<int> li[20001];
// -1 as unvisited, 0 as visitied in even depth, 1 as visited in odd depth.
int visited[20001];
bool result;

int main() {
    cin >> K;
    for (int k = 0; k < K; k++) {
        cin >> N >> M;

        for (int i = 1; i <= N; i++) {
            li[i].clear();
            visited[i] = -1;
        }
        result = true;

        int temp1, temp2;
        for (int i = 0; i < M; i++) {
            cin >> temp1 >> temp2;
            li[temp1].push_back(temp2);
            li[temp2].push_back(temp1);
        }

        // The graph is bipartite iff there is no odd cycle in the graph.
        for (int i = 1; i <= N; i++) {
            if (visited[i] == -1) {
                visited[i] = 0;
                dfs(i);
                if (!result) break;
            }
        }

        if (result) cout << "YES\n";
        else cout << "NO\n";
    }
}

void dfs(int a) {
    for (list<int>::iterator it = li[a].begin(); it != li[a].end(); it++) {
        if (visited[*it] != -1) {
            if ((visited[*it] + visited[a])%2 == 0) result = false;
        }
        else {
            visited[*it] = (visited[a]+1)%2;
            dfs(*it);
        }
    }
}