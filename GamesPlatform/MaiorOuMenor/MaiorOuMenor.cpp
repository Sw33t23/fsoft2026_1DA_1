//
// Created by andre on 27/04/2026.
//


#include "MaiorOuMenor.h"
#include <cstdlib>
#include <ctime>
#include <stdexcept>

using namespace std;

class InvalidDataException : public std::exception
{
private:
    std::string mensagem;
public:
    InvalidDataException(const std::string &msg) : mensagem(msg) {}
    const char *what() const noexcept override
    {
        return mensagem.c_str();
    }
};


