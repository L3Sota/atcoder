#include <algorithm>//min/max/sort(rand-access it)/merge
#include <iostream>//cin/cout/wcin/wcout/left/right/internal/dec/hex/oct/fixed/scientific
#include <vector>

using namespace std;

typedef unsigned long long ull;

int main(void)
{
    int n; size_t k;
    cin >> n >> k;

    vector<int> a;
    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        a.push_back(temp);
    }

    sort(a.begin(), a.end());

    ull total = 0UL;
    for (size_t i = 0; i < k; ++i) {
        total += (ull)a[i];
    }
    cout << (total + (ull)(k*(k-1))/2) << '\n';

    return 0;
}
