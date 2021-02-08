#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    vector<int> VecnFinishDay;
    for(int index = 0; index < progresses.size(); index++){
        int nTurm = 0;
        while(true){
            nTurm++;
            if(progresses[index] + speeds[index] * nTurm >= 100){
                VecnFinishDay.push_back(nTurm);
                break;
            }
        }
    }
    
    while(true){
        if(VecnFinishDay.size() == 0)
            break;
        
        for(int index = 0; index < VecnFinishDay.size(); index++){
            if(VecnFinishDay[index] > 0)
                VecnFinishDay[index]--;       
        }
            
        int nTemp = 0;
        for(vector<int>::iterator iter = VecnFinishDay.begin(); iter != VecnFinishDay.end();){
            if(*iter == 0){
                nTemp++;
                iter = VecnFinishDay.erase(iter);
            }
            else
                break;
        }
        
        if(nTemp)
            answer.push_back(nTemp);
    }
    
    return answer;
}