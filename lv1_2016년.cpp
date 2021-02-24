#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    string answer = "";
    
    vector<int> VecnLastDay;
    VecnLastDay.push_back(31);
    VecnLastDay.push_back(29);
    VecnLastDay.push_back(31);
    VecnLastDay.push_back(30);
    VecnLastDay.push_back(31);
    VecnLastDay.push_back(30);
    VecnLastDay.push_back(31);
    VecnLastDay.push_back(31);
    VecnLastDay.push_back(30);
    VecnLastDay.push_back(31);
    VecnLastDay.push_back(30);
    VecnLastDay.push_back(31);
    
    int nDay = 0;
    for(int index = 0; index < a - 1; index++)
        nDay += VecnLastDay[index];
    nDay += b;
    
    int nShare = nDay / 7;
    int nBorder = nDay % 7;
    
    if(nBorder == 0)
        answer = "THU";
    else if(nBorder == 1)
        answer = "FRI";
    else if(nBorder == 2)
        answer = "SAT";
    else if(nBorder == 3)
        answer = "SUN";
    else if(nBorder == 4)
        answer = "MON";
    else if(nBorder == 5)
        answer = "TUE";
    else if(nBorder == 6)
        answer = "WED";
    
    return answer;
}