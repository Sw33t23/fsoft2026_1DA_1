#ifndef DTO_H
#define DTO_H
#include <string>

struct RegistoDTO {
    std::string username;
    std::string password;
};

struct LoginDTO {
    std::string username;
    std::string password;
};
#endif 