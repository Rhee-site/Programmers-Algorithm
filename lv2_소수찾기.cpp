#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string numbers) {
    int answer = 0;
    
    vector<string> VecStrNumbers;
    vector<int> VecnNumbers;
    
    for(int index = 0; index < numbers.size(); index++){
        string strTemp;
        strTemp = numbers.at(index);
        VecStrNumbers.push_back(strTemp);
        VecnNumbers.push_back(stoi(strTemp));
    }
    
    for(int index = 0; index < VecStrNumbers.size(); index++){
        string strBitMask(index + 1, 1);
        strBitMask.resize(VecStrNumbers.size(), 0);
        
        do{
            string strTemp;
            for(int i = 0; i < VecStrNumbers.size(); i++)
                if(strBitMask[i])
                    strTemp += VecStrNumbers[i];
            VecnNumbers.push_back(stoi(strTemp));    
        }while(next_permutation(VecStrNumbers.begin(), VecStrNumbers.end()));
    }
    
    for(vector<int>::iterator iter = VecnNumbers.begin(); iter != VecnNumbers.end();){
        if(*iter < 2)
            iter = VecnNumbers.erase(iter);
        else{
            bool bCheck = true;
            for(int index = 2; index < *iter; index++){
                if(*iter % index == 0){
                    bCheck = false;
                    break;
                }
            }
            
            if(bCheck)
                iter++;
            else
                iter = VecnNumbers.erase(iter);
        }
    }
    
    sort(VecnNumbers.begin(), VecnNumbers.end());
    VecnNumbers.erase(unique(VecnNumbers.begin(), VecnNumbers.end()), VecnNumbers.end());
    
    answer = VecnNumbers.size();
        
    return answer;
}