#include <iostream>
#include <vector>
#include <queue>

using namespace std;

priority_queue<long long, vector<long long>, greater<long long> > pq;

int main() {
    int n, m;
    cin >> n >> m; // n개의 입력, m번의 합

    int card;
    for (int i =0; i<n; i++) {
        cin >> card;
        pq.push(card);
    }

    long long a, b, sum;
    while (m--) {
        a = pq.top(); pq.pop();
        b = pq.top(); pq.pop();
        sum = a + b;
        pq.push(sum);
        pq.push(sum);
    }
    long long result = 0;
    int k = pq.size();
    while (k--) {
        result += pq.top();
        pq.pop();
    }
    cout << result;
}
