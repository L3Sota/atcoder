// DATA STRUCTURES
#include <vector>

// MISCELLANEOUS
#include <iostream>//cin/cout/wcin/wcout/left/right/internal/dec/hex/oct/fixed/scientific

#ifndef REPST
#define REPST(i,n) for (size_t i = 0; i < n; ++i)
#endif

// --------------------------------------------------------------------------------------

using namespace std;

int main(void)
{
    int n, k;
    cin >> n >> k;
    vector<int> sieve;
    for (int i = 2; k > 1 && i < n; ++i) {
        if (!(n % i)) {
            sieve.push_back(i);
            --k;
            n /= i;
            --i;
        }
    }
    if (k > 1) {
        cout << "-1\n";
    } else {
        REPST(i, sieve.size()) cout << sieve[i] << ' ';
        cout << n << '\n';
    }

    return 0;
}
