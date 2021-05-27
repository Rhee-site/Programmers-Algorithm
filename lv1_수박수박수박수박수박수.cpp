#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    
    for(int index = 0; index < n; index++){
        if(index % 2)
            answer += "박";
        else
            answer += "수";
    }
    
    return answer;
}