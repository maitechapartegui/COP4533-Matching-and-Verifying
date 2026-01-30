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
    // if (!(in >> n)) {
    //   // empty file
    //     return 0;
    // }
    //TODO: n=1 validation and add validation for equal h and students

    //create the output file
    //use the name to be the same
    string outputFile;
    size_t lastDot = filename.find_last_of(".");
    if (lastDot != string::npos) {
        outputFile = filename.substr(0,lastDot) + ".out";
    }
    else {
        outputFile = filename + ".out";
    }

    // need to store all the objects
    vector<Hospital> allHospitals(n);
    vector<Student> allStudents(n);
    // store the empty one
    queue<Hospital*> unmatchedHospitals;

    // for every hospital there is
    for(int i = 0; i < n; i++){
        //aka so index 0 is hospital1
        // so at hospitaln
        allHospitals[i].hosIndex = i;
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
        unmatchedHospitals.push(&allHospitals[i]);
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

    while (unmatchedHospitals.size() !=0){
        // grab the front of the queue
        Hospital* currHospital =unmatchedHospitals.front();
        unmatchedHospitals.pop();

        // grab the curr hospital index tracker aka wherer they are in their choices 1st 2nd etc
        // this index would be initilized to 0 becauese obvs want the first one
        int currPrefIndex = currHospital->prefIndex;
        // grab the studentNum that is the first choice
        int currStudentIndex = currHospital->preferenceList[currPrefIndex];
        // so student 1 is 0
        Student &currStudent = allStudents[currStudentIndex];

        if (!currStudent.isMatched){
            // if current student is NOT matched then match them to the hospital
            //update hospital matching details
            currHospital->gotAMatch(currStudentIndex,currPrefIndex);
            // update student object with hospital details
            currStudent.gotAMatch(currHospital->hosIndex);
        }
        // if the student IS matched
        else {
            //check who the student is currently matched with and compare this compare function int he class
            if (currStudent.betterMatchCheck(currHospital->hosIndex)) {
                // current hospital IS the better match
                // need to update the original hospital student is matched with and add to to teh queue
                Hospital &oldMatchHospital = allHospitals[currStudent.matchedHosIndex];
                oldMatchHospital.undoMatch();
                unmatchedHospitals.push(&oldMatchHospital);
                //update student details
                currStudent.gotAMatch(currHospital->hosIndex);
                //update curr hos details
                currHospital->gotAMatch(currStudentIndex,currPrefIndex);
                // then need to remove the curr from queue
                
            }
            else{
                //current hospital is NOT the better match and is therefore rejected
                // so we just need to try the next student waiting for the nexr round
                //add back to queue
                unmatchedHospitals.push(currHospital);
            }
        }
        currPrefIndex++;
        currHospital->prefIndex = currPrefIndex;
    }

    ofstream out(outputFile);
    if (!out) {
        throw runtime_error("couldnt create the output file");
    }

    for (int i = 0; i < n; i++) {
        out << allHospitals[i].hosNum << " " << allHospitals[i].matchedStudent + 1 << endl;
    }

    out.close();
    return 0;
}