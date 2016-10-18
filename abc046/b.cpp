#include <iostream>//cin/cout/wcin/wcout/left/right/internal/dec/hex/oct/fixed/scientific

using namespace std;

int main(void) {
    size_t n;
    unsigned long k;
    cin >> n >> k;
    unsigned long a = k;
    --k;
    for(size_t i = 0; i < n-1; ++i)
        a *= k;
    
    cout << a << endl;
    return 0;
}
