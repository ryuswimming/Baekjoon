#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int compare(pair<int, int> , pair<int, int> );

int main() {
    int count;
    cin >> count;

    vector<pair<int, int> > array;

    int temp1, temp2;
    for (int i = 0; i < count; i++) {
        cin >> temp1 >> temp2;
        array.push_back(make_pair(temp1, temp2));
    }

    sort(array.begin(), array.end(), compare);

    for (int i = 0; i < count; i++) {
        cout << array[i].first << ' ' << array[i].second << '\n';
    }
}

int compare(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}