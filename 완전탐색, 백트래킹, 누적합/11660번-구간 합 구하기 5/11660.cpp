#include <iostream>

using namespace std;

int sumArr[1025][1025];

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m, k;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> k;
            sumArr[i][j] = sumArr[i][j-1] + k;
        }
    }
    int x1, y1, x2, y2;

    while (m--) {
        int sum = 0;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int i = x1; i <= x2; i++) {
            sum += sumArr[i][y2] - sumArr[i][y1-1];
        }
        cout << sum << "\n";
    }
}
