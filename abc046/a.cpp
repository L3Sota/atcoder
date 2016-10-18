#include <iostream>//cin/cout/wcin/wcout/left/right/internal/dec/hex/oct/fixed/scientific

using namespace std;

int main(void) {
    const size_t nums = 101;
    size_t hello[nums];
    for(size_t i = 0; i < nums; ++i)
        hello[i] = 0;
    size_t a, b, c;
    cin >> a >> b >> c;
    ++hello[a];
    ++hello[b];
    ++hello[c];
    size_t count = 0;
    for(size_t i = 0; i < nums; ++i)
        if(hello[i]) ++count;
    cout << count << endl;

    return 0;
}
