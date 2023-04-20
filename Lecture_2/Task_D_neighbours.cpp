#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int CalcBiggerNumber() {
  int temp;
  int res_cnt = 0;
  vector<int> numbers;
  string temp_string;
  getline(cin, temp_string);
  stringstream ss(temp_string);
  while (ss >> temp) {
    numbers.push_back(temp);
  }
  for (size_t i = 1; i < numbers.size() - 1; ++i) {
    if (numbers[i] > numbers[i - 1] && numbers[i] > numbers[i + 1]) {
      res_cnt++;
    }
  }
  return res_cnt;
}

int main_D() {
  cout << CalcBiggerNumber() << endl;
  return 0;
}

/*
Дан список чисел. Определите, сколько в этом списке элементов, которые больше двух своих соседей и выведите количество таких элементов.

Формат ввода
Вводится список чисел. Все числа списка находятся на одной строке.

Формат вывода
Выведите ответ на задачу.
*/
