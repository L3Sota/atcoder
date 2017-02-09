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

    int x = a[0];
    int y = a[1];
    bool found = false;
    for (size_t i = 2; i < n; ++i)
    {
        if ((x + y) > a[i]) {
            found = true;
            break;
        }
        x = y;
        y = a[i];
    }

    cout << (found ? "YES" : "NO") << endl;

    return 0;
}
