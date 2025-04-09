#include<iostream>
#include<string>

int main() {
  int i;
  int cpt;
  std::string mot;
  bool vuS;
  char c;
  std::getline(std::cin, mot);
  cpt = 0;
  i = 0;
  while((i) < ((mot).length())) {
    c = (mot)[((i) + (1))-1];
    if ((c) == ('s')) {
        vuS = true;

    } else if ((c) == ('p')) {
        vuS = false;

    } else if ((c) == ('e')) {
        vuS = true;

    } else {
        if ((vuS) && ((c) == ('i'))) {
            cpt = (cpt) + (1);
            vuS = false;

        } else {
            vuS = false;

        }
    }    i = (i) + (1);
  }
  std::cout << std::string("test1 ") << std::string(" test2");
  for(int i = 1; i < 3; i += 1) {
    std::cout << std::string("ça marche");
  }
  std::cout << std::string("Il y a ");
  std::cout << cpt;
  std::cout << std::string(" \"si\" dans la chaîne \"");
  std::cout << mot;
  std::cout << std::string("\".\n");
  return 0;
}
