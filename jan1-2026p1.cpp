#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int n;
    cin >> n;

    vector<int> arr;

    for (int i = 0; i < n; i++) {
        arr.push_back(i);

        if (i > 1) {
            int pos = i / 2;
            int first = arr[0];

            arr.erase(arr.begin());
            arr.insert(arr.begin() + pos, first);
        }

        for (int j = 0; j <= i; j++) {
            cout << arr[j] << " ";
        }
        cout << endl;
    }
}
