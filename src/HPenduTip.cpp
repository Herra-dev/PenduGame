#include "HPenduTip.h"

HPenduTip::HPenduTip(QWidget *parent): QDialog(parent),
    m_layoutPrincipale(nullptr),
    m_dailyTip(nullptr),
    m_labelImage(nullptr),
    m_labelDailyTip(nullptr),
    m_Ok(nullptr)
{
    //Configuration windows
    setWindowTitle("Phrase du jour");
    setWindowModality(Qt::WindowModal);

    //============================================
    m_layoutPrincipale = new QGridLayout; //Layout principale
    m_dailyTip = new QString;

    piocherDailyTip();
    m_labelImage = new QLabel;
    m_labelDailyTip = new QLabel(*m_dailyTip);
    m_Ok = new QPushButton("D'accord");

    QPalette palette;


    //============================================

    int i(0);
    i = HObject::genereNombreHasard(9);

    std::string pathToPixmap("images/IconesTip/Lampe");
    pathToPixmap += std::to_string(i);
    pathToPixmap += ".png";

    //============================================

    m_labelImage->setPixmap(QPixmap(pathToPixmap.c_str()));

    m_labelDailyTip->setWordWrap(true);
    m_labelDailyTip->setFont(QFont("Z003", 25));

    int rouge(HObject::genereNombreHasard(255));
    int vert(HObject::genereNombreHasard(254));
    int bleu(HObject::genereNombreHasard(253));

    std::cout << "Rouge: " << rouge << std::endl;
    std::cout << "Vert: " << vert << std::endl;
    std::cout << "Bleu: " << bleu << std::endl;

    palette.setColor(QPalette::Button, QColor(rouge,
                                              vert,
                                              bleu, 255));
    m_Ok->setPalette(palette);
    m_Ok->setFont(QFont("Z003", 20));

    //============================================

    m_layoutPrincipale->addWidget(m_labelImage, 0, 0);
    m_layoutPrincipale->addWidget(m_labelDailyTip, 0, 1);
    m_layoutPrincipale->addWidget(m_Ok, 1, 1);

QObject::connect(m_Ok, SIGNAL(clicked(bool)), this, SLOT(close()));

    //============================================
    setLayout(m_layoutPrincipale);

}

/*********************************************************/

HPenduTip::~HPenduTip()
{
    delete m_layoutPrincipale;
    m_layoutPrincipale = nullptr;

    delete m_dailyTip;
    m_dailyTip = nullptr;

    std::cout << "HPenduTip détruit" << std::endl;
}

/*********************************************************/

void HPenduTip::piocherDailyTip()
{
    if(!(m_dailyTip->isEmpty()))
    {
        m_dailyTip->clear();
    }

    std::string motDuJour("");
    std::ifstream monFluxIn(pathToFile);

    if(monFluxIn)
    {
        int nbrDeMot(nbrMot());
        int nbrHasard(HObject::genereNombreHasard(nbrDeMot));
        int i(0);

        while(std::getline(monFluxIn, motDuJour))
        {
            if(i == nbrHasard)
            {
                break;
            }

            i++;
        }

        std::getline(monFluxIn, motDuJour);

        *m_dailyTip = motDuJour.c_str();

        if(m_dailyTip->isEmpty())
        {
            std::cout << "Vide" << std::endl;
            *m_dailyTip = dailyTip;
        }

    }
    else
    {
        std::cout << "Impossible d'ouvrir le fichier" << std::endl;
        piocherDailyTip();
    }
}

/*********************************************************/

int HPenduTip::nbrMot()
{
    std::ifstream monFluxIn(pathToFile);

    if(monFluxIn)
    {
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
        std::cout << "Impossible d'ouvir le fichier de Tips" << std::endl;
        return 1;
    }
}

