#include <iostream>
#include <sstream>
#include <vector>

int main() {
  char a0[5][30] = {
    "_____________________      O",
    "| O  |              |= o ",
    "|/|__|              |    O",
    "|                   |",
    "|___/O\\______/O\\____|"
  };
  char a1[5][30] = {
    "_____________________ o    ",
    "| O  |              |=   O ",
    "|/|__|              |  o",
    "|                   |",
    "|___/o\\______/o\\____|"
  };

  long long an = 0;
//   char q[8][30] = {
//     " ______________             ",
// "< Hello World! >           ",
// " --------------            ",
// "        \\   ^__^           ",
// "         \\  (oo)\\_______   ",
// "            (__)\\       )\\/\\",
// "                ||----w |  ",
// "                ||     ||  ",
//   };

  for (int w = 100; w >= 0; w--) {
    std::stringstream out;
    for (int k = 0; k < 10; k++) out << std::endl;
    for (int i = 0; i < 5; i++) {
      for (int x = 0; x < w; x++)
        out << ' ';
      for (int j = 0; j < 29; j++)
        out << ((an % 10 > 5) ? a0[i][j] : a1[i][j]);
      out << std::endl;
    }
    std::cout << out.str() << std::endl;
    for (int oi = 0; oi < 10000000; oi++);
    an++;
    std::cout << "\033[2J\033[0;0H";
  }

  return 0;
}