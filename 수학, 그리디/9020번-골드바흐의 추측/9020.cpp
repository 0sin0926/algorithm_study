#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool check[250000];
vector<int> vec;

void partition(int n) {
    int minus;

    int resultA = 0, resultB = 0, cnt = 10000;
    for (int i =0; i<vec.size(); i++) {
        for (int j = i; j<vec.size(); j++) {
            if (vec[i] + vec[j] == n) {
                minus = vec[j] - vec[i];
                if (minus < cnt) {
                    cnt = minus;
                    resultA = vec[i];
                    resultB = vec[j];
                }
            }
        }
    }
    cout << resultA << " " << resultB << "\n";
}

int main() {
    for (int i = 2; i < 10001 ; i++) {
        check[i] = false;
    }
    for (int i = 2; i <= sqrt(10001); i++) {
        if (check[i]) continue;
        for (int j = 2; i*j <= 10001; j++) {
            check[i*j] = true;
        }
    }

    for (int i =2; i < 10001; i++) {
        if (check[i]) continue;
        vec.push_back(i);
    }


    int t, n;
    cin >> t;

    while (t--) {
        cin >> n;
        partition(n);
    }
}
