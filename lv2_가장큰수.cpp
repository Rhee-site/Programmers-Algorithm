#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool Compare(string strFirst, string strSecond){
    return strFirst + strSecond > strSecond + strFirst;
}

string solution(vector<int> numbers) {
    string answer = "";
    
    vector<string> VecstrNumbers;
    for(int index = 0; index < numbers.size(); index++)
        VecstrNumbers.push_back(to_string(numbers[index]));
    
    sort(VecstrNumbers.begin(), VecstrNumbers.end(), Compare);
    
    if(VecstrNumbers.front() == "0")
        answer = "0";
    else
        for(int index = 0; index < VecstrNumbers.size(); index++)
            answer += VecstrNumbers[index];
    
    return answer;
}