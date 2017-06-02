// MISCELLANEOUS
#include <iostream>//cin/cout/wcin/wcout/left/right/internal/dec/hex/oct/fixed/scientific
#include <new>

// --------------------------------------------------------------------------------------

// DECLARATIONS
template <typename T> void read(size_t n, T* a);

// IMPLEMENTATIONS
template <typename T> void read(size_t n, T* a) {
    for (size_t i = 0; i < n; ++i) { std::cin >> a[i]; }
}

using namespace std;

static const size_t SEQ_MAX = 114514UL;

int main(void) {
    int m;
    cin >> m;
    int* seq = new int[m];
    read(m, seq);

    int seq_count[SEQ_MAX] = {0};

    for (size_t i = 0; i < m; ++i) {
        ++seq_count[--seq[i]];
    }

    bool duped = true;

    for (size_t i = 0; i < SEQ_MAX; ++i) {
        if (seq_count[i] > 1) {
            duped = false;
            break;
        }
    }

    cout << (duped?"YES\n":"NO\n");

    delete[] seq;
    return 0;
}
