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
    // TODO: Need to ensure number of students and hospitals is equal AND handle n=1



    // removed this sorry 
    // Create data storage structures
    // vector<vector<int>> hospitalPrefs(n, vector<int>(n));
    // vector<vector<int>> studentPrefs(n, vector<int>(n));

    // need to store all the objects
    vector<Hospital> allHospitals(n);
    vector<Student> allStudents(n);
    // store the empty one
    queue<int> unmatchedHospitals;

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
        unmatchedHospitals.push(i);
        cout << "\n";
    }

    // do the same for the students
    for(int i = 0; i < n; i++){
        allStudents[i].studentNum = i+1;
        allStudents[i].hospitalOrder.resize(n);
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
    // vector<Hospital> unmatchedHospitals(n);
    int hosProposing =0;

    while (unmatchedHospitals.size() !=0){
        // grab the front of the queue
        int hNum = unmatchedHospitals.front();
        Hospital &currHospital = allHospitals[hNum];
        unmatchedHospitals.pop();

        // grab the curr hospital index tracker aka wherer they are in their choices 1st 2nd etc
        // this index would be initilized to 0 becauese obvs want the first one
        int currPrefIndex = currHospital.matchedStudentIndex;
        // grab the studentNum that is the first choice
        int currStudentNum = currHospital.preferenceList[currPrefIndex];
        
        Student &currStudent = allStudents[currStudentNum];

        if (!currStudent.isMatched){
            // if current student is NOT matched then match them to the hospital
            //update hospital matching details
            currHospital.gotAMatch(currStudentNum,currPrefIndex);
            // update student object with hospital details
            currStudent.gotAMatch(currHospital.hosNum);
        }
        // if the student IS matched
        else {
            //check who the student is currently matched with and compare this compare function int he class
            if (currStudent.betterMatchCheck(hNum)) {
                // current hospital IS the better match
                // need to update the original hospotal student is matched with and add to to teh queue
                Hospital &oldMatchHospital = allHospitals[currStudent.currentMatchedHosNum];
                oldMatchHospital.undoMatch();
                unmatchedHospitals.push(oldMatchHospital.hosNum);
                //update student details
                currStudent.gotAMatch(hNum);
                //update curr hos details
                currHospital.gotAMatch(currStudentNum,currPrefIndex);
                // then need to remove the curr from queue
                
            }
            else{
                //current hospital is NOT the better match and is therefore rejected
                // so we just need to try the next student waiting for the nexr round
                //add back to queue
                unmatchedHospitals.push(hNum);
            }
        }
        currPrefIndex ++;
    }
    
}