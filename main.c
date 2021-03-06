#include <stdio.h>
#include <string.h>
#define L (19)
#define EMPTY (0)
#define ME (1)
#define OPPONENT (2)

typedef int Field[L][L];

void printField(Field);
void calcNextPlacing(Field, int *, int *);

int verbose = 0;

int main(int argc, char *argv[]) {
  int opponentY, opponentX, myY, myX;
  if(argc >= 2 && strcmp(argv[1], "-v") == 0) {
    verbose = 1;
  }

  Field field = {};

  while(1) {
    printField(field);

    if(scanf("%d %d", &opponentY, &opponentX) != 2) {
      break;
    }

    if(opponentY != -1 && opponentX != -1) {
      field[opponentY][opponentX] = OPPONENT;
    }

    printField(field);

    calcNextPlacing(field, &myY, &myX);

    printf("%d %d\n", myY, myX);
    field[myY][myX] = ME;
  }
}

void calcNextPlacing(Field field, int *myY, int *myX) {
  // Change here!
  int y, x;
  for(y = 0; y < L; ++y) {
    for(x = 0; x < L; ++x) {
      if(field[y][x] == EMPTY) {
        *myY = y;
        *myX = x;
        return;
      }
    }
  }
}

void printField(Field field) {
  int x, y;
  if(!verbose) {
    return;
  }

  fprintf(stderr, "  ");
  for(x = 0; x < L; ++x) {
    fprintf(stderr, "%2d", x);
  }
  fprintf(stderr, "\n");

  for(y = 0; y < L; ++y) {
    fprintf(stderr, "%2d", y);
    for(x = 0; x < L; ++x) {
      switch(field[y][x]) {
        case EMPTY:
          fprintf(stderr, "  ");
          break;
        case ME:
          fprintf(stderr, " o");
          break;
        case OPPONENT:
          fprintf(stderr, " x");
          break;
      }
    }
    fprintf(stderr, "%2d\n", y);
  }

  fprintf(stderr, "  ");
  for(x = 0; x < L; x++) {
    fprintf(stderr, "%2d", x);
  }
  fprintf(stderr, "\n");
}
