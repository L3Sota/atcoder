// MISCELLANEOUS
#include <iostream>//cin/cout/wcin/wcout/left/right/internal/dec/hex/oct/fixed/scientific
#include <limits>//numeric_limits<type>::max/min/lowest/epsilon/infinity/quiet_NaN/signaling_NaN
#include <new>

typedef unsigned long long ull;

// --------------------------------------------------------------------------------------

#define PRIME7_SHORT 10007UL
#define PRIME9_SHORT 10009UL
#define PRIME7 1000000007UL

// DECLARATIONS
struct F;

// IMPLEMENTATIONS
struct F
{
    F() : m_value(0UL), modulus(PRIME7) {}
    F(unsigned long long value,
        unsigned long long mod) : m_value(value%mod), modulus(mod) {}
    F operator+(F other) const
        { return {m_value + other.m_value, modulus}; }
    F operator-(F other) const
        { return {m_value - other.m_value + modulus, modulus}; }
    F operator*(F other) const
        { return {m_value * other.m_value, modulus}; }

    unsigned long long operator()(void) const { return (unsigned long long) m_value; }
 
    unsigned long long m_value;
    unsigned long long modulus;
};

using namespace std;

int main(void) {
    ull n; size_t p, q;
    cin >> n >> p >> q;
    F* a = new F[p];
    F* b = new F[q];

    for (size_t i = 0; i < p; ++i) {
        ull temp; cin >> temp;
        a[i] = F{temp, n};
    }
    for (size_t i = 0; i < q; ++i) {
        ull temp; cin >> temp;
        b[i] = F{temp, n};
    }
    int* votes = new int[n];
    for (size_t i = 0; i < n; ++i) {
        votes[i] = 0;
    }
    for (size_t i = 0; i < p; ++i) {
        for (size_t j = 0; j < q; ++j) {
            size_t pos = static_cast<size_t>((F{0UL,n} - a[i] - b[j])());
            ++votes[pos];
        }
    }

    size_t minpos = n;
    int minval = numeric_limits<int>::max();
    for (size_t i = 1; i < n; ++i) {
        if (minval > votes[i]) {
            minval = votes[i];
            minpos = i;
        }
    }
    {
        size_t i = 0;
        if (minval > votes[i]) {
            minval = votes[i];
            minpos = i;
        }
    }
    cout << (minpos ? minpos : n) << '\n';
    delete[] votes;
    delete[] b;
    delete[] a;
    return 0;
}
