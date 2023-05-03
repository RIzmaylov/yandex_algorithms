#include <iostream>
#include <set>
#include <string>

using namespace std;

void Cnt_Words()
{
  set<string> words;
  string temp;
  while(cin >> temp)
  {
    words.insert(temp);
  }
  cout << words.size() << endl;
}

int main()
{
  Cnt_Words();
  return 0;
}
