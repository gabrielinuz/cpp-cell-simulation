#include "Nucleus.hpp"

Nucleus::Nucleus(const std::string& dnaSequence) : dna(dnaSequence) 
{
    // El inicializador de la lista de miembros ya asigna el valor de dna.
}

const std::string& Nucleus::getGeneticInformation() const 
{
    return dna;
}