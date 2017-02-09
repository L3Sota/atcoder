#include <iostream>//cin/cout/wcin/wcout/left/right/internal/dec/hex/oct/fixed/scientific

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    int max = 0;
    for (int i = 0; i < a; ++i)
    {
        int temp;
        cin >> temp;

        if (max < temp)
            max = temp;
    }
    cout << ((max - b) < 0 ? 0 : (max - b)) << endl;
    return 0;
}
