// MISCELLANEOUS
#include <algorithm>//min/max/sort(rand-access it)/merge
#include <iomanip>//setfill/setw/setprecision/fixed/scientific
#include <iostream>//cin/cout/wcin/wcout/left/right/internal/dec/hex/oct/fixed/scientific

#ifndef REP
#define REP(i,n) for (int i = 0; i < n; ++i)
#endif

// --------------------------------------------------------------------------------------

using namespace std;

int main(void)
{
    int t;
    cin >> t;
    cout << setprecision(numeric_limits<double>::digits10 + 1);
    REP(test,t)
    {
        double d;
        int n;
        cin >> d >> n;
        double slowest_time = 0.0;
        REP(i, n) {
            double k, s;
            cin >> k >> s;
            slowest_time = max(slowest_time, (d - k) / s);
        }
        cout << "Case #" << (test+1) << ": " << (d / slowest_time) << "\n";
    }
    return 0;
}
