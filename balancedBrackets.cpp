// Problem from Hackerrank

// Handout
//
// A bracket is considered to be any one of the following characters: (, ), {, }, [, or ].
//
// Two brackets are considered to be a matched pair if the an opening bracket (i.e., (, [, or {)
// occurs to the left of a closing bracket (i.e., ), ], or }) of the exact same type.
// There are three types of matched pairs of brackets: [], {}, and ().
//
// A matching pair of brackets is not balanced if the set of brackets it encloses are not matched.
// For example, {[(])} is not balanced because the contents in between { and } are not balanced.
// The pair of square brackets encloses a single, unbalanced opening bracket, (,
// and the pair of parentheses encloses a single, unbalanced closing square bracket, ].
//
// By this logic, we say a sequence of brackets is considered to be balanced if the following conditions are met:
// - It contains no unmatched brackets.
// - The subset of brackets enclosed within the confines of a matched pair of brackets
//   is also a matched pair of brackets.
//
// Given strings of brackets, determine whether each sequence of brackets is balanced.
// If a string is balanced, print YES on a new line; otherwise, print NO on a new line.
//
// Input Format
//
// The first line contains a single integer, , denoting the number of strings.
// Each line i of the n subsequent lines consists of a single string s, denoting a sequence of brackets.
//
// Constraints
//
// 1 <= n <= 10^3       , being n the number of expressions
// 1 <= len(s) <= 10^3  , being s the expression
// Each character in the sequence will be a bracket (i.e., {, }, (, ), [, or ]).
//
// Output Format
//
// For each string, print whether or not the string of brackets is balanced on a new line.
// If the brackets are balanced, print YES; otherwise, print NO.
//
// Sample Input
//
// 3
// {[()]}
// {[(])}
// {{[[(())]]}}
//
// Sample Output
//
// YES
// NO
// YES

#include <string>
#include <stack>
#include <iostream>

using namespace std;

bool is_balanced(string expression) {
    // Create a stack to implement the context-free grammar with production rules
    // 1. S -> SS
    // 2. S -> ()
    // 3. S -> (S)
    // 4. S -> []
    // 5. S -> [S]
    // 6. S -> {}
    // 7. S -> {S}
    stack<char> brackets;

    // Iterate through the expression, to see if it is a word in the grammar
    for ( uint i = 0; i < expression.size(); ++i ) {
        switch( expression[i] ) {
            // Opening a bracket of any type always matches the start of a PR.
            case '(': case '[': case '{': { brackets.push( expression[i] ); break; }

            // Closing a bracket matches the end of a PR only if the expression is balanced
            case ')': {
                if( brackets.size() && brackets.top() == '(' ) { brackets.pop(); break; }
                return false;
            }
            case ']': {
                if( brackets.size() && brackets.top() == '[' ) { brackets.pop(); break; }
                return false;
            }
            case '}': {
                if( brackets.size() && brackets.top() == '{' ) { brackets.pop(); break; }
                return false;
            }
        }
    }
    // The word is in the grammar iff there are no more brackets left to match in the end.
    return brackets.empty();
}

int main(){
    int t;
    string expression;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        cin >> expression;
        if( is_balanced(expression) ) cout << "YES" << endl;
        else cout << "NO" << endl;
        expression.erase();
    }
    return 0;
}
