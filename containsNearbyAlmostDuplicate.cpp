// Given an array of integers, find out whether there are two distinct indices i and j in the array such that
// - The difference between nums[i] and nums[j] is at most t.
// - The difference between i and j is at most k.

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int size = nums.size();
        for( uint i = 0; i < size; ++i ) {
            for( uint j = i+1; j-i <= k; ++j ) {
                if( abs(nums[i] - nums[j]) > t ) continue;
                return true;
            }
        }
        return false;
    }
};
