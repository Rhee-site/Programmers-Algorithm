#include <string>
#include <vector>
#include <map>
using namespace std;

vector<string> StringSplit(string strInfo){
    vector<string> VecstrResult;
    string strTemp;
    for(int index = 0; index < strInfo.size(); index++){
        if(strInfo[index] == ' '){
            VecstrResult.push_back(strTemp);
            strTemp.clear();
        }
        else{
            strTemp += strInfo[index];
        }
    }
    VecstrResult.push_back(strTemp);
    return VecstrResult;
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    
    vector<string> VecstrUID;
    map<string, string> NameInfo;
    
    for(int index = 0; index < record.size(); index++){
        vector<string> VecstrTemp = StringSplit(record[index]);
        if(VecstrTemp[0][0] == 'E'){
            answer.push_back("님이 들어왔습니다.");
            VecstrUID.push_back(VecstrTemp[1]);
            NameInfo[VecstrTemp[1]] = VecstrTemp[2];
        }
        else if(VecstrTemp[0][0] == 'C'){
            NameInfo[VecstrTemp[1]] = VecstrTemp[2];
        }
        else if(VecstrTemp[0][0] == 'L'){
            answer.push_back("님이 나갔습니다.");
            VecstrUID.push_back(VecstrTemp[1]);
        }
    }
    
    for(int index = 0; index < answer.size(); index++)
        answer[index] = NameInfo[VecstrUID[index]] + answer[index];
    
    return answer;
}