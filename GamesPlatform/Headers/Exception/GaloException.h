#ifndef GALOEXCEPTION_H_H
#define GALOEXCEPTION_H

#include <string>

class GaloException {
public:
    static int getInt(const std::string& label);
};

#endif // GALOUTILS_H