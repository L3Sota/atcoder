// MISCELLANEOUS
#include <cstdlib>//abs/atof/atoi/atol/atoll/strtod/strtof/..., srand/rand, calloc/malloc, exit, qsort
#include <iostream>//cin/cout/wcin/wcout/left/right/internal/dec/hex/oct/fixed/scientific
#include <limits>//numeric_limits<type>::max/min/lowest/epsilon/infinity/quiet_NaN/signaling_NaN
#include <new>

#ifndef REP
#define REP(i,n) for (int i = 0; i < n; ++i)
#endif

const bool debug = true;

// --------------------------------------------------------------------------------------

using namespace std;

int main(void)
{
    int n, x;
    cin >> n >> x;
    int* xx = new int[n];
    REP(i,n) {
        cin >> xx[i];
    }
    int* vv = new int[n];
    REP(i,n) {
        cin >> vv[i];
    }

    int* times = new int[n];
    REP(i,n) {
        times[i] = abs(xx[i] - x) / vv[i];
    }
    int min_time = numeric_limits<int>::max();
    int argmin = -1;
    bool bad = false;
    REP(i,n) {
        if (min_time > times[i]) {
            min_time = times[i];
            argmin = i;
            bad = false;
        } else if (min_time == times[i]) {
            bad = true;
        }
    }
    cout << (bad ? -1 : argmin) << '\n';
    return 0;
}
