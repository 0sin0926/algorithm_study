#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int k;
    bool start = false;
    while (cin >> k && k != 0) {
        if (start) cout << "\n";
        start = true;

        int subArr[13];
        int arr[13];
        for (int i = 0; i < k; i++) { // 테케 입력받음
            cin >> arr[i];
        }

        for (int i = 0; i < k; i++) { // 처음 6개를 0으로 초기화
            if (i <= 5) subArr[i] = 0;
            else subArr[i] = 1;
        }

        do {
            int cnt = 0;
            for (int i = 0; i < k; i++) {
                if (subArr[i] == 0) {
                    cout << arr[i];
                    cnt++;
                    if (cnt <= 5) cout << " ";
                    else cout << "\n";
                }
                if (cnt==6) break;
            }
        } while (next_permutation(subArr, subArr + k));

    }
}
