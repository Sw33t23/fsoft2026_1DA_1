#include "../../Headers/Container/JogadorContainer.h"

JogadorContainer::JogadorContainer() : nextId(1) {}

bool JogadorContainer::add(const std::string& username, const std::string& password) {
    if (usernameExiste(username)) {
        return false;
    }
    jogadores.emplace_back(username, password);
    return true;
}

Jogador* JogadorContainer::validarCredenciais(const std::string& username, const std::string& password) {
    for (auto& jogador : jogadores) {
        if (jogador.username == username && jogador.password == password) {
            return &jogador;
        }
    }
    return nullptr;
}

bool JogadorContainer::usernameExiste(const std::string& username) const {
    for (const auto& jogador : jogadores) {
        if (jogador.username == username) {
            return true;
        }
    }
    return false;
}

const std::vector<Jogador>& JogadorContainer::getJogadores() const {
    return jogadores;
}
