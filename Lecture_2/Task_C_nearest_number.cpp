#include <iostream>
#include <vector>

using namespace std;

int TakeArrAndGetNearestNum(int size) {
  vector<int> numbers;
  while (size--) {
    int x;
    cin >> x;
    numbers.push_back(x);
  }
  int main_num;
  cin >> main_num;
  int min_sub = abs(numbers[0] - main_num);
  int res = numbers[0];
  for (auto i : numbers) {
    if (abs(i - main_num) < min_sub) {
      min_sub = abs(i - main_num);
      res = i;
    }
  }
  return res;
}

int main_C()
{
  int size;
  cin >> size;
  cout << TakeArrAndGetNearestNum(size) << endl;
  return 0;
}

/*
Напишите программу, которая находит в массиве элемент, самый близкий по величине к  данному числу.

Формат ввода
В первой строке задается одно натуральное число N, не превосходящее 1000 – размер массива.
Во второй строке содержатся N чисел – элементы массива (целые числа, не превосходящие по модулю 1000).
В третьей строке вводится одно целое число x, не превосходящее по модулю 1000.

Формат вывода
Вывести значение элемента массива, ближайшее к x. Если таких чисел несколько, выведите любое из них
*/
