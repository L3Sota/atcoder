// MISCELLANEOUS
#include <iostream>//cin/cout/wcin/wcout/left/right/internal/dec/hex/oct/fixed/scientific

#ifndef REP
#define REP(i,n) for (int i = 0; i < n; ++i)
#endif

#ifndef REPST
#define REPST(i,n) for (size_t i = 0; i < n; ++i)
#endif

// --------------------------------------------------------------------------------------

using namespace std;

bool incompatible(char a, char b) {
    switch (a) {
        case 'R': { return (b == 'V' || b == 'R' || b == 'O'); }
        case 'O': { return (b == 'R' || b == 'O' || b == 'Y'); }
        case 'Y': { return (b == 'O' || b == 'Y' || b == 'G'); }
        case 'G': { return (b == 'Y' || b == 'G' || b == 'B'); }
        case 'B': { return (b == 'G' || b == 'B' || b == 'V'); }
        case 'V': { return (b == 'B' || b == 'V' || b == 'R'); }
        default: return false;
    }
}

int main(void)
{
    int t;
    cin >> t;
    REP(test,t)
    {
        int n;
        // red, ora, yel, gre, blu, vio
        int colors[6];
        char colorchars[6] = {'R', 'O', 'Y', 'G', 'B', 'V'};
        cin >> n;
        REP(i,6) { cin >> colors[i];}
        int red, ora, yel, gre, blu, vio;
        red = colors[0];
        ora = colors[1];
        yel = colors[2];
        gre = colors[3];
        blu = colors[4];
        vio = colors[5];

        string s(n, '?');
        // int* indices = new int[n];

        if (ora == 0 && gre == 0 && vio == 0) {
            int countmax = max({red, yel, blu});
            size_t argmax = 0;
            REP(i, 3) { if (countmax == colors[2*i]) { argmax = 2*i; break; } }
            REPST(pos, n) {
                s[pos] = colorchars[argmax];
                --colors[argmax];
                countmax = 0;
                if (pos < n-1) {
                    size_t next_argmax = 7;
                    REP(i, 3) {
                        if (2*i == argmax) {
                            continue;
                        } else {
                            if (countmax < colors[2*i]) {
                                countmax = colors[2*i];
                                next_argmax = 2*i;
                            }
                        }
                    }
                    argmax = next_argmax;
                    if (argmax == 7) {
                        break;
                    }
                }
            }
            if (argmax == 7) {
                s = "IMPOSSIBLE";
            } else if(s[0] == s[n-1]) {
                if (n <= 3 || s[0] == s[n-2] || s[n-1] == s[n-3]) {
                    s = "IMPOSSIBLE";
                } else {
                    char last = s[n-1];
                    char seco = s[n-2];
                    s[n-1] = seco;
                    s[n-2] = last;
                }
            }
        } else {
            bool used_g, used_v, used_o;
            used_g = !gre;
            used_v = !vio;
            used_o = !ora;
            bool block[3] = {used_g, used_v, used_o};
            bool rg, bo, yv;
            rg = (used_g || red >= gre + 1);
            yv = (used_v || yel >= vio + 1);
            bo = (used_o || blu >= ora + 1);
            if (rg && yv && bo) {
                if (!used_g) {
                    colors[0] -= gre;
                    red = colors[0];
                }
                if (!used_v) {
                    colors[2] -= vio;
                    yel = colors[2];
                }
                if (!used_o) {
                    colors[4] -= ora;
                    blu = colors[4];
                }
                int countmax = max({red, yel, blu});
                size_t argmax = 0;
                REP(i, 3) { if (countmax == colors[2*i]) { argmax = 2*i; break; } }
                REPST(pos, n) {
                    if (!block[argmax / 2]) {
                        size_t opposite = (argmax + 3)%6;
                        while (colors[opposite]) {
                            s[pos++] = colorchars[argmax];
                            s[pos++] = colorchars[opposite];
                            --colors[opposite];
                        }
                        block[argmax / 2] = true;
                    }
                    s[pos] = colorchars[argmax];
                    --colors[argmax];
                    countmax = 0;
                    if (pos < n-1) {
                        size_t next_argmax = 7;
                        REP(i, 3) {
                            if (2*i == argmax) {
                                continue;
                            } else {
                                if (countmax < colors[2*i]) {
                                    countmax = colors[2*i];
                                    next_argmax = 2*i;
                                }
                            }
                        }
                        argmax = next_argmax;
                        if (argmax == 7) {
                            break;
                        }
                    }
                }
                if (argmax == 7) {
                    s = "IMPOSSIBLE";
                } else if (incompatible(s[0], s[n-1])) {
                    if (n <= 3 || incompatible(s[0], s[n-2]) || incompatible(s[n-1], s[n-3])) {
                        s = "IMPOSSIBLE";
                    } else {
                        char last = s[n-1];
                        char seco = s[n-2];
                        s[n-1] = seco;
                        s[n-2] = last;
                    }
                }
            } else {
                if (red == gre && ora == 0 && yel == 0 && blu == 0 && vio == 0) {
                    REP(i,n) {
                        if (i%2) { s[i] = 'G'; }
                        else { s[i] = 'R'; }
                    }
                } else if (ora == blu && red == 0 && yel == 0 && gre == 0 && vio == 0) {
                    REP(i,n) {
                        if (i%2) { s[i] = 'O'; }
                        else { s[i] = 'B'; }
                    }
                } else if (yel == vio && red == 0 && ora == 0 && gre == 0 && blu == 0) {
                    REP(i,n) {
                        if (i%2) { s[i] = 'V'; }
                        else { s[i] = 'Y'; }
                    }
                } else {
                    s = "IMPOSSIBLE";
                }
            }
        }
        cout << "Case #" << (test+1) << ": " << s << '\n';
        

    }

    return 0;
}
