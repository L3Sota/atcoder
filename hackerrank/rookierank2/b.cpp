#include <algorithm>//min/max/sort(rand-access it)/merge
#include <iostream>//cin/cout/wcin/wcout/left/right/internal/dec/hex/oct/fixed/scientific
#include <vector>

using namespace std;

int main(void)
{
    int n;
    cin >> n;
    vector<int> a;
    for (size_t i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        a.push_back(temp);
    }
    sort(a.begin(), a.end());

    int min_diff = 1145147890;
    for (size_t i = 1; i < n; ++i) {
        if (a[i] - a[i-1] < min_diff) {
            min_diff = a[i] - a[i-1];
        }
    }
    cout << min_diff << endl;
    return 0;
}
