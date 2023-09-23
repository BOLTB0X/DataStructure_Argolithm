// 7568 덩치
// https://www.acmicpc.net/problem/7568
#include <iostream>

using namespace std;

int N;
pair<int, int> mens[51];

int main(void) {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL); 
  cout.tie(NULL);

  cin >> N;
  for (int i = 1; i <= N; ++i) {
    cin >> mens[i].first >> mens[i].second;
  }

  for (int i = 1; i <= N; ++i) {
    int rank = 1;
    for (int j = 1; j <= N; ++j) {
      if (i == j) continue;
      if ((mens[i].first < mens[j].first) && 
        (mens[i].second < mens[j].second)) {
        rank += 1;
        }
    }
    cout << rank << " ";
  }

  
  return 0;
}