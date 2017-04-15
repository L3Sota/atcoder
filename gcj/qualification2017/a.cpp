// MISCELLANEOUS
#include <iostream>//cin/cout/wcin/wcout/left/right/internal/dec/hex/oct/fixed/scientific
#include <string>//stoi/stol/stoul/stoll/stoull/stof/stod/stold/to_string/getline

typedef unsigned int ui;

// --------------------------------------------------------------------------------------

using namespace std;

int main(void)
{
    size_t t;
    cin >> t;
    for (size_t i = 1; i <= t; ++i) {
        string s;
        cin >> s;
        size_t k;
        cin >> k;
        ui flips = 0;
        for (size_t j = 0; j <= s.size() - k; ++j) {
            if (s[j] == '-') {
                ++flips;
                for (size_t dj = 0; dj < k; ++dj) {
                    s[j + dj] = (s[j + dj] == '+') ? '-' : '+';
                }
            }
        }
        bool correct = true;
        for (size_t j = s.size() - k; j < s.size(); ++j) {
            if (s[j] == '-') {
                correct = false;
                break;
            }
        }
        cout << "Case #" << i << ": " << (correct ? to_string(flips) : "IMPOSSIBLE") << '\n';
    }
    return 0;
}
