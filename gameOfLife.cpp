// 1. Any live cell with fewer than two live neighbors dies, as if caused by under-population.
// 2. Any live cell with two or three live neighbors lives on to the next generation.
// 3. Any live cell with more than three live neighbors dies, as if by over-population..
// 4. Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.

/*
1 is alive
0 is dead
2 is was alive, but will die
-1 is was dead, but will live
*/
#include <vector>
#include <iostream>

using namespace std;

class Solution {
    int computeNeighbors( const int &i, const int &j, const vector< vector<int> >& board ) {
        int neighbors = 0;
        if( i != 0 ) {
            if( board[i-1][j] > 0 ) ++neighbors; // top
            if( j != 0 && board[i-1][j-1] > 0 ) ++neighbors; // top left
            if( j != board[i].size()-1 && board[i-1][j+1] > 0 ) ++neighbors; // top right
        }
        if( i != board.size()-1 ) {
            if( board[i+1][j] > 0 ) ++neighbors; // bottom
            if( j != 0 && board[i+1][j-1] > 0 ) ++neighbors; // bottom left
            if( j != board[i].size()-1 && board[i+1][j+1] > 0 ) ++neighbors; // bottom right
        }
        if( j != 0 && board[i][j-1] > 0 ) ++neighbors; // left
        if( j != board[i].size()-1 && board[i][j+1] > 0 ) ++neighbors; // right
        return neighbors;
    }

    void computeNextState( const int &i, const int &j, vector< vector<int> >& board, const int &neighbors ) {
        if( board[i][j] ) {                             // kill cell if necessary
            if( neighbors < 3 ) board[i][j] = 2;
            if( neighbors > 3 ) board[i][j] = 2;
        } else if ( neighbors == 3 ) board[i][j] = -1;  // revive cell if necessary
    }
public:
    void gameOfLife( vector< vector<int> >& board ) {
        for( int i = 0; i < board.size(); ++i ){
            for( int j = 0; j < board[i].size(); ++j ) {

                computeNextState( i, j, board, computeNeighbors( i, j, board ) );

            }
        }

        for( int i = 0; i < board.size(); ++i ){
            for( int j = 0; j < board[i].size(); ++j ) {
                if( board[i][j] == -1) board[i][j] = 1;
                else if( board[i][j] == 2 ) board[i][j] = 0;
            }
        }
    }
};

void printBoard( const vector< vector<int> >& board ) {
    for( int i = 0; i < board.size(); ++i ){
        for( int j = 0; j < board[i].size(); ++j ) {
            cout << board[i][j] << "\t";
        }
        cout << "\n";
    }
}

int main( int argc, char **argv ) {
    // Parse args and stuff

    vector<int> r1;
    r1.push_back(0);
    r1.push_back(1);
    r1.push_back(1);
    vector<int> r2;
    r2.push_back(1);
    r2.push_back(1);
    r2.push_back(0);
    vector<int> r3;
    r3.push_back(0);
    r3.push_back(1);
    r3.push_back(1);
    vector< vector<int> > board;
    board.push_back(r1);
    board.push_back(r2);
    board.push_back(r3);

    cout << "Initial board:\n";
    printBoard( board );

    Solution sol;
    sol.gameOfLife( board );

    cout << "Resulting board:\n";
    printBoard( board );
}
