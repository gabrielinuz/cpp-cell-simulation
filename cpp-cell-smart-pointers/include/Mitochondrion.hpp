#pragma once

/**
 * @class Mitochondrion
 * @brief Representa una mitocondria, el orgánulo productor de energía.
 * @details Su función principal es simular la producción de ATP (energía).
 */
class Mitochondrion 
{
    public:
        /**
        * @brief Construye un nuevo objeto Mitochondrion.
        */
        Mitochondrion();

        /**
        * @brief Simula la producción de energía (ATP).
        * * @return int La cantidad de energía producida en un ciclo.
        */
        int produceATP() const;
};