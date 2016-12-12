// Given a 2d grid map of '1's (land) and '0's (water), count the number of islands.
// An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.
// You may assume all four edges of the grid are all surrounded by water.
//
// Example 1:
//
// 11110
// 11010
// 11000
// 00000
// Answer: 1
//
// Example 2:
//
// 11000
// 11000
// 00100
// 00011
// Answer: 3
//
// Input format example 1:
// ["11110","11010","11000","00000"]

#include <algorithm>

using namespace std;

class Solution {
  public:

    void colourIsland( int x, int y, vector<vector<char>>& grid ) {
        // Colour current cell if applicable
        if( grid[x][y] == '1' ) grid[x][y] = 'X';
        else return;
        // And then look for those around
        if( x-1 >= 0 )              colourIsland( x-1, y, grid );
        if( x+1 < grid.size() )     colourIsland( x+1, y, grid );
        if( y-1 >= 0 )              colourIsland( x, y-1, grid );
        if( y+1 < grid[x].size() )  colourIsland( x, y+1, grid );
    }

    int numIslands(vector<vector<char>>& grid) {
        uint islands = 0;

        // Find unexplored land (1s). Once found, convert the island into x's
        for( int x = 0; x < grid.size(); ++x ) {
            for( int y = 0; y < grid[x].size(); ++y ) {
                if( grid[x][y] == '1' ) {
                    colourIsland( x, y, grid );
                    ++islands;
                }
            }
        }

        return islands;
    }
};
