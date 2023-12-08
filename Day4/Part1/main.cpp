#include <bits/stdc++.h>

using namespace std;
vector<unordered_set<int>> winners;
int card_num = 0;

int solve(vector<vector<int>>& cards) {
    int res = 0;
    for (int i = 0; i < cards.size(); i++) {
        int count = 0;
        for (int j = 0; j < cards[i].size(); ++j) {
            if (winners[i].count(cards[i][j])) {
                ++count;
            }
        }
        if (count > 0) {
            res += (1 << (count-1));
        }
        cout << i << " " << count << " " << res << endl;
    }

    return res;
}

int main() {
    vector<vector<int>> nums;
    string s;
    int n;
    char c;
    while (getline(cin, s)) {
        ++card_num;
        unordered_set<int> wins;
        int index = 10;
        
        while (s[index] != '|') {
            wins.insert(stoi(string(s.begin()+index, s.begin()+index+2)));
            cout << "inserted: " << stoi(string(s.begin()+index, s.begin()+index+2)) << endl;
            index += 3;
        }
        winners.push_back(wins);

        cout << "wins size: " << wins.size() << endl;
        cout << "winners size: " << winners.size() << endl;
        index += 2;
        vector<int> numbers;
        while (index < s.size()) {
            numbers.push_back(stoi(string(s.begin()+index, s.begin()+index+2)));
            cout << "inserted: " << stoi(string(s.begin()+index, s.begin()+index+2)) << endl;
            index += 3;
        }
        
        nums.push_back(numbers);
        cout << "numbers size: " << numbers.size() << endl;
        cout << "nums size: " << nums.size() << endl;
    }

    cout << "input read" << endl;
    cout << solve(nums) << endl;

    return 0;
}