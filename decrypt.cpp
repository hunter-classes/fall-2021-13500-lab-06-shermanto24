#include <iostream>
#include "decrypt.h"
#include "caesar.h"

std::string decryptCaesar(std::string ciphertext, int rshift)
{
  return encryptCaesar(ciphertext, -rshift);
}

std::string decryptVigenere(std::string ciphertext, std::string keyword)
{
  //checks each char in keyword to see if it is valid
  for (int i = 0; i < keyword.length(); i++)
  {
    char keycurr = keyword[i];
    if (keycurr < 97 || keycurr > 122)
    {
      std::cout << "keyword must contain only lowercase alphabetic characters" << '\n';
      return ciphertext;
    }
  }

  std::string result = "";
  int j = 0; //pos in keyword

  //decrypting ciphertext
  for (int i = 0; i < ciphertext.length(); i++)
  {
    char ciphercurr = ciphertext[i];
    char keycurr = keyword[j];

    int shift = (int)keycurr - 97; //a = 97
    result += shiftChar(ciphercurr, -shift);

    if (j == keyword.length() - 1)
      j = 0;
    else if ( (isalpha(ciphercurr)) )
      j++;
  }

  return result;
}
