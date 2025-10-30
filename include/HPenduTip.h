#ifndef HPENDUTIP_H
#define HPENDUTIP_H

#define dailyTip "Le saviez-vous? Vous pouvez ajouter des fichiers contenant des mots à deviner en les mettant dans le repertoire \"<b>files/dictionnaires/</b>\" du dossier où vous avez décompresser le jeu !!!"
#define pathToFile "files/Tips/Tips"

#include "HObject.h"

#include <fstream>
#include <iostream>
#include <string>

#include <QWidget>
#include <QGridLayout>
#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QObject>
#include <QPalette>

class HPenduTip: public QDialog
{
    Q_OBJECT

public:
    HPenduTip(QWidget *parent = nullptr);
    ~HPenduTip();

    void piocherDailyTip();
    int nbrMot();

protected:
    QGridLayout *m_layoutPrincipale;
    QString *m_dailyTip;
    QLabel *m_labelImage;
    QLabel *m_labelDailyTip;
    QPushButton *m_Ok;

};

#endif // HPENDUTIP_H
