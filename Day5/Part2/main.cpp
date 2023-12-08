#include <bits/stdc++.h>

using namespace std;
//source, destination, transition
map<long, pair<long, long>> seed_to_soil;
map<long, pair<long, long>> soil_to_fertilizer;
map<long, pair<long, long>> fertilizer_to_water;
map<long, pair<long, long>> water_to_light;
map<long, pair<long, long>> light_to_temperature;
map<long, pair<long, long>> temperature_to_humidity;
map<long, pair<long, long>> humidity_to_location;


long to_soil(long num) {
    if (num < seed_to_soil.begin()->first) return num;
    auto it = seed_to_soil.lower_bound(num);
    if (it->first == num) return num + it->second.first - it->first;
    --it;
    if (num < it->first + it->second.second) {
        return it->second.first - it->first + num;
    }
    return num;
}
long to_fertilizer(long num) {
    if (num < soil_to_fertilizer.begin()->first) return num;
    auto it = soil_to_fertilizer.lower_bound(num);
    if (it->first == num) return num + it->second.first - it->first;
    --it;
    if (num < it->first + it->second.second) {
        return it->second.first - it->first + num;
    }
    return num;
}
long to_water(long num) {
    if (num < fertilizer_to_water.begin()->first) return num;
    auto it = fertilizer_to_water.lower_bound(num);
    if (it->first == num) return num + it->second.first - it->first;
    --it;
    if (num < it->first + it->second.second) {
        return it->second.first - it->first + num;
    }
    return num;
}
long to_light(long num) {
    if (num < water_to_light.begin()->first) return num;
    auto it = water_to_light.lower_bound(num);
    if (it->first == num) return num + it->second.first - it->first;
    --it;
    if (num < it->first + it->second.second) {
        return it->second.first - it->first + num;
    }
    return num;
}
long to_temperature(long num) {
    if (num < light_to_temperature.begin()->first) return num;
    auto it = light_to_temperature.lower_bound(num);
    if (it->first == num) return num + it->second.first - it->first;
    --it;
    if (num < it->first + it->second.second) {
        return it->second.first - it->first + num;
    }
    return num;
}
long to_humidity(long num) {
    if (num < temperature_to_humidity.begin()->first) return num;
    auto it = temperature_to_humidity.lower_bound(num);
    if (it->first == num) return num + it->second.first - it->first;
    --it;
    if (num < it->first + it->second.second) {
        return it->second.first - it->first + num;
    }
    return num;
}
long to_location(long num) {
    if (num < humidity_to_location.begin()->first) return num;
    auto it = humidity_to_location.lower_bound(num);
    if (it->first == num) return num + it->second.first - it->first;
    --it;
    if (num < it->first + it->second.second) {
        return it->second.first - it->first + num;
    }
    return num;
}


long answers(vector<long>& seeds) {
    long min_location = LONG_MAX;
    unordered_set<long> all_seeds;
    for (int i = 0; i < seeds.size(); i += 2) {
        for (int j = 0; j < seeds[i+1]; j += 10000) {
            //cout << "seed " << seeds[i] + j << endl;
            all_seeds.insert(seeds[i] + j);
        }
    }
    long min_seed = LONG_MAX;
    for (const auto& seed : all_seeds) {
        long soil = to_soil(seed);
        long fertilizer = to_fertilizer(soil);
        long water = to_water(fertilizer);
        long light = to_light(water);
        long temperature = to_temperature(light);
        long humidity = to_humidity(temperature);
        long location = to_location(humidity);
        if (min_location > location) {
            min_seed = seed;
            min_location = location;
        }
        //min_location = min(min_location, location);
        //cout <<  "seed " << seed << " soil " << soil << " fertilizer " << fertilizer << " water " << water << " light " << light << " temperature " << temperature << " humidity " << humidity << " location " << location << endl;
    }
    min_location = LONG_MAX;
    for (int i = min_seed-10000; i < min_seed; ++i) {
        long soil = to_soil(i);
        long fertilizer = to_fertilizer(soil);
        long water = to_water(fertilizer);
        long light = to_light(water);
        long temperature = to_temperature(light);
        long humidity = to_humidity(temperature);
        long location = to_location(humidity);
        if (min_location > location) {
            min_location = location;
        }
        //min_location = min(min_location, location);
        cout <<  "seed " << i << " soil " << soil << " fertilizer " << fertilizer << " water " << water << " light " << light << " temperature " << temperature << " humidity " << humidity << " location " << location << endl;
    }

    return min_location;
}

long solve(vector<string>& input) {
    vector<long> seeds;
    stringstream s1(input[0]);
    string s;
    long seed;
    s1 >> s;
    while (s1 >> seed) {
        seeds.push_back(seed);
    }
    cout << "seeds to soil" << endl;
    int line = 3;
    while (isdigit(input[line][0])) {
        stringstream s2(input[line]);
        long dest, source, transition;
        s2 >> dest >> source >> transition;
        seed_to_soil[source] = make_pair(dest, transition);
        ++line;
        cout << "source " << source << " dest " << dest << " transition " << transition << endl;
    }
    line += 2;
    cout << "soil to fertilizer" << endl;
    while (isdigit(input[line][0])) {
        stringstream s3(input[line]);
        long dest, source, transition;
        s3 >> dest >> source >> transition;
        soil_to_fertilizer[source] = make_pair(dest, transition);
        ++line;
    }
    line += 2;

    cout << "fertilizer to water" << endl;
    while (isdigit(input[line][0])) {
        stringstream s4(input[line]);
        long dest, source, transition;
        s4 >> dest >> source >> transition;
        fertilizer_to_water[source] = make_pair(dest, transition);
        ++line;
    }
    line += 2;
    cout << "water to light" << endl;
    while (isdigit(input[line][0])) {
        stringstream s5(input[line]);
        long dest, source, transition;
        s5 >> dest >> source >> transition;
        water_to_light[source] = make_pair(dest, transition);
        ++line;
    }
    line += 2;
    cout << "light to temperature" << endl;
    while (isdigit(input[line][0])) {
        stringstream s6(input[line]);
        long dest, source, transition;
        s6 >> dest >> source >> transition;
        light_to_temperature[source] = make_pair(dest, transition);
        ++line;
    }
    line += 2;

    cout << "temperature to humidity" << endl;
    while (isdigit(input[line][0])) {
        stringstream s7(input[line]);
        long dest, source, transition;
        s7 >> dest >> source >> transition;
        cout << "dest " << dest << " source " << source << " transition " << transition << endl;
        temperature_to_humidity[source] = make_pair(dest, transition);
        ++line;
    }
    line += 2;
    cout << "humidity to location" << endl;

    while (line < input.size() && isdigit(input[line][0])) {
        stringstream s8(input[line]);
        long dest, source, transition;
        s8 >> dest >> source >> transition;
        humidity_to_location[source] = make_pair(dest, transition);
        ++line;
    }
    cout << "input read" << endl;
    
    return answers(seeds);
}

int main() {
    string s;
    vector<string> input;
    while (getline(cin, s)) {
        input.push_back(s);
    }

    
    cout << "input read" << endl;
    cout << solve(input) << endl;

    return 0;
}