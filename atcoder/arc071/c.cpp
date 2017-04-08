// DATA STRUCTURES
#include <vector>

// MISCELLANEOUS
#include <iostream>//cin/cout/wcin/wcout/left/right/internal/dec/hex/oct/fixed/scientific

typedef unsigned int ui;

using namespace std;

static const int alph = 26;

int main(void)
{
    size_t n;
    cin >> n;
    ui v[alph] = {0};
    {
        string ss;
        cin >> ss;
        for (size_t i = 0; i < ss.size(); ++i) {
            ++v[ss[i] - 'a'];
        }
    }
    for (size_t i = 1; i < n; ++i) {
        ui v_other[alph] = {0};
        string s;
        cin >> s;
        for (size_t j = 0; j < s.size(); ++j) {
            ++v_other[s[j] - 'a'];
        }
        for (size_t j = 0; j < alph; ++j) {
            v[j] = std::min(v[j], v_other[j]);
        }
    }

    for (size_t i = 0; i < alph; ++i) {
        for (size_t j = 0; j < v[i]; ++j) {
            cout << static_cast<char>(i + 'a');
        }
    } cout << '\n';

    return 0;
}
