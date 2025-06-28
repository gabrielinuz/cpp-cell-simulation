#include "Cell.hpp"
#include <iostream>

// --- IMPLEMENTACIÓN DEL CONSTRUCTOR ---
Cell::Cell(const std::string& name, const std::string& dna, int mitochondriaCount)
    : organismName(name),
      nucleus(nullptr),   // <-- CAMBIO: Buena práctica inicializar punteros a nullptr.
      membrane(nullptr),  // <-- CAMBIO: Buena práctica inicializar punteros a nullptr.
      energyLevel(20)
{
    // Usamos 'new' para reservar memoria manualmente para cada componente.
    nucleus = new Nucleus(dna);     // <-- CAMBIO: De std::make_unique a new
    membrane = new CellMembrane();  // <-- CAMBIO: De std::make_unique a new

    // Creamos el número especificado de mitocondrias en el heap.
    for (int i = 0; i < mitochondriaCount; ++i)
    {
        mitochondria.push_back(new Mitochondrion()); // <-- CAMBIO: Guardamos un nuevo puntero.
    }
}

// --- IMPLEMENTACIÓN DEL DESTRUCTOR ---
Cell::~Cell() 
{
    std::cout << "\n*** Destructor de Cell '" << organismName << "' llamado. Liberando memoria... ***" << std::endl;

    // 1. Liberamos la memoria de los componentes individuales.
    delete nucleus;
    std::cout << "    - Memoria del Nucleo liberada." << std::endl;
    delete membrane;
    std::cout << "    - Memoria de la Membrana liberada." << std::endl;

    // 2. Iteramos sobre el vector para liberar cada mitocondria.
    for (Mitochondrion* mito : mitochondria)
    {
        delete mito;
    }
    std::cout << "    - Memoria de " << mitochondria.size() << " Mitocondrias liberada." << std::endl;

    // El vector 'mitochondria' en sí se limpiará automáticamente porque no es un puntero.
}

void Cell::liveOneCycle()
{
    std::cout << "\n-> Iniciando ciclo de vida para " << organismName << "..." << std::endl;

    // La sintaxis para acceder a los miembros a través de punteros (->) no cambia.
    membrane->regulateTransport();

    int producedEnergy = 0;
    // <-- CAMBIO: Iteramos sobre punteros, la sintaxis de llamada '->' es la misma.
    for (const Mitochondrion* mito : mitochondria)
    { 
        producedEnergy += mito->produceATP();
    }
    std::cout << "    [Mitocondrias] Energía producida en este ciclo: " << producedEnergy << " ATP." << std::endl;
    energyLevel += producedEnergy;

    int consumedEnergy = 5 + mitochondria.size();
    energyLevel -= consumedEnergy;
    std::cout << "    [Metabolismo] Energía consumida: " << consumedEnergy << " ATP." << std::endl;

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