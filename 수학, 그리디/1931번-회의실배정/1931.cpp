#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool check[100000];
int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    vector<pair<int, int>> vec;

    int n, start, end;
    cin >> n;
    for (int i =0; i<n;i++) {
        cin >> start >> end;
        vec.push_back({end, start}); // 반대로넣고
    }

    // second(끝나는 시간) 기준으로 정렬
    sort(vec.begin(), vec.end(), [](auto &a, auto &b) {
        if (a.first != b.first) return a.first < b.first;
        return a.second < b.second;
    });

    vector<pair<int, int>>::iterator iter = vec.begin();
    vector<pair<int, int>>::iterator iter2;

    int cnt = 1; // begin()부터 시작했다치고, 두 번째로 끝나는 거부터 탐색

    int currentEnd = vec.begin()->first;
    for (iter = next(vec.begin()); iter != vec.end(); iter++) {
        if (iter->second < currentEnd) continue; // 현재 iter의 시작시간이 이전의 끝나는시간보다 작으면

        // 위 조건을 충족했을 때
        cnt++;
        currentEnd = iter->first;
    }
    cout << cnt;
}

