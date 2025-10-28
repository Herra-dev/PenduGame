#ifndef GAME_H
#define GAME_H

#include "HObject.h"
#include <QString>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>

class Game
{
public:
    /***********************************************/
    //CONSTRUCTEUR(S) et DESTRUCTEUR(S)

    Game(QString p_langue = "France");//Constructeur
    virtual ~Game();//Destructeur

    //FIN CONSTRUCTEUR(S) et DESTRUCTEUR(S)
    /***********************************************/





    /***********************************************/
    //GETTERS et SETTERS

    QString get_m_langueDossier() const;
    void set_m_langueDossier(QString p_dossier);

    QString get_m_langueChoisie() const;
    void set_m_langueChoisie(QString p_langue);

    QString get_m_motPioche() const;
    void set_m_motPioche(QString p_pioche);

    QString get_m_motTrouve() const;
    void set_m_motTrouve(QString p_trouve);

    int get_m_nbrCoups() const;
    void set_m_nbrCoups(int p_coups);

    int get_m_niveau() const;
    void set_m_niveau(int p_niveau);

    //FIN GETTERS et SETTERS
    /***********************************************/

    /***********************************************/
    void piocherMotHasard();
    int nbrMotDansLangue();
    void initialiserMotTrouve(int nbrLettre = 0);
    bool verifierMotPiocheTrouve() const;
    void demanderLangue(); //pas fini
    void listerLangue();
    void calculerCoups();

    //MÉTHODES VIRTUELLES
    /***********************************************/
    virtual void nbrCoups() = 0; //virtuelle pure

protected:
    //
    QString *m_langueDossier;
    QString *m_langueChoisie;
    QString *m_motPioche;
    QString *m_motTrouve;
    int *m_niveau;
    int *m_nbrCoups;
public:
    std::vector <std::string> m_langueDisponible;


};

#endif // GAME_H
