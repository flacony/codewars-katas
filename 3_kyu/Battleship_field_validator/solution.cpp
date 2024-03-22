#include <map>
#include <vector>

bool validate_battlefield(std::vector<std::vector<int>> field) {
  std::vector<std::vector<int>> field1(11, std::vector<int>(12, 0));
  int shipCells{0};
  for (int i{0}; i < 10; i++) {
    for (int j{0}; j < 10; j++) {
      if (field[i][j] != 0 && field[i][j] != 1) return false;
      shipCells += field[i][j];
      field1[i][j + 1] = field[i][j];
    }
  }
  if (shipCells != 20) return false;

  std::map<int, int> shipsMap;
  for (int i{1}; i < 5; i++) {
    shipsMap[i] = 5 - i;
  }

  for (int row{0}; row < 10; row++) {
    for (int col{1}; col <= 10; col++) {
      if (field1[row][col] == 1) {
        int ship = row;
        do {
          field1[ship][col] = 4;
          if (field1[ship + 1][col - 1] == 1 || field1[ship + 1][col + 1] == 1)
            return false;

          ship++;

        } while (field1[ship][col] == 1);

        if (ship - row == 1) {
          ship = col;
          do {
            field1[row][ship] = 4;
            if (field1[row + 1][ship + 1] == 1) return false;

            ship++;

          } while (field1[row][ship] == 1);
          if (--shipsMap[ship - col] < 0) return false;
        } else {
          if (--shipsMap[ship - row] < 0) return false;
        }
      }
    }
  }
  return true;
}