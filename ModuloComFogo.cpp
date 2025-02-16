#include "ModuloComFogo.hpp"
#include <iostream>

ModuloComFogo::ModuloComFogo(char tipo) : Modulo(tipo){}
ModuloComFogo::ModuloComFogo(){}

char ModuloComFogo::getTipo() const{
    return tipo;
}
bool ModuloComFogo::podeAcessar() const{
    return false;
}
void ModuloComFogo::setTipo(char tipo){
    this->tipo = tipo;
}