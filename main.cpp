#include <iostream>

#include "funcs.h"
#include "caesar.h"
#include "vigenere.h"

int main()
{
  //task B
  std::cout << "Task B\n" << '\n';
  std::cout << "shiftChar(A, 25) = " << shiftChar('A', 25) << '\n';
  std::cout << "encryptCaesar(\"Hello, World!\", 10) = " << encryptCaesar("Hello, World!", 10) << '\n';

  //task C
  std::cout << "Task C\n" << '\n';
  std::cout << "encryptVigenere(\"Hello, World!\", \"cake\") = " << encryptVigenere("Hello, World!", "cake") << '\n';

  return 0;
}
