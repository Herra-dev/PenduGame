#ifndef HPENDUAIDE_H
#define HPENDUAIDE_H

#include <iostream>

#include <QDialog>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QGridLayout>
#include <QLabel>
#include <QPixmap>
#include <QScrollArea>
#include <QFormLayout>
#include <QPushButton>
#include <QObject>

class HPenduAide: public QDialog
{
    Q_OBJECT

public:
    HPenduAide(QDialog *parent = nullptr);
    ~HPenduAide();

protected:
    void aide_allocationWidget();
    void aide_configurationWidget();
    void aide_ajoutWidget();

protected:
    QVBoxLayout *layout_principale; //Le layout conteneur principal
    QScrollArea *scroll;
    QGroupBox *groupe_principale; //Le groupe principale
    QGridLayout *m_gridLayout;

    //============================= Partie 1
    QLabel *m_labelTitre;
    QLabel *m_introduction;
    QLabel *m_image1;
    QGroupBox *m_groupe1;
    QFormLayout *m_form1;
    QLabel *m_labelNum1;
    QLabel *m_labelExp1;
    QLabel *m_labelNum2;
    QLabel *m_labelExp2;
    QLabel *m_labelNum3;
    QLabel *m_labelExp3;
    QLabel *m_labelNum4;
    QLabel *m_labelExp4;

    //============================= Partie 2
    QLabel *m_labelTitrePartie2;
    QLabel *m_image2;
    QGroupBox *m_groupe2;
    QFormLayout *m_form2;
    QLabel *m_labelNum5;
    QLabel *m_labelExp5;
    QLabel *m_labelNum6;
    QLabel *m_labelExp6;
    QLabel *m_labelNum7;
    QLabel *m_labelExp7;
    QLabel *m_labelNum8;
    QLabel *m_labelExp8;
    QLabel *m_labelNum9;
    QLabel *m_labelExp9;

    //============================= Partie 3
    QLabel *m_labelTitrePartie3;
    QLabel *m_image3;
    QLabel *m_labelCarSpeciaux;

    //============================= Partie 4
    QPushButton *m_ok;
};

#endif // HPENDUAIDE_H
