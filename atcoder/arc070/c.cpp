#include <cmath>//fmin/fmax/fabs/sin(h)/cos(h)/tan(h)/exp/log/pow/sqrt/cbrt/ceil/floor/round/trunc
#include <iostream>//cin/cout/wcin/wcout/left/right/internal/dec/hex/oct/fixed/scientific

typedef unsigned int ui;

using namespace std;

int main(void)
{
    ui x; cin >> x;
    double n = (sqrt(8. * x + 1) - 1) / 2.;
    cout << static_cast<int>(ceil(n)) << endl;
    return 0;
}
