#ifndef JOGADOR_SERVICE_H
#define JOGADOR_SERVICE_H

#include "../Container/JogadorContainer.h"
#include "../DTO/DTO.h"
#include "../Model/Jogador.h"

class JogadorService {
private:
    JogadorContainer& container;

public:
    JogadorService(JogadorContainer& container);

    void registarJogador(const RegistoDTO& dados);

    Jogador* autenticar(const LoginDTO& dados);
};
#endif