#include <iostream>
#include <vector>

using namespace std;

void FlatNumber() {
  int flat1, entrance1, floor1, all_floors, flat2, entrance2, floor2;
  cin >> flat1 >> all_floors >> flat2 >> entrance2 >> floor2;
  if (flat2 < all_floors * (entrance2 - 1) + floor2 ||
      flat2 <= 0 || all_floors <= 0 || flat2 <= 0 || entrance2 <= 0 || floor2 <= 0 ||
      floor2 > all_floors) {
    cout << -1 << ' ' << -1 << '\n';
    return;
  }
  if (flat1 == flat2) {
    cout << entrance2 << ' ' << floor2 << '\n';
    return;
  }
  int cnt_floors_to_2 = floor2 + all_floors * (entrance2 - 1);

  if (cnt_floors_to_2 == 1 && flat2 < flat1) {
    if (all_floors == 1) {
      cout << 0 << ' ' << 1 << '\n';
      return;
    }
    if (all_floors >= flat1 || flat1 <= all_floors * flat2) {
      cout << 1 << ' ' << 0 << '\n';
      return;
    }
    cout << 0 << ' ' << 0 << '\n';
    return;
  }
  int max_flats_in_floor = flat2 % cnt_floors_to_2 == 0 ? flat2 / cnt_floors_to_2 : flat2 / cnt_floors_to_2 + 1;
  int min_flats_in_floor;
  if (cnt_floors_to_2 != 1) min_flats_in_floor = flat2 % (cnt_floors_to_2 - 1) == 0 ? flat2 / (cnt_floors_to_2 - 1) - 1 : flat2 / (cnt_floors_to_2 - 1);
  else min_flats_in_floor = max_flats_in_floor;
  int max_cnt_floors_to_1 = flat1 % max_flats_in_floor == 0 ? flat1 / max_flats_in_floor : flat1 / max_flats_in_floor + 1;
  int min_cnt_floors_to_1 = flat1 % min_flats_in_floor == 0 ? flat1 / min_flats_in_floor : flat1 / min_flats_in_floor + 1;
  if (min_cnt_floors_to_1 != max_cnt_floors_to_1) {
    int max_entrance1 = max_cnt_floors_to_1 % all_floors == 0 ? max_cnt_floors_to_1 / all_floors : max_cnt_floors_to_1 / all_floors + 1;
    int min_entrance1 = min_cnt_floors_to_1 % all_floors == 0 ? min_cnt_floors_to_1 / all_floors : min_cnt_floors_to_1 / all_floors + 1;
    if (max_entrance1 != min_entrance1) {
      int mid_flats_in_floor = (max_flats_in_floor - min_flats_in_floor) / 2 + min_flats_in_floor;
      int mid_cnt_floors_to_1 = flat1 % mid_flats_in_floor == 0 ? flat1 / mid_flats_in_floor : flat1 / mid_flats_in_floor + 1;
      int mid_entrance1 = mid_cnt_floors_to_1 % all_floors == 0 ? mid_cnt_floors_to_1 / all_floors : mid_cnt_floors_to_1 / all_floors + 1;
      if (max_cnt_floors_to_1 - (max_entrance1 - 1) * all_floors  == min_cnt_floors_to_1 - (min_entrance1 - 1) * all_floors &&
          max_cnt_floors_to_1 - (max_entrance1 - 1) * all_floors  == mid_cnt_floors_to_1 - (mid_entrance1 - 1) * all_floors) {
        cout << 0 << ' ' << max_cnt_floors_to_1 - (max_entrance1 - 1) * all_floors << '\n';
        return;
      }
      cout << 0 << ' ' << 0 << '\n';
      return;
    } else {
      cout << max_entrance1 << ' ' << 0 << '\n';
      return;
    }
  }
  entrance1 = max_cnt_floors_to_1 % all_floors == 0 ? max_cnt_floors_to_1 / all_floors : max_cnt_floors_to_1 / all_floors + 1;
  floor1 = max_cnt_floors_to_1 <= all_floors ? max_cnt_floors_to_1 : max_cnt_floors_to_1 - all_floors * (entrance1 - 1);
  cout << entrance1 << ' ' << floor1 << '\n';
}

vector<int> AppsPerFloor(int all_floors, int flat2, int entrance2, int floor2) {
  int min_bound = flat2 / (all_floors * (entrance2 - 1) + floor2);
  int max_bound = (flat2 - 1) / (all_floors * (entrance2 - 1) + floor2 - 1);
  vector<int> possible_flats_in_floor;
  for (int i = min_bound; i <= max_bound; ++i) {
    if (i != 0 && (all_floors * (entrance2 - 1) + floor2 - 1) * i + (flat2 - 1) % i == flat2 - 1) {
      possible_flats_in_floor.push_back(i);
    }
  }
  return possible_flats_in_floor;
}

pair<int ,int> FlatNumber_v2(int flat1, int all_floors, int flat2, int entrance2, int floor2) {
  vector<int> possible_flats_in_floor;
  if (floor2 > all_floors) return {-1, -1};

  if (entrance2 == 1 && floor2 == 1) {
    if (flat1 <= flat2) {
      return {1, 1};
    }
    else {
      for (int i = flat2; i <= flat1; ++i) {
        possible_flats_in_floor.push_back(i);
      }
    }
  }
  else {
    possible_flats_in_floor = AppsPerFloor(all_floors, flat2, entrance2, floor2);
  }
  pair<int, int> res = {-1, -1};
  for (auto c : possible_flats_in_floor) {
    int floor_index = ((flat1 - 1 - (flat1 - 1) % c) / c) + 1;

    int floor1 = floor_index % all_floors;
    int entrance1 = ((floor_index - floor1) / all_floors) + 1;

    if (floor1 == 0) {
      floor1 = all_floors;
      entrance1--;
    }
    if (res.first == -1 && res.second == -1) res = {entrance1, floor1};
    else {
      if (entrance1 != res.first) res.first = 0;
      if (floor1 != res.second) res.second = 0;
    }
  }
  return res;
}

int main() {
  int flat1, all_floors, flat2, entrance2, floor2;
  cin >> flat1 >> all_floors >> flat2 >> entrance2 >> floor2;
  auto res = FlatNumber_v2(flat1, all_floors, flat2, entrance2, floor2);
  cout << res.first << ' ' << res.second << endl;
  return 0;
}
