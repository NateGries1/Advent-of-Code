#include <bits/stdc++.h>
using namespace std;

int solve(vector<string>& nums) {
    int res = 0;
    for (const string &s : nums) {
        cout << s << endl;
        int num;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] >= 48 && s[i] <= 57) {
                num = (s[i] - 48) * 10;
                break;
            }
        }
        for (int i = s.size()-1; i >= 0; --i) {
            if (s[i] >= 48 && s[i] <= 57) {
                num += (s[i] - 48);
                break;
            }
        }
        res += num;
        cout << num << endl;
    }
    return res;
}
int main() {
    vector<string> input;
    int n;
    string s;
    while (cin >> s) {
        input.push_back(s);
        //cout << s << endl;
    }
    
    cout << solve(input) << endl;
}