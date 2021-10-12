#pragma once

// A helper function to shift one character by rshift
char shiftChar(char c, int rshift);

// Caesar cipher encryption
std::string encryptCaesar(std::string plaintext, int rshift);
