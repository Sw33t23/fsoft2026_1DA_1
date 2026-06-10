#ifndef RANKING_VIEW_H
#define RANKING_VIEW_H
 
#include <string>
#include <vector>
#include "../Model/Ranking.h"
 
class RankingView {
public:
    void exibirTop10(const std::vector<EntradaRanking>& lista,
                     const std::string& nomeJogo,
                     const std::string& colunaValor);

    int pedirOpcaoMenu();
 
    void mostrarOpcaoInvalida();
    void mostrarAVoltar();
};
#endif
