#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    map<string, int> hash;
    for (auto p : participant) {
        if (hash.end() == hash.find(p))
            hash.insert(make_pair(p, 1));
        else
            hash[p]++;
    }
    
    for (auto c : completion) {
        hash[c]--;
    }
    
    for (auto p : participant) {
        if (hash[p] > 0) {
            answer = p;
            break;
        }
    }
    return answer;
}