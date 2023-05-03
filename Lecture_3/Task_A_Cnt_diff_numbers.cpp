#include <iostream>
#include <set>

using namespace std;

int Cnt_Diff_Nums()
{
  set<int> nums;
  int num;
  while(cin >> num)
  {
    nums.insert(num);
  }
  return nums.size();
}

int main()
{
  cout << Cnt_Diff_Nums() << endl;
  return 0;
}

/*
Даны два списка чисел, которые могут содержать до 10000 чисел каждый.
Выведите все числа, которые входят как в первый, так и во второй список в порядке возрастания.
Примечание. И даже эту задачу на Питоне можно решить в одну строчку.

Формат ввода
Вводятся два списка целых чисел. Все числа каждого списка находятся на отдельной строке.

Формат вывода
Выведите ответ на задачу.
*/
