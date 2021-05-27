#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int nIndex = 0;
    for(int index = 0; index < s.size(); index++){
        if(s[index] == 32){
            answer += " ";
            nIndex = 0;
        }
        else{
            if(nIndex % 2){
                if(s[index] >= 65 && s[index] <= 90)
                    answer += (s[index] + 32);
                else
                    answer += s[index];
            }
            else{
                if(s[index] >= 97 && s[index] <= 122)
                    answer += (s[index] - 32);   
                else
                    answer += s[index];
            }
            nIndex++;
        }
    }
    
    return answer;
}