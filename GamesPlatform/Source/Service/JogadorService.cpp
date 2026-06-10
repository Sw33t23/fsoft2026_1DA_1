#include "../../Headers/Service/JogadorService.h"
#include "../../Headers/Exception/Exception.h"

JogadorService::JogadorService(JogadorContainer& container) : container(container) {}

void JogadorService::registarJogador(const RegistoDTO& dados) {
    if (dados.username.empty()) {
        throw InvalidDataException("O username nao pode estar vazio.");
    }
    if (dados.password.length() < 4) {
        throw InvalidDataException("A password deve ter pelo menos 4 caracteres.");
    }

    bool sucesso = container.add(dados.username, dados.password);
    if (!sucesso) {
        throw DuplicatePlayerException(
            "O username '" + dados.username + "' ja esta registado.",
            dados.username
        );
    }
}

Jogador* JogadorService::autenticar(const LoginDTO& dados) {
    if (dados.username.empty() || dados.password.empty()) {
        throw InvalidLoginException("Username e password nao podem estar vazios.");
    }

    Jogador* jogador = container.validarCredenciais(dados.username, dados.password);
    if (jogador == nullptr) {
        throw InvalidLoginException("Username ou password incorretos.");
    }

    return jogador;
}
