#ifndef BASE64LIB_H
#define BASE64LIB_H

#include <string>

std::string StringToBase64(const std::string& source_string);
std::string Base64ToString(const std::string& base64_string);

#endif // BASE64LIB_H