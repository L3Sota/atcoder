#include <iostream>//cin/cout/wcin/wcout/left/right/internal/dec/hex/oct/fixed/scientific

using namespace std;

int main(void)
{
    int a[5] = {0, 0, 0, 0, 0};
    int n;
    cin >> n;
    for (size_t i = 0; i < n; ++i) {
        size_t t;
        cin >> t;
        --t;
        ++a[t];
    }

    int highest = 0;
    int type = -1;
    for (size_t i = 0; i < 5; ++i) {
        if (highest < a[i]) {
            highest = a[i];
            type = i;
        }
    }

    cout << (type + 1) << endl;
    return 0;
}
