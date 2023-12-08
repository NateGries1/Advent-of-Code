#include <bits/stdc++.h>

using namespace std;

long solve(vector<int>& times, vector<int>& distances) {
    long time = 0;
    long distance = 0;
    int t_size = 0;
    int d_size = 0;

    for (int i = 0; i < times.size(); ++i) {
        t_size = log10(times[i])+1;
        time *= pow(10, t_size);
        time += times[i];
        
        d_size = log10(distances[i])+1;
        distance *= pow(10, d_size);
        distance += distances[i];

        cout << "t: " << time << " distance: " << distance << endl;
    }
    cout << "time: " << time << " distance: " << distance << endl;
    int higher = int(time/2.0 + sqrt(time*time - 4*distance)/2.0-0.00001);
    int lower = ceil(time/2.0 - sqrt(time*time - 4*distance)/2.0+0.00001);
    cout << higher << " " << lower << endl;
    return higher-lower+1;
    
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