#include <iostream>//cin/cout/wcin/wcout/left/right/internal/dec/hex/oct/fixed/scientific

using namespace std;

typedef unsigned long long ull;
 
int main(int argc, char* argv[])
{
    ull x;
    cin >> x;
    
    ull a = (x%11 > 6 ? 2 : 1);
    if (x%11 == 0) --a;

    cout << ((x/11)*2 + a) << endl;

    return 0;
}
