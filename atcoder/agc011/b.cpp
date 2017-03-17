#include <algorithm>//min/max/sort(rand-access it)/merge
#include <iostream>//cin/cout/wcin/wcout/left/right/internal/dec/hex/oct/fixed/scientific
#include <vector>

using namespace std;

typedef unsigned long long ull;

int main(void)
{
    size_t n;
    cin >> n;

    vector<ull> a;
    for (size_t i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        a.push_back(temp);
    }

    sort(a.begin(), a.end());

    ull streak = 0UL;
    ull sum = 0UL;
    for (size_t i = 0; i < n; ++i) {
        sum += a[i];
        ull next = a[i+1];
        if (next <= 2*sum)
            { ++streak; }
        else 
            { streak = 0UL; }
    }

    cout << streak << endl;
    return 0;
}
