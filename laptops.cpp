#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main_6() {
  int lt1_a, lt1_b, lt2_a, lt2_b;
  cin >> lt1_a >> lt1_b >> lt2_a >> lt2_b;
  vector<pair<int, int>> combinations;
  combinations.push_back({max(lt1_a, lt2_a), lt1_b + lt2_b});
  combinations.push_back({max(lt1_a, lt2_b), lt1_b + lt2_a});
  combinations.push_back({max(lt1_b, lt2_a), lt1_a + lt2_b});
  combinations.push_back({max(lt1_b, lt2_b), lt1_a + lt2_a});
  sort(combinations.begin(), combinations.end(), [](pair<int, int>& comb1, pair<int, int>& comb2) { return comb1.first * comb1.second < comb2.first * comb2.second; });
  cout << combinations[0].first << ' ' << combinations[0].second << '\n';
  return 0;
}
