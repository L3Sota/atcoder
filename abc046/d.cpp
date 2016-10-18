#include <iostream>//cin/cout/wcin/wcout/left/right/internal/dec/hex/oct/fixed/scientific
#include <string>//stoi/stol/stoul/stoll/stoull/stof/stod/stold/to_string/getline

using namespace std;

int main(void) {
    string s;
    cin >> s;
    int n = s.size();
    int score = n/2;
    for (int i = 0; i < n; ++i)
        if (s[i] == 'p')
            --score;;
    cout << score << endl;
    return 0;
}
