#include <iostream>

#include "caesar.h"
#include "vigenere.h"
#include "decrypt.h"

int main()
{
  //task B
  std::cout << "Task B\n" << '\n';
  std::cout << "shiftChar('A', 25) == " << shiftChar('A', 25) << '\n';
  std::cout << "shiftChar('y', 35) == " << shiftChar('y', 35) << '\n';

  std::cout << "\nencryptCaesar(\"Hello, World!\", 10) == " << encryptCaesar("Hello, World!", 10) << '\n';
  std::cout << "encryptCaesar(\"A Light-Year Apart\", 5) == " << encryptCaesar("A Light-Year Apart", 5) << '\n';

  //task C
  std::cout << "\n\nTask C\n" << '\n';
  std::cout << "encryptVigenere(\"Hello, World!\", \"cake\") == " << encryptVigenere("Hello, World!", "cake") << '\n';
  std::cout << "encryptVigenere(\"short\", \"looooong\") == " << encryptVigenere("short", "looooong") << '\n';

  //task D
  std::cout << "\n\nTask D\n" << '\n';
  std::cout << "decryptCaesar(\"Rovvy, Gybvn!\", 10) == " << decryptCaesar("Rovvy, Gybvn!", 10) << '\n';
  std::cout << "decryptCaesar(\"Pcvbmz Kwttmom\", 60) == " << decryptCaesar("Pcvbmz Kwttmom", 60) << '\n';

  std::cout << "\ndecryptVigenere(\"Jevpq, Wyvnd!\", \"cake\") == " << decryptVigenere("Jevpq, Wyvnd!", "cake") << '\n';
  std::cout << "decryptVigenere(\"Ryldip Msjvieo\", \"key\") == " << decryptVigenere("Ryldip Msjvieo", "key") << '\n';

  return 0;
}
