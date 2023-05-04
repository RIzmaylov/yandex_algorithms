#include <iostream>
#include <set>

using namespace std;

int Turtles()
{
  int N;
  int res = 0;
  cin >> N;
  set<int> behind;
  set<int> in_front;
  for (int i = 0; i < N; ++i)
  {
    int a, b;
    cin >> a >> b;
    if (a >= 0 && b >= 0 && a + b == N - 1 && behind.find(a) == behind.end() && in_front.find(b) == in_front.end())
    {
      ++res;
      behind.insert(a);
      in_front.insert(b);
    }
  }
  return res;
}

int main()
{
  cout << Turtles() << endl;
  return 0;
}
