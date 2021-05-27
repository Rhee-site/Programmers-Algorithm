#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    bool answer = true;
    string strNumber = to_string(x);
    int nSum = 0;
    for(int index = 0; index < strNumber.size(); index++){
        string strTemp;
        strTemp = strNumber[index];
        nSum += stoi(strTemp);
    }
    
    if(x % nSum)
        answer = false;
    
    return answer;
}