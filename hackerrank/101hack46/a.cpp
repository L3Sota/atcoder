#include <algorithm>//min/max/sort(rand-access it)/merge
#include <iostream>//cin/cout/wcin/wcout/left/right/internal/dec/hex/oct/fixed/scientific
#include <vector>

using namespace std;

typedef unsigned long long ull;

int main(void)
{
    ull n;
    cin >> n;
    ull j = 1UL;
    ull mil = 0UL;
    vector<ull> cal;
    for (size_t i = 0; i < n; ++i) {
        ull temp; cin >> temp;
        cal.push_back(temp);
    }
    sort(cal.begin(), cal.end(), greater<ull>());
    for (size_t i = 0; i < n; ++i) {
        mil += cal[i]*j;
        j *= 2UL;
    }
    cout << mil << endl;
    return 0;
}
