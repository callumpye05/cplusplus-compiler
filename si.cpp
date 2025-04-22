#include<iostream>
#include<string>
#include<vector>

int main() {
  std::vector<int> T;
  int i;
  int x;
  T = std::vector<int>(10);
  for(int i = 1; i < (T).length(); i += 1) {
    T[i] = 2;
  }
  for (auto x : T) {
    std::cout << std::string("la valeur est :");
    std::cout << x;
  }
  return 0;
}
