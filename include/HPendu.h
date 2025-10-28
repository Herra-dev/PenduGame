#ifndef HPENDU_H
#define HPENDU_H

#include "Game.h"
#include <QChar>


class HPendu: public Game
{
public:
    /***********************************************/
    //CONSTRUCTEUR(S) et DESTRUCTEUR(S)

    HPendu();//Constructeur
    ~HPendu();//Destructeur

    //FIN CONSTRUCTEUR(S) et DESTRUCTEUR(S)
    /***********************************************/


    /***********************************************/
    //GETTERS et SETTERS

    QChar get_m_lettreEntree() const;
    void set_m_lettreEntree(QChar p_lettre);

    //FIN GETTERS et SETTERS
    /***********************************************/


    /***********************************************/
    bool verifierLettreEntree() const;
    void changerMotTrouve();

    //MÉTHODES VIRTUELLES HÉRITÉES DE la classe Game
    void nbrCoups();

protected:
    QChar *m_lettreEntree;

};

#endif // HPENDU_H
