// DATA STRUCTURES
#include <vector>

// MISCELLANEOUS
#include <algorithm>//min/max/sort(rand-access it)/merge
#include <iostream>//cin/cout/wcin/wcout/left/right/internal/dec/hex/oct/fixed/scientific

typedef unsigned int ui;

using namespace std;

int main(void)
{
    size_t n;
    cin >> n;
    vector<int> a;
    for (size_t i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        a.push_back(temp);
    }
    sort(a.begin(), a.end());
    ui shortest_dist = static_cast<ui>(a[1] - a[0]);
    ui count = 0U;
    for (size_t i = 0; i < n-1; ++i) {
        ui candidate = static_cast<ui>(a[i+1] - a[i]);
        if (shortest_dist > candidate) {
            shortest_dist = candidate;
            count = 1U;
        } else if (shortest_dist == candidate) {
            ++count;
        }
    }
    cout << shortest_dist << ' ' << count << '\n';

    return 0;
}
