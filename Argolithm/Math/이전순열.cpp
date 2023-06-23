#include <algorithm>  
#include <vector>  

using namespace std;

int n;
vector <int> per;

bool previous_permutation(vector<int>& per, int n) {
    int i = n - 1;
    while (i > 0 && per[i - 1] <= per[i]) i -= 1;
    if (i <= 0) return false;
    int j = n - 1;
    while (per[j] >= per[i - 1]) j -= 1;
    int temp = per[i - 1];
    per[i - 1] = per[j];
    per[j] = temp;
    j = n - 1;
    while (i < j) {
        temp = per[i];
        per[i] = per[j];
        per[j] = temp;
        i += 1;
        j -= 1;
    }
    return true;
}