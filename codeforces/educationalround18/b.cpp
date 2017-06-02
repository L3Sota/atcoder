// DATA STRUCTURES
#include <list>

// MISCELLANEOUS
#include <iostream>//cin/cout/wcin/wcout/left/right/internal/dec/hex/oct/fixed/scientific
#include <iterator>
#include <new>

typedef unsigned int ui;
typedef unsigned long long ull;

// --------------------------------------------------------------------------------------

#define PRIME7 1000000007UL

// DECLARATIONS
template <typename T> void read(size_t n, T* a);

// IMPLEMENTATIONS
template <typename T> void read(size_t n, T* a) {
    for (size_t i = 0; i < n; ++i) { std::cin >> a[i]; }
}

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
    { return (os << value()); }

using namespace std;

int main(void) {
    ui n, k;
    cin >> n >> k;
    F leader{1, n};
    ui* a = new ui[k];
    list<ui> l;
    read(k, a);
    for (ui i = 1; i <= n; ++i) {
        l.push_back(i);
    }
    for (size_t i = 0; i < k; ++i) {
        leader = F{a[i], n-i} + leader;
        auto it = l.begin();
        if (leader()) {
            for (ull j = 1; j < leader(); ++j) {
                ++it;
            }
        } else {
            ui save = *it;
            l.erase(it);
            l.push_back(save);
            it = l.end();
            --it; --it;
        }
        cout << *it << (i < k-1 ? ' ' : '\n');
        l.erase(it);
    }
    delete[] a;
    return 0;
}
