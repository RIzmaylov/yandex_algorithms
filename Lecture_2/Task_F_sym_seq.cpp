#include <iostream>
#include <vector>

using namespace std;

struct Answer {
  int cnt_nums = 0;
  vector<int> nums;
};


bool Is_Symmetric (const vector<int>& nums, int index) {
  int index_end = nums.size() - 1;
  for (; index <= index_end; ++index, --index_end) {
    if (nums[index] != nums[index_end]) return false;
  }
  return true;
}

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
  for (size_t i = 0; i < numbers.size(); ++i) {
    if (Is_Symmetric(numbers, i)) {
      answ.nums = {numbers.begin(), numbers.begin() + i};
      answ.cnt_nums = i;
      break;
    }
  }
  return answ;
}

int main_F() {
  Answer answ = CntToSymSeq();
  cout << answ.cnt_nums << endl;
  for (int i = answ.nums.size() - 1; i >= 0; --i) {
    cout << answ.nums[i] << ' ';
  }
  cout << endl;
  return 0;
}
