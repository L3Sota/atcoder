#include <iostream>//cin/cout/wcin/wcout/left/right/internal/dec/hex/oct/fixed/scientific
#include <string>//stoi/stol/stoul/stoll/stoull/stof/stod/stold/to_string/getline
#include <vector>

using namespace std;

typedef unsigned int ui;
typedef unsigned long long ull;

ui digits(ull n)
{
    ui dig = 1;
    while(n >= 10)
    {
        n /= 10;
        ++dig;
    }
    return dig;
}

int main(void)
{
    int q;
    cin >> q;
    vector<string> v;
    for (int qr = 0; qr < q; ++qr) {
        string s;
        cin >> s;
        v.push_back(s);
    }
    for (int qr = 0; qr < q; ++qr) {
        string s = v[qr];
        if (s[0] == '0') {
            cout << "NO\n";
            continue;
        }
        ull beautiful = 0UL;
        for (size_t initial_length = 1; initial_length <= s.size()/2; ++initial_length) {
            ull first_num = (ull)stoll(s.substr(0,initial_length));
            ull num = first_num + 1UL;
            size_t pos = initial_length;
            while(pos < s.size()) {
                ui len = digits(num);
                if (pos + len > s.size()) {
                    pos = s.size() + 1;
                    break;
                }
                if (s.substr(pos, len) != to_string(num)) {
                    pos = s.size() + 1;
                    break;
                }
                ++num;
                pos += len;
            }
            if (pos == s.size()) {
                beautiful = first_num;
                break;
            }
        }
        cout << ((beautiful == 0) ? "NO\n" : ("YES "+to_string(beautiful)+"\n"));
    }

    return 0;
}
