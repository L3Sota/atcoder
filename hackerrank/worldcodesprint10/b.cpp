// DATA STRUCTURES
#include <list>

// MISCELLANEOUS
#include <algorithm>//min/max/sort(rand-access it)/merge
#include <iostream>//cin/cout/wcin/wcout/left/right/internal/dec/hex/oct/fixed/scientific

using namespace std;

#ifndef REP
#define REP(i,n) for (int i = 0; i < n; ++i)
#endif

list<int>::iterator zigzag(list<int>& v) {
    if (v.size() < 2) return v.end();
    auto one = v.begin();
    auto initial = one++;
    bool upwards = *initial < *one;
    for (auto next = ++(v.begin()); next != v.end(); ++next) {
        auto point = next++;
        if (next == v.end()) break;
        std::cerr << upwards << '\n';
        if (upwards) {
            if (*point < *next) {
                return point;
            } else {
                upwards = false;
            }
        } else {
            if (*point > *next) {
                return point;
            } else {
                upwards = true;
            }
        }
        next = point;
    }
    return v.end();
}

int main(void) {
    int n;
    cin >> n;
    list<int> v;
    REP(i,n) { int t; cin >> t; v.push_back(t); }
    auto zz = zigzag(v);
    std::cerr << "a\n";
    while (zz != v.end()) {
        v.erase(zz);
        zz = zigzag(v);
        std::cerr << "b\n";
    }
    cout << (n - v.size()) << '\n';
    return 0;
}
