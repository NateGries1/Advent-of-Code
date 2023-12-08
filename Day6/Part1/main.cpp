#include <bits/stdc++.h>

using namespace std;

long solve(vector<int>& times, vector<int>& distances) {
    int res = 1;
    for (int i = 0; i < times.size(); ++i) {
        int t = times[i];
        int distance = distances[i];
        cout << "t: " << t << " distance: " << distance << endl;
        int higher = int(t/2.0 + sqrt(t*t - 4*distances[i])/2.0-0.00001);
        int lower = ceil(t/2.0 - sqrt(t*t - 4*distances[i])/2.0+0.00001);
        cout << higher << " " << lower << endl;
        res *= higher-lower+1;
    }
    return res;
    
}

int main() {
    string s;
    vector<string> input;
    vector<int> times;
    vector<int> distances;

    getline(cin, s);
    stringstream ss(s);
    string str;
    int time;
    ss >> str;
    while (ss >> time) {
        times.push_back(time);
    }

    getline(cin, s);
    ss = stringstream(s);
    int distance;
    ss >> str;
    while (ss >> distance) {
        distances.push_back(distance);
    }
    
    cout << "input read" << endl;
    cout << solve(times, distances) << endl;

    return 0;
}