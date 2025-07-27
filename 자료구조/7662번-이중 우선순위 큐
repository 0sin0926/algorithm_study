#include <iostream>
#include <set>

using namespace std;

int main() {
    int t, k, insertIndex, dIndex;
    char cmd;
    multiset<int> ms;

    cin >> t;
    while (t--) {
        cin >> k;
        while (k--) {
            cin >> cmd;
            if (cmd == 'I') {
                cin >> insertIndex;
                ms.insert(insertIndex);
            }
            else {
                cin >> dIndex;
                if (!ms.empty()) {
                    if (dIndex == -1) ms.erase(ms.begin());
                    else ms.erase(prev(ms.end()));
                }
            }
        }
        if (ms.empty()) cout << "EMPTY\n";
        else cout << *prev(ms.end()) << " " << *ms.begin()  << "\n";
        ms.clear();
    }



}
