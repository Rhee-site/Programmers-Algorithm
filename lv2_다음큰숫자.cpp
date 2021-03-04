#include <string>
#include <vector>
#include <bitset>

using namespace std;

int OneCounting(string strNumber){
    int nCount = 0;
    for(int index = 0; index < strNumber.size(); index++)
        if(strNumber[index] == '1')
            nCount++;
    return nCount;
}

int solution(int n) {
    int answer = 0;
    
    string strNumber = bitset<32>(n).to_string();
    int nOneCount = OneCounting(strNumber);
    answer = n + 1;
    
    while(true){
        string strTargetNumber = bitset<32>(answer).to_string();
        if(nOneCount == OneCounting(strTargetNumber))
            break;
        answer++;
    }
    
    return answer;
}