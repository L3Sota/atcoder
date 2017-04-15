// DATA STRUCTURES
#include <queue>
#include <vector>

// MISCELLANEOUS
#include <iostream>//cin/cout/wcin/wcout/left/right/internal/dec/hex/oct/fixed/scientific
#include <iterator>

typedef unsigned int ui;
typedef unsigned long long ull;

// --------------------------------------------------------------------------------------

using namespace std;

int main(void)
{
    ui t;
    cin >> t;
    for (ui test = 1; test <= t; ++test) {
        ull n, k;
        cin >> n >> k;
        queue<ull> q;
        q.push(n);
        q.push(n);
        ull count = 0;
        ull vsize = 2;
        vector<ull> v;
        while (count < k)
        {
            q.pop();
            ull qq = q.front();
            if (qq) {
                ++count;
                v.push_back(qq/2);
                v.push_back((qq-1)/2);
            }
            if (v.size() == vsize) {
                bool all_equal = true;
                for (size_t i = 0; i < v.size(); ++i) {
                    if (v[0] != all_equal) {
                        all_equal = false;
                        break;
                    }
                }
                if (all_equal) {
                    ull val_s = v[0];
                    ull val_l = v[0];
                    while (count < k && val_s == val_l)
                    {
                        vsize *= 2;
                        count += vsize;
                        val_s = (val_s - 1)/2;
                        val_l = val_l/2;
                    }
                    if (val_s == val_l) {
                        cout << "Case #" << test << ": " << val_l << ' ' << val_s << '\n';
                        return 0;
                    } else {
                        for (size_t i = 0; i < vsize/2; ++i) {
                            q.push(val_l);
                        }
                        for (size_t i = 0; i < vsize/2; ++i) {
                            q.push(val_s);
                        }
                    }
                } else {
                    sort(v.begin(), v.end(), greater<ull>());
                    for (size_t i = 0; i < v.size(); ++i) {
                        q.push(v[i]);
                    }
                    vsize *= 2;
                    v = vector<ull>();
                }
            }
        }
        ull qq = q.front();
        cout << "Case #" << test << ": " << (qq/2) << ' ' << ((qq-1)/2) << '\n';
    }

    return 0;
}
