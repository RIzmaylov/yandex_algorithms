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
  int flats_in_floor = flat2 % cnt_floors_to_2 == 0 ? flat2 / cnt_floors_to_2 : flat2 / cnt_floors_to_2 + 1;
  int cnt_floors_to_1 = flat1 / flats_in_floor + 1;
  entrance1 = cnt_floors_to_1 / all_floors + 1;
  floor1 = cnt_floors_to_1 % all_floors;
  cout << entrance1 << ' ' << floor1 << '\n';
}

int main()
{
  FlatNumber();
  return 0;
}
