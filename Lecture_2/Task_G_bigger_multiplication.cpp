#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

void ReadAndWriteSeq(vector<int>& nums) {
  string temp_s;
  getline(cin, temp_s);
  stringstream ss(temp_s);
  int temp;
  while(ss >> temp) {
    nums.push_back(temp);
  }
}

pair<int, int> BiggerMult2() {
  vector<int> nums;
  ReadAndWriteSeq(nums);

  if (nums.size() == 2) {
    return nums[0] < nums[1] ? make_pair(nums[0], nums[1]) : make_pair(nums[1], nums[0]);
  }
  int first_pos_max = 0, second_pos_max = 0, first_neg_max = 0, second_neg_max = 0;

  for (size_t i = 0; i < nums.size(); ++i) {
    if (nums[i] > 0) {
      if (nums[i] > first_pos_max) {
        second_pos_max = first_pos_max;
        first_pos_max = nums[i];
      }
      else if (nums[i] > second_pos_max) {
        second_pos_max = nums[i];
      }
    } else {
      if (nums[i] < first_neg_max) {
        second_neg_max = first_neg_max;
        first_neg_max = nums[i];
      }
      else if (nums[i] < second_neg_max) {
        second_neg_max = nums[i];
      }
    }
  }
  int pos_prod = first_pos_max * second_pos_max;
  int neg_prod = first_neg_max * second_neg_max;
  if (pos_prod > neg_prod) {
    return first_pos_max < second_pos_max ? make_pair(first_pos_max, second_pos_max) : make_pair(second_pos_max, first_pos_max);
  } else {

    return first_neg_max < second_neg_max ? make_pair(first_neg_max, second_neg_max) : make_pair(second_neg_max, first_neg_max);
  }
}

pair<int, int> BiggerMult() {
  vector<int> nums;
  ReadAndWriteSeq(nums);

  int first = nums[0], second = nums[1];
  int mult = nums[0] * nums[1];

  for (size_t i = 0; i < nums.size() - 1; ++i) {
    for (size_t j = i + 1; j < nums.size(); ++j) {
      if ((nums[i] * nums[j]) > mult) {
        first = nums[i];
        second = nums[j];
        mult = nums[i] * nums[j];
      }
    }
  }
  return (first < second ? make_pair(first, second) : make_pair(second, first));
}

int main() {
  pair<int, int> res = BiggerMult2();
  cout << res.first << ' ' << res.second << endl;
  return 0;
}
