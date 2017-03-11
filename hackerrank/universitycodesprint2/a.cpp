#include <iostream>//cin/cout/wcin/wcout/left/right/internal/dec/hex/oct/fixed/scientific

using namespace std;

int main(void)
{
    int q;
    cin >> q;
    int x, n;
    cin >> x;
    n = x;
    int cx, cn;
    cx = cn = 0;
    for (int i = 1; i < q; ++i) {
        int t;
        cin >> t;
        if (x < t) {
            x = t;
            ++cx;
        }
        if (n > t) {
            n = t;
            ++cn;
        }
    }
    cout << cx << ' ' << cn << '\n';
    return 0;
}
