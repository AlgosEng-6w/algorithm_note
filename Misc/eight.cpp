#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    while (cin >> n && n) {
        string s;
        cin >> s;

        int r = 0, y = 0;
        bool wr = false, wy = false;

        for (char c : s) {
            if (c == 'R') r++;
            else if (c == 'Y') y++;
            else if (c == 'B') wr = (r == 7);
            else if (c == 'L') wy = (y == 7);

            if (wr || wy) break;
        }

        if (wr) cout << "Red\n";
        else if (wy) cout << "Yellow\n";
    }

    return 0;
}