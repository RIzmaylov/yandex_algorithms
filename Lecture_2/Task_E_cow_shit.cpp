#include <iostream>
#include <vector>

using namespace std;

size_t Competition() {
  int n;
  cin >> n;
  vector<int> results;
  for (int i = 0; i < n; ++i) {
    int temp;
    cin >> temp;
    results.push_back(temp);
  }
  size_t Vasiliy_place = 1;
  size_t Vasiliy_index = 0;
  int winner_id = 0;
  for (size_t i = 1; i < results.size(); ++i) {
    if (results[i] > results[winner_id]) winner_id = i;
  }
  for (size_t i = 1; i < results.size() - 1; ++i) {
    if (results[i] % 10 == 5 && results[i] > results[i + 1] && winner_id < i) {
      if (Vasiliy_index == 0 || (Vasiliy_index != 0 && results[Vasiliy_index] < results[i]))
        Vasiliy_index = i;
    }
  }
  if (Vasiliy_index == 0) return Vasiliy_index;
  for (size_t i = 0; i < results.size(); ++i) {
    if (results[i] > results[Vasiliy_index]) Vasiliy_place++;
  }
  return Vasiliy_place;
}

int main() {
  while (true)
  cout << Competition() << endl;
  return 0;
}

/*
Ежегодный турнир «Веселый коровяк» — по метанию коровьих лепешек на дальность — прошел 8–9 июля в селе Крылово Осинского района Пермского края.
Участники соревнований кидают «снаряд» — спрессованный навоз, выбирая его из заранее заготовленной кучи.
Желающих поупражняться в силе броска традиционно очень много — как мужчин, так и женщин.
Каждую лепешку, которую метнули участники «Веселого коровяка», внимательно осматривали женщины в костюмах коров и тщательно замеряли расстояние.
Соревнования по метанию коровьих лепешек проводятся в Пермском крае с 2009 года.

К сожалению, после чемпионата потерялись записи с фамилиями участников, остались только записи о длине броска в том порядке,
в котором их совершали участники.

Трактиорист Василий помнит три факта:

1) Число метров, на которое он метнул лепешку, оканчивалось на 5

2) Один из победителей чемпионата метал лепешку до Василия

3) Участник, метавший лепешку сразу после Василия, метнул ее на меньшее количество метров

Будем считать, что участник соревнования занял k-е место, если ровно (k − 1) участников чемпионата метнули лепешку строго дальше, чем он.

Какое максимально высокое место мог занять Василий?

Формат ввода
Первая строка входного файла содержит целое число n — количество участников чемпионата по метанию лепешек (3 ≤ n ≤ 105).

Вторая строка входного файла содержит n положительных целых чисел,
каждое из которых не превышает 1000, — дальность броска участников чемпионата, приведенные в том порядке, в котором происходило метание.

Формат вывода
Выведите самое высокое место, которое мог занять тракторист Василий.
Если не существует ни одного участника чемпионата, который удовлетворяет, описанным выше условиям, выведите число 0.
*/
