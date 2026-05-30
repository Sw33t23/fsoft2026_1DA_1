//
// Created by andre on 27/04/2026.
//

#ifndef FSOFT2026_1DA_1_MAIOROUMENOR_H
#define FSOFT2026_1DA_1_MAIOROUMENOR_H

class MaiorOuMenor {
private:
    int numeroSecreto;
    int limiteMax;
    int tentativasAtuais;

    bool palpiteValid(int palpite) const;

public:
    MaiorOuMenor();

    void iniciarJogoNovo();
    int verificarPalpite(int palpite);

    int getTentativasAtuais() const;
    int getLimiteMax() const;

};

#endif //FSOFT2026_1DA_1_MAIOROUMENOR_H