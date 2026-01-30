#include <vector>
#include <map>

using namespace std;

struct Hospital {
    int hosNum;
    // always starts off as false
    bool isMatched = false;
    // should we make this hold the objects or just match the names?
    vector<int> preferenceList;
    //this is gonna correspond to the studentNum of the student class
    int matchedStudent = 0;
    // so basically if they got their first choice second choice etc so we dont have to go throught their preferenec list again 
    int matchedStudentIndex = 0;

    void gotAMatch(int student, int studentIndex){
        matchedStudent=0;
        matchedStudentIndex = studentIndex;
        isMatched = true;
    }

    void undoMatch(){
        isMatched = false;
        matchedStudent = 0;
        // need to leave student index as is cause we need to mvoe onto the next choice
    }
};

struct Student {
    int studentNum;
    bool isMatched = false;
    int currentMatchedHosNum= 0;
    // basically the index hospital and then the value will be the ranking
    // prefList[HOSPITAL1] = 1 AKA rank 
    vector<int> hospitalOrder;

    bool betterMatchCheck (int currHospital){
        if(hospitalOrder[currHospital] < hospitalOrder[currentMatchedHosNum]){
            // if it is a better match return true
            return true;
            // need to edit the new match details in the main
        }
        else{
            return false;
        }
    }
    void gotAMatch(int hospital){
        currentMatchedHosNum = hospital;
        isMatched = true;
    }
};