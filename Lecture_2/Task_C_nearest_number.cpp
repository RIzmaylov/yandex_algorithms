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

int main()
{
  int size;
  cin >> size;
  cout << TakeArrAndGetNearestNum(size) << endl;
  return 0;
}
