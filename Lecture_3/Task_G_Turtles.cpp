#include <iostream>

using namespace std;

int Turtles()
{
  int N;
  int res = 0;
  cin >> N;
  for (int i = 0; i < N; ++i)
  {
    int a, b;
    cin >> a >> b;
    if (a + b == N - 1) ++res;
  }
  return res;
}

int main()
{
  cout << Turtles() << endl;
  return 0;
}
