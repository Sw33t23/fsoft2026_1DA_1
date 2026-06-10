#include "../../Headers/View/JogadorView.h"
#include <iostream>
#include <limits>

void JogadorView::menuPrincipal() const {
    std::cout << "\n=============================\n";
    std::cout << "   PLATAFORMA DE JOGOS\n";
    std::cout << "=============================\n";
    std::cout << " 1. Registar\n";
    std::cout << " 2. Iniciar Sessao\n";
    std::cout << " 3. Sair\n";
    std::cout << "=============================\n";
    std::cout << "Opcao: ";
}

int JogadorView::pedirOpcaoMenuPrincipal() const {
    menuPrincipal();
    int opcao;
    while (!(std::cin >> opcao)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Entrada invalida. Tente novamente: ";
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return opcao;
}

RegistoDTO JogadorView::pedirDadosRegisto() const {
    RegistoDTO dados;
    std::cout << "\n--- REGISTO ---\n";
    std::cout << "Username: ";
    std::getline(std::cin, dados.username);
    std::cout << "Password (minimo 4 caracteres): ";
    std::getline(std::cin, dados.password);
    return dados;
}

LoginDTO JogadorView::pedirDadosLogin() const {
    LoginDTO dados;
    std::cout << "\n--- INICIAR SESSAO ---\n";
    std::cout << "Username: ";
    std::getline(std::cin, dados.username);
    std::cout << "Password: ";
    std::getline(std::cin, dados.password);
    return dados;
}

void JogadorView::mostrarPerfil(const std::string& nome, double saldo) const {
    std::cout << "\n=============================\n";
    std::cout << "  Bem-vindo, " << nome << "!\n";
    std::cout << "  Saldo: $" << saldo << "\n";
    std::cout << "=============================\n";
}

void JogadorView::mostrarSucesso(const std::string& msg) const {
    std::cout << "[OK] " << msg << "\n";
}

void JogadorView::mostrarErro(const std::string& msg) const {
    std::cout << "[ERRO] " << msg << "\n";
}
