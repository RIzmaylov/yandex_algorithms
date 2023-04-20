#include <iostream>
#include <sstream>

using namespace std;

void UpList() {
  string s;
  getline(cin, s);
  stringstream ss(s);
  int first;
  int x;
  ss >> first;
  bool flag = true;
  while (ss >> x) {
    if (x > first) {
      first = x;
    } else {
      flag = false;
      break;
    }
  }
  if (flag) cout << "YES" << endl;
  else cout << "NO" << endl;
}

int main_A()
{
  UpList();
  return 0;
}

/*
Дан список. Определите, является ли он монотонно возрастающим(то есть верно ли, что каждый элемент этого списка больше предыдущего).

Выведите YES, если массив монотонно возрастает и NO в противном случае.
*/
