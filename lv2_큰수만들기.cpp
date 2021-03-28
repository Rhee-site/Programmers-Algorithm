#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    
    int nSearchIndex = 0;
    for(int index = 0; index < number.size() - k; index++){
        char chMaxNumber = number[nSearchIndex];
        int nMaxIndex = nSearchIndex;
        for(int nTemp = nSearchIndex; nTemp <= k + index; nTemp++){
            if(chMaxNumber < number[nTemp]){
                chMaxNumber = number[nTemp];
                nMaxIndex = nTemp;
            }
        }
        nSearchIndex = nMaxIndex + 1;
        answer += chMaxNumber;
    }
    
    return answer;
}