#include <iostream>
#include <set>

using namespace std;

int OpenCalculator()
{
  set<int> nums;
  for (int i = 0; i < 3; ++i)
  {
    int temp_num;
    cin >> temp_num;
    nums.insert(temp_num);
  }
  int output_num;
  cin >> output_num;
  set<int> output_num_in_set;
  while(output_num != 0)
  {
    output_num_in_set.insert(output_num % 10);
    output_num /= 10;
  }
  int old_size = nums.size();
  nums.merge(output_num_in_set);
  return nums.size() - old_size;
}

int main_E()
{
  cout << OpenCalculator() << endl;
  return 0;
}

/*
В новой программе OpenCalculator появилась новая возможность – можно настроить, какие кнопки отображаются, а какие – нет.
Если кнопка не отображается на экране, то ввести соответствующую цифру с клавиатуры или копированием из другой программы нельзя.
Петя настроил калькулятор так, что он отображает только кнопки с цифрами x, y, z. Напишите программу, определяющую,
сможет ли Петя ввести число N, а если нет, то какое минимальное количество кнопок надо дополнительно отобразить на экране для его ввода.

Формат ввода
Сначала вводятся три различных числа из диапазона от 0 до 9: x, y и z (числа разделяются пробелами).
Далее вводится целое неотрицательное число N, которое Петя хочет ввести в калькулятор. Число N не превышает 10000.

Формат вывода
Выведите, какое минимальное количество кнопок должно быть добавлено для того, чтобы можно было ввести число N
(если число может быть введено с помощью уже имеющихся кнопок, выведите 0)
*/
