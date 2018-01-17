#include <algorithm>//min/max/sort(rand-access it)/merge
#include <iostream>//cin/cout/wcin/wcout/left/right/internal/dec/hex/oct/fixed/scientific
#include <string>//stoi/stol/stoul/stoll/stoull/stof/stod/stold/to_string/getline

#ifndef REP
#define REP(i,n) for (int i = 0; i < n; ++i)
#endif

using namespace std;

int main(void)
{
    int n;
    cin >> n;

    int* count = new int[n];
    string* names = new string[n];
    REP(i,n) {
        count[i] = 0;
        names[i] = "";
    }

    REP(voter,n) {
        string vote;
        cin >> vote;
        REP(i,n) {
            if (names[i] == "") names[i] = vote;
            if (names[i] == vote) {
                ++(count[i]);
                break;
            }
        }
    }
    cout << names[distance(count, max_element(count, count+n))] << endl;

    delete[] count;
    delete[] names;
    return 0;
}
