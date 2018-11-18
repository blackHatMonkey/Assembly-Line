// Name: Brian Smith
// Seneca Student ID: 137105177
// Seneca email: bsmith55@myseneca.ca
// Date of completion: 18/11/2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

// Workshop 9 - Multi-Threading
// SecureData.cpp

#include <cstring>
#include <fstream>
#include <functional>
#include <iostream>
#include <string>
#include <thread>

#include "SecureData.h"

using namespace std;

namespace w9 {

void converter(char *t, char key, int n, const Cryptor &c) {
  for (int i = 0; i < n; i++)
    t[i] = c(t[i], key);
}

SecureData::SecureData(const char *file, char key, ostream *pOfs) {
  ofs = pOfs;

  // open text file
  fstream input(file, std::ios::in);
  if (!input)
    throw string("\n***Failed to open file ") + string(file) + string(" ***\n");

  // copy from file into memory
  input.seekg(0, std::ios::end);
  nbytes = (int)input.tellg() + 1;

  text = new char[nbytes];

  input.seekg(ios::beg);
  int i = 0;
  input >> noskipws;
  while (input.good())
    input >> text[i++];
  text[nbytes - 1] = '\0';
  *ofs << "\n"
       << nbytes - 1 << " bytes copied from file " << file
       << " into memory (null byte added)\n";
  encoded = false;

  // encode using key
  code(key);
  *ofs << "Data encrypted in memory\n";
}

SecureData::~SecureData() { delete[] text; }

void SecureData::display(std::ostream &os) const {
  if (text && !encoded)
    os << text << std::endl;
  else if (encoded)
    throw std::string("\n***Data is encoded***\n");
  else
    throw std::string("\n***No data stored***\n");
}

void SecureData::code(char key) {
  auto cry = Cryptor();
  thread t1(bind(converter, text, key, nbytes / 4, cry));
  thread t2(bind(converter, text + (nbytes / 4), key, nbytes / 4, cry));
  thread t3(bind(converter, text + (nbytes / 2), key, nbytes / 4, cry));
  thread t4(bind(converter, text + (3 * nbytes / 4), key, nbytes / 4, cry));

  t1.join();
  t2.join();
  t3.join();
  t4.join();

  encoded = !encoded;
}

void SecureData::backup(const char *file) {
  if (!text)
    throw std::string("\n***No data stored***\n");
  else if (!encoded)
    throw std::string("\n***Data is not encoded***\n");
  else {
    std::ofstream f(file, std::ios::out | std::ios::trunc | std::ios::binary);

    if (!f) {
      throw std::string("Failed to open file for backup!");
    }

    f.write(text, nbytes);
  }
}

void SecureData::restore(const char *file, char key) {
  std::ifstream f(file, std::ios::in | std::ios::binary);

  if (!f) {
    throw std::string("Failed to open file for restore!");
  }

  f.seekg(0, std::ios::end);
  auto size = f.tellg();
  f.seekg(0, std::ios::beg);

  delete[] text;
  text = new char[size];

  f.read(text, nbytes);

  *ofs << "\n"
       << nbytes << " bytes copied from binary file " << file
       << " into memory.\n";

  encoded = true;

  // decode using key
  code(key);

  *ofs << "Data decrypted in memory\n\n";
}

std::ostream &operator<<(std::ostream &os, const SecureData &sd) {
  sd.display(os);
  return os;
}
} // namespace w9
