#pragma once
#include <string>
#include <vector>

class Astronauta{
    protected:
        std::string nome;
        bool atendimentoUrgente;
        int x, y, nivelSaude;

    public:
        Astronauta(std::string nome, bool atendimentoUrgente, int nivelSaude, int x, int y);

        int getX();
        int getY();
        std::string getNome();
        int getNivelSaude();
        bool getAtendimentoUrgente();
        void setX(int x);
        void setY(int y);
};