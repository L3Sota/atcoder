#include <algorithm>//min/max/sort(rand-access it)/merge
#include <iostream>//cin/cout/wcin/wcout/left/right/internal/dec/hex/oct/fixed/scientific
#include <vector>

using namespace std;

typedef unsigned int ui;
typedef unsigned long long ull;

int main(void)
{
    ui n, c, k;
    cin >> n >> c >> k;
    std::vector<ui> t;
    for (size_t i = 0; i < n; ++i) {
        ui temp;
        cin >> temp;
        t.push_back(temp);
    }
    if (c == 1) {
        cout << n << endl;
        return 0;
    }
    sort(t.begin(), t.end());
    ull buses = 0UL;

    ui first_t = t[0];
    ui current_load = 1;
    for (size_t i = 1; i < n; ++i) {
        if (current_load == c || first_t + k < t[i]) {
            ++buses;
            first_t = t[i];
            current_load = 1;
        } else {
            ++current_load;
        }
    }

    cout << ++buses << endl;
    return 0;
}
