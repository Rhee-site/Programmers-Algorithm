#include <iostream>
#include<vector>
#include <queue>
using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;

    priority_queue<int, vector<int>, less<int>> pq_A;
    priority_queue<int, vector<int>, greater<int>> pq_B;
    
    for(int index = 0; index < A.size(); index++){
        pq_A.push(A[index]);
        pq_B.push(B[index]);
    }
    
    while(!pq_A.empty() && !pq_B.empty()){
        answer += pq_A.top() * pq_B.top();
        pq_A.pop();
        pq_B.pop();
    }
    
    return answer;
}