#include <bits/stdc++.h>

using namespace std;
//source, destination, transition
unordered_map<long, pair<long, long>> seed_to_soil;
unordered_map<long, pair<long, long>> soil_to_fertilizer;
unordered_map<long, pair<long, long>> fertilizer_to_water;
unordered_map<long, pair<long, long>> water_to_light;
unordered_map<long, pair<long, long>> light_to_temperature;
unordered_map<long, pair<long, long>> temperature_to_humidity;
unordered_map<long, pair<long, long>> humidity_to_location;


long to_soil(long num) {
    for (const auto& [key, value] : seed_to_soil) {
        cout << "key: " << key << " value: " << value.first << " " << value.second << endl;
        if (num >= key && num < key + value.second) {
            return value.first - key + num;
        }
    }
    return num;
}
long to_fertilizer(long num) {
    for (const auto& [key, value] : soil_to_fertilizer) {
        cout << "key: " << key << " value: " << value.first << " " << value.second << endl;
        if (num >= key && num < key + value.second) {
            return value.first - key + num;
        }
    }
    return num;
}
long to_water(long num) {
    for (const auto& [key, value] : fertilizer_to_water) {
        cout << "key: " << key << " value: " << value.first << " " << value.second << endl;
        if (num >= key && num < key + value.second) {
            return value.first - key + num;
        }
    }
    return num;
}
long to_light(long num) {
    cout << "water to light" << endl;
    for (const auto& [key, value] : water_to_light) {
        cout << "key: " << key << " value: " << value.first << " " << value.second << endl;
        if (num >= key && num < key + value.second) {
            return value.first - key + num;
        }
    }
    return num;
}
long to_temperature(long num) {
    for (const auto& [key, value] : light_to_temperature) {
        cout << "key: " << key << " value: " << value.first << " " << value.second << endl;
        if (num >= key && num < key + value.second) {
            return value.first - key + num;
        }
    }
    return num;
}
long to_humidity(long num) {
    for (const auto& [key, value] : temperature_to_humidity) {
        cout << "key: " << key << " value: " << value.first << " " << value.second << endl;
        if (num >= key && num < key + value.second) {
            return value.first - key + num;
        }
    }
    return num;
}
long to_location(long num) {
    for (const auto& [key, value] : humidity_to_location) {
        cout << "key: " << key << " value: " << value.first << " " << value.second << endl;
        if (num >= key && num < key + value.second) {
            return value.first - key + num;
        }
    }
    return num;
}


long answers(vector<long>& seeds) {
    long min_location = INT_MAX;
    for (int i = 0; i < seeds.size(); ++i) {
        long seed = seeds[i];
        long soil = to_soil(seed);
        long fertilizer = to_fertilizer(soil);
        long water = to_water(fertilizer);
        long light = to_light(water);
        long temperature = to_temperature(light);
        long humidity = to_humidity(temperature);
        long location = to_location(humidity);
        min_location = min(min_location, location);
        cout << "seed: " << seed << " soil: " << soil << " fertilizer: " << fertilizer << " water: " << water << " light: " << light << " temperature: " << temperature << " humidity: " << humidity << " location: " << location << endl;
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