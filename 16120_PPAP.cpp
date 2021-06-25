// String
#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    string PPAP;
    int check = 0; // 1 : 1st P, 2: 2nd P, 3: 3rd A, 4: 4th P --> 1 or 2 ( previous P exists ) 
    int P_count = 0;
    cin >> PPAP;

    int i;
    int PPAP_len = PPAP.length();

    if (PPAP_len == 1 && PPAP[0] == 'P')
        cout << "PPAP";
    else if (PPAP[0] == 'A')
        cout << "NP";
    else {
        for (i = 0; i < PPAP_len; i++) {
            if (check == 1 && PPAP[i] == 'A') {
                P_count = -1;
                break;
            }

            if (PPAP[i] == 'P')
                P_count++;

            if (check == 0 && PPAP[i] == 'P') {
                check = 1;
                continue;
            }

            if (check == 1 && PPAP[i] == 'P') {
                check = 2;
                continue;
            }

            if (check == 2 && PPAP[i] == 'A') {
                check = 3;
                continue;
            }
 
            if (check == 3 && PPAP[i] == 'P') {
                check = 4;
                P_count -= 3;
                P_count++;
                if (P_count > 1)
                    check = 2;
                else 
                    check = 1;
            }
        }
        if (P_count == 1)
            cout << "PPAP";
        else
            cout << "NP";
    }
    return 0;
}