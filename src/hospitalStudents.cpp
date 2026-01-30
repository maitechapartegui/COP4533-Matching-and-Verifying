#include <vector>
#include <map>

using namespace std;

struct Hospital {
    int hosNum;
    // always starts off as false
    bool isMatched = false;
    // should we make this hold the objects or just match the names?
    vector<int> preferenceList;
    int matchedStudent =0;
    // so basically if they got their first choice second choice etc so we dont have to go throught their preferenec list again 
    int matchedStudentIndex = 1;

    void gotAMatch(int student, int studentIndex){
        matchedStudent=0;
        matchedStudentIndex = studentIndex;
    }
};

struct Student {
    int studentNum;
    bool isMatched = false;
    int currentMatchedHos= 0;
    // basically the index hospital and then the value will be the ranking
    // prefList[HOSPITAL1] = 1 AKA rank 
    vector<int> hospitalOrder;

    bool betterMatch (int currHospital){
        if(hospitalOrder[currHospital] < hospitalOrder[currentMatchedHos]){
            // if it is a better match return true
            return true;
            // need to edit the new match details in the main
        }
        else{
            return false;
        }
    }
    
};