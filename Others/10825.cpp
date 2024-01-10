#include <iostream>
#include <vector>
#include <tuple>
#include <string>
#include <algorithm>
using namespace std;

int compare(tuple<string, int, int, int> , tuple<string, int, int, int> );

int main() {
    int count;
    cin >> count;

    vector<tuple<string, int, int, int> > array(count);

    string temp1;
    int temp2, temp3, temp4;
    for (int i = 0; i < count; i++) {
        cin >> temp1 >> temp2 >> temp3 >> temp4;
        array[i] = make_tuple(temp1, temp2, temp3, temp4);
    }

    sort(array.begin(), array.end(), compare);

    for (int i = 0; i < count; i++) {
        cout << get<0> (array[i]) << '\n';
    }
}

int compare(tuple<string, int, int, int> a, tuple<string, int, int, int> b) {
    if (get<1> (a) == get<1> (b)) {
        if (get<2> (a) == get<2> (b)) {
            if (get<3> (a) == get<3> (b)) {
                return get<0> (a) < get<0> (b);
            }
            return get<3> (a) > get<3> (b);
        }
        return get<2> (a) < get<2> (b);
    }
    return get<1> (a) > get<1> (b);
}