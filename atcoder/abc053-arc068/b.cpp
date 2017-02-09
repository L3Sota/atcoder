#include <iostream>//cin/cout/wcin/wcout/left/right/internal/dec/hex/oct/fixed/scientific
#include <string>//stoi/stol/stoul/stoll/stoull/stof/stod/stold/to_string/getline

using namespace std;

int main(void)
{
    string s;
    cin >> s;
    int beg, end;
    beg = end = -1;

    for (int pos = 0;; ++pos)
    {
        if (s[pos] == 'A')
        {
            beg = pos;
            break;
        }
    }
    for (int pos = s.size()-1;; --pos)
    {
        if (s[pos] == 'Z')
        {
            end = pos;
            break;
        }
    }
 
    cout << (end - beg + 1) << endl;
 
    return 0;
}
