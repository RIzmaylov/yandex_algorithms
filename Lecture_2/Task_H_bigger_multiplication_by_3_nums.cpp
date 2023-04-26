#include <iostream>
#include <vector>

using namespace std;

void BiggerMult2(int64_t& num1, int64_t& num2, int64_t& num3) {
  vector<int64_t> nums;
  int64_t temp;
  while(cin >> temp) {
    nums.push_back(temp);
  }
  int64_t first_pos_max, second_pos_max, third_pos_max, first_neg_max, second_neg_max;
  first_pos_max = max(nums[0], max(nums[1], nums[2]));
  if (first_pos_max == nums[0]) {
    second_pos_max = max(nums[1], nums[2]);
    third_pos_max = min(nums[1], nums[2]);
  } else if (first_pos_max == nums[1]) {
    second_pos_max = max(nums[0], nums[2]);
    third_pos_max = min(nums[0], nums[2]);
  } else {
    second_pos_max = max(nums[0], nums[1]);
    third_pos_max = min(nums[0], nums[1]);
  }
  if (nums.size() == 3) {
    num1 = third_pos_max;
    num2 = second_pos_max;
    num3 = first_pos_max;
    return;
  }

  first_neg_max = third_pos_max;
  second_neg_max = second_pos_max;

  for (size_t i = 3; i < nums.size(); ++i) {
    if (nums[i] > first_pos_max) {
      third_pos_max = second_pos_max;
      second_pos_max = first_pos_max;
      first_pos_max = nums[i];
    }
    else if (nums[i] > second_pos_max) {
      third_pos_max = second_pos_max;
      second_pos_max = nums[i];
    }
    else if (nums[i] > third_pos_max) {
      third_pos_max = nums[i];
    }
    if (nums[i] < first_neg_max) {
      second_neg_max = first_neg_max;
      first_neg_max = nums[i];
    }
    else if (nums[i] < second_neg_max) {
      second_neg_max = nums[i];
    }
  }
  int64_t prod1 = first_pos_max * second_pos_max * third_pos_max;
  int64_t prod2 = first_pos_max * first_neg_max * second_neg_max;
  if (prod1 > prod2) {
    num1 = first_pos_max;
    num2 = second_pos_max;
    num3 = third_pos_max;
  } else {
    num1 = first_pos_max;
    num2 = first_neg_max;
    num3 = second_neg_max;
  }
}

int main() {
  int64_t num1, num2, num3;
  BiggerMult2(num1, num2, num3);
  cout << num1 << ' ' << num2  << ' ' << num3 << endl;
  return 0;
}
