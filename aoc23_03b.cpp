
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
  if (inputFile.is_open())
  {
    std::string line;

    while (std::getline(inputFile, line))
    {
      lLines = line.length();
      nLines += 1;
    }
    inputFile.close();
  }

  inputFile.open("input2303.txt");
  std::vector<std::vector<int>> symAdj(nLines, std::vector<int>(lLines,-1));
  int ngear = 0;

  // Get symbols surroundings
  if (inputFile.is_open())
  {
    std::string line;
    long res_tot = 0;
    int ii = 0;
    while (std::getline(inputFile, line))
    {
      for(int jj = 0; jj < lLines; jj++)
      {
        char ljj = line[jj];
        if (ljj == '*')
        {
          for (int jn =-1; jn < 2; jn ++)
            for (int in =-1; in < 2; in ++)
              if ((jj+jn >= 0) && (jj+jn  < lLines))
                if ((ii+in >= 0) && (ii+in  < nLines))
                  symAdj[ii+in][jj+jn] = ngear;
          ngear += 1;
        }
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
    std::vector<int> res_vec(ngear+1,0);
    std::vector<int> num_vec(ngear+1,0);
    while (std::getline(inputFile, line))
    {
      std::string snum;
      int bnum = 0;
      std::vector<int> vadj(8,-1);
      int nadj = 0;
      for(int jj = 0; jj < lLines; jj++)
      {
        char ljj = line[jj];
        if ((ljj >= '0') && (ljj <= '9'))
        {
          bnum = 1;
          if (symAdj[ii][jj] > -1)
          {
            if (vadj[nadj] > -1)
            {
              if(vadj[nadj] != symAdj[ii][jj])
              {
                nadj += 1;
              }
            }
            vadj[nadj] = symAdj[ii][jj];
          }
          snum += ljj; 
        }
        if (bnum == 1)
        {
          if (ljj < '0' || ljj > '9')
          {
            int inum = stoi(snum); 
            snum.clear();
            for(nadj = 0; nadj < 8; nadj++)
            {
              int adj = vadj[nadj];
              if (adj > -1)
              {
                if (num_vec[adj] == 0)
                {
                  res_vec[adj] = inum;
                }
                if (num_vec[adj] == 1)
                {
                  res_vec[adj] *= inum;
                }
                num_vec[adj] += 1;
              }
            }
            bnum = 0;
            nadj = 0;
            std::fill(vadj.begin(), vadj.end(), -1);

          }
        }
      }
      if (bnum == 1)
      {
        int inum = stoi(snum);   
        for(nadj = 0; nadj < 8; nadj++)
        {
          int adj = vadj[nadj];
          if (adj > -1)
          {
            if (num_vec[adj] == 0)
            {
              res_vec[adj] = inum;
            }
            if (num_vec[adj] == 1)
            {
              res_vec[adj] *= inum;
            }
            num_vec[adj] += 1;
          }
        }
      }
      ii += 1;
    }
    for (int jj=0; jj < ngear+1; jj++)
    {
      if(num_vec[jj] == 2)
      {
        res_tot += res_vec[jj];
      }
    }
    inputFile.close();
    std::cout << "Ans: " << res_tot << std::endl;
  }
  return 0;
}
