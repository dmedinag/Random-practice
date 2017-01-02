#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement( vector<int>& nums, const int val ) {

        int size = nums.size();

        for( int i = 0; i < size; ++i ) {
            while( nums[i] == val ) {
                for( int j = i; j < size; nums[ j++ ] = nums[ j+1 ] );
                nums[ --size ]  = val;
            }
        }
        return size;
    }
};

string arrayToStr( const vector<int>& nums ) {
    string res = "";
    for( auto num : nums ) res += to_string(num) + " ";
    return res;
}

int main( int argc, char **argv ) {

    Solution sol;
    vector<int> nums;
    int num;

    cout << "Enter values separated by either spaces or new lines.\n";
    cout << "Enter value -1 to finish." << endl;

    for( ;; ) {
        cin >> num;
        if( num == -1 ) { break; }
        nums.push_back( num );
    }

    cout << "Original array: " << arrayToStr( nums ) << endl;

    cout << "Enter value to remove\n";
    cin >> num;
    cout << "Value to remove: " << num << endl;

    int size = sol.removeElement( nums, num );

    cout << "Modified array: " << arrayToStr( nums ) << endl;

    cout << "Returned size: " << size << endl;
}
