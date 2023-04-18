#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int lt1_a, lt1_b, lt2_a, lt2_b;
  cin >> lt1_a >> lt1_b >> lt2_a >> lt2_b;
  int sub_1a_to_2a = lt1_a > lt2_a ? lt1_a - lt2_a : lt2_a - lt1_a;
  int sub_1a_to_2b = lt1_a > lt2_b ? lt1_a - lt2_b : lt2_b - lt1_a;
  int sub_1b_to_2a = lt1_b > lt2_a ? lt1_b - lt2_a : lt2_a - lt1_b;
  int sub_1b_to_2b = lt1_b > lt2_b ? lt1_b - lt2_b : lt2_b - lt1_b;

  int min_sub = min(min(sub_1a_to_2a, sub_1a_to_2b), min(sub_1b_to_2a, sub_1b_to_2b));
  if (min_sub == sub_1a_to_2a) {
    cout << max(lt1_a, lt2_a) << ' ' << lt1_b + lt2_b << '\n';
  } else if (min_sub == sub_1a_to_2b) {
    cout << max(lt1_a, lt2_b) << ' ' << lt1_b + lt2_a << '\n';
  } else if (min_sub == sub_1b_to_2a) {
    cout << max(lt1_b, lt2_a) << ' ' << lt1_a + lt2_b << '\n';
  } else if (min_sub == sub_1b_to_2b) {
    cout << max(lt1_b, lt2_b) << ' ' << lt1_a + lt2_a << '\n';
  }
  return 0;
}
