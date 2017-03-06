#include <iostream>//cin/cout/wcin/wcout/left/right/internal/dec/hex/oct/fixed/scientific
#include <string>//stoi/stol/stoul/stoll/stoull/stof/stod/stold/to_string/getline

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;

    a = (a+11)%13;
    b = (b+11)%13;

    if (a  > b) { cout << "Alice\n"; }
    if (a  < b) { cout << "Bob\n"; }
    if (a == b) { cout << "Draw\n"; }

    return 0;
}
