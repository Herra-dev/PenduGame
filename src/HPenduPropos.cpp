#include "HPenduPropos.h"

HPenduPropos::HPenduPropos(QDialog *parent): QDialog(parent),
    m_layoutPrincipale(nullptr),
    m_scroll(nullptr),
    m_groupPropos(nullptr),
    m_gridLayoutPropos(nullptr),
    m_imageLogoHPendu(nullptr),
    m_imageLogoCarotte(nullptr),
    m_titreJeu(nullptr),
    m_labelInfo(nullptr),
    m_labelFaireDon(nullptr),
    m_labelDon1(nullptr),
    m_labelEmail(nullptr),
    m_labelDon2(nullptr),
    m_labelTechnologieUtilisee(nullptr),
    m_technologieUtilisee1(nullptr),
    m_technologieUtilisee2(nullptr)
{
    //Configuration windows
    setWindowTitle("Information HPendu");
    setFixedWidth(400);

    //============================================

    m_layoutPrincipale = new QVBoxLayout;
    m_scroll = new QScrollArea;


    propos_allocationGrpLayout();
    propos_allocationWidget();
    propos_configurationWidget();
    propos_ajoutWidget();

    m_groupPropos->setLayout(m_gridLayoutPropos);
    m_scroll->setWidget(m_groupPropos);
    m_layoutPrincipale->addWidget(m_scroll);

    setLayout(m_layoutPrincipale);

}

/*********************************************************/

HPenduPropos::~HPenduPropos()
{
    delete m_layoutPrincipale;
    m_layoutPrincipale = nullptr;

    std::cout << "HPenduPropos détruit" << std::endl;
}

/*********************************************************/

void HPenduPropos::propos_allocationGrpLayout()
{
    m_groupPropos = new QGroupBox;
    m_gridLayoutPropos = new QGridLayout;
}

/*********************************************************/

void HPenduPropos::propos_allocationWidget()
{
    m_imageLogoHPendu = new QLabel;
    m_imageLogoCarotte = new QLabel;
    m_titreJeu = new QLabel("HPENDU");
    m_labelInfo = new QLabel("HPendu est totalement gratuit.<br/>"
                             "Le code source est disponible sur le github à l'adresse:<br/>"
                             "<b>https://github.com/Herra-Dev/GamePendu</b>");
    m_labelFaireDon = new QLabel("Faire un don: ");
    m_labelDon1 = new QLabel("<b>**</b> Vous pouvez contribuer à l'amélioration du jeu:<br/>- En nous reportant les <b>bugs</b> que vous rencontrez<br/>"
                             "- En nous donnant des <b>idées d'amélioration</b><br/>"
                             "par email: ");
    m_labelEmail = new QLabel("<b>irdnarheriniaina@gmail.com</b>");
    m_labelDon2 = new QLabel("<b>**</b> Vous pouvez également montrer votre gratitude envers le développeur via airtel money: <b>+261331943883</b><br>"
                             "(On vous remercie d'avance)");
    m_labelTechnologieUtilisee = new QLabel("Ce programme a été réalisé avec: ");
    m_technologieUtilisee1 = new QLabel;
    m_technologieUtilisee2 = new QLabel;
}

/*********************************************************/

void HPenduPropos::propos_configurationWidget()
{
    m_imageLogoHPendu->setPixmap(QPixmap("images/IconesJeu/HPendu.png"));
    //===================================================

    m_imageLogoCarotte->setPixmap(QPixmap("images/IconesJeu/Carotte.png"));
    //===================================================

    QPalette palette;
    palette.setColor(QPalette::WindowText, QColor(200, 100, 0, 255));
    m_titreJeu->setFont(QFont("Z003", 30));
    m_titreJeu->setPalette(palette);

    //===================================================

    m_labelInfo->setWordWrap(true);
    //===================================================

    palette.setColor(QPalette::WindowText, QColor(0, 100, 200, 255));
    m_labelFaireDon->setFont(QFont("Z003", 20));
    m_labelFaireDon->setWordWrap(true);
    m_labelFaireDon->setPalette(palette);
    //===================================================

    m_labelDon1->setWordWrap(true);
    //===================================================

    m_labelEmail->setWordWrap(true);
    //===================================================

    m_labelDon2->setWordWrap(true);
    //===================================================

    m_labelTechnologieUtilisee->setFont(QFont("Z003", 15));
    m_labelTechnologieUtilisee->setWordWrap(true);
    //===================================================

    m_technologieUtilisee1->setPixmap(QPixmap("images/IconesJeu/C++.png"));
    m_technologieUtilisee1->setAlignment(Qt::AlignHCenter);
    //===================================================

    m_technologieUtilisee2->setPixmap(QPixmap("images/IconesJeu/Qt.png"));
    m_technologieUtilisee2->setAlignment(Qt::AlignHCenter);
    //===================================================

    m_groupPropos->setMaximumWidth(350);
}

/*********************************************************/

void HPenduPropos::propos_ajoutWidget()
{
    m_gridLayoutPropos->addWidget(m_imageLogoHPendu, 0, 0);
    m_gridLayoutPropos->addWidget(m_imageLogoCarotte, 0, 2);
    m_gridLayoutPropos->addWidget(m_titreJeu, 1, 1);
    m_gridLayoutPropos->addWidget(m_labelInfo, 2, 1);
    m_gridLayoutPropos->addWidget(m_labelFaireDon, 3, 1);
    m_gridLayoutPropos->addWidget(m_labelDon1, 4, 1);
    m_gridLayoutPropos->addWidget(m_labelEmail, 5, 1);
    m_gridLayoutPropos->addWidget(m_labelDon2, 6, 1);
    m_gridLayoutPropos->addWidget(m_labelTechnologieUtilisee, 7, 1);
    m_gridLayoutPropos->addWidget(m_technologieUtilisee1, 8, 1);
    m_gridLayoutPropos->addWidget(m_technologieUtilisee2, 9, 1);
}

/*********************************************************/
