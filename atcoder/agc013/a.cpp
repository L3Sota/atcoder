// MISCELLANEOUS
#include <iostream>//cin/cout/wcin/wcout/left/right/internal/dec/hex/oct/fixed/scientific

#ifndef REPST
#define REPST(i,n) for (size_t i = 0; i < n; ++i)
#endif

typedef unsigned int ui;

// --------------------------------------------------------------------------------------

using namespace std;

int main(void)
{
    size_t n;
    cin >> n;
    int a, prev, stat = 0;
    ui count = 0;
    cin >> a;
    REPST(i,n-1) {
        prev = a;
        cin >> a;
        switch (stat) {
            case 0: {
                if (a > prev) { stat = 1; }
                else if (a < prev) { stat = -1; }
                break;
            }
            case 1: {
                if (a < prev) { ++count; stat = 0; }
                break;
            }
            case -1: {
                if (a > prev) { ++count; stat = 0; }
                break;
            }
            default: { break; }
        }
    }
    cout << (++count) << '\n';

    return 0;
}
