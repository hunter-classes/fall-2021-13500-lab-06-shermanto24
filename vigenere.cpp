#include <iostream>
#include <cctype>

#include "vigenere.h"
#include "caesar.h"

std::string encryptVigenere(std::string plaintext, std::string keyword)
{
  //checks each char in keyword to see if it is valid
  for (int i = 0; i < keyword.length(); i++)
  {
    char keycurr = keyword[i];
    if (keycurr < 97 || keycurr > 122)
    {
      std::cout << "keyword must contain only lowercase alphabetic characters" << '\n';
      return "";
    }
  }

  std::string result = "";
  int j = 0; //pos in keyword
  
  //encrypting plaintext
  for (int i = 0; i < plaintext.length(); i++)
  {
    char plaincurr = plaintext[i];
    char keycurr = keyword[j];

    int shift = (int)keycurr - 97; //a = 97
    result += shiftChar(plaincurr, shift);

    if (j == keyword.length() - 1)
      j = 0;
    else if ( (isalpha(plaincurr)) )
      j++;
  }

  return result;
}
