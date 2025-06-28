#include "CellMembrane.hpp"
#include <iostream>

CellMembrane::CellMembrane() 
{
    // Constructor por defecto.
}

void CellMembrane::regulateTransport() const 
{
    // Simula la acción de la membrana imprimiendo un mensaje.
    std::cout << "    [Membrana] Regulando el paso de nutrientes..." << std::endl;
}