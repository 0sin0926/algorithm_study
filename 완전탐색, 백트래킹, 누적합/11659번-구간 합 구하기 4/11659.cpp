#include <iostream>

using namespace std;

int sumArr[100000];

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m, k;
    cin >> n >> m;

    for (int i =0; i < n; i++) {
        cin >> k;
        if (i==0) sumArr[i] = k;
        else sumArr[i] = sumArr[i-1] + k;
    }

    int a, b;
    while (m--) {
        cin >> a >> b;
        cout << sumArr[b -1] - sumArr[a - 2] << "\n";
    }

}
