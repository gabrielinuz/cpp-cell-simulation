#pragma once
#include <string>

/**
 * @class Nucleus
 * @brief Representa el núcleo de una célula, que contiene el material genético.
 * @details Almacena la secuencia de ADN y provee acceso a ella.
 */
class Nucleus 
{
    public:
        /**
        * @brief Construye un nuevo objeto Nucleus.
        * * @param dnaSequence La secuencia de ADN que contendrá este núcleo.
        */
        Nucleus(const std::string& dnaSequence);

        /**
        * @brief Obtiene la información genética almacenada.
        * * @return const std::string& Una referencia constante a la secuencia de ADN.
        */
        const std::string& getGeneticInformation() const;

    private:
        /// @brief Secuencia de ADN almacenada como una cadena de texto.
        std::string dna;
        int cianina;
};