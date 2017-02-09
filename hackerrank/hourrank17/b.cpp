#include <algorithm>//min/max/sort(rand-access it)/merge
#include <iostream>//cin/cout/wcin/wcout/left/right/internal/dec/hex/oct/fixed/scientific
#include <vector>

using namespace std;

int main() {
    int cases;
    cin >> cases;
    for (int current_case = 0; current_case < cases; ++current_case)
    {
        int n;
        cin >> n;
        vector<int> rsum;
        vector<int> csum;
        for (int i = 0; i < n; ++i) {
            rsum.push_back(0);
            csum.push_back(0);
        }

        for (int i = 0; i < n; ++i) {
            rsum[i] = 0;
            for (int j = 0; j < n; ++j) {
                int temp;
                cin >> temp;
                rsum[i] += temp;
                csum[j] += temp;
            }
        }

        sort(rsum.begin(), rsum.end());
        sort(csum.begin(), csum.end());

        bool possible = true;
        for (int i = 0; i < n; ++i) {
            if (rsum[i] != csum[i]) {
                possible = false;
                break;
            }
        }

        cout << (possible ? "Possible" : "Impossible") << endl;
    }
    
    return 0;
}

