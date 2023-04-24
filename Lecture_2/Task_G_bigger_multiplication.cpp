#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

void ReadAndWriteSeq(vector<int>& nums) {
  string temp_s;
  getline(cin, temp_s);
  stringstream ss(temp_s);
  while(ss) {
    int temp;
    ss >> temp;
    nums.push_back(temp);
  }
}

pair<int, int> BiggerMult() {
  vector<int> nums;
  ReadAndWriteSeq(nums);
  int first = nums[0], second = nums[1];
  int mult = nums[0] * nums[1];
  for (size_t i = 0; i < nums.size() - 2; ++i) {
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
  pair<int, int> res = BiggerMult();
  cout << res.first << ' ' << res.second << endl;
  return 0;
}
