// exception.cpp
#include <stdexcept>
#include <cstdio>
#include <iostream>
#include <memory>

using namespace std;

class File_ptr{
  FILE* p;
public:
  File_ptr(const char* n, const char* a)
    : p { fopen(n, a) }
  {
    if(p == nullptr)
      throw std::runtime_error{ "File_ptr: Can't open file." };
  }

  File_ptr(const string& n, const char* a)
    : File_ptr{ n.c_str(), a }
  {}

  explicit File_ptr(FILE* pp)
    : p { pp }
  {
    if(p == nullptr)
      throw std::runtime_error{ "File_ptr: nullptr." };
  }

  // destructor
  ~File_ptr() { fclose(p); }

  operator FILE*() { return p; }
};




void doSomeComputation() {
  throw std::runtime_error("failure during doing some computation");
}

void example() {
  File_ptr logfile("logfile.txt", "w+");

  try{
    if (!logfile) {
      throw std::runtime_error("failed to open file");
    }
    fputs("log1", logfile);
  }
  catch(const std::runtime_error& error){
    cout << error.what() << endl;
    fclose(logfile);
    throw;
  }
  try{
    doSomeComputation();
  }catch(...){}

  /*------------------------------------------------*/
  cout << "closing logfile" << endl;
  fclose(logfile);
  /*------------------------------------------------*/
}



int main(void) {
  cout << "Calling example()" << endl;

  try{
    example();
  }catch(const std::runtime_error& error){
    cout << error.what() << endl;
  }

  cout << "After calling example()" << endl;
  return 0;
}