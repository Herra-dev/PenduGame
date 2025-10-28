#ifndef HPENDUPROPOS_H
#define HPENDUPROPOS_H

#include <iostream>
#include <QPushButton>
#include <QDialog>
#include <QVBoxLayout>
#include <QLabel>
#include <QGroupBox>
#include <QGridLayout>
#include <QScrollArea>
#include <QFont>
#include <QPalette>

class HPenduPropos: public QDialog
{
public:
    HPenduPropos(QDialog *parent = nullptr);
    ~HPenduPropos();

protected:
    void propos_allocationGrpLayout();
    void propos_allocationWidget();
    void propos_configurationWidget();
    void propos_ajoutWidget();

protected:
    QVBoxLayout *m_layoutPrincipale;
    QScrollArea *m_scroll;
    QGroupBox *m_groupPropos;
    QGridLayout *m_gridLayoutPropos;
    QLabel *m_imageLogoHPendu;
    QLabel *m_imageLogoCarotte;
    QLabel *m_titreJeu;
    QLabel *m_labelInfo;
    QLabel *m_labelFaireDon;
    QLabel *m_labelDon1;
    QLabel *m_labelEmail;
    QLabel *m_labelDon2;
    QLabel *m_labelTechnologieUtilisee;
    QLabel *m_technologieUtilisee1;
    QLabel *m_technologieUtilisee2;


};

#endif // HPENDUPROPOS_H
