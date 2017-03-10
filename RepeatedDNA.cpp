class Solution {
  public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector< string > sequences;
        bool repeated = false;

        for( int init = 0; init + 10 < s.size() ; ++init ) {
            string current = s.substr(init, init+10);
            if( sequences.find(current) != string::npos ) continue;

            for( int search = init+1; search + 10 < s.size() ; ++search ) {
                if( s.substr(init, init+10) == current ) repeated = true;
            }

            if( repeated ) {
                sequences.push_back(current);
                repeated = false;
            }
        }

        return sequences;
    }
};

int main( int argc, char **argv ) {
    string s = "";
    cout << "Enter a DNA sequence: ";
    cin >> s;
    cout << "\nEntered: " << s << endl;

    vector< string > res = findRepeatedDnaSequences( s );

    cout << "Found these repeated sequences: "
}
