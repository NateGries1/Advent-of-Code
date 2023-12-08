#include <bits/stdc++.h>

using namespace std;

int card_value(unordered_set<int> w, vector<int>& card);
vector<unordered_set<int>> winners;
int card_num = 0;

int solve(vector<vector<int>>& cards) {
    int res = 0;
    vector<int> number_cards(cards.size(), 1);
    
    for (int i = 0; i < cards.size(); ++i) {
        cout << "number_cards " << i << " " << number_cards[i] << endl;
        int count = card_value(winners[i], cards[i]);
        cout << i << endl;
        for (int j = 0; j < count; ++j) {
            number_cards[i+j+1] += number_cards[i];
            cout << i+j+1 << " " << number_cards[i+j+1] << endl;
        }
        res += count * number_cards[i];
        cout << i << " " << count << " " << res << endl;
    }
    return accumulate(number_cards.begin(), number_cards.end(), 0);
}
int card_value(unordered_set<int> w, vector<int>& card) {
        int count = 0;
        for (int i = 0; i < card.size(); ++i) {
            if (w.count(card[i])) {
                ++count;
            }
        }
        return count;
        return count? 1 << (count-1): 0;
        if (count > 0) {
            return (1 << (count-1));
        } else {
            return 0;
        }

}

int main() {
    vector<vector<int>> nums;
    string s;
    int n;
    char c;
    while (getline(cin, s)) {
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
        ++card_num;
    }

    cout << "input read" << endl;
    cout << solve(nums) << endl;

    return 0;
}