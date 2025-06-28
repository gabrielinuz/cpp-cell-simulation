#pragma once

#include "Nucleus.hpp"
#include "Mitochondrion.hpp"
#include "CellMembrane.hpp"
#include <vector>
#include <string>
// Se elimina <memory> ya que no usaremos punteros inteligentes.

/**
 * @class Cell
 * @brief Modela una célula biológica con gestión manual de memoria.
 * @details Muestra cómo construir y destruir objetos componentes explícitamente
 * usando punteros crudos y el destructor de la clase contenedora.
 */
class Cell
{
    public:
        /**
        * @brief Construye un nuevo objeto Cell, reservando memoria para sus componentes.
        * * @param name El nombre identificador del organismo al que pertenece la célula.
        * @param dna La secuencia de ADN para el núcleo de la célula.
        * @param mitochondriaCount El número inicial de mitocondrias en la célula.
        */
        Cell(const std::string& name, const std::string& dna, int mitochondriaCount);

        /**
        * @brief Destruye el objeto Cell, liberando la memoria de todos sus componentes.
        */
        ~Cell(); // <-- CAMBIO: Añadimos un destructor explícito.

        /**
        * @brief Simula un ciclo de vida de la célula.
        */
        void liveOneCycle();

        /**
        * @brief Muestra el estado actual de la célula en la consola.
        */
        void printStatus() const;

        // --- Regla de los Tres/Cinco: Deshabilitamos la copia ---
        // Prevenimos que la célula se pueda copiar para evitar problemas de doble liberación de memoria.
        Cell(const Cell&) = delete;
        Cell& operator=(const Cell&) = delete;

    private:
        /// @brief El nombre del organismo.
        std::string organismName;
        
        /// @brief Puntero crudo al único núcleo de la célula.
        Nucleus* nucleus; // <-- CAMBIO: De std::unique_ptr<Nucleus> a Nucleus*

        /// @brief Puntero crudo a la única membrana de la célula.
        CellMembrane* membrane; // <-- CAMBIO: De std::unique_ptr<CellMembrane> a CellMembrane*

        /// @brief Un vector que contiene punteros a todas las mitocondrias de la célula.
        std::vector<Mitochondrion*> mitochondria; // <-- CAMBIO: Ahora es un vector de punteros.

        /// @brief El nivel de energía actual de la célula.
        int energyLevel;
};