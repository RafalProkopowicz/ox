//--------------------------------------------------------------------------------------------------//
//
//
//
//
// -1 -> pole  zajete przez O
//  0 -> pole puste
//  1 -> pole zajete przez X
//--------------------------------------------------------------------------------------------------//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int xy = 1; //rozmiar planszy
int field[3][3]; //plansza
int yvalue = 0, xvalue = 0; //wartosci kolumny i rzedu
int gracz = -1; //ktory gracz
int x = -1, y = -1; //pozycja do zmiany


int fieldCreate(){
  printf("---------------------------------------------\n");
  printf("<#> ");
  for (size_t i = 0; i < xy; i++) {
    printf("<%d> ", i);
  }
  printf("\n");

  for (size_t i = 0; i < xy; i++) {
    printf("<%d> ", i);
    for (size_t j = 0; j < xy; j++) {
      switch (field[i][j]) {
        case -1: printf("[O] ");
          break;
        case 0: printf("[ ] ");
          break;
        case 1: printf("[X] ");
          break;
        default: printf("[error]");
      }
    }
    printf("\n");
  }
}

int winCheck(){
  for (size_t i = 0; i < xy; i++) {
    for (size_t j = 0; j < xy; j++) {
    switch (field[i][j]) {
      case -1:
        xvalue -= 1;
        yvalue -= 1;
        break;
      case 0:
        xvalue = 0;
        yvalue = 0;
        break;
      case 1:
        xvalue += 1;
        yvalue += 1;
        break;
      }
    }
    xvalue = 0;
  }

  printf("<<[%d] [%d]>>\n", xvalue, yvalue);
  //-xy wygrana O
  //xy wygrana X
  if (xvalue == xy || xvalue == -xy || yvalue == xy || yvalue == -xy) {
    fieldCreate();
    printf("YAY WYGRANA o/\n");
    if (gracz == 0) {
      printf("WYGALO KOLKO");
    } else {
      printf("WYGAL KRZYZYK");
    }
    exit(0);
  }
  //zerowanie wartosci do kolejnego przejscia
  yvalue = 0;
  xvalue = 0;
}

int main() {

  while (xy<3) {
  printf("ile na ile plansza?\n");
  scanf("%d", &xy);
  }

  //zerowanie  planszy
  for (size_t i = 0; i < xy; i++) {
    for (size_t j = 0; j < xy; j++) {
      field[i][j] = 0;
    }
  }


  while (1==1) {
    x = -1;
    y = -1;

    fieldCreate();
    printf("---------------------------------------------\n");
    printf("Daj pozycje gdzie wstawic nastepny ruch [x,y]\n");

      while (field[x][y] == 0) { // CZY TO POTRZEBNE?
        scanf("%d %d", &x, &y);
        printf("[%d]\n", field[x][y]);

        if ((x >= 0) && (y >= 0) && field[x][y] == 0) {
          if (gracz==-1) {
            field[x][y] = -1; // O
          } else {
            field[x][y] = 1; // X
          }
        gracz = gracz * -1;
        }
    }
    winCheck();
  }
  return 0;
}
