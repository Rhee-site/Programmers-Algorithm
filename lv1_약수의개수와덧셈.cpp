#include <string>
#include <vector>

using namespace std;

int solution(int left, int right) {
    int answer = 0;
    
    int index = left;
    while(index <= right){
        int nCount = 0;
        for(int i = 1; i <= index; i++)
            if(index % i == 0)
                nCount++;
        
        if(nCount % 2 == 0)
            answer += index;
        else
            answer -= index;
        
        index ++;
    }
    
    return answer;
}