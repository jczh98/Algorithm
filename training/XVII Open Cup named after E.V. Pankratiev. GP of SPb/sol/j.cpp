#include <stdlib.h>
#include <algorithm>
#include <cstdio>
#include <string>
#include <cstring>
#include <cassert>

using namespace std;

const char* digits[8] = {
".XXXXX.....XX....XXXXX...XXXXX.....XXX..XXXXXXX..XXXXX..XXXXXXX..XXXXX...XXXXX..",
"XX..XXX...XXX...XX...XX.XX...XX...XXXX..XX......XX...XX.XX...XX.XX...XX.XX...XX.",
"XX.XXXX..XXXX........XX......XX..XX.XX..XXXXXX..XX......X....XX.XX...XX.XX...XX.",
"XXXX.XX....XX......XXX....XXXX..XX..XX.......XX.XXXXXX......XX...XXXXX...XXXXXX.",
"XXX..XX....XX....XXX.........XX.XXXXXXX......XX.XX...XX....XX...XX...XX......XX.",
"XXX..XX....XX...XX......XX...XX.....XX..XX...XX.XX...XX...XX....XX...XX.XX...XX.",
".XXXXX...XXXXXX.XXXXXXX..XXXXX.....XXXX..XXXXX...XXXXX....XX.....XXXXX...XXXXX..",
"................................................................................",
};

const int W = 12 * 60;
const int H = 12;

char line[H][W + 1];

void paint(int x, int y) {
  y = (y + W) % W;
  line[x][y] = 'X';
}

void paint_digit(int x, int center) {
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (digits[i][8*x+j] == 'X') {
        paint(i + 3, j + center - 4);
      }
    }
  }
}

void paint_int(int x, int center) {
  if (x < 10) {
    paint_digit(x, center);
  } else {
    paint_digit(x / 10, center - 4);
    paint_digit(x % 10, center + 4);
  }
}

char s[H][61];

int main() {
  freopen("timer.in", "r", stdin);
  freopen("timer.out", "w", stdout);

  memset(line, '.', sizeof(line));
  for (int i = 0; i < H; i++) {
    line[i][W] = 0;
  }

  for (int i = 0; i < 60; i++) {
    paint(0, i * 12 - 1);
    paint(0, i * 12);
    paint(1, i * 12 - 1);
    paint(1, i * 12);
  }

  for (int i = 0; i < 60; i += 5) {
    paint_int(i, ((60 - i) % 60) * 12);
  }

//  for (int i = 0; i < H; i++) {
//    printf("%s\n", line[i]);
//  }

  for (int i = 0; i < H; i++) {
    scanf("%s", s[i]);
  }


  int ans = -1;

  for (int shift = 0; shift < W; shift++) {
    bool ok = true;
    for (int i = 0; i < H; i++) {
      for (int j = 0; j < 60 && ok; j++) {
        if (s[i][j] == '-') continue;
        if (s[i][j] != line[i][(j + shift + W - 30) % W]) ok = false;
      }
    }
    if (ok) {
      assert(ans == -1);    
      ans = shift;
    }
  }

  assert(ans != -1);

  int sec = (3600 - 5 * ans) % 3600;

  printf("%02d:%02d\n", sec / 60, sec % 60);

}

