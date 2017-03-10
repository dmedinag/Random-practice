// Problem from Hackerrank

// Handout
//
// A kidnapper wrote a ransom note but is worried it will be traced back to him.
// He found a magazine and wants to know if he can cut out whole words from it and
// use them to create an untraceable replica of his ransom note. The words in his
// note are case-sensitive and he must use whole words available in the magazine,
// meaning he cannot use substrings or concatenation to create the words he needs.
//
// Given the words in the magazine and the words in the ransom note, print "Yes" if
// he can replicate his ransom note exactly using whole words from the magazine;
// otherwise, print "No".
//
// Input Format
//
// The first line contains two space-separated integers describing the respective
// values of m (the number of words in the magazine) and n (the number of words in the ransom note).
// The second line contains m space-separated strings denoting the words present in the magazine.
// The third line contains n space-separated strings denoting the words present in the ransom note.
// 
// Constraints
//
// 1 <= (m, n) <= 3000
// 1 <= len(any_word) <= 5
// Each word consists of English alphabetic letters (i.e., a to z and A to Z).
// The words in the note and magazine are case-sensitive.
//
// Sample Input
//
// 6 4
// give me one grand today night
// give one grand today

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#define MAX_WORD_SIZE 5

int main(){
    int m; // #words in magazine
    int n; // #words in ransom letter
    scanf("%d %d",&m,&n);

    // We can even skip the challenge if there are less word in the magazine than in the letter
    if( m < n ) goto fail;

    // Otherwise, parse the input words in both magazine and ransom letter
    char* *magazine = malloc(sizeof(char*) * m);
    for(int magazine_i = 0; magazine_i < m; magazine_i++){
       magazine[magazine_i] = (char *)malloc(MAX_WORD_SIZE * sizeof(char));
       scanf("%s",magazine[magazine_i]);
    }
    char* *ransom = malloc(sizeof(char*) * n);
    for(int ransom_i = 0; ransom_i < n; ransom_i++){
       ransom[ransom_i] = (char *)malloc(MAX_WORD_SIZE * sizeof(char));
       scanf("%s",ransom[ransom_i]);
    }

    for( int i = 0; i < n; ++i ) {      // for every word in ransom
        for( int j = 0; j < m; ++j ) {  // try to find a match in magazine

            // Is this word in the magazine the one we were looking for?
            for( int k = 0; k < MAX_WORD_SIZE; ++k ) {
                // Compare character by character
                if( ransom[i][k] != magazine[j][k] ) {  // Fail as we find a mismatch
                    if( j == m-1 ) goto fail;       // Word in ransom not in magazine -> OUTPUT FAILURE!
                    goto nextWord;                  // This one wasn't a match, but we still keep some hope!
                }
            }

            // Found a match -> discard word in magazine and look for the next one in ransom
            magazine[j][0] = '-';
            break;
            nextWord:;
        }
    }
    // Found a match for every word in ransom
    printf("Yes\n");
    return 0;

    fail: // Impossible to compose the letter with that magazine fragment
    printf("No\n");
    return 0;
}
