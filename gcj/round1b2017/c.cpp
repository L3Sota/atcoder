// DATA STRUCTURES
#include <set>
#include <stack>
#include <vector>

// MISCELLANEOUS
#include <iomanip>//setfill/setw/setprecision/fixed/scientific
#include <iostream>//cin/cout/wcin/wcout/left/right/internal/dec/hex/oct/fixed/scientific

#ifndef REP
#define REP(i,n) for (int i = 0; i < n; ++i)
#endif

#ifndef REPST
#define REPST(i,n) for (size_t i = 0; i < n; ++i)
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
        size_t n;
        int q;
        cin >> n >> q;
        vector<double> distv, speedv;
        REP(i,n) {
            double e, s;
            cin >> e >> s;
            distv.push_back(e);
            speedv.push_back(s);
        }
        double** distm = new double*[n];
        REP(i,n) {
            distm[i] = new double[n];
            REP(j,n) {
                cin >> distm[i][j];
            }
        }
        cout << "Case #" << (test+1) << ": ";
        REP(qq,q) {
            int s, e;
            cin >> s >> e;
            --s; --e;
            vector<double> dp(n, numeric_limits<double>::max());
            dp[s] = 0.0;
            set<int> updated;
            updated.insert(s);
            vector<bool> updated_touch(n, false);
            updated_touch[e] = true;
            updated_touch[s] = true;
            while (updated.size()) {
                bool touch = true;
                REP(i,n) {
                    if (!updated_touch[i]) {
                        touch = false;
                        break;
                    }
                }
                if (touch) {
                    break;
                }
                set<int> next_updated;
                for(auto it = updated.begin(); it != updated.end(); ++it) { // start from i
                    int i = *it;
                    updated_touch[i] = true;
                    cerr << "from " << i << '\n';
                    stack<pair<int, double>> dfs;
                    REPST(j,n) { // attempt to reach j
                        if (distm[i][j] == -1 || distm[i][j] > distv[i]) {
                            continue;
                        }
                        double timetotal = distm[i][j] / speedv[i];
                        if (dp[j] > dp[i] + timetotal) {
                            dp[j] = dp[i] + timetotal;
                        }
                        if (j != e) {
                            next_updated.insert(j);
                            dfs.emplace(j, distm[i][j]);
                            cerr << "to " << j << '\n';
                        }
                    }
                    while (!dfs.empty()) {
                        int k; double distorig;
                        tie(k, distorig) = dfs.top();
                        dfs.pop();
                        cerr << "stack " << k << '\n';
                        REPST(j,n) {
                            if (distm[k][j] == -1) {
                                continue;
                            }
                            double disttotal = distorig + distm[k][j];
                            if (disttotal > distv[i]) {
                                continue;
                            }
                            cerr << "attempting " << k << " to " << j << '\n';
                            cerr << dp[j] << ' ' << dp[k] << ' ' << disttotal << ' ' << speedv[i] << '\n';
                            if (dp[j] > dp[i] + disttotal / speedv[i]) {
                                dp[j] = dp[i] + disttotal / speedv[i];
                                // dfs.emplace(j, disttotal);
                                // if (j != e) {
                                //     next_updated.insert(j);
                                // }
                                cerr << "to " << j << "(stack)\n";
                            }
                            if (j != e) {
                                dfs.emplace(j, disttotal);
                                next_updated.insert(j);
                            }
                        }
                    }
                    cerr << "DFS end\n";
                    REP(nnn,n) {
                        cerr << dp[nnn] << ' ';
                    }
                    cerr << '\n';
                }
                updated = next_updated;
            }
            cout << dp[e];
            if (qq == q-1) {
                cout << '\n';
            } else {
                cout << ' ';
            }
        }
    }
    return 0;
}
