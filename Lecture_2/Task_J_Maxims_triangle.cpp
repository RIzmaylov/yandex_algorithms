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

int main_J() {
  double first, second;
  Maxims_triangle(first, second);
  cout << fixed << setprecision(7) << first << ' ' << second << endl;
  return 0;
}

/*
С детства Максим был неплохим музыкантом и мастером на все руки. Недавно он самостоятельно сделал несложный перкуссионный
музыкальный инструмент — треугольник. Ему нужно узнать, какова частота звука, издаваемого его инструментом.

У Максима есть профессиональный музыкальный тюнер, с помощью которого можно проигрывать ноту с заданной частотой.
Максим действует следующим образом: он включает на тюнере ноты с разными частотами и для каждой ноты на слух определяет,
ближе или дальше она к издаваемому треугольником звуку, чем предыдущая нота. Поскольку слух у Максима абсолютный,
он определяет это всегда абсолютно верно.

Вам Максим показал запись, в которой приведена последовательность частот, выставляемых им на тюнере, и про каждую ноту,
начиная со второй, записано — ближе или дальше она к звуку треугольника, чем предыдущая нота.
Заранее известно, что частота звучания треугольника Максима составляет не менее 30 герц и не более 4000 герц.

Требуется написать программу, которая определяет, в каком интервале может находиться частота звучания треугольника.

Формат ввода
Первая строка входного файла содержит целое число n — количество нот, которые воспроизводил Максим с помощью тюнера (2 ≤ n ≤ 1000).
 Последующие n строк содержат записи Максима, причём каждая строка содержит две компоненты: вещественное число fi — частоту,
 выставленную на тюнере, в герцах (30 ≤ fi ≤ 4000), и слово «closer» или слово «further» для каждой частоты, кроме первой.

Слово «closer» означает, что частота данной ноты ближе к частоте звучания треугольника, чем частота предыдущей ноты,
что формально описывается соотношением: |fi − ftriangle| < |fi − 1 − ftriangle| .

Слово «further» означает, что частота данной ноты дальше, чем предыдущая.

Если оказалось, что очередная нота так же близка к звуку треугольника, как и предыдущая нота,
то Максим мог записать любое из двух указанных выше слов.

Гарантируется, что результаты, полученные Максимом, непротиворечивы.

Формат вывода
В выходной файл необходимо вывести через пробел два вещественных числа — наименьшее и наибольшее возможное значение частоты звучания треугольника,
изготовленного Максимом. Числа должны быть выведены с точностью не хуже 10−6.
*/
