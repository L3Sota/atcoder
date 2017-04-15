// MISCELLANEOUS
#include <iostream>//cin/cout/wcin/wcout/left/right/internal/dec/hex/oct/fixed/scientific
#include <string>//stoi/stol/stoul/stoll/stoull/stof/stod/stold/to_string/getline

typedef unsigned int ui;

// --------------------------------------------------------------------------------------

using namespace std;

int main(void)
{
    ui t;
    cin >> t;
    for (ui test = 1; test <= t; ++test) {
        string s;
        cin >> s;
        bool found = false;
        while (!found) {
            found = true;
            char current = s[0];
            for (size_t i = 1; i < s.size(); ++i) {
                if (current <= s[i]) {
                    current = s[i];
                } else {
                    --s[i-1];
                    for (size_t j = i; j < s.size(); ++j) {
                        s[j] = '9';
                    }
                    found = false;
                    break;
                }
            }
            if (found) {
                cout << "Case #" << test << ": " << stoll(s) << '\n';
                break;
            }
        }
    }

    return 0;
}
