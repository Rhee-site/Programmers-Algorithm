#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    
    int nProcessingCount = 0;
    int nZeroCount = 0;
    
    while(s != "1"){
        string strTemp;
        nProcessingCount++;
        
        for(int index = 0; index < s.size(); index++)
            if(s[index] == '0')
                nZeroCount++;
            else
                strTemp += "1";
        
        int nTemp = strTemp.size();
        s.clear();
        while(nTemp > 0){
            s += to_string(nTemp % 2);
            nTemp /= 2;
        }
    }
    
    answer.push_back(nProcessingCount);
    answer.push_back(nZeroCount);
    
    return answer;
}