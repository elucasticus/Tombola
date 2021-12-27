#include "tabellone.hpp"
#include <algorithm>
#include <random>

namespace Tombola {
Tabellone::Tabellone(const unsigned int& t_dim)
    : m_dim(t_dim)
{
    for (unsigned int i = 0; i < m_dim; ++i) {
        m_output_terminale.push_back(0);
        m_numeri.push_back(i);
    }
    auto rng = std::default_random_engine {};
    std::shuffle(m_numeri.begin(), m_numeri.end(), rng);
}

void Tabellone::stampa_numeri() const
{
    for (auto& e : m_numeri) {
        std::cout << e << std::endl;
    }
}

void Tabellone::stampa_tabellone() const
{
    for (unsigned int i = 0; i < m_dim; ++i) {
        if (!m_output_terminale[i]) {
            std::cout << "-\t";
        } else {
            std::cout << (i + 1) << "\t";
        }
        if ((i + 1) % 10 == 0) {
            std::cout << std::endl;
        }
    }
}

void Tabellone::estrai_numero()
{
    std::cout << "Numero " << m_numeri[m_index] + 1 << std::endl;
    m_output_terminale[m_numeri[m_index]] = 1;
    m_index++;
}

bool Tabellone::controlla_sequenza(const std::vector<unsigned int>& t_indici) const
{
    for (auto& e : t_indici) {
        if (e > m_dim) {
            throw std::out_of_range("index out of range");
        } else if (m_output_terminale[e - 1] == false) {
            return false;
        }
    }
    return true;
}
} // namespace Tombola
