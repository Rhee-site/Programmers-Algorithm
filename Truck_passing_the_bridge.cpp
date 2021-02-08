#include <string>
#include <vector>
#include <iostream>
using namespace std;

typedef struct{
    int nWeight;
    int nLength;
}TruckInfo;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    
    int nSum = 0;
    vector<TruckInfo> VecTruckInfo;
    
    while(true){
        if(VecTruckInfo.size() == 0)
            if(truck_weights.size() == 0)
                break;
        
        answer++;
        
        for(vector<TruckInfo>::iterator iter = VecTruckInfo.begin(); iter != VecTruckInfo.end();){
            iter->nLength++;
            if(iter->nLength >= bridge_length){
                nSum -= iter->nWeight;
                iter = VecTruckInfo.erase(iter);
            }
            else
                iter++;
        }
        
        if(truck_weights.size() != 0){
            if(nSum + truck_weights.front() <= weight){
                 nSum += truck_weights.front();
                 TruckInfo Temp;
                 Temp.nWeight = truck_weights.front();
                 Temp.nLength = 0;
                 VecTruckInfo.push_back(Temp);
                truck_weights.erase(truck_weights.begin());
            }   
        }
    }
    
    return answer;
}