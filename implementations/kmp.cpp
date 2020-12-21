#include <iostream>
#include <vector>

typedef std::vector<int> kmpTable_t;

// http://www.inf.fh-flensburg.de/lang/algorithmen/pattern/kmpen.htm version
// Checks the same value of the string multiple times
// Kinda weird
kmpTable_t buildTable2(const std::string& W) {
  kmpTable_t t(W.size()+1);
  int i = 0, j = -1;
  int m {static_cast<int>(W.size())};
  t[i] = j; // b[0] = -1, always
  while (i < m) {
    while (j >= 0 && W[i] != W[j]) j = t[j];
    i++; j++;
    t[i] = j;    
  }
  return t;
}

// Builds the fantastic Knuth-Morris-Pratt table thingy
// It's really cool
// O(m)
kmpTable_t buildTable(const std::string& W) {
  kmpTable_t t(W.size()+1);
  int m {static_cast<int>(W.size())};
  t[0] = -1; // By definition
  for (int i = 1, j = 0; i < m; i++, j++) {
    if (W[i] == W[j]) {
      t[i] = t[j]; // There can't be a prefix larger than t[j]
    }
    else {
      t[i] = j; // The prefix ends at position j

      // // What the fuck does this mean??
      // Won't just a j = -1 do?
      // I'm pretty sure just a j = -1 would do
      j = t[j]; // Increase performance? What?? Wikipedia??
      while (j >= 0 && t[j] != t[i])
        j = t[j]; // Hey, that's the same line as before!
      if (j != -1) std::cout << "WOAH! '" << W << '\'' << std::endl;
    }
  }
  return t;
}

// Finds the first occurence of W(ord) in T(ext)
// O(n) time complexity double exclam !!
int findKMP(const std::string& T, const std::string& W, const kmpTable_t& table) {
  int n = static_cast<int>(T.size()), 
      m = static_cast<int>(W.size()),
      i {0}, // Text offset
      j {0}; // Word offset
  while (i < n) {
    if (T[i] == W[j]) {
      i++; j++;
      if (j == m) return i-m; // Match found;
    }
    else {
      j = table[j];
      if (j < 0) {
        i++; j++;
      }
    }
  }

  // Match not found
  return -1;
}

int main() {
  std::string T; // Text string
  std::string W; // Word/Pattern string
  std::cin >> T >> W; // Read text and word from stdin

  int n; std::cin >> n;
  std::string aux;
  kmpTable_t auxTable;
  while (n--) {
    std::cin >> aux;
    auxTable = buildTable(aux);
  }

  // Build table for use in find function
  kmpTable_t table { buildTable(W) };  

  std::cout << T << ' ' << W << std::endl;

  for (const auto i : table) {
    std::cout << i << ' ';
  } 
  std::cout << std::endl;

  // Outputs the index of the first occurence
  std::cout << findKMP(T, W, table) << std::endl;

  return 0;
}