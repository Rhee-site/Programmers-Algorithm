#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    
    vector<int> VecnNumbers;
    for(int index = 0; index < operations.size(); index++){
        
        istringstream ss(operations[index]);
        vector<string> VecstrTemp;
        string strTemp;
        
        while(getline(ss, strTemp, ' '))
            VecstrTemp.push_back(strTemp);
        
        if(VecstrTemp[0] == "I"){
            VecnNumbers.push_back(stoi(VecstrTemp[1]));
            sort(VecnNumbers.begin(), VecnNumbers.end());
        }
        else{
            if(VecnNumbers.size()){
                if(VecstrTemp[1] == "1")
                    VecnNumbers.erase(VecnNumbers.end() - 1);
                else
                    VecnNumbers.erase(VecnNumbers.begin());   
            }
        }
    }
    
    if(VecnNumbers.size()){
        answer.push_back(VecnNumbers.back());   
        answer.push_back(VecnNumbers.front());
    }
    else{
        answer.push_back(0);
        answer.push_back(0);
    }
    
    return answer;
}