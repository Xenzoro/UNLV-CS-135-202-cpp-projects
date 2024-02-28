//
// Created by BEN CISNEROS.
//

#ifndef myException_hpp
#define myException_hpp

#include <iostream>
#include <string>

class myException
{
public:
  myException(const char* msg);
  myException(const std::string& msg);
  std::string what() const;

private:
  std::string message_;
};

#endif // myException_hpp