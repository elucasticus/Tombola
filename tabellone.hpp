#ifndef TOMBOLA_TABELLONE
#define TOMBOLA_TABELLONE

#include <iostream>
#include <stdexcept>
#include <vector>

namespace Tombola {
class Tabellone {
private:
    std::vector<unsigned int> m_numeri;
    std::vector<bool> m_output_terminale;
    unsigned int m_dim;
    unsigned int m_index = 0;

public:
    Tabellone(const unsigned int& t_dim);

    void stampa_tabellone() const;

    void stampa_numeri() const;

    void estrai_numero();

    bool controlla_sequenza(const std::vector<unsigned int>& t_indici) const;
};
} // namespace Tombola

#endif // TOMBOLA_TABELLONE
