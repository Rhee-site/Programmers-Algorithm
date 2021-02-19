#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef struct {
    bool operator()(vector<int> VecnFirst, vector<int> VecnSecond){
        return VecnFirst[1] > VecnSecond[1];
    }
}Compare;

int solution(vector<vector<int>> jobs) {
    int answer = 0;

    sort(jobs.begin(), jobs.end());
    priority_queue<vector<int>, vector<vector<int>>, Compare> PriorityQ;

    int time = 0;
    int nCurrentJobIndex = 0;
    int nJobsCount = jobs.size();

    while(true){        
        if(nJobsCount > nCurrentJobIndex){
            if(time >= jobs[nCurrentJobIndex].front()){
                PriorityQ.push(jobs[nCurrentJobIndex++]);
                continue;
            }
        }

        if(!PriorityQ.empty()){
            time += PriorityQ.top()[1];
            answer += time - PriorityQ.top().front();
            PriorityQ.pop();
        }
        else
            time = jobs[nCurrentJobIndex].front();

        if(PriorityQ.empty()){
            if(nCurrentJobIndex >= nJobsCount){
                answer = answer / nJobsCount;
                break;   
            }
        }
}

    return answer;
}