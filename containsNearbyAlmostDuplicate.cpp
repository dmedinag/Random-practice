// Given an array of integers, find out whether there are two distinct indices i and j in the array such that
// - The difference between nums[i] and nums[j] is at most t.
// - The difference between i and j is at most k.

#include <vector>
// #include <cmath>

using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int size = nums.size();
        for( int i = 0; i < size; ++i ) {
            for( int j = i+1; j-i <= k; ++j ) {
                if( fabs(nums[i] - nums[j]) > t ) continue;
                return true;
            }
        }
        return false;
    }
};
