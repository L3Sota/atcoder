#include <algorithm>//min/max/sort(rand-access it)/merge
#include <iostream>//cin/cout/wcin/wcout/left/right/internal/dec/hex/oct/fixed/scientific
#include <string>//stoi/stol/stoul/stoll/stoull/stof/stod/stold/to_string/getline

using namespace std;

int main(void)
{
    string a, b;
    cin >> a >> b;
    cout << ((a == b) ? -1 : (int)max(a.size(), b.size())) << endl;
    return 0;
}
