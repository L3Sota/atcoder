#include <iostream>//cin/cout/wcin/wcout/left/right/internal/dec/hex/oct/fixed/scientific

using namespace std;

int main(void)
{
    char hack[10] = {'h','a','c','k','e','r','r','a','n','k'};
    int q;
    cin >> q;
    for (size_t i = 0; i < q; ++i) {
        string s;
        cin >> s;
        size_t pos = 0;
        for (size_t j = 0; j < s.size(); ++j) {
            if (pos == 10) {
                break;
            }
            if (s[j] == hack[pos]) {
                ++pos;
            }
        }
        cout << ((pos == 10) ? "YES\n" : "NO\n");
    }
    return 0;
}
