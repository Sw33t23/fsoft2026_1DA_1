//
// Created by andre on 01/06/2026.
//

#ifndef FSOFT2026_1DA_1_MENOROUMAIORVIEW_H
#define FSOFT2026_1DA_1_MENOROUMAIORVIEW_H
#include <exception>


using namespace std;

class MenorOuMaiorView
{
public:
    void mostrarInstrucoes() const;
    int pedirPalpite() const;
    void mostrarFeedbackPalpite(int estadojogo) const;
    void mostrarTentativas(int tentativas) const;


};


#endif //FSOFT2026_1DA_1_MENOROUMAIORVIEW_H