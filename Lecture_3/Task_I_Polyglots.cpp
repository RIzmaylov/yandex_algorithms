#include <iostream>
#include <set>

using namespace std;

void Polyglots()
{
  int N, M;
  cin >> N;
  set<string> all_langs;
  set<string> main_langs;
  for(int i = 0; i < N; ++i)
  {
    cin >> M;
    set<string> langs;
    for (int j = 0; j < M; ++j)
    {
      string lang;
      cin >> lang;
      langs.insert(lang);
    }
    all_langs.merge(langs);
    if (langs.size())
    {
      main_langs = langs;
    }
    else
    {
      main_langs.clear();
    }
  }
  cout << main_langs.size() << endl;
  for (auto c : main_langs)
  {
    cout << c << endl;
  }
  cout << all_langs.size() << endl;
  for (auto c : all_langs)
  {
    cout << c << endl;
  }
}

int main()
{
  Polyglots();
  return 0;
}
