/// The centre node is the only one with multiple edges that is more than 2.
/// we can solve by counting the array itself
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    
    
    int findCenter(vector<vector<int>>& edges) {
        
        
        unordered_map<double,unordered_map<double, int>> frequencyMap;

    // Count the frequency of each element in the nested arrays
    for (const auto& outerArray : edges) {
        for (const auto& innerElement : outerArray) {
            frequencyMap[outerArray.size()][innerElement]++;
        }
    }

    // Find the element with the highest frequency
    double mostFrequentElement = 0.0;
    int maxFrequency = 0;

    for (const auto& outerPair : frequencyMap) {
        for (const auto& innerPair : outerPair.second) {
            if (innerPair.second > maxFrequency) {
                maxFrequency = innerPair.second;
                mostFrequentElement = innerPair.first;
            }
        }
    }

    return mostFrequentElement;
        
    }
};