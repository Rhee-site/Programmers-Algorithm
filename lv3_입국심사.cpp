#include <string>
#include <vector>
#include <algorithm>

using namespace std;

unsigned long long solution(int n, vector<int> times) {
    unsigned long long answer = 0;
    
    sort(times.begin(), times.end());
    
    unsigned long long low = 1;
    unsigned long long high = times.back() * n;
    
    while(low <= high){
        unsigned long long mid = (low + high) / 2;
        unsigned long long Current = 0;
        
        for(int index = 0; index < times.size(); index++)
            Current += mid / times[index];
        
        if(Current >= n){
            if(answer)
                answer = min(answer, mid);
            else
                answer = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    
    return answer;
}