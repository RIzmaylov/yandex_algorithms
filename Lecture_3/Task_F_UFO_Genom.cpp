#include <iostream>
#include <set>

using namespace std;

int UFO_Genom()
{
  string frst_gen, scnd_gen;
  cin >> frst_gen >> scnd_gen;
  multiset<int> collection_1;
  int res = 0;
  for (int c = 0; c < frst_gen.size() - 1; ++c)
  {
    int temp = frst_gen[c] * 100 + frst_gen[c + 1];
    collection_1.insert(temp);
  }
  for (int c = 0; c < scnd_gen.size() - 1; ++c)
  {
    int temp = scnd_gen[c] * 100 + scnd_gen[c + 1];
    res += collection_1.count(temp);
  }
  return res;
}

int main()
{
  cout << UFO_Genom() << endl;
  return 0;
}
