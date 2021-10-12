#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "caesar.h"
#include "vigenere.h"
#include "decrypt.h"

//----------------- task B -----------------

//shiftChar

TEST_CASE("shiftChar positive in bounds")
{
  CHECK(shiftChar('A', 25) == 'Z');
  CHECK(shiftChar('a', 25) == 'z');
  CHECK(shiftChar('B', 5) == 'G');
  CHECK(shiftChar('h', 10) == 'r');
}

TEST_CASE("shiftChar positive out of bounds")
{
  CHECK(shiftChar('Z', 5) == 'E');
  CHECK(shiftChar('z', 7) == 'g');
  CHECK(shiftChar('Y', 30) == 'C');
  CHECK(shiftChar('y', 35) == 'h');
  CHECK(shiftChar('X', 53) == 'Y');
}

TEST_CASE("shiftChar 0, negative in bounds")
{
  CHECK(shiftChar('X', 0) == 'X');
  CHECK(shiftChar('S', -10) == 'I');
  CHECK(shiftChar('g', -6) == 'a');
}

TEST_CASE("shiftChar negative out of bounds")
{
  CHECK(shiftChar('C', -7) == 'V');
  CHECK(shiftChar('I', -16) == 'S');
  CHECK(shiftChar('a', -20) == 'g');
}

//encryptCaesar

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

//----------------- task D -----------------

//decryptCaesar

TEST_CASE("decryptCaesar regular cases")
{
  CHECK(decryptCaesar("Rovvy, Gybvn!", 10) == "Hello, World!");
  CHECK(decryptCaesar("F Qnlmy-Djfw Fufwy", 5) == "A Light-Year Apart");
}

TEST_CASE("decryptCaesar multiple-wrap cases")
{
  CHECK(decryptCaesar("Rovvy, Gybvn!", 36) == "Hello, World!");
  CHECK(decryptCaesar("Pcvbmz Kwttmom", 60) == "Hunter College");
}

TEST_CASE("decryptCaesar unchanged cases")
{
  CHECK(decryptCaesar("123456!@#$%^", 7) == "123456!@#$%^");
  CHECK(decryptCaesar("", 5) == "");
}

//decryptVigenere

TEST_CASE("decryptVigenere with valid keyword")
{
  CHECK(decryptVigenere("Jevpq, Wyvnd!", "cake") == "Hello, World!");
  CHECK(decryptVigenere("Ryldip Msjvieo", "key") == "Hunter College");
  CHECK(decryptVigenere("dvcfh", "looooong") == "short");
}

TEST_CASE("decryptVigenere with invalid keyword") //ciphertext is returned
{
  CHECK(decryptVigenere("hello", "!@#$%^&") == "hello");
  CHECK(decryptVigenere("hi", "abc123") == "hi");
  CHECK(decryptVigenere("goodbye", "A123") == "goodbye");
}

TEST_CASE("decryptVigenere unchanged cases")
{
  CHECK(decryptVigenere("", "word") == "");
  CHECK(decryptVigenere("!@#$%^&*()_+", "dnm") == "!@#$%^&*()_+");
}
