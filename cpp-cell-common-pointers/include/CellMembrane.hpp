#pragma once

/**
 * @class CellMembrane
 * @brief Representa la membrana celular, que controla el transporte de sustancias.
 */
class CellMembrane
{
    public:
        /**
        * @brief Construye un nuevo objeto CellMembrane.
        */
        CellMembrane();

        /**
        * @brief Simula la regulación del transporte de nutrientes a través de la membrana.
        */
        void regulateTransport() const;
};