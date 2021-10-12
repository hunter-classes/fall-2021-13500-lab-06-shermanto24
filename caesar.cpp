#include <iostream>
#include <cctype>

#include "caesar.h"

char shiftChar(char c, int rshift)
{
  char result = c;

  if (isalpha(c))
  {
    int base;
    if (c >= 65 && c <= 90) //uppercase
      base = 65;
    else //lowercase, 97 <= c <= 122
      base = 97;

    int newshift = rshift % 26; //[0, 25]
    if (c + newshift > base + 25) //if it's out of bounds
      result = c + newshift - 26;
    else //in bounds
      result = c + newshift;
  }

  return result;
}

std::string encryptCaesar(std::string plaintext, int rshift)
{
  std::string result = "";

  for (int i = 0; i < plaintext.length(); i++)
  {
    char curr = plaintext[i];
    result += shiftChar(curr, rshift);
  }

  return result;
}
