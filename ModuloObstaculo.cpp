#include "ModuloObstaculo.hpp"
#include <iostream>

ModuloObstaculo::ModuloObstaculo(char tipo) : Modulo(tipo){}
ModuloObstaculo::ModuloObstaculo(){}

char ModuloObstaculo::getTipo() const{
    return tipo;
}
bool ModuloObstaculo::podeAcessar() const{
    return false;
}
void ModuloObstaculo::setTipo(char tipo){
    this->tipo = tipo;
}