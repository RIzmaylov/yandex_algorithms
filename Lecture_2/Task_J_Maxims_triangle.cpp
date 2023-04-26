#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

void ChangeResFreqs(double prev_freq, double cur_freq, double& start_res_freq, double& finish_res_freq, string messege) {
  if (messege == "closer") {
    if (cur_freq > prev_freq) {
      double temp_min_freq = prev_freq + (cur_freq - prev_freq) / 2.0;
      if (temp_min_freq > start_res_freq) start_res_freq = temp_min_freq;
    } else {
      double temp_max_freq = prev_freq - (prev_freq - cur_freq) / 2.0;
      if (finish_res_freq > temp_max_freq) finish_res_freq = temp_max_freq;
    }
  } else if (messege == "further") {
    if (cur_freq > prev_freq) {
      double temp_max_freq = prev_freq + (cur_freq - prev_freq) / 2.0;
      if (finish_res_freq > temp_max_freq) finish_res_freq = temp_max_freq;
    } else {
      double temp_min_freq = prev_freq - (prev_freq - cur_freq) / 2.0;
      if (temp_min_freq > start_res_freq) start_res_freq = temp_min_freq;
    }
  }
}

void Maxims_triangle(double& first, double& second) {
  int N;
  cin >> N;
  vector<double> freqs;
  double first_freq;
  cin >> first_freq;
  freqs.push_back(first_freq);
  double start_res_freq = 30.0;
  double finish_res_freq = 4000.0;
  N--;
  while (N--) {
    double temp_freq;
    string temp_mes;
    cin >> temp_freq >> temp_mes;
    ChangeResFreqs(freqs.back(), temp_freq, start_res_freq, finish_res_freq, temp_mes);
    freqs.push_back(temp_freq);
  }
  first = start_res_freq;
  second = finish_res_freq;
}

int main() {
  double first, second;
  Maxims_triangle(first, second);
  cout << fixed << setprecision(7) << first << ' ' << second << endl;
  return 0;
}
