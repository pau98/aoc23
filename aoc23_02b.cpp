
// C++ headers
#include <cmath>
#include <iostream>
#include <fstream>
#include <vector>
int main() {
  // Open input text file
  std::ifstream inputFile("input2302.txt");
 

  if (inputFile.is_open()) {
    std::string line;
    int res_tot = 0;
    while (std::getline(inputFile, line))
    {
      int N = line.length();
      std::string snum;
      int gval = 1;
      int gnum;
      bool bnum = 0;
      int rmin = 0;
      int gmin = 0;
      int bmin = 0;

      for(int ii = 0; ii < N ; ii++)
      {
        char lii = line[ii];
        if (lii >= '0' && lii <= '9')
        {
          bnum = 1;
          snum += lii;
        }
        if (bnum == 1)
        {
          if (lii == ' ')
          {
            int inum = stoi(snum);
            snum.clear();
            bnum = 0;
            char col = line[ii+1];
            if ((col == 'r') && (inum > rmin)) rmin = inum;
            if ((col == 'g') && (inum > gmin)) gmin = inum;
            if ((col == 'b') && (inum > bmin)) bmin = inum;
          }
          else if (lii == ':')
          {
            snum.clear();
            bnum = 0;
          }
        }
      }
      res_tot += rmin*gmin*bmin;
    }
    inputFile.close();
    std::cout << "Ans: " << res_tot << std::endl;
  }
  return 0;
}
