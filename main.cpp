#include <iostream>

#include "caesar.h"
#include "vigenere.h"
#include "decrypt.h"

int main()
{
  //task B
  std::cout << "Task B\n" << '\n';
  std::cout << "shiftChar(A, 25) == " << shiftChar('A', 25) << '\n';
  std::cout << "encryptCaesar(\"Hello, World!\", 10) == " << encryptCaesar("Hello, World!", 10) << '\n';

  //task C
  std::cout << "\n\nTask C\n" << '\n';
  std::cout << "encryptVigenere(\"Hello, World!\", \"cake\") == " << encryptVigenere("Hello, World!", "cake") << '\n';

  //task D
  std::cout << "\n\nTask D\n" << '\n';
  std::cout << "decryptCaesar(\"Rovvy, Gybvn!\", 10) == " << decryptCaesar("Rovvy, Gybvn!", 10) << '\n';
  std::cout << "decryptVigenere(\"Jevpq, Wyvnd!\", \"cake\") == " << decryptVigenere("Jevpq, Wyvnd!", "cake") << '\n';

  return 0;
}
