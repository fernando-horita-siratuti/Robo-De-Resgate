#include "RoboDeResgate.hpp"
#include <vector>
#include <queue>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <cctype>
#include <algorithm>

RoboDeResgate::RoboDeResgate(int posicaoInicialX, int posicaoInicialY, EstacaoEspacial& estacaoEspacial) : posicaoInicialX(posicaoInicialX), posicaoInicialY(posicaoInicialY), estacaoEspacial(estacaoEspacial){}

void RoboDeResgate::iniciarResgate(){
    int linhas = estacaoEspacial.getLinhas();
    int colunas = estacaoEspacial.getColunas();

    int iniX = this->posicaoInicialX;
    int iniY = this->posicaoInicialY;

    auto matriz = estacaoEspacial.getMatriz();
    bool encontrado = false;
    
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    while(true){
        std::vector<Posicao> caminho = {};
        std::vector<std::vector<Posicao>> anterior(linhas, std::vector<Posicao>(colunas, {-1, -1}));
        std::vector<std::vector<bool>> visitado(linhas, std::vector<bool>(colunas, false));
        std::queue<std::pair<int, int>> fila;

        fila.push({iniX, iniY});
        visitado[iniX][iniY] = true;
        Posicao destino = {-1, -1};

        while(!fila.empty() && !encontrado){
            int x = fila.front().first;
            int y = fila.front().second;
            int nx, ny;
            fila.pop();

            if(matriz[x][y]->getTipo() == 'A' && !proximoAoFogo(x, y)){
                for(auto& astronauta : estacaoEspacial.getAstronautas()){
                    if(astronauta.getX() == x && astronauta.getY() == y){
                        RoboDeResgate::resgatarAstronauta(astronauta);
                        destino = {x, y};
                        matriz[x][y]->setTipo('G');
                        encontrado = true;
                        break;
                    }
                }
            }

            for(int i = 0; i < 4; i++){ 
                nx = x + dx[i];
                ny = y + dy[i];
                
                if(nx >= 0 && nx < linhas && ny >= 0 && ny < colunas && !visitado[nx][ny]){
                    char tipo = matriz[nx][ny]->getTipo();
                    if(tipo != '#' && tipo != 'F' && tipo != '~' && !proximoAoFogo(nx, ny)){
                        visitado[nx][ny] = true;
                        anterior[nx][ny] = {x, y};
                        fila.push({nx, ny});
                    }
                }
            }
        }

        if(!encontrado){
            destino = {posicaoInicialX, posicaoInicialY};
            for(Posicao p = destino; p.x != -1 && p.y != -1; p = anterior[p.x][p.y]){
                caminho.push_back(p);
            }
            reverse(caminho.begin(), caminho.end());
    
            imprimirCaminho(caminho);
            break;
        }

        for(Posicao p = destino; p.x != -1 && p.y != -1; p = anterior[p.x][p.y]){
            caminho.push_back(p);
        }
        reverse(caminho.begin(), caminho.end());

        imprimirCaminho(caminho);

        if(!caminho.empty()){ 
            iniX = caminho.back().x;
            iniY = caminho.back().y;
        }
        encontrado = false;
    }

    for(auto& astronauta1 : estacaoEspacial.getAstronautas()){
        int verifica = 0;
        for(auto& astronauta2 : resgatados){
            if(astronauta1.getX() == astronauta2.getX() && astronauta1.getY() == astronauta2.getY()){
                verifica++;
                break;
            }
        }
        if(verifica == 0){
            naoResgatados.push_back(astronauta1);
        }
    }
}

void RoboDeResgate::imprimirCaminho(std::vector<Posicao> &caminhoDeRetorno){
    auto matriz = estacaoEspacial.getMatriz();
    int linhas = estacaoEspacial.getLinhas();
    int colunas = estacaoEspacial.getColunas();
    std::vector<std::vector<bool>> caminhoPercorrido(linhas, std::vector<bool>(colunas, false));
    for(const auto& posicao : caminhoDeRetorno){
        caminhoPercorrido[posicao.x][posicao.y] = true;
    }
    
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            if(i == caminhoDeRetorno.back().x && j == caminhoDeRetorno.back().y){
                std::cout << "R ";
            } 
            else if(caminhoPercorrido[i][j]){
                std::cout << "* ";
            } 
            else{
                if(matriz[i][j]->getTipo() == 'G'){
                    std::cout << "A ";
                }
                else{
                    std::cout << matriz[i][j]->getTipo() << " ";
                }
            }
        }
        std::cout << "\n";
    }
    passos += caminhoDeRetorno.size() - 1;
    std::cout << "\nQuantidade de astronautas resgatados até o momento: " << resgatados.size() << "\n";
    std::cout << "Passos: " << passos << "\n\n";
}

bool RoboDeResgate::proximoAoFogo(int posicaoX, int posicaoY){
    auto matriz = estacaoEspacial.getMatriz();
    int linhas = estacaoEspacial.getLinhas();
    int colunas = estacaoEspacial.getColunas();

    if(posicaoX + 1 < linhas && matriz[posicaoX + 1][posicaoY]->getTipo() == 'F'){
        return true;
    }
    if(posicaoX - 1 >= 0 && matriz[posicaoX - 1][posicaoY]->getTipo() == 'F'){
        return true;
    }
    if(posicaoY + 1 < colunas && matriz[posicaoX][posicaoY + 1]->getTipo() == 'F'){
        return true;
    }
    if(posicaoY - 1 >= 0 && matriz[posicaoX][posicaoY - 1]->getTipo() == 'F'){
        return true;
    }
    return false;
}

void RoboDeResgate::resgatarAstronauta(Astronauta astronauta){
    resgatados.push_back(astronauta);
}

void RoboDeResgate::registrarRelatorio(std::string arquivo){
    std::ofstream arquivoDeSaida(arquivo);

    if(!arquivoDeSaida.is_open()){
        std::cout << "Erro ao abrir o arquivo de saída.\n";
        return;
    }
    arquivoDeSaida << "- - - - - Relatório de resgate - - - - -\n\n";
    if(resgatados.size() > 0){
        arquivoDeSaida << "- Lista de astronautas resgatados: \n\n";
        arquivoDeSaida << "\t- Número de astronautas resgatados: " << resgatados.size() << "\n";
        for(int i = 0; i < resgatados.size(); i++){
            if(resgatados[i].getAtendimentoUrgente()){
                arquivoDeSaida << "\t- " << resgatados[i].getNome() << ": Saúde " <<  resgatados[i].getNivelSaude() << ", Atendimento médico urgente: Sim, Posição: (" << resgatados[i].getX() << ", " << resgatados[i].getY() << ")" << "\n";
            }
            else{
                arquivoDeSaida << "\t- " << resgatados[i].getNome() << ": Saúde " <<  resgatados[i].getNivelSaude() << ", Atendimento médico urgente: Não, Posição: (" << resgatados[i].getX() << ", " << resgatados[i].getY() << ")" << "\n";
            }
        }
    }
    if(naoResgatados.size() > 0){
        arquivoDeSaida << "\n- Lista de astronautas não resgatados: \n\n";
        for(int i = 0; i < naoResgatados.size(); i++){
            if(naoResgatados[i].getAtendimentoUrgente()){
                arquivoDeSaida << "\t- " << naoResgatados[i].getNome() << ": Saúde " <<  naoResgatados[i].getNivelSaude() << ", Atendimento médico urgente: Sim, Posição: (" << naoResgatados[i].getX() << ", " << naoResgatados[i].getY() << ")" << "\n";
            }
            else{
                arquivoDeSaida << "\t- " << naoResgatados[i].getNome() << ": Saúde " <<  naoResgatados[i].getNivelSaude() << ", Atendimento médico urgente: Não, Posição: (" << naoResgatados[i].getX() << ", " << naoResgatados[i].getY() << ")" << "\n";
            }
        }
    }
    arquivoDeSaida << "\n- Tempo total da operação de resgate: " << passos << " passos\n";
    arquivoDeSaida.close();
    std::cout << "- - - - - Relatório de resgate - - - - -\n\n";
    if(resgatados.size() > 0){
        std::cout << "- Lista de astronautas resgatados: \n\n";
        std::cout << "\t- Número de astronautas resgatados: " << resgatados.size() << "\n";
        for(int i = 0; i < resgatados.size(); i++){
            if(resgatados[i].getAtendimentoUrgente()){
                std::cout << "\t- " << resgatados[i].getNome() << ": Saúde " <<  resgatados[i].getNivelSaude() << ", Atendimento médico urgente: Sim, Posição: (" << resgatados[i].getX() << ", " << resgatados[i].getY() << ")" << "\n";
            }
            else{
                std::cout << "\t- " << resgatados[i].getNome() << ": Saúde " <<  resgatados[i].getNivelSaude() << ", Atendimento médico urgente: Não, Posição: (" << resgatados[i].getX() << ", " << resgatados[i].getY() << ")" << "\n";
            }
        }
    }
    if(naoResgatados.size() > 0){
        std::cout << "\n- Lista de astronautas não resgatados: \n\n";
        for(int i = 0; i < naoResgatados.size(); i++){
            if(naoResgatados[i].getAtendimentoUrgente()){
                std::cout << "\t- " << naoResgatados[i].getNome() << ": Saúde " <<  naoResgatados[i].getNivelSaude() << ", Atendimento médico urgente: Sim, Posição: (" << naoResgatados[i].getX() << ", " << naoResgatados[i].getY() << ")" << "\n";
            }
            else{
                std::cout << "\t- " << naoResgatados[i].getNome() << ": Saúde " <<  naoResgatados[i].getNivelSaude() << ", Atendimento médico urgente: Não, Posição: (" << naoResgatados[i].getX() << ", " << naoResgatados[i].getY() << ")" << "\n";
            }
        }
    }
    std::cout << "\n- Tempo total da operação de resgate: " << passos << " passos\n";
}   