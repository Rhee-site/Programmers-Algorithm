#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;

    int nPCount = 0;
    int nYCount = 0;
    for(int index = 0; index < s.size(); index++){
        if(s[index] == 'p')
            nPCount++;
        else if(s[index] == 'P')
            nPCount++;
        else if(s[index] == 'y')
            nYCount++;
        else if(s[index] == 'Y')
            nYCount++;
    }    
    
    if(nPCount != nYCount)
        answer = false;

    return answer;
}