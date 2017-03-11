#include <iostream>//cin/cout/wcin/wcout/left/right/internal/dec/hex/oct/fixed/scientific
#include <utility>//pair

using namespace std;

typedef unsigned long long ull;

int main(void)
{
    int g;
    cin >> g;
    for (int game = 0; game < g; ++game)
    {
        size_t n, m;
        ull x;
        cin >> n >> m >> x;

        ull* a = new ull[n];
        ull* b = new ull[m];

        for (size_t i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (size_t i = 0; i < m; ++i) {
            cin >> b[i];
        }

        ull* aps = new ull[n];
        ull* bps = new ull[m];
        size_t best_a = 0;
        size_t best_b = 0;
        aps[0] = a[0];
        bps[0] = b[0];
        for (size_t i = 1; i < n; ++i)
        {
            aps[i] = aps[i-1] + a[i];
            if (aps[i] <= x) { best_a = i; }
            else { break; }
        }
        for (size_t i = 1; i < m; ++i)
        {
            bps[i] = bps[i-1] + b[i];
            if (bps[i] <= x) { best_b = i; }
            else { break; }
        }

        /* trivial cases */
        if (a[0] > x && b[0] > x) 
            { cout << "0\n"; continue; }
        if (a[0] > x && b[0] <= x)
            { cout << (best_b+1) << '\n'; continue; }
        if (a[0] <= x && b[0] > x)
            { cout << (best_a+1) << '\n'; continue; }
 
        // force best_a >= best_b
        if (best_a < best_b) {
            swap(best_a, best_b);
            swap(n, m);
            swap(a, b);
            swap(aps, bps);
        }

        ull best_score = 1UL+(ull)best_a;
        for (size_t current_a = best_a, current_b = 0; current_a <= best_a && current_b <= best_b; ++current_b)
        {
            ull val;
            val = aps[current_a] + bps[current_b];
            if (val <= x) {
                ull new_score = current_a + current_b + 2UL;
                if (best_score < new_score) {
                    best_score = new_score;
                }
            } else {
                --current_a;
            }
        }

        cout << best_score << '\n';

        delete[] a;
        delete[] b;
        delete[] aps;
        delete[] bps;
    }

    return 0;
}
