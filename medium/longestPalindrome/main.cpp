#include <iostream>
#include <fstream>
#include <string>
#include "solution.h"

int main() {
  std::string str;
  std::getline(std::cin, str);
  std::string result = Solution::longestPalindrome(str);
  std::cout << result << std::endl;
  return 0;
}