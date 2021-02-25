#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    
    int nChooseCount = nums.size() / 2;
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(),nums.end()),nums.end());
    
    if(nChooseCount >= nums.size())
        answer = nums.size();
    else
        answer = nChooseCount;
    
    return answer;
}