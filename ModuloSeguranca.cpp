#include "ModuloSeguranca.hpp"
#include <iostream>

ModuloSeguranca::ModuloSeguranca(char tipo) : Modulo(tipo){}
ModuloSeguranca::ModuloSeguranca(){}

char ModuloSeguranca::getTipo() const{
    return tipo;
}
bool ModuloSeguranca::podeAcessar() const{
    return true;
}
void ModuloSeguranca::setTipo(char tipo){
    this->tipo = tipo;
}