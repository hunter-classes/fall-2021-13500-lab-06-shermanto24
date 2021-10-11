#include <iostream>

void printASCII(std::string line);

int main()
{
  printASCII("Cat :3 Dog");
  std::cout << '\n';
  printASCII("");
  std::cout << '\n';
  printASCII(" ");
}

void printASCII(std::string line)
{
  for (int i = 0; i < line.length(); i++)
  {
    char curr = line[i];
    std::cout << curr << " " << (int)curr << '\n';
  }
}
