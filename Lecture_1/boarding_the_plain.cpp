#include <iostream>
#include <vector>

using namespace std;

void Boarding_the_plain() {
  int cnt_rows = 0;
  int cnt_passangers = 0;
  vector<int> left_side;
  vector<int> right_side;

  cin >> cnt_rows;
  for (int i = 0; i < cnt_rows; ++i) {
    char c;
    int number = 0;
    for (int j = 2; j >= 0; --j) {
      cin >> c;
      if (c == '#') {
        int g = 1 << j;
        number += g;
      }
    }
    left_side.push_back(number);
    number = 0;
    cin.peek();
    for (int j = 2; j >= 0; --j) {
      cin >> c;
      if (c == '#') {
        int g = 1 << j;
        number += g;
      }
    }
    right_side.push_back(number);
  }
}

int main_2()
{
  Boarding_the_plain();
  return 0;
}
