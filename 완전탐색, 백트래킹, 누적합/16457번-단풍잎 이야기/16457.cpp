#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

unordered_set<int> s; // 사용 가능 스킬
vector<int> v; // 퀘스트
int n, m, k; // n : 스킬 개수, m : 퀘스트 개수, k : 퀘스트당 사용할 스킬 개수
int skill;
int Max;
int cnt, result;

vector<int>comb; // 스킬 조합을 위한 subArr

void dfs(int idx, int selectedSkills) {
    if (selectedSkills==n) {
        s.clear();
        for (int i =0; i< 2*n; i++) {
            if (comb[i]) s.insert(i+1);
        }

        // 퀘스트 수행
        cnt = 0;
        result = 0;
        for (int i =0; i< m*k; i++) {
            if (s.find(v[i]) != s.end()) cnt++;
            if ((i + 1) % k == 0) {
                if (cnt == k) result++;
                cnt = 0;
            }
        }

        Max = max(Max, result);
        return;
    }

    // comb[]로 어떤 스킬을 고를지 정하고,
    // selectedSkills로 지금까지 몇 개를 골랐는지 체크한다
    for (int i = idx; i<2*n; i++) {
        comb[i] = 1;
        dfs(i+1, selectedSkills +1);
        comb[i] = 0; // 백트래킹
    }
}
int main() {
    cin >> n >> m >> k;

    // 퀘스트 스킬 정보 입력
    for (int i = 0; i < m * k; i++) {
        cin >> skill;
        v.push_back(skill);
    }

    // 백트래킹을 위한 배열 초기화
    comb.resize(2*n, 0);  // 사용 가능한 스킬에 대해 0으로 초기화
    Max = 0;

    // dfs 호출 시작
    dfs(0, 0);

    // 결과 출력
    cout << Max;

    return 0;
}
