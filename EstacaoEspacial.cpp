#include "EstacaoEspacial.hpp"
#include <vector>
#include <iostream>
#include <stdlib.h>

EstacaoEspacial::EstacaoEspacial(int linhas, int colunas) : linhas(linhas), colunas(colunas){
    matriz.resize(linhas, std::vector<Modulo*>(colunas, nullptr));
}

void EstacaoEspacial::addModulo(int linha, int coluna, char modulo){
    if(modulo == 'A'){
        matriz[linha][coluna] = new ModuloComAstronauta(modulo);
    } 
    else if(modulo == 'F'){
        matriz[linha][coluna] = new ModuloComFogo(modulo);
    }
    else if(modulo == '.'){
        matriz[linha][coluna] = new ModuloNormal(modulo);
    }
    else if(modulo == '#'){
        matriz[linha][coluna] = new ModuloObstaculo(modulo);
    }
    else if(modulo == 'S'){
        matriz[linha][coluna] = new ModuloSeguranca(modulo);
    }
    else if(modulo == '~'){
        matriz[linha][coluna] = new ModuloVazio(modulo);
    }
    else{
        std::cerr << "Caractere inválido. Encerrando o programa.\n";
        exit(0);
    }
}
void EstacaoEspacial::addAstronauta(Astronauta astronauta){
    astronautas.push_back(astronauta);
}
std::vector<std::vector<Modulo*>> EstacaoEspacial::getMatriz(){
    return matriz;
}
std::vector<Astronauta>& EstacaoEspacial::getAstronautas(){
    return astronautas;
}
int EstacaoEspacial::getLinhas(){
    return linhas;
}
int EstacaoEspacial::getColunas(){
    return colunas;
}