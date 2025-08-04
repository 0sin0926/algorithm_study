#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int abs(int a, int b) {
    return a-b > 0 ? a-b : -(a-b);
}
vector<int> v;

int main() {
    int n, k;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> k;
        v.push_back(k);
    }
    sort(v.begin(), v.end());
    int max = 0;
    do {
        int sum = 0;
        for (int i = 0; i < n-1; i++) {
            sum += abs(v[i], v[i+1]);
        }
        if (sum > max) max = sum;

    } while (next_permutation(v.begin(), v.end()));
    cout << max;
}
