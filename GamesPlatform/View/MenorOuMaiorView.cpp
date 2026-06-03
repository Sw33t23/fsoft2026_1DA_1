//
// Created by andre on 01/06/2026.
//

#include "MenorOuMaiorView.h"
#include <iostream>

using namespace std;

void MenorOuMaiorView::mostrarInstrucoes() const
{
    cout << "\n========================================" << endl;
    cout << "           MAIOR OU MENOR                 " << endl;
    cout << "==========================================" << endl;
    cout << "REGRAS:" << endl;
    cout << "- Deve adivinhar um numero aleatorio de 1 a 100" << endl;
    cout << "- Serao contadas as tentativas que precisou para acertar" << endl;
}

int MenorOuMaiorView::pedirPalpite() const
{
    int palpite;
    cout << "Introduza o seu palpite: ";
    cin >> palpite;
    return palpite;
}

void MenorOuMaiorView::mostrarFeedbackPalpite(int estadojogo) const
{
    if (estadojogo == 1)
    {
        cout << "O numero secreto e MENOR!" << endl;
    }
    else if (estadojogo == -1)
    {
        cout << "O numero secreto e MAIOR!" << endl;
    }
}

void MenorOuMaiorView::mostrarTentativas(int tentativas) const
{
    cout << "Tentativas Atuais: " << tentativas << endl;
}

void MenorOuMaiorView::mostrarResultadoFinal(int tentativas, int recorde) const
{
    cout << "=========== Parabens ===========" << tentativas << endl;
    cout << "Acertaste o numero secreto!" << endl;
    cout << "Tentativas: " << tentativas << endl;

    if (tentativas < recorde)
    {
        cout << "NOVO Recorde Pessoal!" << endl;
    }
    else
    {
        cout << "Recorde pessoal Atual: " << recorde << endl;
    }
}


void MenorOuMaiorView::mostrarAviso(const string& mensagem) const
{
    cout << "AVISO: " << mensagem << endl;
}
