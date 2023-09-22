// 23971 ZOAC 4
// https://www.acmicpc.net/problem/23971
#include <iostream>
#include <cmath>

using namespace std;

int main(void) {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL); 
  cout.tie(NULL);

  int H, W, N, M;
  cin >> H >> W >> N >> M;
  double a = (double)H / (double(N)+1);
  double b = (double)W / (double(M)+1);
  cout << (int)ceil(a) * (int)ceil(b);

  return 0;
}