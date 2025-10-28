#include "Game.h"

/**********************************************/

/**
 * @brief Game::Game constructeur
 * @param p_langue QString
 */
Game::Game(QString p_langue):
    m_langueDossier(new QString),
    m_langueChoisie(new QString),
    m_motPioche(new QString),
    m_motTrouve(new QString),
    m_niveau(new int),
    m_nbrCoups(new int)
{
    *m_langueDossier = "files/dictionnaires/";
    *m_langueChoisie = p_langue;//par défaut: francais
    *m_nbrCoups = 0;
}

/**********************************************/

/**
 * @brief Game::~Game destructeur
 */
Game::~Game()
{
    delete m_langueDossier;
    m_langueChoisie = nullptr;

    delete m_langueChoisie;
    m_langueChoisie = nullptr;

    delete m_motPioche;
    m_motPioche = nullptr;

    delete m_motTrouve;
    m_motTrouve = nullptr;

    delete m_nbrCoups;
    m_nbrCoups = nullptr;


    std::cout << "HGame détruit" << std::endl;
}

/**********************************************/
//GETTERS et SETTERS

/**
 * @brief Game::get_m_langueDossier
 * @return *m_langueDossier QString
 *
 * retourne le chemin vers le dossier des langues
 */
QString Game::get_m_langueDossier() const
{
    return *m_langueDossier;
}

/**********************************************/

/**
 * @brief Game::set_m_langueDossier
 * @param p_dossier QString
 *
 * change le chemin vers les langues
 */
void Game::set_m_langueDossier(QString p_dossier)
{
    *m_langueDossier = p_dossier;
}

/**********************************************/

/**
 * @brief Game::get_m_langueChoisie
 * @return *m_langueChoisie QString
 *
 * retourne la langue choisie
 */
QString Game::get_m_langueChoisie() const
{
    return *m_langueChoisie;
}

/**********************************************/

/**
 * @brief Game::set_m_langueChoisie
 * @param p_langue QString
 *
 * change la langue à jouer
 */
void Game::set_m_langueChoisie(QString p_langue)
{
    *m_langueChoisie = p_langue;
}

/**********************************************/

/**
 * @brief Game::get_m_motPioche
 * @return *m_motPioche QString
 *
 * retourne le mot pioché
 */
QString Game::get_m_motPioche() const
{
    return *m_motPioche;
}

/**********************************************/

/**
 * @brief Game::set_m_motPioche
 * @param p_pioche QString
 *
 * change le mot pioché
 */
void Game::set_m_motPioche(QString p_pioche)
{
    *m_motPioche = p_pioche;
}

/**********************************************/

/**
 * @brief Game::get_m_motTrouve
 * @return *m_motPioche QString
 *
 * retourne le mot pioché
 */
QString Game::get_m_motTrouve() const
{
    return *m_motTrouve;
}

/***********************************************/

/**
 * @brief Game::set_m_motTrouve
 * @param p_trouve QString
 *
 * change le mot trouvé
 */
void Game::set_m_motTrouve(QString p_trouve)
{
    *m_motTrouve = p_trouve;
}

/***********************************************/

/**
 * @brief Game::get_m_nbrCoups
 * @return *m_nbrCoups int
 *
 * retourne le nombre de coups
 */
int Game::get_m_nbrCoups() const
{
    return *m_nbrCoups;
}

/***********************************************/

/**
 * @brief Game::set_m_nbrCoups
 * @param p_coups int
 *
 * change le nombre de coups
 */
void Game::set_m_nbrCoups(int p_coups)
{
    *m_nbrCoups = p_coups;
}

/***********************************************/

/**
 * @brief Game::get_m_niveau
 * @return *m_niveau int
 *
 * retourne le niveau du jeu
 */
int Game::get_m_niveau() const
{
    return *m_niveau;
}

/***********************************************/

/**
 * @brief Game::set_m_niveau
 * @param p_niveau
 *
 * change le niveau du jeu
 */
void Game::set_m_niveau(int p_niveau)
{
    *m_niveau = p_niveau;
}

//FIN GETTERS et SETTERS
/***********************************************/


/**********************************************/
/**
 * @brief Game::piocherMotHasard
 *
 * fonction qui sert à piocher un mot au hasard dans le dictionnaire:
 * *** Comment ça marche?
 * --1-- D'abord, elle vide les objets contenant les mots:-> pioché et trouvé
 * --2-- Ensuite, elle essaye d'ouvir le fichier de langue:
 *          - Succès: pioche un mot
 *          - Echècs: met la langue en français puis réessaye
 * --3-- Initalise le mot trouvé de même taille que le mot pioché avec des étoiles
 */
void Game::piocherMotHasard()
{
    if(!(m_motPioche->isEmpty()))
    {
        m_motPioche->clear();
        m_motTrouve->clear();
    }

    std::string motPioche("");
    QString chemin(*m_langueDossier + *m_langueChoisie);
    std::ifstream monFluxIn(chemin.toStdString().c_str());

    if(monFluxIn)
    {
        int nbrMot(nbrMotDansLangue());
        int nbrHasard(HObject::genereNombreHasard(nbrMot));
        int i(0);
        while(std::getline(monFluxIn, motPioche))
        {
            if(i == nbrHasard)
            {
                break;
            }

            i++;
        }
        if(std::getline(monFluxIn, motPioche))
        {
            *m_motPioche = motPioche.c_str();
            initialiserMotTrouve(m_motPioche->size());
            std::cout << "Mot pioché: " << get_m_motPioche().toStdString() << std::endl;
            return;
        }
    }
    else
    {
        std::cout << "Impossible d'ouvrir le fichier" << std::endl;
        set_m_langueChoisie("France");
        piocherMotHasard();
    }
}

/**********************************************/

/**
 * @brief Game::nbrMotDansLangue
 * @return nombreMot int
 *
 * retourne le nombre de mot dans le fichier de langue
 */
int Game::nbrMotDansLangue()
{
    QString chemin(*m_langueDossier + *m_langueChoisie);
    std::ifstream monFluxIn(chemin.toStdString().c_str());
    std::cout << "chemin: " << chemin.toStdString() << std::endl;

    if(monFluxIn)
    {
        std::cout << "fichier ouvert" << std::endl;
        std::string temp;
        int nombreMot(0);

        while(std::getline(monFluxIn, temp))
        {
            nombreMot++;
        }

        return nombreMot;
    }

    else
    {
        std::cout << "Impossible d'ouvir le fichier." << std::endl;
        return 1;
    }
}

/**********************************************/

/**
 * @brief Game::initialiserMotTrouve
 * @param nbrLettre int
 *
 * Initialise le mot trouvé avec des '*'
 */
void Game::initialiserMotTrouve(int nbrLettre)
{
    for(int i(0); i < nbrLettre; i++)
    {
        m_motTrouve->push_back('*');
    }
}

/**********************************************/

/**
 * @brief Game::verifierMotPiocheTrouve
 * @return bool
 *
 * Vérifie si le mot trouvé est égale au mot pioché(true s'il y a correspondance)
 */
bool Game::verifierMotPiocheTrouve() const
{
    return ((QString::compare(*m_motPioche, *m_motTrouve, Qt::CaseSensitive)) == 0);
}

/**********************************************/

void Game::demanderLangue()
{
    //On prend la langue dépuis une QComboBox
    //et on le met dans le m_langueChoisie
}

/**********************************************/

/**
 * @brief Game::listerLangue
 *
 * liste les langues disponible et les mette dans un tableau de langue
 */
void Game::listerLangue()
{
    #ifdef _WIN32
        system("dir /b files\\dictionnaires\\ > file\\langue.txt");
    #else
        system("ls files/dictionnaires/ > files/langue.txt");
    #endif // _WIN32

    std::string listeLangue("files/langue.txt");
    std::string langue;

    std::ifstream monFluxIn(listeLangue.c_str());

    m_langueDisponible.clear();

    if(monFluxIn)
    {
        while(std::getline(monFluxIn, langue))
        {
            m_langueDisponible.push_back(langue);
        }
    }
    else
    {
        std::cout << "Impossible d'ouvir le fichier de langue" << std::endl;
        return;
    }
}

/**********************************************/

/**
 * @brief Game::calculerCoups
 *
 * calcule le nombre de coups à partir du niveau choisi et la taille du mot pioché
 */
void Game::calculerCoups()
{
    switch (get_m_niveau()) {
    case 1:
        set_m_nbrCoups(get_m_motPioche().size() + 20);
        break;

    case 2:
        set_m_nbrCoups(get_m_motPioche().size() + 15);
        break;

    case 3:
        set_m_nbrCoups(get_m_motPioche().size() + 10);
        break;

    case 4:
        set_m_nbrCoups(get_m_motPioche().size() + 5);
        break;

    default:
        set_m_nbrCoups(get_m_motPioche().size() + 20);
        break;
    }
}
