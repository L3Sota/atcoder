// DATA STRUCTURES
#include <tuple>

// MISCELLANEOUS
#include <iostream>//cin/cout/wcin/wcout/left/right/internal/dec/hex/oct/fixed/scientific
#include <new>
#include <string>//stoi/stol/stoul/stoll/stoull/stof/stod/stold/to_string/getline
#include <utility>//pair

#ifndef REPST
#define REPST(i,n) for (size_t i = 0; i < n; ++i)
#endif

// --------------------------------------------------------------------------------------

using namespace std;

int main(void)
{
    int n, m;
    cin >> n >> m;
    int last_floor = 0;
    int dp_left = 0;
    int dp_right = m+1;
    int answer = 0;
    string* ss = new string[n];
    REPST(i,n) {
        cin >> ss[i];
    }
    REPST(i,n) {
        string s = ss[n-1-i];
        int leftmost = s.find('1');
        int rightmost = s.rfind('1');
        if (leftmost == string::npos) {
            continue;
        } else {
            last_floor = i;
            if (i == 0) {
                answer = dp_left + rightmost;
                dp_left += 2*rightmost;
            } else {
                answer = min(dp_left + rightmost, dp_right + m+1 - leftmost);
                tie(dp_left, dp_right) = make_pair(
                    min(dp_left + 2*rightmost, dp_right + m+1),
                    min(dp_right + 2*(m+1 - leftmost), dp_left + m+1)
                );
            }
        }
    }
    cout << (answer + last_floor) << '\n';
    delete[] ss;
    return 0;
}
