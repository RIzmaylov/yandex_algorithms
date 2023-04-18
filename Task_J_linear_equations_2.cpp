#include <iostream>

using namespace std;

int main() {
  //ax + by = e,
  //cx + dy = f
  double a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;
  if (a == 0 && b == 0 && c == 0 && d == 0) {
    if (e == 0 && f == 0) {
      cout << 5 << '\n';
      return 0;
    }
    cout << 0 << '\n';
    return 0;
  }
  if (a == 0 && b == 0) {
    int b = f;
    int k = - c;
    cout << 1 << ' ' << k << ' ' << b << '\n';
    return 0;
  }
  if (c == 0 && d == 0) {
    int b = e;
    int k = - a;
    cout << 1 << ' ' << k << ' ' << b << '\n';
    return 0;
  }
  if (b == 0 && d == 0 && a != 0 && c != 0) {
    if (e / a == f / c) {
      cout << 3 << ' ' << e / a << '\n';
    } else {
      cout << 0 << '\n';
    }
    return 0;
  }
  if (a == 0 && c == 0 && b != 0 && d != 0) {
    if (e / b == f / d) {
      cout << 4 << ' ' << e / b << '\n';
    } else {
      cout << 0 << '\n';
    }
    return 0;
  }
  if (b == 0 && d != 0 && a != 0) {
    int x = e / a;
    int y = (f - c * x) / d;
    cout << 2 << ' ' << x << ' ' << y << '\n';
    return 0;
  }
  if (a == 0 && b != 0 && c != 0) {
    int y = e / b;
    int x = (f - d * y) / c;
    cout << 2 << ' ' << x << ' ' << y << '\n';
    return 0;
  }
  if (c == 0 && d != 0 && a != 0) {
    int y = f / d;
    int x = (e - b * y) / a;
    cout << 2 << ' ' << x << ' ' << y << '\n';
    return 0;
  }
  if (d == 0 && c != 0 && b != 0) {
    int x = f / c;
    int y = (e - a * x) / b;
    cout << 2 << ' ' << x << ' ' << y << '\n';
    return 0;
  }
  if (b == 0 && a == 0 || d == 0 && c == 0) {
    cout << 0 << '\n';
    return 0;
  }

  if (b != 0 && d != 0) {
    //y1 = k1 * x1 + m1
    //y2 = k2 * x2 + m2
    int m1 = e / b;
    int m2 = f / d;
    int k1 = -a / b;
    int k2 = -c / d;
    if (k1 != k2) {
      //k1 * x + m1 = k2 * x + m2;
      //k1 * x - k2 * x = m2 - m1;
      //(k1 - k2) * x = m2 - m1;
      //x = (m2 - m1) / (k1 - k2)
      int x = (m2 - m1) / (k1 - k2);
      int y = k1 * x + m1;
      cout << 2 << ' ' << x << ' ' << y << '\n';
      return 0;
    }
    if (k1 == k2 && m1 != m2) {
      cout << 0 << '\n';
      return 0;
    }
    if (k1 == k2 && m1 == m2) {
      cout << 1 << k1 << ' ' << m1 << '\n';
      return 0;
    }
  }
  return 0;
}
