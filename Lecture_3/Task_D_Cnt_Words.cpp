#include <iostream>
#include <set>
#include <string>

using namespace std;

void Cnt_Words()
{
  set<string> words;
  string temp;
  while(cin >> temp)
  {
    words.insert(temp);
  }
  cout << words.size() << endl;
}

int main_D()
{
  Cnt_Words();
  return 0;
}

/*
Во входном файле (вы можете читать данные из sys.stdin, подключив библиотеку sys) записан текст.
Словом считается последовательность непробельных символов идущих подряд, слова разделены одним или большим числом пробелов или символами конца строки.
Определите, сколько различных слов содержится в этом тексте.

Формат ввода
Вводится текст.

Формат вывода
Выведите ответ на задачу.
*/
