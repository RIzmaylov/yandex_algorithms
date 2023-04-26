#include <iostream>
#include <vector>

using namespace std;

void FillAroundMine(vector<vector<int>>& field, int max_rows_index, int max_cols_index, int mine_row, int mine_col) {
  field[mine_row][mine_col] = -100;
  if (mine_row == 0) {
    if (mine_col == 0) {
      if (max_rows_index > mine_row && max_cols_index > mine_col) {
        field[mine_row + 1][mine_col + 1]++;
      }
      if (max_rows_index > mine_row) {
        field[mine_row + 1][mine_col]++;
      }
      if (max_cols_index > mine_col){
        field[mine_row][mine_col + 1]++;
      }
    }
    else {
      field[mine_row][mine_col - 1]++;
      if (max_rows_index > mine_row && max_cols_index > mine_col) {
        field[mine_row + 1][mine_col + 1]++;
      }
      if (max_rows_index > mine_row) {
        field[mine_row + 1][mine_col]++;
        field[mine_row + 1][mine_col - 1]++;
      }
      if (max_cols_index > mine_col){
        field[mine_row][mine_col + 1]++;
      }
    }
  }
  else {
    field[mine_row - 1][mine_col]++;
    if (mine_col == 0) {
      if (max_rows_index > mine_row && max_cols_index > mine_col) {
        field[mine_row + 1][mine_col + 1]++;
      }
      if (max_rows_index > mine_row) {
        field[mine_row + 1][mine_col]++;
      }
      if (max_cols_index > mine_col){
        field[mine_row][mine_col + 1]++;
        field[mine_row - 1][mine_col + 1]++;
      }
    }
    else {
      field[mine_row][mine_col - 1]++;
      field[mine_row - 1][mine_col - 1]++;
      field[mine_row][mine_col]++;
      if (max_rows_index > mine_row && max_cols_index > mine_col) {
        field[mine_row + 1][mine_col + 1]++;
      }
      if (max_rows_index > mine_row) {
        field[mine_row + 1][mine_col]++;
        field[mine_row + 1][mine_col - 1]++;
      }
      if (max_cols_index > mine_col){
        field[mine_row][mine_col + 1]++;
        field[mine_row - 1][mine_col + 1]++;
      }
    }

  }
}

void PrintSapper(const vector<vector<int>>& field) {
  for (auto r : field) {
    for (auto c : r) {
      if (c < 0) {
        cout << '*' << ' ';
      }
      else cout << c << ' ';
    }
    cout << endl;
  }
}

void Sapper() {
  int N_rows, M_columns, K_mines;
  cin >> N_rows >> M_columns >> K_mines;
  vector<vector<int>> field (N_rows, vector<int>(M_columns, 0));
  while(K_mines--) {
    int temp_row, temp_column;
    cin >> temp_row >> temp_column;
    FillAroundMine(field, N_rows - 1, M_columns - 1, temp_row - 1, temp_column - 1);
  }
  PrintSapper(field);
}


int main_I() {
  Sapper();
  return 0;
}

/*
Вам необходимо построить поле для игры "Сапер" по его конфигурации – размерам и координатам расставленных на нем мин.

Вкратце напомним правила построения поля для игры "Сапер":

- Поле состоит из клеток с минами и пустых клеток
- Клетки с миной обозначаются символом *
- Пустые клетки содержат число ki,j, 0≤ ki, j ≤ 8 – количество мин на соседних клетках.
Соседними клетками являются восемь клеток, имеющих смежный угол или сторону.

Формат ввода
В первой строке содержатся три числа: N, 1 ≤ N ≤ 100 - количество строк на поле,
M, 1 ≤ M ≤ 100 - количество столбцов на поле, K, 0 ≤ K ≤ N ⋅ M - количество мин на поле.

В следующих K строках содержатся по два числа с координатами мин:
p, 1 ≤ p ≤ N - номер строки мины, q, 1 ≤ 1 ≤ M - номер столбца мины.

Формат вывода
Выведите построенное поле, разделяя строки поля переводом строки, а столбцы - пробелом.

*/

