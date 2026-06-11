#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <exception>
#include <string>

class InvalidLoginException : public std::exception {

private:
    std::string message;
public:
    InvalidLoginException(const std::string& msg) : message(msg) {}
    const char* what() const noexcept override { return message.c_str(); }
};

class DuplicatePlayerException : public std::exception {

private:
    std::string message;
    std::string usernameDuplicado;
public:
    DuplicatePlayerException(const std::string& msg, const std::string& username)
        : message(msg), usernameDuplicado(username) {}
    const char* what() const noexcept override { return message.c_str(); }
    std::string getUsernameDuplicado() const { return usernameDuplicado; }
};

class InvalidDataException : public std::exception {

private:
    std::string message;
public:
    InvalidDataException(const std::string& msg) : message(msg) {}
    const char* what() const noexcept override { return message.c_str(); }
};
#endif
