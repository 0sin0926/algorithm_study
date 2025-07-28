#include <iostream>
#include <cmath>
using namespace std;

bool check[250000];
void count(int n) {
    int cnt = 0;
    for (int i = n+1; i <= 2*n; i++) {
        if (!check[i]) cnt++;
    }
    cout << cnt << "\n";
}
int main() {
    for (int i = 2; i < 250000; i++) {
        check[i] = false;
    }
    for (int i = 2; i <= sqrt(250000); i++) {
        if (check[i]) continue;
        for (int j = 2; i*j <= 250000; j++) {
            check[i*j] = true;
        }
    }

    int n;
    while (cin >> n && n != 0) {
        count(n);
        
    }
}
