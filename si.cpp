#include<iostream>
#include<string>
#include<vector>

int main() {
  std::vector<std::vector<int>> T;
  int i;
  int j;
  T = std::vector<std::vector<int>>(10);
  for(int i = 1; i < (T).length(); i += 1) {
    T[i] = std::vector<int>(10);
    for(int i = 1; i < (T[i]).length(); i += 1) {
      T[i][j] = (i) + (j);
    }
  }
  return 0;
}
