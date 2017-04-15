// DATA STRUCTURES
#include <vector>

// MISCELLANEOUS
#include <algorithm>//min/max/sort(rand-access it)/merge
#include <iostream>//cin/cout/wcin/wcout/left/right/internal/dec/hex/oct/fixed/scientific

typedef unsigned long long ull;

// --------------------------------------------------------------------------------------

using namespace std;

int main(void)
{
    size_t n;
    cin >> n;
    n *= 3;
    vector<ull> a;
    for (size_t i = 0; i < n; ++i) {
        int temp; cin >> temp;
        a.push_back(temp);
    }
    sort(a.begin(), a.end());

    ull total = 0UL;
    for (size_t i = n/3; i < n; i += 2) {
        total += a[i];
    }
    cout << total << '\n';
    return 0;
}
