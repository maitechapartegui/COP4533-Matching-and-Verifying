#include <vector>
#include <map>

using namespace std;

struct Hospital {
    bool isMatched;
    // should we make this hold the objects or just match the names?
    vector<int> preferenceList;
    int matchedStudent;
    // so basically if they got their first choice second choice etc so we dont have to go throught their preferenec list again 
    int mathedStudentIndex;
};

struct Student {
    bool isMatched;
    int currentMatchedHos;
    vector<int> preferenceList;
    map<int, int> studentOrder;

    map<int, int> grabOrder() {
        //for every thing in the pref list
        for (int i=1; i < preferenceList.size()+1; i++){
            //grab the student it is and its i and add it to the map
            // {hospital, ranking}
            studentOrder.insert({preferenceList[i],i});
        }
    };
    
};