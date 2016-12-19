#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int size = nums.size();
        for( int i = 0; i < nums.size(); ++i ) {
            if( nums[i] == val ) {
                --size;
                for( int j = i+1; j < nums.size(); ++j ) {
                    if( nums[j] != val ) {
                        nums[i] = nums[j];
                        nums[j] = val;
                        break;
                    }
                    ++size;
                } // look for match
            }
        }
        return size;
    }
};

void printArray( vector<int>& nums ) {
    for( auto num : nums ) cout << num << " ";
    cout << endl;
}

int main( int argc, char **argv ) {
    Solution sol;
    vector<int> nums;
    char val;
    string num;
    cin >> noskipws;


    for( ;; ) {
        cin >> val;
        cout << "Read character  '" << val << "'" << endl;
        if( val == ' '  || val == 'z' ) {
            nums.push_back( atoi( num.c_str() ) );
            num.clear();
        }
        if( val == 'z' ) {
        cin >> val;
            break;
        }
        num += val;

        cout << "num is: " << num << endl;
    }


    cout << "Original array: ";
    printArray(nums);
    cout << "Value to remove: " << val << endl;
    int size = sol.removeElement( nums, val );
    cout << "Modified array: ";
    printArray(nums);
    cout << "Returned size: " << size << endl;
}
