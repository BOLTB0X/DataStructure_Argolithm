#include <iostream>
#include <algorithm>

using namespace std;

int N, K;

struct Medal {
int number, gold, silver, bronze;

bool operator < (const Medal &a) const {
  if (gold == a.gold) {
    if (silver == a.silver) {
      return bronze > a.bronze;
    }
    return silver > a.silver;
  }
  return gold > a.gold;
}
};

Medal country[1001];

int main(void) {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL); 
  cout.tie(NULL);

  int answer = 1;
  
  cin >> N >> K;
  for (int i=1; i <= N; ++i) {
    cin >> country[i].number >> country[i].gold >> country[i].silver >> country[i].bronze;
  }

  sort(country+1, country+N+1);

  int idx = 0;

  for (int i =1; i<=N; ++i) {
    if (country[i].number == K) {
      idx = i;
      break;
    }
  }

  for (int i = 1; i <= N; ++i) {
    if (country[i].gold == country[idx].gold && 
      country[i].silver == country[idx].silver &&
      country[i].bronze == country[idx].bronze) {
      answer = i;
      break;
    }
  }

  cout << answer;
  
  return 0;
}