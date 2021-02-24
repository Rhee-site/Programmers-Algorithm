#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    
    istringstream ss(s);
    string strTemp;
    vector<int> VecnNumber;
    
    while(getline(ss, strTemp, ' '))
        VecnNumber.push_back(stoi(strTemp));
        
    int nMax = *max_element(VecnNumber.begin(), VecnNumber.end());
    int nMin = *min_element(VecnNumber.begin(), VecnNumber.end());
    
    answer += to_string(nMin);
    answer += " ";
    answer += to_string(nMax);
    
    return answer;
}