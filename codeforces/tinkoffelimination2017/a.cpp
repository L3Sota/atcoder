// DATA STRUCTURES
#include <vector>

// MISCELLANEOUS
#include <algorithm>//min/max/sort(rand-access it)/merge
#include <iostream>//cin/cout/wcin/wcout/left/right/internal/dec/hex/oct/fixed/scientific
#include <iterator>//pair

#ifndef REP
#define REP(i,n) for (int i = 0; i < n; ++i)
#endif

typedef unsigned int ui;
typedef unsigned long long ull;

const bool debug = true;

// --------------------------------------------------------------------------------------

using namespace std;

int main(void)
{
    ui n, k;
    cin >> n >> k;
    vector<int> a;
    ull b = 0;
    REP(i,n) {
        int t;
        cin >> t;
        a.push_back(t);
    }
    int mmm = *min_element(a.begin(), a.end());
    REP(i,n) {
        if ((a[i] - mmm) % k) {
            cout << "-1\n";
            return 0;
        } else {
            b += ((a[i] - mmm) / k);
        }
    }
    cout << b << '\n';
    return 0;
}