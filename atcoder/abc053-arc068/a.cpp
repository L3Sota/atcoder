#include <iostream>//cin/cout/wcin/wcout/left/right/internal/dec/hex/oct/fixed/scientific

using namespace std;

int main(void)
{
    int x;
    cin >> x;
    cout << ((x < 1200) ? "ABC" : "ARC") << endl;
    return 0;
}
