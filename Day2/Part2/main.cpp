#include <bits/stdc++.h>
using namespace std;

int valid(string s, int game) {
    int res = 0;
    int red = 0, green = 0, blue = 0;
    for (int i = 8; i < s.size();) {
        int k = 0;
        while (isdigit(s[i])) {
            k *= 10;
            k += s[i] - 48;
            ++i;
        }
        ++i;
        switch (s[i]) {
            case 'r':
                cout << red << " " << k << endl;
                red = max(red, k);
                i += 5;
                break;
            case 'g':
                cout << green << " " << k << endl;
                green = max(green, k);
                i += 7;
                break;
            case 'b':
                cout << blue << " " << k << endl;
                blue = max(blue, k);
                i += 6;
                break;
        }
    }
    cout << (red + green + blue) << endl;
    return red * green * blue;
}
int solve(vector<string>& games) {
    int res = 0;
    int i = 0;
    for (int i = 0; i < games.size(); ++i) {
        res += valid(games[i], i + 1);
    }
    return res;
}

int main() {
    vector<string> input;
    int sum = 0;
    int n;
    string s;
    char delimiter;
    int game;
    while (getline(cin, s)) {
        cout << s << endl;
        input.push_back(s);
    }
    cout << "input read" << endl;
    cout << solve(input) << endl;
    return 0;
    
    //cout << solve(input) << endl;
}