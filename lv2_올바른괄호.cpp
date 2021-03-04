#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    int nRight = 0;
    for(int index = 0; index < s.size(); index++){
        if(s[index] == '(')
            nRight++;
        else
            nRight--;
        if(nRight < 0){
            answer = false;
            break;
        }
    }

    if(nRight != 0)
        answer = false;
    
    return answer;
}