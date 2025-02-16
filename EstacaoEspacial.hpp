#pragma once
#include <string>
#include <vector>
#include "Astronauta.hpp"
#include "Modulo.hpp"
#include "ModuloComAstronauta.hpp"
#include "ModuloComFogo.hpp"
#include "ModuloNormal.hpp"
#include "ModuloObstaculo.hpp"
#include "ModuloSeguranca.hpp"
#include "ModuloVazio.hpp"

class EstacaoEspacial{
    protected:
        std::vector<std::vector<Modulo*>> matriz;
        std::vector<Astronauta> astronautas;
        int linhas, colunas;

    public:
        EstacaoEspacial(int linhas, int colunas);

        void addModulo(int linhas, int colunas, char modulo);
        void addAstronauta(Astronauta);
        std::vector<std::vector<Modulo*>> getMatriz();
        std::vector<Astronauta>& getAstronautas();
        int getLinhas();
        int getColunas();
};