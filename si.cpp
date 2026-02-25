#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

int somme(std::vector<int> tab) {
  int i;
  int total;
  total = 0;
  for(int i = 0; i < ((tab).size()) - (1); i += 1) {
    total = ([&]() -> auto { if ((i) < 0 || (i) >= (total) + (tab).size()) throw std::out_of_range("Index non valide pour (total) + (tab)[i]"); return (total) + (tab)[i]; })();
  }
  return total;
}

void afficher_somme(std::vector<int> tab) {
  int resultat;
  resultat = somme(tab);
  std::cout << std::string("Résultat : ");
  std::cout << resultat;
}

int main() {
  std::vector<int> T;
  int i;
  T = std::vector<int>(10);
  for(int i = 1; i < (T).size(); i += 1) {
    T[i] = 2;
  }
afficher_somme(T);  return 0;
}
