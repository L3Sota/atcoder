// DATA STRUCTURES
#include <vector>

// MISCELLANEOUS
#include <iostream>//cin/cout/wcin/wcout/left/right/internal/dec/hex/oct/fixed/scientific

#ifndef REP
#define REP(i,n) for (int i = 0; i < n; ++i)
#endif

#ifndef READ
#define READ(x) std::cin >> x
#endif

// --------------------------------------------------------------------------------------

using namespace std;

int main(void)
{
    int t;
    cin >> t;
    REP(test,t)
    {
        int r, c;
        cin >> r >> c;
        vector<string> v;
        REP(i,r) {string s; READ(s); v.push_back(s);}
        vector<bool> vv;
        REP(i,r)
        {
            string qq = string(c, '?');
            if (v[i] == qq) {
                vv.push_back(true);
            } else {
                vv.push_back(false);
                REP(j,c) {
                    bool found = false;
                    if (v[i][j] == '?') {
                        for (int jj = j+1; jj < c; ++jj) {
                            if (v[i][jj] != '?') {
                                for (int jjj = j; jjj < jj; ++jjj) {
                                    v[i][jjj] = v[i][jj];
                                }
                                found = true;
                                break;
                            }
                        }
                        if (!found) {
                            for (int jj = j-1; jj >= 0; --jj) {
                                if (v[i][jj] != '?') {
                                    for (int jjj = jj+1; jjj <= j; ++jjj) {
                                        v[i][jjj] = v[i][jj];
                                    }
                                    found = true;
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }
        REP(i,r)
        {
            if (vv[i]) {
                for (int ii = i+1; ii < r; ++ii) {
                    if (!vv[ii]) {
                        for (int iii = i; iii < ii; ++iii) {
                            v[iii] = v[ii];
                        }
                        vv[i] = true;
                        break;
                    }
                }
                if (vv[i]) {
                    for (int ii = i-1; ii >= 0; --ii) {
                        if (!vv[ii]) {
                            for (int iii = ii+1; iii <= i; ++iii) {
                                v[iii] = v[ii];
                            }
                            vv[i] = true;
                            break;
                        }
                    }
                }
            }
        }

        cout << "Case #" << (test+1) << ":\n";
        REP(i,r) cout << v[i] << '\n';
    }
    return 0;
}
