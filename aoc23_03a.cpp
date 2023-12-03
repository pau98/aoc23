
// C++ headers
#include <cmath>
#include <iostream>
#include <fstream>
#include <vector>
int main() {
  // Open input text file
  std::ifstream inputFile("input2303.txt");
  
  // Get size of input
  int nLines = 0;
  int lLines;
  if (inputFile.is_open()) {
    std::string line;

    while (std::getline(inputFile, line))
    {
      lLines = line.length();
      nLines += 1;
    }
    inputFile.close();
  }

  inputFile.open("input2303.txt");
  std::vector<std::vector<int>> symAdj(nLines, std::vector<int>(lLines,0));

  // Flag symbols surroundings
  if (inputFile.is_open())
  {
    std::string line;
    int res_tot = 0;
    int ii = 0;
    while (std::getline(inputFile, line))
    {
      for(int jj = 0; jj < lLines; jj++)
      {
        char ljj = line[jj];
        if (ljj < '0' || ljj > '9')
          if (ljj != '.')
            for (int jn =-1; jn < 2; jn ++)
              for (int in =-1; in < 2; in ++)
                if ((jj+jn >= 0) && (jj+jn  < lLines))
                  if ((ii+in >= 0) && (ii+in  < nLines))
                    symAdj[ii+in][jj+jn] = 1;
      }
      ii += 1;
    } 
  } 
  inputFile.close();
  
  // Sum adjecent parts
  inputFile.open("input2303.txt");
  if (inputFile.is_open())
  {
    std::string line;
    int res_tot = 0;
    int ii = 0;
    while (std::getline(inputFile, line))
    {
      std::string snum;
      int bnum = 0;
      int adj = 0;
      for(int jj = 0; jj < lLines; jj++)
      {
        char ljj = line[jj];
        if (ljj >= '0' && ljj <= '9')
        {
          bnum = 1;
          adj = std::max(symAdj[ii][jj],adj);
          snum += ljj;
        }
        if (bnum == 1)
        {
          if (ljj < '0' || ljj > '9')
          {
            int inum = stoi(snum);
            snum.clear();
            bnum = 0;
            res_tot += inum*adj;
            adj = 0;
          }
        }
      }
      if (bnum == 1)
      {
        int inum = stoi(snum);
        res_tot += inum*adj;
      }
      ii += 1;
    }
    inputFile.close();
    std::cout << "Ans: " << res_tot << std::endl;
  }
  return 0;
}
