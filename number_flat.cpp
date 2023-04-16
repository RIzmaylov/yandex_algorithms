#include <iostream>

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
      cout << 0 << ' ' << 0 << '\n';
      return;
    } else {
      cout << max_entrance1 << ' ' << 0 << '\n';
      return;
    }
  }
  entrance1 = max_cnt_floors_to_1 % all_floors == 0 ? max_cnt_floors_to_1 / all_floors : max_cnt_floors_to_1 / all_floors + 1;
  floor1 = max_cnt_floors_to_1 <= all_floors ? max_cnt_floors_to_1 : max_cnt_floors_to_1 - all_floors * (entrance1 - 1);
//  if (!floor1) floor1++;
  cout << entrance1 << ' ' << floor1 << '\n';
}

int main()
{
  FlatNumber();
  return 0;
}
