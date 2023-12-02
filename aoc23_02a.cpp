
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
    int rmax = 12;
    int gmax = 13;
    int bmax = 14;
    while (std::getline(inputFile, line))
    {
      int N = line.length();
      std::string snum;
      int gval = 1;
      int gnum;
      bool bnum = 0;
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
            if ((col == 'r') && (inum > rmax)) gval = 0;
            if ((col == 'g') && (inum > gmax)) gval = 0;
            if ((col == 'b') && (inum > bmax)) gval = 0;
          }
          else if (lii == ':')
          {
            gnum = stoi(snum);
            snum.clear();
            bnum = 0;
          }
        }
      }
      res_tot += gnum*gval;
    }
    inputFile.close();
    std::cout << "Ans: " << res_tot << std::endl;
  }
  return 0;
}
