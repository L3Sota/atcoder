#include <iostream>//cin/cout/wcin/wcout/left/right/internal/dec/hex/oct/fixed/scientific

typedef unsigned long long ull;

using namespace std;

int main(void)
{
    ull a, b;
    cin >> a >> b;
    ull n = 0UL;
    while(a<=b) {
        ++n;
        a *= 3UL;
        b *= 2UL;
    }
    cout << n << '\n';
    return 0;
}
