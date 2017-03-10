// Given an array of integers, find out whether there are two distinct indices i and j in the array such that
// - The difference between nums[i] and nums[j] is at most t.
// - The difference between i and j is at most k.

#include <iostream>
#include <vector>
#include <cmath>
#include <iterator>
#include <string>
#include <regex>

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

int main( int argc, char **argv ) {
    if( argc != 4 ) {
        cout << "Usage: " << argv[0] << " \"val1 val2 ... valN\" k t";
        return -1;
    }

    vector<int> A;
    regex word_regex("(\\S+)");
    string arr(argv[1]);

    auto words_begin = sregex_iterator(arr.begin(), arr.end(), word_regex);
    auto words_end = sregex_iterator();

    for (sregex_iterator i = words_begin; i != words_end; ++i) {
        A.push_back(atoi(i->str().c_str()));
    }

    Solution sol;
    char res = sol.containsNearbyAlmostDuplicate(A, atoi(argv[2]), atoi(argv[3]))
        ? 'T' : 'F';
    cout << "Solution: " << res << endl;
}
