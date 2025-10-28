#include "HPendu.h"

/**
 * @brief HPendu::HPendu constructeur
 */
HPendu::HPendu(): Game(),
    m_lettreEntree(nullptr)
{
    m_lettreEntree = new QChar;

}

/**********************************************/

/**
 * @brief HPendu::~HPendu destructeur
 */
HPendu::~HPendu()
{
    delete m_lettreEntree;
    m_lettreEntree = nullptr;

    std::cout << "HPendu détruit" << std::endl;
}

/**********************************************/
//GETTERS et SETTERS

/**
 * @brief HPendu::get_m_lettreEntree
 * @return *m_lettreEntree QChar
 */
QChar HPendu::get_m_lettreEntree() const
{
    return *m_lettreEntree;
}

/**********************************************/

/**
 * @brief HPendu::set_m_lettreEntree
 * @param p_lettre QChar
 */
void HPendu::set_m_lettreEntree(QChar p_lettre)
{
    *m_lettreEntree = p_lettre;
}

//FIN GETTERS et SETTERS
/***********************************************/


/***********************************************/

/**
 * @brief HPendu::verifierLettreEntree
 * @return bool
 *
 * Vérifie si le mot pioché contient la lettre entrée
 */
bool HPendu::verifierLettreEntree() const
{
    return (m_motPioche->contains(*m_lettreEntree, Qt::CaseSensitive));
}

/***********************************************/

/**
 * @brief HPendu::changerMotTrouve
 *
 * Change le mot trouvé
 * Comment ça marche?
 * --1-- Vérifie si le mot pioché contient la lettre entrée:
 *          - true:
 *              cherche l'index où le caractère du mot pioché est la même que le caractère entré
 *              remplace le caractère à cet index par le caractère entré dans le mot trouvé
 *          - false:
 *              decrémente le coups du joueur(euse)
 */
void HPendu::changerMotTrouve()
{
    if(verifierLettreEntree())
    {
        std::cout << "Occurence: " << m_motPioche->count(*m_lettreEntree) << std::endl;

        for(int i(0); i < m_motPioche->size(); i++)
        {
            m_motTrouve->replace(m_motPioche->indexOf(*m_lettreEntree, i, Qt::CaseSensitive), 1, *m_lettreEntree);
        }


        std::cout << "Mot trouvé: " << m_motTrouve->toStdString() << std::endl;
    }
    else
    {
        set_m_nbrCoups(--*m_nbrCoups);
        return;
    }
}

/***********************************************/

void HPendu::nbrCoups()
{

}
