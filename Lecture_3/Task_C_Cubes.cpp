#include <iostream>
#include <set>

using namespace std;

void Cubes()
{
  set<int> nums1, nums2;
  int cnt1, cnt2;
  cin >> cnt1 >> cnt2;
  while(cnt1--)
  {
    int temp;
    cin >> temp;
    nums1.insert(temp);
  }
  while(cnt2--)
  {
    int temp;
    cin >> temp;
    nums2.insert(temp);
  }
  set<int> f1 = nums1, f2 = nums2;
  nums1.merge(nums2);
  cout << nums2.size() << endl;
  for (auto c : nums2)
  {
    cout << c << ' ';
  }
  cout << endl;
  cout << f1.size() - nums2.size() << endl;
  for (auto c : f1)
  {
    if (nums2.find(c) == nums2.end())
    {
      cout << c << ' ';
    }
  }
  cout << endl;
  cout << f2.size() - nums2.size() << endl;
  for (auto c : f2)
  {
    if (nums2.find(c) == nums2.end())
    {
      cout << c << ' ';
    }
  }
  cout << endl;
}

int main()
{
  Cubes();
  return 0;
}
