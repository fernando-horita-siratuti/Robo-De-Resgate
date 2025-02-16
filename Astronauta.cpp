#include "Astronauta.hpp"
#include <vector>
#include <iostream>

Astronauta::Astronauta(std::string nome, bool atendimentoUrgente, int nivelSaude, int x, int y) : nome(nome), atendimentoUrgente(atendimentoUrgente), nivelSaude(nivelSaude), x(x), y(y){}
int Astronauta::getX(){
    return x;
}
int Astronauta::getY(){
    return y;
}
std::string Astronauta::getNome(){
    return nome;
}
int Astronauta::getNivelSaude(){
    return nivelSaude;
}
bool Astronauta::getAtendimentoUrgente(){
    return atendimentoUrgente;
}
void Astronauta::setX(int x){
    this->x = x;
}
void Astronauta::setY(int y){
    this->y = y;
}