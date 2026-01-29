#include <fstream>
#include <iostream>
#include <vector>
using namespace std;


// Read in input file
// Hanlde input data and separate into vectors?
// Do actual algorithm code

int main(int argc, char** argv){
    // Read in file information
    if(argc < 2){
        cout << "Invalid input" << endl;
        return 1;
    }
    string filename = argv[1];

    ifstream in(filename);
    if(!in){
        throw runtime_error("Could not open input file");
    }

    int n;
    in >> n;

    if(n <= 0){
        throw runtime_error("Invalid 'n' value");
    }


    // Create data storage structures
    vector<vector<int>> hospitalPrefs(n, vector<int>(n));
    vector<vector<int>> studentPrefs(n, vector<int>(n));

    for(int i = 0; i < n; i++){
        for(int j =0; j < n; j++){
                in >> hospitalPrefs[i][j];
                cout << hospitalPrefs [i][j];
        }
        cout << "\n";
    }

    for(int i = 0; i < n; i++){
        for(int j =0; j < n; j++){
                in >> studentPrefs[i][j];
                cout << studentPrefs[i][j];
        }
        cout << "\n";
    }


    // Start matching algorithm logic
    vector<vector<int>> pairs(n, vector<int>(2));

    
}