#include <iostream>
#include <string>
using namespace std;
int solution(int n)
{
    int answer = 0;
    
    string strNumber = to_string(n);
    for(int index = 0; index < strNumber.size(); index++){
        string strTemp;
        strTemp = strNumber.at(index);
        answer += atoi(strTemp.c_str());   
    }

    return answer;
}