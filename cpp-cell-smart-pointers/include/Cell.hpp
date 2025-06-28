#pragma once

#include "Nucleus.hpp"
#include "Mitochondrion.hpp"
#include "CellMembrane.hpp"
#include <vector>
#include <string>
#include <memory>

/**
 * @class Cell
 * @brief Modela una célula biológica básica utilizando composición de objetos.
 * @details Una célula TIENE un núcleo, TIENE una membrana y TIENE mitocondrias.
 * Gestiona el estado y el comportamiento general de la célula.
 */
class Cell
{
    public:
        /**
        * @brief Construye un nuevo objeto Cell.
        * * @param name El nombre identificador del organismo al que pertenece la célula.
        * @param dna La secuencia de ADN para el núcleo de la célula.
        * @param mitochondriaCount El número inicial de mitocondrias en la célula.
        */
        Cell(const std::string& name, const std::string& dna, int mitochondriaCount);

        /**
        * @brief Simula un ciclo de vida de la célula.
        * @details Durante un ciclo, la célula produce y consume energía.
        */
        void liveOneCycle();

        /**
        * @brief Muestra el estado actual de la célula en la consola.
        */
        void printStatus() const;

    private:
        /// @brief El nombre del organismo.
        std::string organismName;
        
        /// @brief Puntero inteligente al único núcleo de la célula.
        std::unique_ptr<Nucleus> nucleus;

        /// @brief Puntero inteligente a la única membrana de la célula.
        std::unique_ptr<CellMembrane> membrane;

        /// @brief Un vector que contiene todas las mitocondrias de la célula.
        std::vector<Mitochondrion> mitochondria;

        /// @brief El nivel de energía actual de la célula.
        int energyLevel;
};