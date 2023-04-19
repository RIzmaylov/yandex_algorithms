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
  string answer = type_of_seq[0];
  while(true) {
    cin >> x;
    if (x == -2000000000) break;
    if(first_flag) {
      if (x > first) answer = type_of_seq[1];
      if (x < first) answer = type_of_seq[3];
      first_flag = false;
    }
    if (x == first) {
      if (answer == type_of_seq[1]) answer = type_of_seq[2];
      if (answer == type_of_seq[3]) answer = type_of_seq[4];
    }
    if (x > first) {
      if (answer == type_of_seq[0]) answer = type_of_seq[2];
      if (answer == type_of_seq[3] || answer == type_of_seq[4]) answer = type_of_seq[5];
    }
    if (x < first) {
      if (answer == type_of_seq[0]) answer = type_of_seq[4];
      if (answer == type_of_seq[1] || answer == type_of_seq[2]) answer = type_of_seq[5];
    }
    first = x;
  }
  return answer;
}

int main()
{
  cout << GetSeqAndWhatTypeOf() << endl;
  return 0;
}
