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


int main() {
  Sapper();
  return 0;
}

