#include <iostream>
#include <vector>
#include <tuple>
#include <string>
#include <algorithm>
using namespace std;

int compare(tuple<int, int, string> , tuple<int, int, string> );

int main() {
    int count;
    cin >> count;

    vector<tuple<int, int, string> > array(count);

    int temp1;
    string temp2;
    for (int i = 0; i < count; i++) {
        cin >> temp1 >> temp2;
        array[i] = make_tuple(i, temp1, temp2);
    }

    sort(array.begin(), array.end(), compare);

    for (int i = 0; i < count; i++) {
        cout << get<1> (array[i]) << ' ' << get<2> (array[i]) << '\n';
    }
}

int compare(tuple<int, int, string> a, tuple<int, int, string> b) {
    if (get<1> (a) == get<1> (b)) return get<0> (a) < get<0> (b);
    return get<1> (a) < get<1> (b);
}