#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    
    for(int index = 0; index < s.size(); index++){
        if(s[index] == 32){
            answer += " ";
        }
        else{
            if(s[index] > 64 && s[index] < 91){
                if(s[index] + n > 90){
                    answer += (s[index] + n - 26);
                }
                else{
                    answer += (s[index] + n);
                }
            }
            else if(s[index] > 96 && s[index] < 123){
                if(s[index] + n > 122){
                    answer += (s[index] + n - 26);
                }
                else{
                    answer += (s[index] + n);
                }
            }
        }
    }
    
    return answer;
}