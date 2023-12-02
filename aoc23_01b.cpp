
// C++ headers
#include <cmath>
#include <iostream>
#include <fstream>
#include <vector>

int main() {
  // Open input text file
  std::ifstream inputFile("input2301.txt");
 

  if (inputFile.is_open()) {
    std::string line;
    std::vector<std::string> nums = {"one","two","three","four","five","six","seven","eight","nine"};
    std::string digs = "123456789";
    int nnums = nums.size();
    int res_tot = 0;
    while (std::getline(inputFile, line))
    {
      int N = line.length();
      // Check written nums
      int f = 0;
      char cf = line[f];
      char nummax;
      char nummin;
      int posmin = N;
      int posmax = 0;
      for (int ii = 0; ii < nnums; ii++)
      {
        std::string num = nums[ii];
        int pos = line.find(num);
        int rpos = line.rfind(num);

        if (pos != std::string::npos)
        {
          if (pos < posmin)
          {
            nummin = digs[ii];
            posmin = pos;
          }
          if (rpos > posmax)
          {
            nummax = digs[ii];
            posmax = rpos;
          }
        }
      }
      // First digit
      while((cf < '0' || cf > '9'))
      {
        f++;
        cf = line[f];
      }
      if (f > posmin) cf = nummin;
      // Last digit
      int l = N-1;
      char cl = line[l];
      while ((cl < '0' || cl > '9'))
      {
        l--;
        cl = line[l];
      }
      if (l < posmax) cl = nummax;
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
