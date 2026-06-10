#ifndef JOGADOR_VIEW_H
#define JOGADOR_VIEW_H

#include <string>
#include <vector>
#include "../DTO/DTO.h"

class JogadorView {
public:
    void menuPrincipal() const;

    int pedirOpcaoMenuPrincipal() const;

    RegistoDTO pedirDadosRegisto() const;

    LoginDTO pedirDadosLogin() const;

    void mostrarPerfil(const std::string& nome, double saldo) const;

    void mostrarSucesso(const std::string& msg) const;
    void mostrarErro(const std::string& msg) const;
};
#endif