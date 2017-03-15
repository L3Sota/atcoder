#include <algorithm>//min/max/sort(rand-access it)/merge
#include <array>
#include <bitset>
// #include <chrono>//std::chrono::/system_clock/steady_clock/high_resolution_clock/duration
#include <climits>//INT_MAX/INT_MIN/ULLONG_MAX
#include <cmath>//fmin/fmax/fabs/sin(h)/cos(h)/tan(h)/exp/log/pow/sqrt/cbrt/ceil/floor/round/trunc
#include <cstdlib>//abs/atof/atoi/atol/atoll/strtod/strtof/..., srand/rand, calloc/malloc, exit, qsort
// #include <fstream>//ifstream/ofstream
#include <iomanip>//setfill/setw/setprecision/fixed/scientific
#include <iostream>//cin/cout/wcin/wcout/left/right/internal/dec/hex/oct/fixed/scientific
#include <iterator>
#include <limits>//numeric_limits<type>::max/min/lowest/epsilon/infinity/quiet_NaN/signaling_NaN
#include <list>
#include <queue>
#include <string>//stoi/stol/stoul/stoll/stoull/stof/stod/stold/to_string/getline
#include <tuple>
#include <utility>//pair
#include <valarray>
#include <vector>

#define PRIME_SHORT 10007
#define PRIME 1000000007

using namespace std;

typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, int> plli;
typedef pair<ull, int> puli;
typedef pair<double, int> pdi;
typedef pair<ll, ll> pllll;
typedef pair<ull, ull> pulul;
typedef pair<double, double> pdd;
typedef tuple<int, int, int> ti3;
typedef tuple<int, int, int, int> ti4;

const bool debug = false;

template<typename T> void rar(size_t n, T* a);
template<typename T> void rar2(size_t n, size_t m, T** a);

template<typename T> T ipow(T base, T exp);

inline size_t left(size_t current, bool swap = false);
inline size_t right(size_t current, bool swap = false);

template<typename T> inline T griddist(T x, T y, T s, T t);
template<typename T> inline T griddist(pair<T, T> one, pair<T, T> two);
template<typename T> inline T griddist(tuple<T, T> one, tuple<T, T> two);

template<typename T> inline T sqeucldist(T x, T y, T s, T t);
template<typename T> inline T sqeucldist(pair<T, T> one, pair<T, T> two);
template<typename T> inline T sqeucldist(tuple<T, T> one, tuple<T, T> two);

inline ull modadd(ull a, ull b, int mod);
inline ull modmult(ull a, ull b, int mod);

template<typename T>
void rar(size_t n, T* a) {
    for (size_t i = 0; i < n; ++i) cin >> a[i];
    return;
}

template<typename T>
void rar2(size_t n, int m, T** a) {
    for (int i = 0; i < n; ++i) {
        a[i] = new int[m];
        for (int j = 0; j < m; ++j) cin >> a[i][j];
    } return;
}

template<typename T>
T ipow(T base, T exp) {
    T result = 1;
    while (exp) {
        if (exp & 1) result *= base;
        exp >>= 1;
        base *= base;
    }
    return result;
}

inline size_t left(size_t current, bool swap) {
    return swap ? right(current) : 2*current+1;
}
inline size_t right(size_t current, bool swap) {
    return swap ? left(current) : 2*(current+1);
}

template<typename T>
inline T griddist(T x, T y, T s, T t) {
    return abs(x-s) + abs(y-t);
}
template<typename T>
inline T griddist(pair<T, T> one, pair<T, T> two) {
    return abs(one.first - two.first) + abs(one.second - two.second);
}
template<typename T>
inline T griddist(tuple<T, T> one, tuple<T, T> two) {
    return abs(get<0>(one) - get<0>(two)) + abs(get<1>(one) - get<1>(two));
}

template<typename T>
inline T sqeucldist(T x, T y, T s, T t) {
    T a = x-s;
    T b = y-t;
    return a*a+b*b;
}
template<typename T>
inline T sqeucldist(pair<T, T> one, pair<T, T> two) {
    T a = one.first - two.first;
    T b = one.second - two.second;
    return a*a+b*b;
}
template<typename T>
inline T sqeucldist(tuple<T, T> one, tuple<T, T> two) {
    T a = get<0>(one) - get<0>(two);
    T b = get<1>(one) - get<1>(two);
    return a*a+b*b;
}

inline ull modadd(ull a, ull b, int mod) {
    return ((a%mod) + (b%mod))%mod;
}
inline ull modmult(ull a, ull b, int mod) {
    return ((a%mod)*(b%mod))%mod;
}

int main(void) {
    int n;
    cin >> n;
    int m;
    cin >> m;

    char p;
    cin >> p;
    char q;
    cin >> q;
    char r;
    cin >> r;

    string s;
    cin >> s;
    string t;
    cin >> t;

    int* arr = new int[n];
    rar(n, arr);
    int** rra = new int*[n];
    rar2(n, n, rra);

    //debug output
    if (debug)
    {
        //1D
        cout << "arr" << endl;
        for (int i = 0; i < n; ++i)
        {
            cout << arr[i] << "\t";
        }
        //2D
        cout << "\nrra" << endl;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                cout << rra[i][j] << "\t";
            }
            cout << endl;
        }
    }

    return 0;
}
