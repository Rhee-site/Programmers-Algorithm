#include <string>
#include <vector>

using namespace std;

double solution(vector<int> arr) {
    double answer = 0;
    for(int index = 0; index < arr.size(); index++)
        answer += arr[index];
    answer /= arr.size();
    return answer;
}