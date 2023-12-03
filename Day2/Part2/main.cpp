#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> numbers = {
    {"zero", 0},
    {"one", 1},
    {"two", 2},
    {"three", 3},
    {"four", 4},
    {"five", 5},
    {"six", 6},
    {"seven", 7},
    {"eight", 8},
    {"nine", 9},
};

int solve(vector<string> nums) {
    int res = 0;
    for (const string &s : nums) {
        int num;
        int num_index = INT_MAX;
        int index = INT_MAX;
        int min_num;
        for (const auto &p : numbers) {
            int i = s.find(p.first);
            if (i != string::npos && i < index) {
                index = i;
                min_num = p.second;
            }
        }
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] >= 48 && s[i] <= 57) {
                num_index = i;
                num = (s[i] - 48) * 10;
                break;
            }
        }
        if (index < num_index) {
            num = min_num * 10;
        }
        //cout << num << endl;

        index = 0;
        num_index = 0;
        for (const auto &p : numbers) {
            int i = s.rfind(p.first);
            //cout << p.first << " " << i << endl;
            if (i != string::npos && i > index) {
                index = i;
                min_num = p.second;
            }
        }
        //cout << index << " " << min_num << endl;

        int num2;
        for (int i = s.size()-1; i >= 0; --i) {
            if (s[i] >= 48 && s[i] <= 57) {
                num_index = i;
                num2 = (s[i] - 48);
                break;
            }
        }
        //cout << num2 << " " << num_index << endl;

        if (index > num_index) {
            num += min_num;
        } else {
            num += num2;
        }
        res += num;
        cout << num << endl;
    }
    return res;
}
int main() {
    
    cout << "adl;fjalkdfj" << endl;
    vector<string> input;
    int n;
    string s;
    while (cin >> s) {
        input.push_back(s);
    }
    
    cout << solve(input) << endl;
}