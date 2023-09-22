//  5073 삼각형과 세 변
//  https://www.acmicpc.net/problem/5073
#include <iostream>
#include <cmath>

using namespace std;

int main(void) {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL); 
  cout.tie(NULL);

  while (1) {
    int a, b, c;
    cin >> a >> b >> c;
    
    if (a == 0 && b == 0 && c == 0) 
      break;
    else {
      if (a+b <= c || b+c<=a || a+c <= b) cout << "Invalid" << "\n";
      else {
        if (a == b && b == c) {
          cout << "Equilateral" << "\n";
        } else if ((a == b && b != c) || (b == c && a != c) || (a == c && c != b)) {
          cout << "Isosceles" << "\n";
        } else {
          cout << "Scalene" << "\n";
        }
      }
    }
  }

  return 0;
}