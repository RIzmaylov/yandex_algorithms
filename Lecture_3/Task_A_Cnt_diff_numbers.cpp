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

int main_A()
{
  cout << Cnt_Diff_Nums() << endl;
  return 0;
}

/*
Дан список чисел, который может содержать до 100000 чисел. Определите, сколько в нем встречается различных чисел.

Формат ввода
Вводится список целых чисел. Все числа списка находятся на одной строке.

Формат вывода
Выведите ответ на задачу.
*/
