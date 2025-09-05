//
// Created by BEN CISNEROS.
//

#include "myException.hpp"

myException::myException(const char* msg) : message_(msg) { }

myException::myException(const std::string& msg) : message_(msg) { }

std::string myException::what() const {
  return message_.c_str();
}