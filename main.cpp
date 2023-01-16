#include <iostream>
#include <stack>
#include <vector>

std::stack<int> stos;
int n, ile;

void tablica_now(std::vector <int>  tablica){
  int now, j;
  for (int i = 1; i < tablica.size(); i++) {
    now = tablica[i];
    j = i - 1;
    while ((tablica[j] > now && j >= 0)) {
      tablica[j + 1] = tablica[j];
      j = j - 1;
    }
    tablica[j + 1] = now;
    std::cout << "HEL";
  }
   for (int i = 0; i < tablica.size(); i++) {
    std::cout << tablica[i] << "   ";
  }
}

int main() {
  std::string atom;
  std::cout << "Podaj ile masz cyfr:";
  std::cin >> ile;
  while (ile > n) {
    n++;
    std::cin >> atom;
    if (atom == "+") {
      int right = stos.top();
      stos.pop();
      int left = stos.top();
      stos.pop();
      stos.push(right + left);
      continue;
    }
    if(atom == "-") {
      int right = stos.top();
      stos.pop();
      int left = stos.top();
      stos.pop();
      stos.push(right - left);
      continue;
    }
    if(atom == "*") {
      int right = stos.top();
      stos.pop();
      int left = stos.top();
      stos.pop();
      stos.push(right * left);
      continue;
    }
    if(atom == "/") {
      int right = stos.top();
      stos.pop();
      int left = stos.top();
      stos.pop();
      stos.push(right / left);
      continue;
    }
    if (atom == "print") {
      std::cout << stos.top();
      stos.pop();
      continue;
    }
    if(atom == "sort") {
      int schowek;
      std::vector <int> tablica = {};
      int stała;
      stała = stos.size();
      for(int i =0; i < stała;i++){
        schowek = stos.top();
        stos.pop();
        tablica[i] = schowek;
      }
      tablica_now(tablica);
   continue;
    }
    int liczba = stoi(atom);
    stos.push(liczba);
  }
}
