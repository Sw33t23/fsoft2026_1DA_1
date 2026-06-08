// ============================================================
//  Galo.cpp  –  Ponto de entrada do Jogo do Galo
//
//  Liga o main principal ao padrão MVC do jogo:
//    View  -> GaloView
//    Controller -> GaloController
// ============================================================

#include "Galo.h"
#include "../view/GaloView.h"
#include "../Controller/GaloController.h"

// Chamado pelo main principal da plataforma
void jogarGalo(const std::string& nomeJogador) {
    GaloView view;                    // camada de apresentação
    GaloController controller(view);  // lógica do jogo
    controller.iniciar(nomeJogador);  // arranca o jogo
}