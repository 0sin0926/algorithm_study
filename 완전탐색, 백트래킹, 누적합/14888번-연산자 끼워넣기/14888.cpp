#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> num; // 숫자
vector<int> oper; // 연산자

int main() {
    int n, number;
    cin >> n;

    for (int i=0;i<n;i++) {
        cin >> number;
        num.push_back(number);
    }
    // + : 0, - : 1, * : 2, / : 3
    int op;
    for (int i =0; i<4;i++) {
        cin >> op;
        if (op != 0) {
            while (op--) {
                oper.push_back(i);
            }
        }
    }

    long long max = -1000000000;
    long long min = 1000000000;
    do {
        long long sum = num[0];
        for (int i = 1; i < n; i++) {
            int o = oper[i-1];
            switch (o) {
                case 0 : sum += num[i]; break;
                case 1 : sum -= num[i]; break;
                case 2 : sum *= num[i]; break;
                default :
                    int k;
                    if (sum <0) sum = -(-sum / num[i]);
                    else sum = sum / num[i];
            }
        }
        if (sum > max) max = sum;
        if (sum < min) min = sum;
    } while (next_permutation(oper.begin(), oper.end()));
    cout << max << "\n" << min;
}
