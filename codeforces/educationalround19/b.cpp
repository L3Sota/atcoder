// DATA STRUCTURES
#include <vector>

// MISCELLANEOUS
#include <iostream>//cin/cout/wcin/wcout/left/right/internal/dec/hex/oct/fixed/scientific
#include <limits>//numeric_limits<type>::max/min/lowest/epsilon/infinity/quiet_NaN/signaling_NaN

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
    int n;
    vector<int> a;
    cin >> n;
    REP(i,n) {int temp; READ(temp); a.push_back(temp);}
    int dp_odd_pos = 0;
    int dp_odd_neg = numeric_limits<int>::lowest() + 114514;
    int dp_even_pos = -1;
    int dp_even_neg = numeric_limits<int>::lowest() + 114514;
    bool only_neg_odd = true;
    bool only_neg_eve = true;
    if (a[0] > 0) {
        if (a[0] % 2)
            { dp_odd_pos = a[0]; only_neg_odd = false; }
        else
            { dp_even_pos = a[0]; only_neg_eve = false; }
    } else {
        if (a[0] % 2)
            { dp_odd_neg = a[0]; }
        else
            { dp_even_neg = a[0]; }
    }
    for (int i = 1; i < n; ++i) {
        int dpop = dp_odd_pos;
        int dpon = dp_odd_neg;
        int dpep = dp_even_pos;
        int dpen = dp_even_neg;

        if (a[i] > 0) {
            if (a[i] % 2) {//odd a
                if (only_neg_eve) {
                    if (only_neg_odd) {
                        dpen = max(dp_even_neg, dp_odd_neg + a[i]);
                        dpon = max(dp_odd_neg, dp_even_neg + a[i]);
                        dpop = max(dp_odd_pos, a[i]);
                        only_neg_odd = false;
                    } else {
                        dpep = max(dp_even_pos, dp_odd_pos + a[i]);
                        dpop = max(dp_odd_pos, a[i]);
                        only_neg_eve = false;
                    }
                } else {
                    if (only_neg_odd) {
                        dpep = max(dp_even_pos, dp_odd_neg + a[i]);
                        dpon = max(dp_odd_neg, dp_even_pos + a[i]);
                        only_neg_odd = false;
                    } else {
                        dpep = max(dp_even_pos, dp_odd_pos + a[i]);
                        dpop = max(dp_odd_pos, dp_even_pos + a[i]);
                    }
                }
            } else {//even a
                if (only_neg_eve) {
                    dpep = max(dp_even_pos, a[i]);
                    only_neg_eve = false;
                } else {
                    dpep = max(dp_even_pos, dp_even_pos + a[i]);
                }

                if (only_neg_odd) {
                    dpon = max(dp_odd_neg, dp_odd_neg + a[i]);
                } else {
                    dpop = max(dp_odd_pos, dp_odd_pos + a[i]);
                }
            }
        } else if (a[i] < 0) {
            if (a[i] % 2) {//odd a
                //dpon update
                dpon = max(dpon, a[i]);
                if (!only_neg_eve) {
                    dpon = max(dpon, dp_even_pos + a[i]);
                }
                //dpen update
                if (!only_neg_odd) {
                    dpen = max(dpen, dp_odd_pos + a[i]);
                }
            } else {//even a
                //dpon update
                //dpen update
                dpen = max(dpon, a[i]);
            }
        } else {//a[i] == 0
            if (only_neg_eve) {
                only_neg_eve = false;
                dpep = 0;
            }
        }

        if (dpon > 0) {
            only_neg_odd = false;
            if (dpop < dpon) {
                dpop = dpon;
            }
            dpon = -1;
        }
        if (dpen >= 0) {
            only_neg_eve = false;
            if (dpep < dpen) {
                dpep = dpen;
            }
            dpen = -2;
        }
        //update
        dp_odd_pos = dpop;
        dp_odd_neg = dpon;
        dp_even_pos = dpep;
        dp_even_neg = dpen;
    }
    cout << (only_neg_odd ? dp_odd_neg : dp_odd_pos) << '\n';
    return 0;
}
