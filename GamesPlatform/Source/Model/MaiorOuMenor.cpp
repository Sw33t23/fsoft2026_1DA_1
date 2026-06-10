//
// Created by andre on 27/04/2026.
//


#include "../../Headers/Model/MaiorOuMenor.h"
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


MaiorOuMenor::MaiorOuMenor() : limiteMax(100), tentativasAtuais(0), numeroSecreto(0)
{
    static bool estadojogo = false;
    if (!estadojogo)
    {
        srand(time(NULL));
        estadojogo = true;
    }
}

void MaiorOuMenor::iniciarJogoNovo()
{
    this->tentativasAtuais = 0;
    this->numeroSecreto = (rand() % this->limiteMax) + 1;
}

bool MaiorOuMenor::palpiteValid(int palpite) const
{
    if (palpite < 1 || palpite > limiteMax)
    {
        return false;
    }
    return true;
}

int MaiorOuMenor::verificarPalpite(int palpite)
{
    if (!this->palpiteValid(palpite))
    {
        throw InvalidDataException("Palpite invalido: Deve estar entre 1 e 100!");
    }
    this->tentativasAtuais++;

    if (palpite == this->numeroSecreto)
    {
        return 0;
    }
    if(palpite > this->numeroSecreto)
    {
        return 1;
    }
    if (palpite < this->numeroSecreto)
    {
        return -1;
    }
}


int MaiorOuMenor::getTentativasAtuais() const
{
    return this->tentativasAtuais;
}

int MaiorOuMenor::getLimiteMax() const
{
    return this->limiteMax;
}





