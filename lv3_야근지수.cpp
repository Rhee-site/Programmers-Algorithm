#include <string>
#include <vector>
#include <queue>
using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    
    priority_queue<int, vector<int>, less<int>> pq;
    for(int index = 0; index < works.size(); index++)
        pq.push(works[index]);
    
    int nTime = 0;
    while(true){
        if(nTime == n)
            break;
        
        int nTargetWorks = pq.top();
        pq.pop();
        nTargetWorks--;
        if(nTargetWorks)
            pq.push(nTargetWorks);
        
        nTime++;
    }
    
    int nCount = pq.size();
    for(int index = 0; index < nCount; index++){
        answer += pq.top() * pq.top();
        pq.pop();
    }
    
    return answer;
}