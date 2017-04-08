// DATA STRUCTURES
#include <vector>

// MISCELLANEOUS
#include <iostream>//cin/cout/wcin/wcout/left/right/internal/dec/hex/oct/fixed/scientific

typedef unsigned long long ull;

#define PRIME7 1000000007UL

// DECLARATIONS
struct F;
template <class CharT, class Traits>
auto& operator<<(std::basic_ostream<CharT, Traits>& os, const F value);

// IMPLEMENTATIONS
struct F
{
    F() : m_mod(PRIME7), m_value(0UL) {}
    F(unsigned long long value) : m_mod(PRIME7), m_value(value%m_mod) {}
    F(unsigned long long value, unsigned long long mod) : m_mod(mod), m_value(value%m_mod) {}
    F operator+(F other) const
        { return {m_value + other.m_value, m_mod}; }
    F operator-(F other) const
        { return {m_value - other.m_value + m_mod, m_mod}; }
    F operator*(F other) const
        { return {m_value * other.m_value, m_mod}; }

    unsigned long long operator()() const { return (unsigned long long) m_value; }

    unsigned long long m_mod;
    unsigned long long m_value;
};

template <class CharT, class Traits>
auto& operator<<(std::basic_ostream<CharT, Traits>& os, const F value)
    { return (os << value.m_value); }

using namespace std;

int main(void) {
    size_t n, m;
    cin >> n >> m;

    std::vector<long> x;
    for (size_t i = 0; i < n; ++i) {
        long temp;
        cin >> temp;
        x.push_back(temp);
    }

    std::vector<long> y;
    for (size_t i = 0; i < m; ++i) {
        long temp;
        cin >> temp;
        y.push_back(temp);
    }

    --n;
    --m;

    F x_sum;
    F y_sum;

    for (size_t i = 0; i < n; ++i) {
        size_t lef, rig;
        lef = i + 1;
        rig = n - i;
        F mult{lef * rig};
        F xx{static_cast<ull>(x[i+1] - x[i])};
        x_sum = x_sum + (mult * xx);
    }

    for (size_t j = 0; j < m; ++j) {
        size_t up, dow;
        up = m - j;
        dow = j + 1;
        F mult{up * dow};
        F yy{static_cast<ull>(y[j+1] - y[j])};
        y_sum = y_sum + (mult * yy);
    }

    F area = x_sum * y_sum;

    cout << area << '\n';
    return 0;
}
