#ifndef JOGADOR_CONTAINER_H
#define JOGADOR_CONTAINER_H

#include <vector>
#include <string>
#include "../Model/Jogador.h"

class JogadorContainer {
private:
    std::vector<Jogador> jogadores;
    int nextId;

public:
    JogadorContainer();

    bool add(const std::string& username, const std::string& password);

    Jogador* validarCredenciais(const std::string& username, const std::string& password);

    bool usernameExiste(const std::string& username) const;

    const std::vector<Jogador>& getJogadores() const;
};
#endif