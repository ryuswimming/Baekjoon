#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    int count;
    cin >> count;

    unordered_map<long long, int> table(100000);
    long long temp1;
    for (int i = 0; i < count; i++) {
        scanf("%lld", &temp1);
        table[temp1]++;
    }

    vector<long long> array;
    int temp2 = 0;
    unordered_map<long long, int> :: iterator iter;
    for (iter = table.begin(); iter != table.end(); iter++) {
        if (iter->second > temp2) {
            temp2 = iter->second;
            array.clear();
            array.push_back(iter->first);
        }
        else if (iter->second == temp2) {
            array.push_back(iter->first);
        }
    }

    long long result = INT64_MAX;
    for (int i = 0; i < array.size(); i++) {
        if (array[i] < result) result = array[i];
    }

    cout << result << endl;
}