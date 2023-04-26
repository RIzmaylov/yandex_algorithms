#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

void BiggerMult2(int64_t& num1, int64_t& num2) {
  vector<int64_t> nums;
  int64_t temp;
  while(cin >> temp) {
    nums.push_back(temp);
  }
  int64_t first_pos_max, second_pos_max, first_neg_max, second_neg_max;
  if (nums[0] > nums[1]) {
    first_pos_max = nums[0];
    second_pos_max = nums[1];
  }
  else {

    first_pos_max = nums[1];
    second_pos_max = nums[0];
  }
  if (nums.size() == 2) {
    num1 = second_pos_max;
    num2 = first_pos_max;
    return;
  }
  first_neg_max = second_pos_max;
  second_neg_max = first_pos_max;
  for (size_t i = 2; i < nums.size(); ++i) {
    if (nums[i] > first_pos_max) {
      second_pos_max = first_pos_max;
      first_pos_max = nums[i];
    }
    else if (nums[i] > second_pos_max) {
      second_pos_max = nums[i];
    }
    if (nums[i] < first_neg_max) {
      second_neg_max = first_neg_max;
      first_neg_max = nums[i];
    }
    else if (nums[i] < second_neg_max) {
      second_neg_max = nums[i];
    }
  }
  int64_t pos_prod = first_pos_max * second_pos_max;
  int64_t neg_prod = first_neg_max * second_neg_max;
  if (pos_prod > neg_prod) {
    num1 = second_pos_max;
    num2 = first_pos_max;
  } else {
    num1 = first_neg_max;
    num2 = second_neg_max;
  }
}

int main_G() {
  int64_t num1, num2;
  BiggerMult2(num1, num2);
  cout << num1 << ' ' << num2 << endl;
  return 0;
}

/*
Дан список, заполненный произвольными целыми числами. Найдите в этом списке два числа, произведение которых максимально.
Выведите эти числа в порядке неубывания.

Список содержит не менее двух элементов. Числа подобраны так, что ответ однозначен.

Решение должно иметь сложность O(n), где n - размер списка.
*/
