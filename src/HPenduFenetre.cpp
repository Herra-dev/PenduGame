#include "HPenduFenetre.h"

/**
 * @brief HPenduFenetre::HPenduFenetre constructeur
 *
 * Comment ça fonctionne?
 * --1-- Paramétrage du Fenetre
 * --2-- Initialisation du pendu
 * --3-- Initialisation du Layout Principale
 *
 *
 * --4-- -  allocation des groupes et layouts(conteneurs) \-----
 *       -  allocation des widgets                         \  (a), (b), (c) et (d)
 *       -  configuration des widgets                       \
 *       -  ajout des widgets au layout                      \-----
 *       -  ajout du layout comme layout du groupe
 *       -  ajout du groupe au layout principale
 *       -  connection des widgets à des slots
 *
 *                   -- Groupe Options (a)
 *                  |
 *              ---- -- Groupe Déroulement (b)
 *                  |
 *                   -- Groupe Jeu (c)
 *                  |
 *                   -- Groupe Propos(d)
 *
 *
 * --5-- Définition du layout principale comme layout principale de la fenêtre
 */
HPenduFenetre::HPenduFenetre(): QWidget(),
    m_layoutPrincipale(nullptr),
    m_pendu(nullptr),
    m_groupOption(nullptr),
    m_gridLayoutOption(nullptr),
    m_formLayoutLangue(nullptr),
    m_labelLangue(nullptr),
    m_langue(nullptr),
    m_titreJeu(nullptr),
    m_formLayoutNiveauJeu(nullptr),
    m_labelNiveauJeu(nullptr),
    m_niveauJeu(nullptr),
    m_groupDeroulement(nullptr),
    m_gridLayoutDeroulement(nullptr),
    m_commencer(nullptr),
    m_quitter(nullptr),
    m_groupJeu(nullptr),
    m_gridLayoutJeu(nullptr),
    m_timer(nullptr),
    m_timeCompteur(nullptr),
    m_lcdNumberTimeCompteur(nullptr),
    m_lcdNumberNbrCoups(nullptr),
    m_labelMotTrouve(nullptr),
    m_labelEntreCaractere(nullptr),
    m_caractereEntree(nullptr),
    m_tester(nullptr),
    m_terminer(nullptr),
    m_groupePRA(nullptr),//=====
    m_layoutPRA(nullptr),//=====
    m_pauser(nullptr),
    m_reprendre(nullptr),
    m_checkCarSpeciaux(nullptr),
    m_groupJeuCarSpeciaux(nullptr),
    m_formLayoutCarSpeciaux(nullptr),
    m_regExpCarEntre(nullptr),
    m_validatorCarEntre(nullptr),
    m_groupePropos(nullptr),
    m_hBoxLayoutPropos(nullptr),
    m_commentJouer(nullptr),
    m_aProposHPendu(nullptr),
    m_aProposQt(nullptr)

{
    //propriétés de la fenêtre
    setWindowTitle("HPendu"); //titre
    setWindowIcon(QIcon("images/HPendu.png"));

    HPenduTip *tip;
    tip = new HPenduTip;
    tip->exec(); //On affiche le daily tip
    tip->deleteLater();

    //==========================================

    m_pendu = new HPendu;
    m_pendu->listerLangue();
    m_timeCompteur = new int;
    *m_timeCompteur = 240;

    /*************************************************************/
//LAYOUT PRINCIPALE

    m_layoutPrincipale = new QVBoxLayout(this);

    /*************************************************************/
//OPTIONS
{
    option_allocationGrpLayout();
    option_allocationWidget();
    option_configurationWidget();
    option_ajoutWidget();

    m_groupOption->setLayout(m_gridLayoutOption);
    m_layoutPrincipale->addWidget(m_groupOption);

    //** connection ** slots ** signals **//

QObject::connect(m_langue, SIGNAL(currentTextChanged(QString)), this, SLOT(slot_changerLanguePendu(QString)));
QObject::connect(m_niveauJeu, SIGNAL(valueChanged(int)), this, SLOT(slot_changerNiveauPendu(int)));
}
//FIN OPTIONS
    /*************************************************************/

    /*************************************************************/
//DEROULEMENTS
 {
    der_allocationGrpLayout();
    der_allocationWidget();
    der_configurationWidget();
    der_ajoutWidget();

    m_groupDeroulement->setLayout(m_gridLayoutDeroulement);
    m_layoutPrincipale->addWidget(m_groupDeroulement);

    //** connection ** slots ** signals **//

QObject::connect(m_commencer, SIGNAL(clicked(bool)), this, SLOT(slot_desactiverOptionCommencer()));
QObject::connect(m_quitter, SIGNAL(clicked(bool)), qApp, SLOT(quit()));
}
//FIN DEROULEMENTS
    /*************************************************************/

    /*************************************************************/
//JEU
{
    jeu_allocationGrpLayout();
    jeu_allocationWidget();
    jeu_configurationWidget();

    m_groupJeu->setLayout(m_gridLayoutJeu);
    m_layoutPrincipale->addWidget(m_groupJeu);

    m_groupJeu->setEnabled(false); //désactive par défaut

    //** connection ** slots ** signals **//

QObject::connect(m_checkCarSpeciaux, SIGNAL(stateChanged(int)), this, SLOT(slot_afficherCarSpeciaux(int)));
QObject::connect(m_tester, SIGNAL(clicked(bool)), this, SLOT(slot_testerCaractereEntre()));
QObject::connect(m_terminer, SIGNAL(clicked(bool)), this, SLOT(slot_activerOptionTerminer()));
QObject::connect(m_pauser, SIGNAL(clicked(bool)), this, SLOT(slot_pauserJeu()));
QObject::connect(m_reprendre, SIGNAL(clicked(bool)), this, SLOT(slot_reprendreJeu()));
}
//FIN JEU
    /*************************************************************/

    /*************************************************************/
//A-PROPOS
{
    propos_allocationGrpLayout();
    propos_allocationWidget();
    propos_configurationWidget();
    propos_ajoutWidget();

    m_groupePropos->setLayout(m_hBoxLayoutPropos);
    m_layoutPrincipale->addWidget(m_groupePropos);

    //** connection ** slots ** signals **//

QObject::connect(m_commentJouer, SIGNAL(clicked(bool)), this, SLOT(slot_afficherAide()));
QObject::connect(m_aProposHPendu, SIGNAL(clicked(bool)), this, SLOT(slot_afficherAProposPendu()));
QObject::connect(m_aProposQt, SIGNAL(clicked(bool)), this, SLOT(slot_afficherAProposQt()));
}
//FIN A-PROPOS
    /*************************************************************/

    setLayout(m_layoutPrincipale);
}

/*************************************************************/

/**
 * @brief HPenduFenetre::~HPenduFenetre destructeur
 *
 * Détruit les objets alloués dynamiquement
 */
HPenduFenetre::~HPenduFenetre()
{
    delete m_layoutPrincipale; //Désctruction du Layout Principale
    m_layoutPrincipale = nullptr;

    delete m_pendu; //Déstruction du Pendu
    m_pendu = nullptr;

    delete m_groupOption; //Déstruction du groupe option ainsi que ce qu'il contient
    m_groupOption = nullptr;

    delete m_groupDeroulement; //Déstruction du groupe déroulement ainsi que ce qu'il contient
    m_groupDeroulement = nullptr;

    delete m_groupJeu; //Déstruction du groupe jeu ainsi que ce qu'il contient
    m_groupJeu = nullptr;

    delete m_regExpCarEntre; //Déstruction du RegExp
    m_regExpCarEntre = nullptr;

    delete m_validatorCarEntre; //Déstruction du validator
    m_validatorCarEntre = nullptr;

    delete m_timer; //Déstruction du timer
    m_timer = nullptr;

    delete m_timeCompteur; //Déstruction du compteur
    m_timeCompteur = nullptr;

    std::cout << "HPenduFenetre détruit" << std::endl;
}

/*************************************************************/

/**
 * @brief HPenduFenetre::initialiserAffichageMotTrouve
 *
 * initialise l'affichage de mot trouvé dans des QLablel
 * Comment ça marche?
 * --1-- Détruit les labels, s'il y en a. puis vide le tableau conteneur
 * --2-- Construit des QLabels, en fonction de la taille du mot pioché, avec des '*'
 */
void HPenduFenetre::initialiserAffichageMotTrouve()
{
    int sizeTabLabel(m_affichageMotTrouve.size());

    std::cout << "size: " << m_affichageMotTrouve.size() << std::endl;

    for(int i(0); i < sizeTabLabel; i++)
    {
        delete m_affichageMotTrouve[i];
        m_affichageMotTrouve[i] = nullptr;
    }

    m_affichageMotTrouve.clear();

    std::cout << "size: " << m_affichageMotTrouve.size() << std::endl;

    int sizeMotPioche(m_pendu->get_m_motPioche().size());

    for(int i(0); i < sizeMotPioche; i++)
    {
        m_affichageMotTrouve.push_back(new QLabel("*"));
    }
    std::cout << "size: " << m_affichageMotTrouve.size() << std::endl;
}

/*************************************************************/

/**
 * @brief HPenduFenetre::initialiserCarSpeciaux
 *
 * Initialise les caractères spéciaux qui sont absents sur le clavier
 */
void HPenduFenetre::initialiserCarSpeciaux()
{
    //Libération des cases mémoires
    while(m_formLayoutCarSpeciaux->rowCount() > 0) //Tant qu'il y a une ligne, on l'éfface
        m_formLayoutCarSpeciaux->removeRow((m_formLayoutCarSpeciaux->rowCount())-1);

    m_stringCarSpeciaux.clear();
    m_labelCarSpeciaux.clear();
    m_comboBoxCarSpeciaux.clear();

    /**********************************************************/

    QString caractere("aeuio");

    //Initialisation des caractères spéciaux
    m_stringCarSpeciaux.push_back(new QString("äāâàáãåæ"));
    m_stringCarSpeciaux.push_back(new QString("ëēêèéėę"));
    m_stringCarSpeciaux.push_back(new QString("üūûùúũ"));
    m_stringCarSpeciaux.push_back(new QString("ïīîìíĩį"));
    m_stringCarSpeciaux.push_back(new QString("öōôòóõøœ"));

    //initialisation des QLabel et QComboBox
    int size(caractere.size());
    for(int i(0); i < size; i++)
    {
        m_comboBoxCarSpeciaux.push_back(new QComboBox);
        m_labelCarSpeciaux.push_back(new QLabel(caractere.at(i)));
    }

    //Ajout des items aux QComboBox
    for(int i(0); i < size; i++)
    {
        int sizeCar(m_stringCarSpeciaux[i]->size());
        for(int j(0); j < sizeCar; j++)
        {
            m_comboBoxCarSpeciaux[i]->addItem(m_stringCarSpeciaux[i]->at(j));
        }
    }

    //Configuration des QLabel et QComboBox
    for(int i(0); i < size; i++)
    {
        m_labelCarSpeciaux[i]->setFont(QFont("Arial", 15));

        m_comboBoxCarSpeciaux[i]->setFont(QFont("Arial", 15));
        m_comboBoxCarSpeciaux[i]->setFixedWidth(200);

    }

    //Ajout des QLabel et QComboBox au QFormLayout
    for(int i(0); i < size; i++)
    {
        m_formLayoutCarSpeciaux->addRow(m_labelCarSpeciaux[i], m_comboBoxCarSpeciaux[i]);
    }

    connexionCarSpeciaux();
}

/*************************************************************/

/**
 * @brief HPenduFenetre::connexionCarSpeciaux
 *
 * connection des QComboBox à un slot
 */
void HPenduFenetre::connexionCarSpeciaux()
{
    int size(m_comboBoxCarSpeciaux.size());
    for(int i(0); i < size; i++)
    {
        std::cout << "ici : " << i << std::endl;
        QObject::connect(m_comboBoxCarSpeciaux[i], SIGNAL(currentTextChanged(QString)), m_caractereEntree, SLOT(setText(QString)));
    }
}

/*************************************************************/

/**
 * @brief HPenduFenetre::changerTime
 * @param value int
 *
 * change le temps en fonction du niveau choisi(value)
 */
void HPenduFenetre::changerTime(int value)
{
    switch (value)
    {
    case 1:
        *m_timeCompteur += 120;
        break;
    case 2:
        *m_timeCompteur += 60;
        break;
    case 3:
        *m_timeCompteur += 30;
        break;
    case 4:
        *m_timeCompteur = *m_timeCompteur;
        break;
    default:
        break;
    }
}

/*************************************************************/
//MÉTHODES OPTIONS

void HPenduFenetre::option_allocationGrpLayout()
{
    m_groupOption = new QGroupBox;
    m_gridLayoutOption = new QGridLayout;
    m_formLayoutLangue = new QFormLayout;
    m_formLayoutNiveauJeu = new QFormLayout;
}

/*************************************************************/

void HPenduFenetre::option_allocationWidget()
{
    m_labelLangue = new QLabel("Langue: ");
    m_langue = new QComboBox;
    m_titreJeu = new QLabel("HPENDU");
    m_labelNiveauJeu = new QLabel("Niveau: ");
    m_niveauJeu = new QSpinBox;
}

/*************************************************************/

void HPenduFenetre::option_configurationWidget()
{
    m_labelLangue->setFont(QFont("MathJax_Fraktur", 15));
    m_labelNiveauJeu->setFont(QFont("MathJax_Fraktur", 15));

    int sizeListeLangue(m_pendu->m_langueDisponible.size());
    for(int i(0); i < sizeListeLangue; i++) //Ajout des langues disponibles
    {                                       //Avec des icones, s'il y en a
        QString langue(m_pendu->m_langueDisponible[i].c_str());
        m_langue->addItem(QIcon("images/Icones/" + langue + ".png"), langue);
    }

    m_langue->setCurrentText("France"); //Langue par défaut

    m_titreJeu->setFont(QFont("MathJax_Fraktur", 45));
    m_titreJeu->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    QPalette palette;
    palette.setColor(QPalette::WindowText, QColor(0, 150, 100, 225));
    m_titreJeu->setPalette(palette);

    m_niveauJeu->setMaximum(4); //On ne peut dépasser le niveau 4
    m_niveauJeu->setMinimum(1);
}

/*************************************************************/

void HPenduFenetre::option_ajoutWidget()
{
    m_formLayoutLangue->addRow(m_labelLangue, m_langue);
    m_formLayoutNiveauJeu->addRow(m_labelNiveauJeu, m_niveauJeu);

    m_gridLayoutOption->addLayout(m_formLayoutLangue, 0, 0);
    m_gridLayoutOption->addLayout(m_formLayoutNiveauJeu, 1, 0);
    m_gridLayoutOption->addWidget(m_titreJeu, 0, 1, 2, 1);
}

//FIN MÉTHODES OPTIONS
/*************************************************************/

/*************************************************************/
//MÉTHODES DÉROULEMENTS

void HPenduFenetre::der_allocationGrpLayout()
{
    m_groupDeroulement = new QGroupBox();
    m_gridLayoutDeroulement = new QGridLayout;
}

/*************************************************************/

void HPenduFenetre::der_allocationWidget()
{
    m_commencer = new QPushButton("Commencer");
    m_quitter = new QPushButton("Quitter");
}

/*************************************************************/

void HPenduFenetre::der_configurationWidget()
{
    m_commencer->setFont(QFont("MathJax_Fraktur", 15));
    m_commencer->setToolTip("Commencer le jeu");

    //////////////////////////////////////////////////

    QPalette paletteFor;
    paletteFor.setColor(QPalette::ButtonText, QColor(255, 0, 0, 180));

    m_quitter->setPalette(paletteFor);
    m_quitter->setFont(QFont("MathJax_Fraktur", 15));
    m_quitter->setToolTip("Quitter le jeu");
}

/*************************************************************/

void HPenduFenetre::der_ajoutWidget()
{
    m_gridLayoutDeroulement->addWidget(m_commencer, 0, 1);
    m_gridLayoutDeroulement->addWidget(m_quitter, 1, 0, 1, 3);
}

//FIN MÉTHODES DÉROULEMENTS
/*************************************************************/

/*************************************************************/
//MÉTHODES JEU

void HPenduFenetre::jeu_allocationGrpLayout()
{
    m_groupJeu = new QGroupBox;
    m_gridLayoutJeu = new QGridLayout;
    m_groupePRA = new QGroupBox;//=====
    m_layoutPRA = new QHBoxLayout;//=====
    m_groupJeuCarSpeciaux = new QGroupBox;
    m_formLayoutCarSpeciaux = new QFormLayout;
}

/*************************************************************/

void HPenduFenetre::jeu_allocationWidget()
{
    m_regExpCarEntre = new QRegularExpression(".{1,1}");
    m_validatorCarEntre = new QRegularExpressionValidator(*m_regExpCarEntre);

    m_lcdNumberTimeCompteur = new QLCDNumber;
    m_lcdNumberNbrCoups = new QLCDNumber;
    m_labelMotTrouve = new QLabel("Mot Trouvé:");
    m_labelEntreCaractere = new QLabel("Entrer un caractère: ");
    m_caractereEntree = new QLineEdit;
    m_tester = new QPushButton("Tester");
    m_terminer = new QPushButton("Abandonner");
    m_pauser = new QPushButton("Pauser");
    m_reprendre = new QPushButton("Reprendre");
    m_checkCarSpeciaux = new QCheckBox("Caractères spéciaux");
}

/*************************************************************/

void HPenduFenetre::jeu_configurationWidget()
{
    QPalette palette;

    m_lcdNumberTimeCompteur->setMaximumSize(160, 100);
    m_lcdNumberTimeCompteur->setMinimumSize(130, 100);
    m_lcdNumberTimeCompteur->setToolTip("Temps restants");

    m_lcdNumberNbrCoups->setMaximumSize(160, 100);
    m_lcdNumberNbrCoups->setMinimumSize(130, 100);
    m_lcdNumberNbrCoups->setToolTip("Coups restants");

    palette.setColor(QPalette::WindowText, QColor(0, 100, 255, 200));
    m_labelMotTrouve->setAlignment(Qt::AlignHCenter);
    m_labelMotTrouve->setFont(QFont("MathJax_Fraktur", 15));
    m_labelMotTrouve->setPalette(palette);

    m_labelEntreCaractere->setAlignment(Qt::AlignHCenter);
    m_labelEntreCaractere->setFont(QFont("MathJax_Fraktur", 15));
    m_labelEntreCaractere->setPalette(palette);

    m_caractereEntree->setAlignment(Qt::AlignHCenter);
    m_caractereEntree->setMinimumSize(130, 50);
    m_caractereEntree->setMaximumSize(160, 50);
    m_caractereEntree->setValidator(m_validatorCarEntre);
    m_caractereEntree->setFont(QFont("Arial", 25));

    palette.setColor(QPalette::Button, QColor(0, 200, 180, 250));
    m_tester->setFont(QFont("MathJax_Fraktur", 20));
    m_tester->setPalette(palette);
    m_tester->setToolTip("Tester le caractère entré");

    m_pauser->setFont(QFont("MathJax_Fraktur", 20));
    m_pauser->setPalette(palette);
    m_pauser->setToolTip("Abandonner la partie");
    m_pauser->setIcon(QIcon("images/IconesJeu/pause-button.png"));
    m_pauser->setIconSize(QSize(30, 30));
    m_pauser->setToolTip("Pauser le jeu");

    m_reprendre->setFont(QFont("MathJax_Fraktur", 20));
    m_reprendre->setPalette(palette);
    m_reprendre->setToolTip("Abandonner la partie");
    m_reprendre->setEnabled(false);
    m_reprendre->setIcon(QIcon("images/IconesJeu/play-button.png"));
    m_reprendre->setIconSize(QSize(30, 30));
    m_reprendre->setToolTip("Reprendre le jeu");

    palette.setColor(QPalette::Button, QColor(200, 10, 10, 255));
    m_terminer->setFont(QFont("MathJax_Fraktur", 20));
    m_terminer->setPalette(palette);
    m_terminer->setToolTip("Abandonner la partie");

    m_groupJeuCarSpeciaux->setLayout(m_formLayoutCarSpeciaux);
    m_groupJeuCarSpeciaux->hide();

    m_checkCarSpeciaux->setToolTip("Afficher les caractères spéciaux: <b>ä</b>, <b>â</b>, <b>ü</b>, ...<br>Il se peux que vous n'ayez pas ces caractères sur votre clavier :)");
    m_checkCarSpeciaux->setFont(QFont("MathJax_Fraktur", 15));
}

/*************************************************************/

void HPenduFenetre::jeu_ajoutWidget()
{
    m_gridLayoutJeu->addWidget(m_lcdNumberTimeCompteur, 0, 0);
    m_gridLayoutJeu->addWidget(m_lcdNumberNbrCoups, 0, (m_pendu->get_m_motPioche().size() + 1));
    m_gridLayoutJeu->addWidget(m_labelMotTrouve, 1, 0);
    m_gridLayoutJeu->addWidget(m_labelEntreCaractere, 4, 0);
    m_gridLayoutJeu->addWidget(m_caractereEntree, 5, 0);
    m_gridLayoutJeu->addWidget(m_tester, 6, 0, 1, (m_pendu->get_m_motPioche().size() + 2));

    //======================
    m_groupePRA->setLayout(m_layoutPRA);

    m_layoutPRA->addWidget(m_pauser);
    m_layoutPRA->addWidget(m_reprendre);
    m_layoutPRA->addWidget(m_terminer);

    //======================

    m_gridLayoutJeu->addWidget(m_groupePRA, 7, 0, 1, (m_pendu->get_m_motPioche().size() + 2));
    m_gridLayoutJeu->addWidget(m_checkCarSpeciaux, 8, 0);
    m_gridLayoutJeu->addWidget(m_groupJeuCarSpeciaux, 9, 1, 1, (m_pendu->get_m_motPioche().size()));
}

//FIN MÉTHODES JEU
/*************************************************************/

/*************************************************************/
//MÉTHODES A-PROPOS

void HPenduFenetre::propos_allocationGrpLayout()
{
    m_groupePropos = new QGroupBox;
    m_hBoxLayoutPropos = new QHBoxLayout;
}

/*************************************************************/

void HPenduFenetre::propos_allocationWidget()
{
    m_commentJouer = new QPushButton("Comment Jouer");
    m_aProposHPendu = new QPushButton("HPendu");
    m_aProposQt = new QPushButton("Qt");
}

/*************************************************************/

void HPenduFenetre::propos_configurationWidget()
{
    m_commentJouer->setFont(QFont("MathJax_Fraktur", 15));
    m_commentJouer->setCursor(Qt::WhatsThisCursor);

    m_aProposHPendu->setFont(QFont("MathJax_Fraktur", 15));
    m_aProposHPendu->setCursor(Qt::WhatsThisCursor);

    m_aProposQt->setFont(QFont("MathJax_Fraktur", 15));
    m_aProposQt->setCursor(Qt::WhatsThisCursor);
}

/*************************************************************/

void HPenduFenetre::propos_ajoutWidget()
{
    m_hBoxLayoutPropos->addWidget(m_commentJouer);
    m_hBoxLayoutPropos->addWidget(m_aProposHPendu);
    m_hBoxLayoutPropos->addWidget(m_aProposQt);
}

//FIN MÉTHODES A-PROPOS
/*************************************************************/

/*************************************************************/
//SLOTS

/**
 * @brief HPenduFenetre::slot_changerLanguePendu
 * @param text QString
 *
 * slot appelé à chaque fois que la langue dans le QComboBox change
 * elle change la langue du pendu
 */
void HPenduFenetre::slot_changerLanguePendu(QString text)
{
    m_pendu->set_m_langueChoisie(text);
    std::cout << "Langue: " << m_pendu->get_m_langueChoisie().toStdString() << std::endl;
}

/*************************************************************/

/**
 * @brief HPenduFenetre::slot_changerNiveauPendu
 * @param value int
 *
 * slot appelé à chaque fois que le niveau dans le QSpinBox change
 * elle change le niveau du jeu
 * change le compteur en fonction du niveau choisi
 */
void HPenduFenetre::slot_changerNiveauPendu(int value)
{
    *m_timeCompteur = 120;
    m_pendu->set_m_niveau(value);
    std::cout << "niveau : " << m_pendu->get_m_niveau() << std::endl;

    changerTime(value);
}

/*************************************************************/

/**
 * @brief HPenduFenetre::slot_desactiverOptionCommencer
 *
 * slot pour démarre le jeu
 * Comment ça marche?
 * --1-- Active le timer
 * --2-- Pioche un mot
 *          - reussite: --3--
 *          - erreur(mot pioché -> vide): met le langue comme mot pioché et initialise le mot trouvé
 *              (source d'erreur probable: le fichier existe mais vide
 *                                         on arrive en fin de fichier et récupère une chaîne vide)
 *
 * --3-- Calcul des coups disponibles
 * --4-- Initialisation des affichages du mot Trouvé et des caractères spéciaux
 * --5-- Connection du timer à des slots à savoir:
 *          - slot_changerTimeCompteur(), pour changer le temps restant toute les secondes
 *          - slot_testerFinJeu(), pour tester la fin du jeu
 */
void HPenduFenetre::slot_desactiverOptionCommencer()
{
    m_timer = new QTimer(this);
    connect(m_timer, &QTimer::timeout, this, QOverload<>::of(&HPenduFenetre::update));
    m_timer->start(1000);

    m_groupOption->setEnabled(false);
    m_groupJeu->setEnabled(true);
    m_commencer->setEnabled(false);

    m_pendu->piocherMotHasard(); //Piochage d'un mot dans le dictionnaire
    if(m_pendu->get_m_motPioche().isEmpty()) //Si par erreur, on ne parvient pas à recupérer un mot:
    {                                        //on met la langue comme mot pioché
        m_pendu->set_m_motPioche(m_pendu->get_m_langueChoisie());
        m_pendu->initialiserMotTrouve(m_pendu->get_m_motPioche().size());
    }

    m_pendu->calculerCoups(); //Calcul du nombre de coups

    QPalette palette;
    palette.setColor(QPalette::WindowText, QColor(0, 0, 0, 255));
    m_lcdNumberNbrCoups->setPalette(palette);
    m_lcdNumberNbrCoups->display(m_pendu->get_m_nbrCoups()); //Affichage du nombre de coups

    initialiserCarSpeciaux();
    initialiserAffichageMotTrouve();

    int sizeMotPioche(m_pendu->get_m_motPioche().size());
    for(int i(0); i < sizeMotPioche; i++)
    {
        m_affichageMotTrouve[i]->setAlignment(Qt::AlignHCenter);
        m_affichageMotTrouve[i]->setFrameStyle(QFrame::WinPanel | QFrame::Sunken);
        m_affichageMotTrouve[i]->setFont(QFont("DejaVu", 30));
        m_affichageMotTrouve[i]->setMinimumWidth(50);
        m_gridLayoutJeu->addWidget(m_affichageMotTrouve[i], 1, i+1);

        if(m_affichageMotTrouve[i]->text() == '*')
        {
            QPalette palette;
            palette.setColor(QPalette::WindowText, QColor(255, 50, 50, 255));
            m_affichageMotTrouve[i]->setPalette(palette);
        }
    }

    jeu_ajoutWidget();

QObject::connect(m_timer, &QTimer::timeout, this, &HPenduFenetre::slot_changerTimeCompteur);
QObject::connect(m_timer, &QTimer::timeout, this, &HPenduFenetre::slot_testerFinJeu);
}

/*************************************************************/

/**
 * @brief HPenduFenetre::slot_testerCaractereEntre
 *
 * slot pour tester le caractère entré
 * Comment ça marche?
 *
 * --1-- Vérifie si le joueur à bien entrer un caractère:
 *          - pas de teste et quitte si non
 * --2-- Change le caractère entré du pendu avec celui reçu via QLineEdit
 * --3-- Change le mot trouvé du pendu
 * --4-- Change le conteneur des QLabels en fonction du mot trouvé du pendu
 * --5-- Si le coups est inférieur à 5, avertit le joueur qu'il n'a plus beaucoup de coups
 *          en changeant la couleur du QLCDNumber en rouge
 * --6-- Vide le champs QLineEdit
 */
void HPenduFenetre::slot_testerCaractereEntre()
{
    if(m_caractereEntree->text().isEmpty())
        return;

    QString motTrouve;

    m_pendu->set_m_lettreEntree(m_caractereEntree->text().at(0));
    m_pendu->changerMotTrouve();

    motTrouve = m_pendu->get_m_motTrouve();

    int sizeMotPioche(m_pendu->get_m_motPioche().size());
    for(int i(0); i < sizeMotPioche; i++)
    {
        m_affichageMotTrouve[i]->setText(motTrouve.at(i)); //Changement car par car des QLabel contenant les caractères du mot trouvé

        if(m_affichageMotTrouve[i]->text() != '*')
        {
            QPalette palette;
            palette.setColor(QPalette::WindowText, QColor(0, 0, 0, 255));
            m_affichageMotTrouve[i]->setPalette(palette);
        }
    }

    QPalette palette;
    palette.setColor(QPalette::WindowText, QColor(255, 0, 0, 255));
    if(m_pendu->get_m_nbrCoups() < 5)
        m_lcdNumberNbrCoups->setPalette(palette);

    m_lcdNumberNbrCoups->display(m_pendu->get_m_nbrCoups());

    m_caractereEntree->clear();

    std::cout << "mot trouvé: " << m_pendu->get_m_motTrouve().toStdString() << std::endl;
}

/*************************************************************/

/**
 * @brief HPenduFenetre::slot_activerOptionTerminer
 *
 * slot appelé lorsque le joueur abandonne, échoue ou réussisse
 *
 * elle met le niveau à 1
 */
void HPenduFenetre::slot_activerOptionTerminer()
{
    m_groupOption->setEnabled(true);
    m_groupJeu->setEnabled(false);
    m_commencer->setEnabled(true);
    m_pauser->setEnabled(true);
    m_reprendre->setEnabled(false);
    m_tester->setEnabled(true);

    //Le niveau est mise à 1
    if(m_niveauJeu->value() == 1) //Si le compteur est déjà à 1 --
    {
        m_niveauJeu->setValue(2); //On le change en 2 --
        m_niveauJeu->setValue(1); //Puis 1
    }
    m_niveauJeu->setValue(1);
    m_timer->stop(); //On arrête le timer
}

/*************************************************************/

/**
 * @brief HPenduFenetre::slot_changerTimeCompteur
 *
 * slot appelé pour changer le temps restant au joueur(euse)
 *
 *  decrémente de 1 toute les secondes
 *  alerte le joueur en changeant la couleur du QLCDNumber en rouge quand le compteur passe le 30
 */
void HPenduFenetre::slot_changerTimeCompteur()
{
    QPalette palette;
    palette.setColor(QPalette::WindowText, QColor(5, 0, 0, 255));
    m_lcdNumberTimeCompteur->setPalette(palette);

    *m_timeCompteur -= 1;

    m_lcdNumberTimeCompteur->display(*m_timeCompteur);

    if(*m_timeCompteur < 30) //On met la couleur du QLCDNumber à rouge quand le compteur arrive à 15
    {
        palette.setColor(QPalette::WindowText, QColor(255, 50, 50, 255));
        m_lcdNumberTimeCompteur->setPalette(palette);
    }

    if(*m_timeCompteur < 0)
    {
        m_lcdNumberTimeCompteur->display("!!!!");
    }
}

/*************************************************************/

/**
 * @brief HPenduFenetre::slot_afficherCarSpeciaux
 * @param state int
 *
 * slot appelé pour afficher/cacher les caractères spéciaux
 */
void HPenduFenetre::slot_afficherCarSpeciaux(int state)
{
    if(state == Qt::Unchecked)
        m_groupJeuCarSpeciaux->hide();
    else if(state == Qt::Checked)
        m_groupJeuCarSpeciaux->show();
}

/*************************************************************/

/**
 * @brief HPenduFenetre::slot_testerFinJeu
 *
 * slot appelé pour tester si le joueur gagne ou non
 */
void HPenduFenetre::slot_testerFinJeu()
{
    //Quand le compteur atteint 0
    //ou
    //Quand le nombre de coups est inférieur à 1
    //ou
    //Quand le joueur(euse) à trouver le bon mot
    //-----> On termine la partie
    if(*m_timeCompteur < 0)
    {
        QMessageBox::critical(this, "Compteur", ("Vous n'avez pas fini à temps, le mot mystère est: <b>" + m_pendu->get_m_motPioche() + "</b> !!!"));
        slot_activerOptionTerminer();
    }
    if(m_pendu->get_m_nbrCoups() < 1)
    {
        QMessageBox::critical(this, "Coups", "Vous n'avez plus assez de coups, le mot mystère est: <b>" + m_pendu->get_m_motPioche() + "</b> !!!");
        slot_activerOptionTerminer();
    }
    if(m_pendu->verifierMotPiocheTrouve())
    {
        QMessageBox::information(this, "Félicitation", "Bien joué le mot mystère est bien: <b>" + m_pendu->get_m_motTrouve() + "</b> !!!");
        slot_activerOptionTerminer();
    }
}

/*************************************************************/
/**
 * @brief HPenduFenetre::slot_afficherAide
 *
 * slot appelé pour afficher de l'aide
 */
void HPenduFenetre::slot_afficherAide()
{
    HPenduAide *aide;
    aide = new HPenduAide;
    aide->exec();

    aide->deleteLater();
}

/*************************************************************/
/**
 * @brief HPenduFenetre::slot_afficherAProposPendu
 *
 * slot appelé pour afficher des informations sur HPendus
 */
void HPenduFenetre::slot_afficherAProposPendu()
{
    HPenduPropos *propos;
    propos = new HPenduPropos;
    propos->exec();

    propos->deleteLater();
}

/*************************************************************/
/**
 * @brief HPenduFenetre::slot_afficherAProposQt
 *
 * slot appelé pour afficher des informations sur Qt
 */
void HPenduFenetre::slot_afficherAProposQt()
{
    QMessageBox::aboutQt(this);
}

/*************************************************************/
/**
 * @brief HPenduFenetre::slot_pauserJeu
 *
 * slot appelé pour pauser le jeu
 *
 * Comment ça marche?
 *
 * Quand l'utilisateur appuie sur "Pauser":
 *      On active le bouton "Reprendre"
 *      On desactive le bouton "Pauser"
 *      On desactive le bouton "Pauser"
 * et
 *      On stop le Timer
 */
void HPenduFenetre::slot_pauserJeu()
{
    m_reprendre->setEnabled(true);
    m_pauser->setEnabled(false);
    m_tester->setEnabled(false);

    m_timer->stop();
}

/*************************************************************/
/**
 * @brief HPenduFenetre::slot_reprendreJeu
 *
 * Comment ça marche?
 *
 * Quand l'utilisateur appuie sur "Reprendre":
 *      On active le bouton "Pauser"
 *      On desactive le bouton "Tester"
 *      On desactive le bouton "Reprendre"
 * et
 *      On active le Timer
 */
void HPenduFenetre::slot_reprendreJeu()
{
    m_pauser->setEnabled(true);
    m_tester->setEnabled(true);
    m_reprendre->setEnabled(false);

    m_timer->start();
}
