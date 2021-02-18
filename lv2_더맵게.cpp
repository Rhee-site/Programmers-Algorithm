#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    int nCount = scoville.size();
    
    if(scoville.size() == 1)
        if(scoville.front() < K)
            return -1;
    
    priority_queue<int, vector<int>, greater<int>> q;
    
    for(int index = 0; index < scoville.size(); index++){
        q.push(scoville[index]);
    }
    
    while(true){
        if(q.top() >= K)
            break;
        
        if(q.size() < 2){
            answer = -1;
            break;
        }
        
        int nFirst = q.top();
        q.pop();
        int nSecond = q.top();
        q.pop();
        q.push(nFirst + nSecond * 2);
        
        answer++;
        
         if(answer >= nCount){
            answer = -1;
            break;
        }
    }
    
    return answer;
}