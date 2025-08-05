#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long factArr[21]; // 팩토리얼 값을 저장하는 배열
int arr[20][20]; // 값 들어있는 배열
int subArr[21];

int abs(int a, int b) {
    return a-b > 0 ? a-b : -(a-b);
}
int comb(int n, int r) {
    return factArr[n] / (factArr[r] * factArr[n-r]);
}
vector<int> v;

int main() {
    int n;
    cin >> n;
    for (int i =0; i< n; i++) {
        for (int j =0; j<n; j++) {
            cin >> arr[i][j];
        }
    }

    //factorial 값을 필요한 만큼만 배열에 저장
    int res = 1;
    for (long long i = 1; i <= n; i++) {
        factArr[i] = res*i;
    }

    int k = comb(n, n/2) / 2;
    for (int i = 0; i < n; i++) {
        if (i < n/2) subArr[i] = 0;
        else subArr[i] = 1;
    }

    int cnt = 0;
    int min = 20000;
    do {
        int startSum = 0, linkSum = 0, minus;
        for (int i = 0; i < n; i++) {
            for (int j =0; j<n; j++) {
                if (subArr[i] == 0 && subArr[j]==0) startSum += arr[i][j];
                else if (subArr[i] == 1 && subArr[j]==1) linkSum += arr[i][j];
            }
        }
        minus = abs(startSum, linkSum);
        if (minus < min) min = minus;

        cnt++;
        if (cnt == k) break;
    } while (next_permutation(subArr, subArr + n));
    cout << min;
}
