#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

using namespace std;
int y;
int x;
int size;
class fifo {
  public:
    int * k;
  int remove(int x);
  void add(int);
  fifo();
  void list();
  void deleted();
  void page_fault(int random);
};
fifo::fifo() {
  x = y = size = 0;
}

void fifo::add(int random) {
  k[y] = random;
  y++;
}

int fifo::remove(int y) {
  if (x != 0) {
    k[y] = k[y + 1];
    y++;
  } else if (x == 0) {
    k[y] = k[y + 1];
  }
}

void fifo::list() {
  for (int i = 0; i < 5; i++)
    cout << * (k + i) << " ";
  cout << endl;
}

void fifo::deleted() {
  for (int i = 0; i < 5; i++)
    k[i] = 0;
}

void fifo::page_fault(int random) {
  int flag = 0;
  if (size >= 5) {
    for (int i = 0; i < 5; i++) {
      if (k[i] != random) {
        flag++;
      } else if (k[i] == random) {
        goto jump;
      }
    }
  }
  jump:
    if (flag == 5) {
      cout << " F ";
    }
  else {
    cout << " ";
  }
}
int main(int argc, char ** argv) {
  srand(time(0));
  int random;
  int dongu = 0;
  fifo * obj = new fifo();
  obj -> k = new int[5];
  obj -> deleted();
  cout << "First-in First-out" << endl << endl;
  do {
    if (size >= 5) {
      if (x == 0) {
        y = 0;
        obj -> remove(y);
        x++;
      } else if (x != 0) {
        if (y == 5)
          y = 0;
        obj -> remove(y);
      }
    }
    random = rand() % 8 + 1;
    obj -> page_fault(random);
    cout << "Eklenen sayi=" << random << "->  ";
    obj -> add(random);
    size++;
    dongu++;
    obj -> list();
    cout << y << ". indise eklendi " << endl << endl;

  } while (dongu < 15);
  
  return 0;
}
