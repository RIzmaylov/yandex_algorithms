#include <iostream>
#include <iomanip>

using namespace std;

int main() {
  cout << setprecision(6);
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
    double b = f;
    double k = - c;
    cout << 1 << ' ' << k << ' ' << b << '\n';
    return 0;
  }
  if (c == 0 && d == 0) {
    double b = e;
    double k = - a;
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
    double x = e / a;
    double y = (f - c * x) / d;
    cout << 2 << ' ' << x << ' ' << y << '\n';
    return 0;
  }
  if (a == 0 && b != 0 && c != 0) {
    double y = e / b;
    double x = (f - d * y) / c;
    cout << 2 << ' ' << x << ' ' << y << '\n';
    return 0;
  }
  if (c == 0 && d != 0 && a != 0) {
    double y = f / d;
    double x = (e - b * y) / a;
    cout << 2 << ' ' << x << ' ' << y << '\n';
    return 0;
  }
  if (d == 0 && c != 0 && b != 0) {
    double x = f / c;
    double y = (e - a * x) / b;
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
    double m1 = e / b;
    double m2 = f / d;
    double k1 = -a / b;
    double k2 = -c / d;
    if (k1 != k2) {
      //k1 * x + m1 = k2 * x + m2;
      //k1 * x - k2 * x = m2 - m1;
      //(k1 - k2) * x = m2 - m1;
      //x = (m2 - m1) / (k1 - k2)
      double x = (m2 - m1) / (k1 - k2);
      double y = k1 * x + m1;
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
