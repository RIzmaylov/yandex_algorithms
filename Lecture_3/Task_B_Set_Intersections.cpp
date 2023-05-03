#include <iostream>
#include <sstream>
#include <set>

using namespace std;


int main()
{
  set<int> set1, set2;
  string s1, s2;
  getline(cin, s1);
  getline(cin, s2);
  stringstream ss1(s1), ss2(s2);
  while(ss1)
  {
    int temp;
    ss1 >> temp;
    set1.insert(temp);
  }
  while(ss2)
  {
    int temp;
    ss2 >> temp;
    set2.insert(temp);
  }
  if (set1.size() > set2.size())
  {
    set1.merge(set2);
    for (auto i : set2)
    {
      cout << i << ' ';
    }
    cout << endl;
  }
  else
  {
    set2.merge(set1);
    for (auto i : set1)
    {
      cout << i << ' ';
    }
    cout << endl;
  }
  return 0;
}

/*
Даны два списка чисел, которые могут содержать до 10000 чисел каждый.
Выведите все числа, которые входят как в первый, так и во второй список в порядке возрастания. Примечание.
И даже эту задачу на Питоне можно решить в одну строчку.

Формат ввода
Вводятся два списка целых чисел. Все числа каждого списка находятся на отдельной строке.

Формат вывода
Выведите ответ на задачу.
*/
