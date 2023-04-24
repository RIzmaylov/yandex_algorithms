#include <iostream>
#include <sstream>
#include <vector>
#include <deque>

using namespace std;

struct Answer {
  int cnt_nums;
  deque<int> nums;
};

Answer CntToSymSeq() {
  int N;
  cin >> N;
  vector<int> numbers;
  Answer answ;
  while(N--) {
    int temp;
    cin >> temp;
    numbers.push_back(temp);
  }
  int min_cnt = 0;
  int maybe_cnt = 0;
  for(size_t i = 0, j = numbers.size() - 1; i != j; ++i) {
    if (numbers[i] != numbers[j]) {
      maybe_cnt++;
      min_cnt = maybe_cnt;
    }
    if (numbers[i] == numbers[j]) {
      maybe_cnt++;
      j--;
    }
  }
  answ.cnt_nums = min_cnt;
  for (int i = 0; i < min_cnt; ++i) {
    answ.nums.push_front(numbers[i]);
  }
  return answ;
}

int main() {
  Answer answ = CntToSymSeq();
  cout << answ.cnt_nums << endl;
  for (auto i : answ.nums) {
    cout << i << ' ';
  }
  cout << endl;
  return 0;
}
