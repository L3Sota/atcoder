// DATA STRUCTURES
#include <vector>

// MISCELLANEOUS
#include <cmath>//fmin/fmax/fabs/sin(h)/cos(h)/tan(h)/exp/log/pow/sqrt/cbrt/ceil/floor/round/trunc
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
        int n, p;
        cin >> n >> p;
        vector<int> r;
        REP(i,n) {int temp; READ(temp); r.push_back(temp);}
        vector<vector<int>> count(n, vector<int>(1145141, 0));
        vector<vector<bool>> pass(n, vector<bool>(1145141, false));
        int smallest_num_servings = 1e6;
        int largest_num_servings = 1;
        int largest_q = 0;
        REP(ing,n) {
            int min_q = 1e6;
            int max_q = 0;
            REP(pack,p) {
                int q;
                READ(q);
                ++count[ing][q];
                if (max_q < q) { max_q = q; }
                if (min_q > q) { min_q = q; }
                int lesser = static_cast<int>(ceil(q / (r[ing] * 1.11)));
                int higher = static_cast<int>(floor(q / (r[ing] * 0.89)));
                for (int index = lesser; index <= higher; ++index) {
                    pass[ing][index] = true;
                }
            }
            int smns = static_cast<int>(ceil(min_q / (r[ing] * 1.11)));
            int lans = static_cast<int>(floor(max_q / (r[ing] * 0.89)));
            if (smallest_num_servings > smns) { smallest_num_servings = smns; }
            if (largest_num_servings < lans) { largest_num_servings = lans; }
        }

        int kits = 0;
        for (int num_servings = smallest_num_servings; num_servings <= largest_num_servings; ++num_servings)
        {
            bool keep_going = true;
            REP(i,n) {
                if (!pass[i][num_servings]) { keep_going = false; break; }
            }
            if (!keep_going) { continue; }
            bool fulfilled = true;
            vector<int> erase;
            REP(ing,n)
            {
                int lower = static_cast<int>(ceil(r[ing]*num_servings*0.9));
                int higher = static_cast<int>(min(floor(r[ing]*num_servings*1.1), 1e6));
                int argmax = -1;
                int maxval = 0;
                for (int ind = lower; ind <= higher; ++ind) {
                    if (count[ing][ind] > maxval) {
                        maxval = count[ing][ind];
                        argmax = ind;
                    }
                }
                if (argmax == -1) {
                    fulfilled = false;
                    break;
                } else {
                    erase.push_back(argmax);
                }
            }
            if (fulfilled) {
                REP(j,n) {--count[j][erase[j]];}
                ++kits;
                --num_servings;
                if (kits == p) {
                    break;
                }
            }
        }

        cout << "Case #" << (test+1) << ": " << kits << '\n';
    }
    return 0;
}
