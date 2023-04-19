#include <iostream>
#include <vector>

using namespace std;

void PossibleTriangle() {
  int a, b, c;
  cin >> a >> b >> c;

  if (a >= b + c || b >= a + c || c >= a + b) cout << "NO" << '\n';
  else cout << "YES" << '\n';
}

int main_4()
{
  PossibleTriangle();
  return 0;
}

/*
Даны три натуральных числа. Возможно ли построить треугольник с такими сторонами. Если это возможно, выведите строку YES, иначе выведите строку NO.

Треугольник — это три точки, не лежащие на одной прямой.

Формат ввода
Вводятся три натуральных числа.

Формат вывода
Выведите ответ на задачу.
*/
