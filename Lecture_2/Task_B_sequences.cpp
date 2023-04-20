#include <iostream>
#include <vector>

using namespace std;



string GetSeqAndWhatTypeOf() {
  const vector<string> type_of_seq {
    "CONSTANT",         //0
    "ASCENDING",        //1
    "WEAKLY ASCENDING", //2
    "DESCENDING",       //3
    "WEAKLY DESCENDING",//4
    "RANDOM"            //5
  };
  int first;
  cin >> first;
  int x;
  bool first_flag = true;
  int answer = 0;
  while(true) {
    cin >> x;
    if (x == -2000000000) break;
    if(first_flag) {
      if (x > first) answer = 1;
      if (x < first) answer = 3;
      first_flag = false;
    }
    if (x == first) {
      if (answer == 1) answer = 2;
      if (answer == 3) answer = 4;
    }
    if (x > first) {
      if (answer == 0) answer = 2;
      if (answer == 3 || answer == 4) answer = 5;
    }
    if (x < first) {
      if (answer == 0) answer = 4;
      if (answer == 1 || answer == 2) answer = 5;
    }
    first = x;
  }
  return type_of_seq[answer];
}

int main_B()
{
  cout << GetSeqAndWhatTypeOf() << endl;
  return 0;
}

/*
По последовательности чисел во входных данных определите ее вид:

CONSTANT – последовательность состоит из одинаковых значений
ASCENDING – последовательность является строго возрастающей
WEAKLY ASCENDING – последовательность является нестрого возрастающей
DESCENDING – последовательность является строго убывающей
WEAKLY DESCENDING – последовательность является нестрого убывающей
RANDOM – последовательность не принадлежит ни к одному из вышеупомянутых типов
Формат ввода
По одному на строке поступают числа последовательности ai, |ai| ≤ 109.

Признаком окончания последовательности является число -2× 109. Оно в последовательность не входит.

Формат вывода
В единственной строке выведите тип последовательности.
*/
