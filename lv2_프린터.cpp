#include <string>
#include <vector>
#include <queue>

using namespace std;

typedef struct{
    int nPriority;
    bool bTarget;
}PrintInfo;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    vector<PrintInfo> VecPrint;
    priority_queue<int, vector<int>, less<int>> pq;
    for(int index = 0; index < priorities.size(); index++){
        PrintInfo Temp;
        Temp.nPriority = priorities[index];
        if(index == location)
            Temp.bTarget = true;
        else
            Temp.bTarget = false;
        VecPrint.push_back(Temp);
    
        pq.push(priorities[index]);
    }
    
    while(true){
        int nCurrentPriority = VecPrint.front().nPriority;
        bool bCurrentTarget = VecPrint.front().bTarget;
        if(nCurrentPriority == pq.top()){
            pq.pop();
            answer++;
            if(bCurrentTarget)
                break;
            VecPrint.erase(VecPrint.begin());
        }
        else{
            VecPrint.erase(VecPrint.begin());
            PrintInfo Temp;
            Temp.nPriority = nCurrentPriority;
            Temp.bTarget = bCurrentTarget;
            VecPrint.push_back(Temp);
        }
    }
    
    return answer;
}