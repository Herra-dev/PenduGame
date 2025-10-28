 #ifndef HPENDUFENETRE_H
#define HPENDUFENETRE_H

#include <QApplication>

#include "HPendu.h"
#include "HPenduAide.h"
#include "HPenduTip.h"
#include "HPenduPropos.h"

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QGridLayout>
#include <QComboBox>
#include <QLabel>
#include <QFont>
#include <QObject>
#include <vector>
#include <QLineEdit>
#include <QRegularExpression>
#include <QValidator>
#include <QRegularExpressionValidator>
#include <QPalette>
#include <QColor>
#include <QSpinBox>
#include <QFormLayout>
#include <QHBoxLayout>
#include <QTimer>
#include <QTime>
#include <QLCDNumber>
#include <QCheckBox>
#include <QMessageBox>
#include <QIcon>
#include <QSize>

class HPenduFenetre: public QWidget
{
Q_OBJECT

public:
    HPenduFenetre();//Constructeur
    ~HPenduFenetre();//Destructeur

    void initialiserAffichageMotTrouve();
    void initialiserCarSpeciaux();
    void connexionCarSpeciaux();

protected:
    void changerTime(int value);

    /******************************************************/
    //MÉTHODES OPTIONS

    void option_allocationGrpLayout();
    void option_allocationWidget();
    void option_configurationWidget();
    void option_ajoutWidget();

    //FIN MÉTHODES OPTIONS
    /******************************************************/

    /******************************************************/
    //MÉTHODES DÉROULEMENTS

    void der_allocationGrpLayout();
    void der_allocationWidget();
    void der_configurationWidget();
    void der_ajoutWidget();

    //FIN MÉTHODES DÉROULEMENTS
    /******************************************************/

    /******************************************************/
    //MÉTHODES JEU

    void jeu_allocationGrpLayout();
    void jeu_allocationWidget();
    void jeu_configurationWidget();
    void jeu_ajoutWidget();

    //FIN MÉTHODES JEU
    /******************************************************/

    /******************************************************/
    //MÉTHODES A-PROPOS

    void propos_allocationGrpLayout();
    void propos_allocationWidget();
    void propos_configurationWidget();
    void propos_ajoutWidget();

    //FIN MÉTHODES A-PROPOS
    /******************************************************/

protected:
    QVBoxLayout *m_layoutPrincipale;
    /******************************************************/

    //PENDU

    HPendu *m_pendu;

    //FIN PENDU

    /******************************************************/

    //OPTIONS

    QGroupBox *m_groupOption;
    QGridLayout *m_gridLayoutOption;
    QFormLayout *m_formLayoutLangue;
    QLabel *m_labelLangue;
    QComboBox *m_langue;//Langue
    QLabel *m_titreJeu;//Titre
    QFormLayout *m_formLayoutNiveauJeu;
    QLabel *m_labelNiveauJeu;
    QSpinBox *m_niveauJeu;//Niveau Jeu

    //FIN OPTIONS

    /******************************************************/

    //DÉROULEMENTS

    QGroupBox *m_groupDeroulement;
    QGridLayout *m_gridLayoutDeroulement;
    QPushButton *m_commencer;
    QPushButton *m_quitter;

    //FIN DÉROULEMENTS

    /******************************************************/

    //JEU

    QGroupBox *m_groupJeu;
    QGridLayout *m_gridLayoutJeu;
    QTimer *m_timer;
    int *m_timeCompteur;
    QLCDNumber *m_lcdNumberTimeCompteur;
    std::vector<QLabel*> m_affichageTime;
    QLCDNumber *m_lcdNumberNbrCoups;
    QLabel *m_labelMotTrouve;
    std::vector<QLabel*> m_affichageMotTrouve;
    QLabel *m_labelEntreCaractere;
    QLineEdit *m_caractereEntree;
    QPushButton *m_tester;
    QPushButton *m_terminer;
    QGroupBox *m_groupePRA; //Pauser Reprendre Abandonner
    QHBoxLayout *m_layoutPRA;
    QPushButton *m_pauser;
    QPushButton *m_reprendre;

    QCheckBox *m_checkCarSpeciaux;
    QGroupBox *m_groupJeuCarSpeciaux;
    QFormLayout *m_formLayoutCarSpeciaux;
    std::vector<QLabel*> m_labelCarSpeciaux;
    std::vector<QComboBox*> m_comboBoxCarSpeciaux;
    std::vector<QString*> m_stringCarSpeciaux;

    QRegularExpression *m_regExpCarEntre;
    QValidator *m_validatorCarEntre;

    //FIN JEU

    /******************************************************/

    //A-PROPOS

    QGroupBox *m_groupePropos;
    QHBoxLayout *m_hBoxLayoutPropos;
    QPushButton *m_commentJouer;
    QPushButton *m_aProposHPendu;
    QPushButton *m_aProposQt;

    //FIN A-PROPOS

    /******************************************************/

public slots:
    void slot_changerLanguePendu(QString text);
    void slot_changerNiveauPendu(int value);
    void slot_desactiverOptionCommencer();
    void slot_testerCaractereEntre();
    void slot_activerOptionTerminer();
    void slot_changerTimeCompteur();
    void slot_afficherCarSpeciaux(int state);
    void slot_testerFinJeu();
    void slot_afficherAide();
    void slot_afficherAProposPendu();
    void slot_afficherAProposQt();
    void slot_pauserJeu();
    void slot_reprendreJeu();
};

#endif // HPENDUFENETRE_H
