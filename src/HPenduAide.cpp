#include "HPenduAide.h"

/**
 * @brief HPenduAide::HPenduAide constructeur
 */
HPenduAide::HPenduAide(QWidget *parent): QDialog(parent),
    layout_principale(nullptr),
    scroll(nullptr),
    groupe_principale(nullptr),
    m_gridLayout(nullptr),
    m_labelTitre(nullptr),
    m_introduction(nullptr),
    m_image1(nullptr),
    m_groupe1(nullptr),
    m_form1(nullptr),
    m_labelNum1(nullptr),
    m_labelExp1(nullptr),
    m_labelNum2(nullptr),
    m_labelExp2(nullptr),
    m_labelNum3(nullptr),
    m_labelExp3(nullptr),
    m_labelNum4(nullptr),
    m_labelExp4(nullptr),
    m_labelTitrePartie2(nullptr),
    m_image2(nullptr),
    m_groupe2(nullptr),
    m_form2(nullptr),
    m_labelNum5(nullptr),
    m_labelExp5(nullptr),
    m_labelNum6(nullptr),
    m_labelExp6(nullptr),
    m_labelNum7(nullptr),
    m_labelExp7(nullptr),
    m_labelNum8(nullptr),
    m_labelExp8(nullptr),
    m_labelNum9(nullptr),
    m_labelTitrePartie3(nullptr),
    m_image3(nullptr),
    m_labelCarSpeciaux(nullptr),
    m_labelTipTitre(nullptr),
    m_labelTip(nullptr),
    m_ok(nullptr)
{
    setFixedSize(620, 400);
    setWindowModality(Qt::WindowModal);

    layout_principale = new QVBoxLayout;
    scroll = new QScrollArea;
    groupe_principale = new QGroupBox;
    m_gridLayout = new QGridLayout;

    aide_allocationWidget();
    aide_configurationWidget();
    aide_ajoutWidget();

    groupe_principale->setLayout(m_gridLayout);
    scroll->setWidget(groupe_principale);

    layout_principale->addWidget(scroll);
    layout_principale->addWidget(m_ok);

    setLayout(layout_principale);

QObject::connect(m_ok, SIGNAL(clicked(bool)), this, SLOT(close()));    
}

/*=====================================================*/

HPenduAide::~HPenduAide()
{
    delete layout_principale;
    layout_principale = nullptr;

    std::cout << "HPenduAide détruit" << std::endl;
}

/*=====================================================*/

void HPenduAide::aide_allocationWidget()
{
    //partie 1
    {
    m_labelTitre = new QLabel("COMMENT JOUER ?");
    m_introduction = new QLabel("\nAprès avoir lancé le jeu, vous avez dû tomber sur une fenêtre semblable à la figure suivante: ");
    m_image1 = new QLabel;
    m_groupe1 = new QGroupBox;
    m_form1 = new QFormLayout;
    m_labelNum1 = new QLabel("1");
    m_labelExp1 = new QLabel(" --> Changer la langue à jouer dans la partie");
    m_labelNum2 = new QLabel("2");
    m_labelExp2 = new QLabel(" --> Changer le niveau (entre 1 et 4)\nLe niveau 1 correspond à facile");
    m_labelNum3 = new QLabel("3");
    m_labelExp3 = new QLabel(" --> Debutez la partie");
    m_labelNum4 = new QLabel("4");
    m_labelExp4 = new QLabel(" --> Quitter le jeu");
    }

    //partie 2
    {
    m_labelTitrePartie2 = new QLabel("\nSi vous appuyez sur <b>Commencer</b> une nouvelle partie du fenêtre s'affiche en bas comme à la figure suivante: ");
    m_image2 = new QLabel;
    m_groupe2 = new QGroupBox;
    m_form2 = new QFormLayout;
    m_labelNum5 = new QLabel("5");
    m_labelExp5 = new QLabel(" --> Le temps qui vous reste pour trouver le mot mystère");
    m_labelNum6 = new QLabel("6");
    m_labelExp6 = new QLabel(" --> Le nombre de coups restants");
    m_labelNum7 = new QLabel("7");
    m_labelExp7 = new QLabel(" --> C'est là que vous devrez entrer le caractère à tester");
    m_labelNum8 = new QLabel("8");
    m_labelExp8 = new QLabel(" --> Appuyez dessus pour tester le caractère entré");
    m_labelNum9 = new QLabel("9");
    m_labelExp9 = new QLabel(" --> Appuyez dessus pour abandonner");
    }

    //partie 3
    {
    m_labelTitrePartie3 = new QLabel("Si vous avez coché la case <b>Caractère spéciaux</b>"
                                     " une autre partie de la fenêtre s'affiche:");
    m_image3 = new QLabel;
    m_labelCarSpeciaux = new QLabel("Faites dérouler la liste pour trouver le caractère que vous chercher");
    m_labelTipTitre = new QLabel("Le saviez-vous ?");
    m_labelTip = new QLabel("** Vous pouvez ajouter d'autres langues dans le jeu ?<br>"
                            "** Veuillez à bien nommer vos fichiers de langue et mettez les dans le dossier: <br>"
                            "** files/dictionnaires/nom_fichier où vous avez decompressé l'archive du jeu<br>"
                            "** Si votre fichier est vide, le nom du fichier sera pris comme mot à deviner<br>");
    }

    //partie 4
    m_ok = new QPushButton("J'ai compris");
}

/*=====================================================*/

void HPenduAide::aide_configurationWidget()
{
    QPalette palette;
    //partie 1
    {
    palette.setColor(QPalette::WindowText, QColor(250, 50, 50, 255));
    m_labelTitre->setFont(QFont("Z003", 40));
    m_labelTitre->setWordWrap(true);
    m_labelTitre->setPalette(palette);

    //--------------------------------------------------

    m_image1->setPixmap(QPixmap("images/imagesAide/Game00.png"));

    //--------------------------------------------------

    m_introduction->setFont(QFont("Sans", 15));
    m_introduction->setWordWrap(true);

    //--------------------------------------------------

    palette.setColor(QPalette::WindowText, QColor(250, 90, 50, 255));
    m_labelNum1->setFrameStyle(QFrame::WinPanel | QFrame::Raised);
    m_labelNum1->setLineWidth(10);
    m_labelNum1->setMidLineWidth(10);
    m_labelNum1->setFont(QFont("Lato Black", 25));
    m_labelNum1->setPalette(palette);

    m_labelExp1->setFont(QFont("Z003", 20));
    m_labelExp1->setWordWrap(true);

    //--------------------------------------------------

    palette.setColor(QPalette::WindowText, QColor(100, 50, 200, 255));
    m_labelNum2->setFrameStyle(QFrame::WinPanel | QFrame::Raised);
    m_labelNum2->setLineWidth(10);
    m_labelNum2->setMidLineWidth(10);
    m_labelNum2->setFont(QFont("Lato Black", 25));
    m_labelNum2->setPalette(palette);

    m_labelExp2->setFont(QFont("Z003", 20));
    m_labelExp2->setWordWrap(true);

    //--------------------------------------------------

    palette.setColor(QPalette::WindowText, QColor(0, 50, 150, 255));
    m_labelNum3->setFrameStyle(QFrame::WinPanel | QFrame::Raised);
    m_labelNum3->setLineWidth(10);
    m_labelNum3->setMidLineWidth(10);
    m_labelNum3->setFont(QFont("Lato Black", 25));
    m_labelNum3->setPalette(palette);

    m_labelExp3->setFont(QFont("Z003", 20));
    m_labelExp3->setWordWrap(true);

    //--------------------------------------------------

    palette.setColor(QPalette::WindowText, QColor(0, 150, 0, 255));
    m_labelNum4->setFrameStyle(QFrame::WinPanel | QFrame::Raised);
    m_labelNum4->setLineWidth(10);
    m_labelNum4->setMidLineWidth(10);
    m_labelNum4->setFont(QFont("Lato Black", 25));
    m_labelNum4->setPalette(palette);

    m_labelExp4->setFont(QFont("Z003", 20));
    m_labelExp4->setWordWrap(true);
    }

    //partie 2
    {
    m_labelTitrePartie2->setFont(QFont("Sans", 15));
    m_labelTitrePartie2->setWordWrap(true);

    //--------------------------------------------------

    m_image2->setPixmap(QPixmap("images/imagesAide/Game01.png"));

    //--------------------------------------------------

    palette.setColor(QPalette::WindowText, QColor(0, 230, 0, 255));
    m_labelNum5->setFrameStyle(QFrame::WinPanel | QFrame::Raised);
    m_labelNum5->setLineWidth(10);
    m_labelNum5->setMidLineWidth(10);
    m_labelNum5->setFont(QFont("Lato Black", 25));
    m_labelNum5->setPalette(palette);

    m_labelExp5->setFont(QFont("Z003", 20));
    m_labelExp5->setWordWrap(true);

    //--------------------------------------------------

    palette.setColor(QPalette::WindowText, QColor(200, 20, 0, 255));
    m_labelNum6->setFrameStyle(QFrame::WinPanel | QFrame::Raised);
    m_labelNum6->setLineWidth(10);
    m_labelNum6->setMidLineWidth(10);
    m_labelNum6->setFont(QFont("Lato Black", 25));
    m_labelNum6->setPalette(palette);

    m_labelExp6->setFont(QFont("Z003", 20));
    m_labelExp6->setWordWrap(true);

    //--------------------------------------------------

    palette.setColor(QPalette::WindowText, QColor(240, 240, 0, 255));
    m_labelNum7->setFrameStyle(QFrame::WinPanel | QFrame::Raised);
    m_labelNum7->setLineWidth(10);
    m_labelNum7->setMidLineWidth(10);
    m_labelNum7->setFont(QFont("Lato Black", 25));
    m_labelNum7->setPalette(palette);

    m_labelExp7->setFont(QFont("Z003", 20));
    m_labelExp7->setWordWrap(true);

    //--------------------------------------------------

    palette.setColor(QPalette::WindowText, QColor(0, 50, 100, 255));
    m_labelNum8->setFrameStyle(QFrame::WinPanel | QFrame::Raised);
    m_labelNum8->setLineWidth(10);
    m_labelNum8->setMidLineWidth(10);
    m_labelNum8->setFont(QFont("Lato Black", 25));
    m_labelNum8->setPalette(palette);

    m_labelExp8->setFont(QFont("Z003", 20));
    m_labelExp8->setWordWrap(true);

    //--------------------------------------------------

    palette.setColor(QPalette::WindowText, QColor(250, 140, 0, 255));
    m_labelNum9->setFrameStyle(QFrame::WinPanel | QFrame::Raised);
    m_labelNum9->setLineWidth(10);
    m_labelNum9->setMidLineWidth(10);
    m_labelNum9->setFont(QFont("Lato Black", 25));
    m_labelNum9->setPalette(palette);

    m_labelExp9->setFont(QFont("Z003", 20));
    m_labelExp9->setWordWrap(true);
    }

    //partie 3
    {
    m_labelTitrePartie3->setFont(QFont("Sans", 15));
    m_labelTitrePartie3->setWordWrap(true);

    //--------------------------------------------------

    m_image3->setPixmap(QPixmap("images/imagesAide/Game02.png"));

    //--------------------------------------------------

    m_labelCarSpeciaux->setFont(QFont("Z003", 20));
    m_labelCarSpeciaux->setWordWrap(true);

    palette.setColor(QPalette::WindowText, QColor(50, 150, 250, 255));
    m_labelTipTitre->setFont(QFont("Lato Black", 25));
    m_labelTipTitre->setPalette(palette);

    m_labelTip->setFont(QFont("Z003", 20));
    m_labelTip->setWordWrap(true);

    }

    //partie 4
    {
    palette.setColor(QPalette::Button, QColor(0, 250, 0, 255));
    m_ok->setFont(QFont("Arial", 15));
    m_ok->setPalette(palette);
    }

}

/*=====================================================*/

void HPenduAide::aide_ajoutWidget()
{
    //partie 1
    {
    m_gridLayout->addWidget(m_labelTitre, 0, 0);
    m_gridLayout->addWidget(m_introduction, 1, 0);
    m_gridLayout->addWidget(m_image1, 2, 0);
    m_gridLayout->addWidget(m_groupe1, 3, 0);
    //=========== sous partie 1
        m_form1->addRow(m_labelNum1, m_labelExp1);
        m_form1->addRow(m_labelNum2, m_labelExp2);
        m_form1->addRow(m_labelNum3, m_labelExp3);
        m_form1->addRow(m_labelNum4, m_labelExp4);

        m_groupe1->setLayout(m_form1);

    }

    //partie 2
    {
    m_gridLayout->addWidget(m_labelTitrePartie2, 4, 0);
    m_gridLayout->addWidget(m_image2, 5, 0);
    m_gridLayout->addWidget(m_groupe2, 6, 0);
    //=========== sous partie 2
        m_form2->addRow(m_labelNum5, m_labelExp5);
        m_form2->addRow(m_labelNum6, m_labelExp6);
        m_form2->addRow(m_labelNum7, m_labelExp7);
        m_form2->addRow(m_labelNum8, m_labelExp8);
        m_form2->addRow(m_labelNum9, m_labelExp9);

        m_groupe2->setLayout(m_form2);

    }

    //partie 3
    {
    m_gridLayout->addWidget(m_labelTitrePartie3, 7, 0);
    m_gridLayout->addWidget(m_image3, 8, 0);
    m_gridLayout->addWidget(m_labelCarSpeciaux, 9, 0);
    m_gridLayout->addWidget(m_labelTipTitre, 10, 0);
    m_gridLayout->addWidget(m_labelTip, 11, 0);
    }
}

/*=====================================================*/





