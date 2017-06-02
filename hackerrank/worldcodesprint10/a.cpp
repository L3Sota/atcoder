// MISCELLANEOUS
#include <iostream>//cin/cout/wcin/wcout/left/right/internal/dec/hex/oct/fixed/scientific

using namespace std;

int main(void) {
    int a, b, c;
    cin >> a >> b >> c;
    a *= 10; b *= 10; c *= 10;
    if (a > 100) { a = 100; }
    if (b > 100) { b = 100; }
    if (c > 100) { c = 100; }
    cout << (a + b + c) << '\n';
    return 0;
}
