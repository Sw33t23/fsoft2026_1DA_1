#ifndef GALO_CONTROLLER_H
#define GALO_CONTROLLER_H

#include "../Model/Galo.h"
#include "../View/GaloView.h"

class GaloController {
private:
    Galo* model;
    GaloView view;

public:
    GaloController();
    ~GaloController();
    void iniciarJogo();
};

#endif