// ============================================================
//  Galo.cpp  –  Ponto de entrada do Jogo do Galo
//
//  Liga o main principal ao padrão MVC do jogo:
//    View  -> GaloView
//    Controller -> GaloController
// ============================================================

#include "../../Headers/Model/Galo.h"
#include "../../Headers/View/GaloView.h"
#include "../../Headers/Controller/GaloController.h"
// ============================================================
//  GaloException.cpp  –  Implementação dos utilitários
// ============================================================

#include "../../Headers/Exception/GaloException.h"  // <-- include do próprio header
#include <iostream>
#include <limits>

int GaloException::getInt(const std::string& label) {
    int valor;
    while (true) {
        std::cout << label;
        if (std::cin >> valor) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return valor;
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "  [Erro] Introduz um numero inteiro.\n";
    }
}

// Chamado pelo main principal da plataforma
void jogarGalo(const std::string& nomeJogador) {
    GaloView view;                    // camada de apresentação
    GaloController controller(view);  // lógica do jogo
    controller.iniciar(nomeJogador);  // arranca o jogo
}
