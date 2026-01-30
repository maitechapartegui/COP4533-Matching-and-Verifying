#include <fstream>
#include <iostream>
#include <vector>
#include "hospitalStudents.cpp"
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


    // removed this sorry 
    // Create data storage structures
    // vector<vector<int>> hospitalPrefs(n, vector<int>(n));
    // vector<vector<int>> studentPrefs(n, vector<int>(n));

    // need to store all the objects
    vector<Hospital> allHospitals;
    vector<Student> allStudents;
    // store the empty one
    queue<Hospital> emptyHospitals;

    // for every hospital there is
    for(int i = 0; i < n; i++){
        //aka so index 0 is hospital1
        // so at hospitaln
        allHospitals[i].hosNum = i+1;
        for(int j =0; j < n; j++){
                // start grabbing the input into the list
                int studentNum;
                in >> studentNum;
                // need to be studentNum because it need sto start at 0 index
                allHospitals[i].preferenceList.push_back(studentNum-1);
                // cout << hospitalPrefs [i][j];
        }
        //add to the empty hospital list the hospital object
        emptyHospitals.push(allHospitals[i]);
        cout << "\n";
    }

    // do the same for the students
    for(int i = 0; i < n; i++){
        allStudents[i].studentNum = i+1;
        for(int j =0; j < n; j++){
                int hospitalNum;
                in >> hospitalNum;
                // basically at hospital number 1 = index in the pref list
                // aka hospital 1 is in the 2nd index yk?
                allStudents[i].hospitalOrder[hospitalNum-1] = j;
                // cout << studentPrefs[i][j];
        }
        cout << "\n";
    }

    // // Start matching algorithm logic
    // vector<vector<int>> pairs(n, vector<int>(2));

    // START THE ALGORITHMN
    //create the lists of hospitals
    vector<Hospital> unmatchedHospitals(n);
    int hosProposing =0;

    while (unmatchedHospitals.size() !=0){
        Hospital currentHos = unmatchedHospitals[hosProposing];
        // grab what their choice we are checking should initalize to 1
        int currPrefIndex = currentHos.matchedStudentIndex;
        //THIS IS AN ERROR NEED TO FIND 
        //ideally this would refer to the student class 
        // if current student in this index is not matched then 
        if (currentHos.preferenceList[currPrefIndex]){
            // then match/add them to the hospital
            //update the student object with the hospital details
        }
        else {
            //check who the student is currently matched with and use the orderMap to compare values
            //if curr hospital value is less than the matched hosptial value 
                //updated the og matched hospital details and revert to original
                //update student object with current hospital details
                //update current hospital with student details
                // add og matched hospital back to empty hospital vector
            //else
                // 
        }


    }
    
}