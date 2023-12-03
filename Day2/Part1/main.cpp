#include <bits/stdc++.h>
using namespace std;

int valid(string s, int game) {
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
                if (k > 12) {
                    return 0;
                }
                i += 5;
                break;
            case 'g':
                if (k > 13) {
                    return 0;
                }
                i += 7;
                break;
            case 'b':
                if (k > 14) {
                    return 0;
                }
                i += 6;
                break;
        }
    }
    cout << game << endl;
    return game;

    if (red <= 12 && green <= 13 && blue <= 14) {
        return game;
    }
    return 0;
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