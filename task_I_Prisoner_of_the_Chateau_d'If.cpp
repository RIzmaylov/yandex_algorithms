#include <iostream>
#include <set>

using namespace std;

int main_9() {
  int A, B, C, D, E;
  cin >> A >> B >> C >> D >> E;

  set<int> hole = {D, E};
  set<int> brick = {A, B, C};
  if (*hole.begin() >= *brick.begin() && *next(hole.begin()) >= *next(brick.begin())) {
    cout << "YES" << '\n';
  } else cout << "NO" << '\n';
  return 0;
}

/*
За многие годы заточения узник замка Иф проделал в стене прямоугольное отверстие размером D × E.
Замок Иф сложен из кирпичей, размером A × B × C. Определите, сможет ли узник выбрасывать кирпичи в море через это отверстие,
 если стороны кирпича должны быть параллельны сторонам отверстия.

Формат ввода
Программа получает на вход числа A, B, C, D, E.

Формат вывода
Программа должна вывести слово YES или NO.
*/
