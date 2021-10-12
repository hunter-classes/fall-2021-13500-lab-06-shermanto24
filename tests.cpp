#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "caesar.h"
#include "vigenere.h"

//----------------- task B -----------------

TEST_CASE("shiftChar in bounds")
{
  CHECK(shiftChar('A', 25) == 'Z');
  CHECK(shiftChar('a', 25) == 'z');
  CHECK(shiftChar('B', 5) == 'G');
  CHECK(shiftChar('h', 10) == 'r');
}

TEST_CASE("shiftChar out of bounds")
{
  CHECK(shiftChar('Z', 5) == 'E');
  CHECK(shiftChar('z', 7) == 'g');
  CHECK(shiftChar('Y', 30) == 'C');
  CHECK(shiftChar('y', 35) == 'h');
  CHECK(shiftChar('X', 53) == 'Y');
}

TEST_CASE("encryptCaesar regular cases")
{
  CHECK(encryptCaesar("Hello, World!", 10) == "Rovvy, Gybvn!");
  CHECK(encryptCaesar("A Light-Year Apart", 5) == "F Qnlmy-Djfw Fufwy");
}

TEST_CASE("encryptCaesar multiple-wrap cases")
{
  CHECK(encryptCaesar("Hello, World!", 36) == "Rovvy, Gybvn!");
  CHECK(encryptCaesar("Hunter College", 60) == "Pcvbmz Kwttmom");
}

TEST_CASE("encryptCaesar unchanged cases")
{
  CHECK(encryptCaesar("123456!@#$%^", 7) == "123456!@#$%^");
  CHECK(encryptCaesar("", 5) == "");
}

//----------------- task C -----------------

TEST_CASE("encryptVigenere with valid keyword")
{
  CHECK(encryptVigenere("Hello, World!", "cake") == "Jevpq, Wyvnd!");
  CHECK(encryptVigenere("Hunter College", "key") == "Ryldip Msjvieo");
  CHECK(encryptVigenere("short", "looooong") == "dvcfh");
}

TEST_CASE("encryptVigenere with invalid keyword")
{
  CHECK(encryptVigenere("hello", "!@#$%^&") == "");
  CHECK(encryptVigenere("hi", "abc123") == "");
  CHECK(encryptVigenere("goodbye", "A123") == "");
}

TEST_CASE("encryptVigenere unchanged cases")
{
  CHECK(encryptVigenere("", "word") == "");
  CHECK(encryptVigenere("!@#$%^&*()_+", "dnm") == "!@#$%^&*()_+");
}
