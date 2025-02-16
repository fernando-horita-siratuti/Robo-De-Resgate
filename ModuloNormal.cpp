#include "ModuloNormal.hpp"
#include <iostream>

ModuloNormal::ModuloNormal(char tipo) : Modulo(tipo){}
ModuloNormal::ModuloNormal(){}

char ModuloNormal::getTipo() const{
    return tipo;
}
bool ModuloNormal::podeAcessar() const{
    return true;
}
void ModuloNormal::setTipo(char tipo){
    this->tipo = tipo;
}