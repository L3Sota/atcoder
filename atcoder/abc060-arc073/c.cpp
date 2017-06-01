// DATA STRUCTURES
#include <vector>

// MISCELLANEOUS
#include <iostream>//cin/cout/wcin/wcout/left/right/internal/dec/hex/oct/fixed/scientific

#ifndef REPST
#define REPST(i,n) for (size_t i = 0; i < n; ++i)
#endif

typedef unsigned long long ull;

// --------------------------------------------------------------------------------------

using namespace std;

int main(void)
{
    size_t n;
    ull t;
    cin >> n >> t;
    std::vector<ull> v(n);
    REPST(i,n) cin >> v[i];
    ull ends = 0;
    ull total = 0;
    REPST(i,n) {
        total += (ends <= v[i]) ? t : (v[i] + t - ends);
        ends = v[i] + t;
    }
    cout << total << '\n';

    return 0;
}
