#include <bits/stdc++.h>

using namespace std;

unordered_set<char> symbols = {'!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '+', '=', '[', ']', '{', '}', '|', '\\', ';', ':', '\'', '"', ',', '/', '<', '>', '?'};
unordered_map<string, vector<int>> gears;

int solve(vector<string>& lines) {
    int res = 0;

    for (int i = 0; i < lines.size(); ++i) {
        for (int j = 0; j < lines[i].size(); ++j) {
            if (isdigit(lines[i][j])) {
                int start = j;
                int end = lines[i].find_first_not_of("0123456789", j + 1);

                if (end == string::npos) {
                    end = lines[i].size();
                }

                if (i > 0 || i < lines.size() - 1) {
                    for (int k = max(0, i - 1); k <= min(int(lines.size() - 1), i + 1); ++k) {
                        for (int l = max(0, start - 1); l <= min(end, static_cast<int>(lines[k].size()) - 1); ++l) {
                            if (lines[k][l] == '*') {
                                int num = stoi(lines[i].substr(start, end - start));
                                gears[to_string(k) + "_" + to_string(l)].push_back(num);
                                cout << k << " " << l << " " << num << endl;
                                break;
                            }
                        }
                    }
                }
                j = end - 1;
            }
        }
    }
    for (auto& gear : gears) {
        if (gear.second.size() == 2) {
            cout << gear.first << " " << gear.second[0] << " " << gear.second[1] << endl;
            res += gear.second[0] * gear.second[1];
        }
    }
    return res;

}

int main() {
    vector<string> input;
    string s;
    while (cin >> s) {
        input.push_back(s);
    }

    cout << "input read" << endl;
    cout << solve(input) << endl;

    return 0;
}