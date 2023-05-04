#include <iostream>
#include <set>

using namespace std;

size_t UFO_Genom()
{
  string frst_gen, scnd_gen;
  cin >> frst_gen >> scnd_gen;
  multiset<string> collection_1;
  size_t res = 0;
  for (size_t c = 0; c < scnd_gen.size() - 1; ++c)
  {
    string temp = "";
    temp += scnd_gen[c];
    temp += scnd_gen[c + 1];
    collection_1.insert(temp);
  }
  for (size_t c = 0; c < frst_gen.size() - 1; ++c)
  {
    string temp = "";
    temp += frst_gen[c];
    temp += frst_gen[c + 1];
//    res += collection_1.count(temp);
  if (collection_1.find(temp) != collection_1.end()) res++;
  }
  return res;
}

int main_F()
{
  cout << UFO_Genom() << endl;
  return 0;
}

/*
Геном жителей системы Тау Кита содержит 26 видов оснований, для обозначения которых будем использовать буквы латинского алфавита от A до Z,
а сам геном записывается строкой из латинских букв. Важную роль в геноме играют пары соседних оснований,
например, в геноме «ABBACAB» можно выделить следующие пары оснований: AB, BB, BA, AC, CA, AB.

Степенью близости одного генома другому геному называется количество пар соседних оснований первого генома, которые встречаются во втором геноме.

Вам даны два генома, определите степень близости первого генома второму геному. Программа получает на вход две строки,
состоящие из заглавных латинских букв. Каждая строка непустая, и её длина не превосходит 105.

Программа должна вывести одно целое число – степень близости генома, записанного в первой строке, геному, записанному во второй строке.
*/
