#include <bits/stdc++.h>

using namespace std;

bool compare(pair<string, pair<int, int>>& a, pair<string, pair<int, int>>& b) {
    if (a.second.second == b.second.second) {
        const std::string order = "AKQJT98765432";
        int index = 0;
        while (a.first[index] == b.first[index]) {
            ++index;
        }
        size_t pos1 = order.find(a.first[index]);
        size_t pos2 = order.find(b.first[index]);
        return pos1 > pos2;
    }
    return a.second.second < b.second.second;
}


long solve(vector<pair<string, pair<int, int>>>& game) {
    vector<int> values(game.size());
    for (int i = 0; i < game.size(); ++i) {
        unordered_map<char, int> freq;
        auto hand = game[i];
        string cards = game[i].first;
        for (int j = 0; j < 5; ++j) {
            ++freq[cards[j]];
        }
        int hand_value = 0;
        for (const auto& [key, value] : freq) {
            cout << key << " " << value << " " << hand_value << endl;
            switch (value) {
                case 1: // high card
                    break;
                case 2: // pair
                    switch (hand_value) {
                        case 0:
                            hand_value = 1;
                            break;
                        case 1:
                            hand_value = 2;
                            break;
                        case 3:
                            hand_value = 4;
                            break;
                    }
                    break;
                case 3: //3 of a kind
                    switch(hand_value) {
                        case 0:
                            hand_value = 3;
                            break;
                        case 1:
                            hand_value = 4;
                            break;
                        case 2:
                            hand_value = 3;
                            break;
                    }
                    break;
                case 4: // 4 of a kind
                    hand_value = 5;
                    break;
                case 5: // 5 of a kind
                    hand_value = 6;
                    break;
                
            }
        }
        game[i].second.second = hand_value;
        cout << game[i].first << " " << game[i].second.first << " " << game[i].second.second << endl << endl;
    }
    sort(game.begin(), game.end(), compare);
    for (int i = 0; i < game.size(); ++i) {
        cout << game[i].first << " " << game[i].second.first << " " << game[i].second.second << endl;
    }
    int res = 0;
    for (int i = 0; i < game.size(); ++i) {
        cout << game[i].first << " " << game[i].second.first << " " << game[i].second.second << endl;
        res += game[i].second.first*(i+1);
    }
    return res;
}

int main() {
    vector<pair<string, pair<int, int>>> input;
    string hand;
    int bid;
    while (cin >> hand >> bid) {
        input.push_back(make_pair(hand, make_pair(bid, 0)));
    }

    cout << "input read" << endl;
    cout << solve(input) << endl;

    return 0;
}