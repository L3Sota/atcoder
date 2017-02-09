#include <algorithm>//min/max/sort(rand-access it)/merge
#include <iostream>//cin/cout/wcin/wcout/left/right/internal/dec/hex/oct/fixed/scientific

using namespace std;

typedef unsigned long long ull;

int main(void) {
    int n;
    cin >> n;
    ull t, a, t_prev, a_prev;
    cin >> t >> a;
    for (int i = 1; i < n; ++i)
    {
        ull m_t, m_a, m;
        t_prev = t;
        a_prev = a;
        cin >> t >> a;
        if (t >= t_prev && a >= a_prev) {
            continue;
        } else {
            m_t = t_prev / t + (t_prev % t ? 1 : 0);
            m_a = a_prev / a + (a_prev % a ? 1 : 0);
            m = max(m_t, m_a);
            t *= m;
            a *= m;
        }
    }
    cout << (a + t) << endl;
    return 0;
}
