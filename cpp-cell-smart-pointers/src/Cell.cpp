#include "Cell.hpp"
#include <iostream>

Cell::Cell(const std::string& name, const std::string& dna, int mitochondriaCount)
    : organismName(name),
      energyLevel(20) // Inicia con un nivel de energía base.
{
    // Usamos std::make_unique para crear los componentes, asegurando una gestión de memoria segura.
    nucleus = std::make_unique<Nucleus>(dna);
    membrane = std::make_unique<CellMembrane>();

    // Creamos el número especificado de mitocondrias y las añadimos al vector.
    for (int i = 0; i < mitochondriaCount; ++i) 
    {
        mitochondria.push_back(Mitochondrion());
    }
}

void Cell::liveOneCycle() 
{
    std::cout << "\n-> Iniciando ciclo de vida para " << organismName << "..." << std::endl;

    // 1. La membrana regula los nutrientes.
    membrane->regulateTransport();

    // 2. Cada mitocondria produce energía (ATP).
    int producedEnergy = 0;
    for (const auto& mito : mitochondria) 
    {
        producedEnergy += mito.produceATP();
    }
    std::cout << "    [Mitocondrias] Energía producida en este ciclo: " << producedEnergy << " ATP." << std::endl;
    energyLevel += producedEnergy;

    // 3. La célula consume energía para vivir.
    int consumedEnergy = 5 + mitochondria.size(); // El costo de vida aumenta con más orgánulos.
    energyLevel -= consumedEnergy;
    std::cout << "    [Metabolismo] Energía consumida: " << consumedEnergy << " ATP." << std::endl;

    // 4. El núcleo realiza sus funciones (simulado).
    std::cout << "    [Nucleo] Leyendo instrucciones del ADN: " 
              << nucleus->getGeneticInformation().substr(0, 10) << "..." << std::endl;

    std::cout << "-> Ciclo de vida completado." << std::endl;
}

void Cell::printStatus() const 
{
    std::cout << "========================================" << std::endl;
    std::cout << "Estado de la Célula: " << organismName << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "  Nivel de Energía: " << energyLevel << " ATP" << std::endl;
    std::cout << "  Cantidad de Mitocondrias: " << mitochondria.size() << std::endl;
    std::cout << "  Fragmento de ADN: " << nucleus->getGeneticInformation().substr(0, 20) << "..." << std::endl;
    std::cout << "========================================" << std::endl;
}