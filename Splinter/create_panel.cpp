#include "create_panel.h"
#include <QtWidgets>


Create_panel::Create_panel(QWidget *parent)
{
    b_back = new QPushButton(QString::fromUtf8("\xE2\x97\x80"));
    b_validate = new QPushButton(QString::fromUtf8("\xE2\x9C\x93"));
    b_validate->hide();
    tag_name = new QLineEdit();
    warning = new QLabel("Attention le nom du tag est vide");
    warning->hide();

    QFormLayout* f_create = new QFormLayout();
    f_create->addRow("Nom",tag_name);
    f_create->setFormAlignment(Qt::AlignLeft);

    QWidget* w_create = new QWidget();
    w_create->setLayout(f_create);

    QSpacerItem* space = new QSpacerItem(50,50);
    w_space = new QWidget();
    QHBoxLayout* l_space = new QHBoxLayout();
    l_space->addItem(space);
    w_space->setLayout(l_space);

    QGroupBox* group = new QGroupBox("Creer tag");
    layout = new QGridLayout();
    layout->addWidget(w_create,0,0,1,4);
    layout->addWidget(w_space,1,0,2,4);
    layout->addWidget(warning,4,0,1,4);
    layout->addWidget(b_back,5,0,1,1);
    layout->addWidget(b_validate,5,3,1,1);
    group->setLayout(layout);

    QHBoxLayout* l_group = new QHBoxLayout();
    l_group->addWidget(group);
    this->setLayout(l_group);



    //remplir formulaire -> bouton valider
    connect(tag_name,SIGNAL(textEdited(QString)),this,SLOT(show_validate()));
    //bouton annule -> fermer volet
    connect(b_back,SIGNAL(clicked(bool)),parent,SLOT(hide_create()));
    //bouton validé -> fermer voler
    connect(b_validate,SIGNAL(clicked(bool)),this,SLOT(validate_panel()));
    connect(this,SIGNAL(validate_form(QString)),parent,SLOT(validate(QString)));
}

void Create_panel::show_validate() {
    b_validate->show();
    warning->hide();
}

void Create_panel::reset_form() {
    tag_name->clear();
    b_validate->hide();
    warning->hide();
}

void Create_panel::validate_panel() {
    if (tag_name->text().isEmpty()) {
        warning->show();
    } else {
        emit validate_form(tag_name->text());

    }
}

