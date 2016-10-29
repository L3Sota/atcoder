#include <iostream>//cin/cout/wcin/wcout/left/right/internal/dec/hex/oct/fixed/scientific

using namespace std;

template<typename T> void rar(size_t n, T* a);

int main(void) {
    size_t n;
    cin >> n;
    char *s, *t;
    s = new char[n];
    t = new char[n];
    rar(n, s); rar(n, t);
    size_t start = 0;//where t starts
    size_t search = 0;//current search pos in t
    for (size_t pos = 0; pos < n; ++pos)
    {
        if (s[pos] == t[search]) {//match
            ++search;
        } else if (s[pos] == t[0]) {//no match; new search match
            start = pos;
            search = 1;
        } else {//new search no match
            start = pos+1;
            search = 0;
        }
    }
    cout << start+n << endl;
    return 0;
}

template<typename T>
void rar(size_t n, T* a) {
    for (size_t i = 0; i < n; ++i) cin >> a[i];
    return;
}
