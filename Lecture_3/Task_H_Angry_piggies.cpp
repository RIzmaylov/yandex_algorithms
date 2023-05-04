#include <iostream>
#include <set>

using namespace std;

size_t Angry_Piggies()
{
  int N;
  cin >> N;
  set<int> all_x;
  while (N--)
  {
    int x, y;
    cin >> x >> y;
    all_x.insert(x);
  }
  return all_x.size();
}

int main()
{
  cout << Angry_Piggies() << endl;
  return 0;
}
