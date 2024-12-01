// ok now this is different, this is my first time writing C++ code 
#include <bits/stdc++.h>
#include <unistd.h>
#include <sstream>
#include <vector>
#include <utility> 
#include <cstdlib> 
#include <algorithm>
#include <unordered_map>
using namespace std;

// Creating a function 
pair<vector<int>, vector<int>> read_file(string filename) {
    vector<int> x; 
    vector<int> y;
    ifstream file("C:/Users/chiak/OneDrive/Desktop/aoc_2024/day1/input.txt");

    if (!file.is_open()) {
        cout << "File not found" << endl;
        cout << "Tried to open: input.txt" << endl;
        return make_pair(x, y);
    }
    
    cout << "File opened successfully!" << endl;
    string line; 
    while (getline(file, line)) {
        istringstream iss(line);
        int num1, num2;
        if (iss >> num1 >> num2) {
            // Equivalent to append() in python
            x.push_back(num1);
            y.push_back(num2);
        }
    }
    file.close();
    return make_pair(x, y);


}
int main() {
    pair<vector<int>, vector<int>> result = read_file("C:/Users/chiak/OneDrive/Desktop/aoc_2024/day1/input.txt");

    // Sort both vectors
    sort(result.first.begin(), result.first.end());
    sort(result.second.begin(), result.second.end());

    int diff; 
    int diff_sum = 0; 

    // Part 1 
    for (int i = 0; i < result.first.size(); i++) {
        diff = abs(result.first[i] - result.second[i]);
        diff_sum += diff;
    }
    cout << "Final sum: " << diff_sum << endl;

    // Part 2 
    // Create a frequency map for the second vector
    unordered_map<int, int> freq_map;
    for (int num : result.second) {
        freq_map[num]++;
    }

    int product_sum = 0;

    for (int num : result.first) {
        product_sum += num * freq_map[num];
    }
    cout << "Product sum: " << product_sum << endl;

}