#include <iostream>

using namespace std;

int main() {
  int N, K, M;
  cin >> N >> K >> M;

  int left_m = N;
  int cnt_details = 0;

  if (M > K || K > N) {
    cout << cnt_details << '\n';
    return 0;
  }
  while (left_m >= K) {
    int cnt_blanks = left_m / K;
    int m_left_1 = left_m % K;
    cnt_details += K / M * cnt_blanks;
    int m_left_2 = K % M;
    left_m = m_left_1 + m_left_2 * cnt_blanks;
  }

  cout << cnt_details << '\n';
  return 0;
}
