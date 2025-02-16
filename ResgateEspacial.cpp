#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cctype>
#include <sstream>
#include "Astronauta.hpp"
#include "EstacaoEspacial.hpp"
#include "Modulo.hpp"
#include "ModuloComAstronauta.hpp"
#include "ModuloComFogo.hpp"
#include "ModuloNormal.hpp"
#include "ModuloObstaculo.hpp"
#include "ModuloSeguranca.hpp"
#include "RoboDeResgate.hpp"

int main(){
    for(int i = 1; i <= 5; i++){
        int numLinha, numColuna, linha = 0, coluna = 0, linhaRobo, colunaRobo, cont = 0, linhasLidas = 0, astronautas = 0;
        std::string linhaLeitura;

        std::string nomeArquivo = "entrada" + std::to_string(i) + ".txt";
        std::ifstream entrada(nomeArquivo);
        
        if(!entrada){
            std::cerr << "Não foi possível abrir o arquivo de entrada: '" << nomeArquivo << "'. Encerrando o programa.\n";
            return -1;
        }

        std::cout << "\n- - - - - " << i << "° matriz - - - - - \n\n";
        
        entrada >> numLinha >> numColuna;
        EstacaoEspacial estacaoEspacial(numLinha, numColuna);

        std::getline(entrada, linhaLeitura);
        
        while(std::getline(entrada, linhaLeitura)){
            if(linhaLeitura.find("Astronautas:") != std::string::npos){
                break;
            }
            if(linhasLidas >= numLinha){
                std::cerr << "Erro: Mais linhas encontradas do que o especificado em " << nomeArquivo << ". Encerrando o programa.\n";
                return -1;
            }
            if(linhaLeitura.length() != numColuna){
                std::cerr << "Erro: Número de colunas incorreto na linha " << linhasLidas + 1 << " do arquivo " << nomeArquivo << ". Encerrando o programa.\n";
                return -1;
            }
            for(char ch : linhaLeitura){
                ch = toupper(ch);
                if(ch == '\n' || ch == ' '){
                    continue;
                }
                else if(ch == 'S'){
                    linhaRobo = linha;
                    colunaRobo = coluna;
                    cont++;
                }
                else if(ch == 'A'){
                    astronautas++;
                }
                estacaoEspacial.addModulo(linha, coluna, ch);
                coluna++;
                if(coluna == numColuna){
                    coluna = 0;
                    linha++;
                }
            }
            linhasLidas++;
        }
        
        if(linhasLidas != numLinha){
            std::cerr << "Erro: Número de linhas lido diferente do especificado no arquivo " << nomeArquivo << ". Encerrando o programa.\n";
            return -1;
        }
        if(cont == 0){
            std::cout << "Nenhum robô de resgate foi encontrado na estação espacial do arquivo " << nomeArquivo << ". Encerrando o programa.\n";
            return -1;
        }
        
        RoboDeResgate roboDeResgate(linhaRobo, colunaRobo, estacaoEspacial);
        std::string nome;
        int nivelSaude, x, y;
        bool atendimentoUrgente;
        auto matriz = estacaoEspacial.getMatriz();
        
        while(std::getline(entrada, linhaLeitura)){
            if(linhaLeitura.empty()){
                continue;
            }
            if(linhaLeitura.find("Posições dos astronautas na matriz:") != std::string::npos){
                break;
            }
            std::stringstream ss(linhaLeitura);
            std::getline(ss, nome, ',');
            ss >> nivelSaude;
            ss.ignore(1, ',');
            ss >> atendimentoUrgente;
            
            Astronauta astronauta(nome, atendimentoUrgente, nivelSaude, 0, 0);
            estacaoEspacial.addAstronauta(astronauta);
        }
        
        while(std::getline(entrada, linhaLeitura)){
            if(linhaLeitura.empty()){
                continue;
            }
            std::stringstream ss(linhaLeitura);
            std::getline(ss, nome, ':');
            ss.ignore(2, '(');
            ss >> x;
            ss.ignore(1, ',');
            ss >> y;
            ss.ignore(1, ')');
            
            if(matriz[x][y]->getTipo() != 'A'){
                std::cout << "Posição inválida para o astronauta: " << nome << " no arquivo " << nomeArquivo << ". Encerrando o programa.\n";
                return -1;
            }
            
            bool encontrado = false;
            for(auto &astronauta : estacaoEspacial.getAstronautas()){
                if(astronauta.getNome() == nome){
                    astronauta.setX(x);
                    astronauta.setY(y);
                    encontrado = true;
                    break;
                }
            }
            
            if(!encontrado){
                std::cout << "Astronauta " << nome << " não foi encontrado na estação espacial do arquivo " << nomeArquivo << ". Encerrando o programa.\n";
                return -1;
            }
        }
        if(estacaoEspacial.getAstronautas().size() != astronautas){
            std::cout << "Número de astronautas informados não condiz com o número de astronautas na matriz. Encerrando o programa.\n";
            return -1;
        }
        std::string nomeArquivoSaida = "saida" + std::to_string(i) + ".txt";
        
        roboDeResgate.iniciarResgate();
        roboDeResgate.registrarRelatorio(nomeArquivoSaida);
        entrada.close();
    }
    
    return 0;
}