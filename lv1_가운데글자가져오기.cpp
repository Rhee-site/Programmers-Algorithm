#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    
    int nTargetIndex = s.size() / 2;
    if(s.size() % 2){
        answer += s.at(nTargetIndex);
    }
    else{
        answer += s.at(nTargetIndex - 1);
        answer += s.at(nTargetIndex);
    }
    
    return answer;
}