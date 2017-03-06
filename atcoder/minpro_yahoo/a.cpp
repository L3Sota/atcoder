#include <iostream>//cin/cout/wcin/wcout/left/right/internal/dec/hex/oct/fixed/scientific
#include <string>//stoi/stol/stoul/stoll/stoull/stof/stod/stold/to_string/getline

using namespace std;

int main(void)
{
    string s;
    cin >> s;

    int yahoo[4] = {0};

    for (size_t i = 0; i < s.size(); ++i) {
        switch (s[i])
        {
            case 'y': {++yahoo[0]; break;}
            case 'a': {++yahoo[1]; break;}
            case 'h': {++yahoo[2]; break;}
            case 'o': {++yahoo[3]; break;}
            default: break;
        }
    }
    if (yahoo[0] == 1 && yahoo[1] == 1 && yahoo[2] == 1 && yahoo[3] == 2) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}
