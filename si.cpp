#include<iostream>
#include<string>
#include<vector>

void afficher_somme(std::vector<int> tab) {
  int resultat  resultat = somme(tab);
  std::cout << std::string("Résultat : ");
  std::cout << resultat;
}

int main() {
    std::vector<int> T;
    int i;
  T = std::vector<int>(10);
  for(int i = 1; i < (T).length(); i += 1) {
    T[i] = 2;
  }
afficher_somme(T);  return 0;
}
