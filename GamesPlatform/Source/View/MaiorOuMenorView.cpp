//
// Created by andre on 01/06/2026.
//

#include "../../Headers/View/MaiorOuMenorView.h"
#include <iostream>

using namespace std;

void MaiorOuMenorView::mostrarInstrucoes() const
{
    cout << "\n========================================" << endl;
    cout << "           MAIOR OU MENOR                 " << endl;
    cout << "========================================" << endl;
    cout << "REGRAS:" << endl;
    cout << "- Deve adivinhar um numero aleatorio de 1 a 100" << endl;
    cout << "- Serao contadas as tentativas que precisou para acertar" << endl;
}

int MaiorOuMenorView::pedirPalpite() const
{
    int palpite;
    cout << "Introduza o seu palpite: ";
    while (!(cin >> palpite))
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Erro! Introduza um palpite valido! \n";
        cout << "Introduza o seu palpite: ";
    }
    return palpite;
}

void MaiorOuMenorView::mostrarFeedbackPalpite(int estadojogo) const
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

void MaiorOuMenorView::mostrarTentativas(int tentativas) const
{
    cout << "Tentativas Atuais: " << tentativas << endl;
}

void MaiorOuMenorView::mostrarResultadoFinal(int tentativas, int recorde) const
{
    cout << "=========== Parabens ===========" << endl;
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

void MaiorOuMenorView::mostrarAviso(const string& mensagem) const
{
    cout << "AVISO: " << mensagem << endl;
}
