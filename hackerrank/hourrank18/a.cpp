#include <iostream>//cin/cout/wcin/wcout/left/right/internal/dec/hex/oct/fixed/scientific

using namespace std;

int main(void)
{
    int m, n;
    cin >> m >> n;

    for (size_t i = 0; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;
        if (a == m)
            { m = b; }
        else if (b == m)
            { m = a; }
    }

    cout << m << endl;
    return 0;
}
