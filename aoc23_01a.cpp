
// C++ headers
#include <cmath>
#include <iostream>
#include <fstream>

int main() {
  // Open input text file
  std::ifstream inputFile("input2301.txt");
 

  if (inputFile.is_open()) {
    std::string line;
    int res_tot = 0;
    while (std::getline(inputFile, line)) {
        int N = line.length();
        // First digit
        int f = 0;
        char cf = line[f];
        while((cf < '0' || cf > '9'))
        {
          f++;
          cf = line[f];
        }
        // Last digit
        int l = N-1;
        char cl = line[l];
        while ((cl < '0' || cl > '9'))
        {
          l--;
          cl = line[l];
        }
        std::string res_line;
        res_line += cf;
        res_line += cl;
        res_tot += stoi(res_line);
    }
    inputFile.close();
    std::cout << "Ans: " << res_tot << std::endl;
  }
  return 0;
}
