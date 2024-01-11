#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int count, K;
    cin >> count >> K;

    vector<int> array(count);
    int temp1;
    for (int i = 0; i < count; i++) {
        scanf("%d", &temp1);
        array[i] = temp1;
    }

    // Use heap to find K-th smallest element, which is O(KlogN);
    make_heap(array.begin(), array.end(), greater<int>());

    for (int i = 0; i < K-1; i++) {
        pop_heap(array.begin(), array.end(), greater<int>());
        array.pop_back();
    }
    pop_heap(array.begin(), array.end(), greater<int>());
    cout << array.back() << endl;
}