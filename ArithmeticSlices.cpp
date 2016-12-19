// A sequence of number is called arithmetic if
// - It consists of at least three elements
// - The difference between any two consecutive elements is the same.
//
// For example, these are arithmetic sequence:
//
// 1, 3, 5, 7, 9
// 7, 7, 7, 7
// 3, -1, -5, -9
// The following sequence is not arithmetic.
//
// 1, 1, 2, 5, 7
//
// A zero-indexed array A consisting of N numbers is given. A slice of that array is any pair of integers (P, Q) such that 0 <= P < Q < N.
//
// A slice (P, Q) of array A is called arithmetic if the sequence:
// A[P], A[p + 1], ..., A[Q - 1], A[Q] is arithmetic. In particular, this means that P + 1 < Q.
//
// The function should return the number of arithmetic slices in the array A.
//
//
// Example:
//
// A = [1, 2, 3, 4]
//
// return: 3, for 3 arithmetic slices in A: [1, 2, 3], [2, 3, 4] and [1, 2, 3, 4] itself.

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    int subslices( int slicesize ) {
        int subslices = 0;
        for( int i = slicesize; i > 2; subslices += i-- - 2 );
        return subslices;
    }
  public:
    int numberOfArithmeticSlices(vector<int>& A) {

        int size = A.size();

        if( size < 3 ) return 0;

        int slices = 0, diff = A[1] - A[0], slicesize = 2;

        for( int i = 2; i < size; ++i ) {

            if( (A[i] - A[i-1] != diff) ) {

                // Found the end of an aritmetic slice: add all subslices
                slices += subslices( slicesize );
                // restart count, carry on
                diff = A[i] - A[i-1];
                slicesize = 2;
                continue;

            } // if
            ++slicesize;
        } // for

        // Add last slice's subslices
        slices += subslices( slicesize );

        return slices;
    }
};

int main( int argc, char **argv ) {
    vector<int> A;
    for( int i = 1; i < argc; A.push_back( atoi( argv[i++] ) ) );
    Solution sol;
    cout << "Solution: " << sol.numberOfArithmeticSlices(A) << endl;
}
