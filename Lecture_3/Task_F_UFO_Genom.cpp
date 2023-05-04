#include <iostream>
#include <set>

using namespace std;

size_t UFO_Genom()
{
  string frst_gen, scnd_gen;
  cin >> frst_gen >> scnd_gen;
  multiset<string> collection_1;
  size_t res = 0;
  for (size_t c = 0; c < scnd_gen.size() - 1; ++c)
  {
    string temp = "";
    temp += scnd_gen[c];
    temp += scnd_gen[c + 1];
    collection_1.insert(temp);
  }
  for (size_t c = 0; c < frst_gen.size() - 1; ++c)
  {
    string temp = "";
    temp += frst_gen[c];
    temp += frst_gen[c + 1];
//    res += collection_1.count(temp);
  if (collection_1.find(temp) != collection_1.end()) res++;
  }
  return res;
}

int main()
{
  cout << UFO_Genom() << endl;
  return 0;
}
