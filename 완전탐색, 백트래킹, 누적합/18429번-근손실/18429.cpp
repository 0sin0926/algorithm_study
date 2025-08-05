#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> v;
vector<int> idx;
int main() {
    int n, k;
    cin >> n >> k;

    int weight;
    for (int i =0; i< n; i++) {
        cin >> weight;
        v.push_back(weight);
    }

    for (int i =0; i<n; i++) {
        idx.push_back(i);
    }


    int cnt = 0;
    do {
        int currentWeight = 500;
        bool result = true;
        for (int i =0; i< n; i++) {
            currentWeight += v[idx[i]];
            currentWeight -= k;
            if (currentWeight < 500) {
                result = false;
                break;
            }

        }
        if (result) cnt++;
    } while (next_permutation(idx.begin(), idx.end()));
    cout << cnt;
}
