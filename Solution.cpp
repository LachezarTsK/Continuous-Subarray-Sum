
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
    
public:
    bool checkSubarraySum(const vector<int>& input, int target) const {
        unordered_set<int> previousPrefixSumModuloTarget;
        int previousSum = 0;
        int currentSum = 0;

        for (const auto& value : input) {
            currentSum += value;
            //C++20: ...contains(currentSum % target), done the old way for compatibility.
            if (previousPrefixSumModuloTarget.find(currentSum % target) != previousPrefixSumModuloTarget.end()) {
                return true;
            }
            previousPrefixSumModuloTarget.insert(previousSum % target);
            previousSum = currentSum;
        }
        return false;
    }
};
