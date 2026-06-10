// ============================================================
//  GaloUtils.cpp  –  Implementação dos utilitários
// ============================================================

#include "GaloUtils.h"  // <-- include do próprio header
#include <iostream>
#include <limits>

int GaloUtils::getInt(const std::string& label) {
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