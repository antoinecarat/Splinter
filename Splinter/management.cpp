#include "management.h"


Management::Management(QWidget *parent) : QWidget(parent)
{
//Tab Management

    //Associate/Creat/
    b_create = new QPushButton("Créer tag");
    b_remove = new QPushButton("Supprimer tags");
    b_associate = new QPushButton("Associer tags");
    b_associate->setEnabled(false);
    b_dissociate = new QPushButton("Dissocier tags");
    b_dissociate->setEnabled(false);

    //Path/Next/Pres
    QString path = QDir::homePath();
    pbar = new QLineEdit(path);
    pbar->setReadOnly(true);
    b_previous = new QPushButton(QString::fromUtf8("\xE2\x97\x80"));
    b_next = new QPushButton(QString::fromUtf8("\xE2\x96\xB6"));

    QHBoxLayout* layout_pn = new QHBoxLayout();
    layout_pn->addWidget(b_previous);
    layout_pn->addWidget(b_next);
    layout_pn->setSpacing(0);
    QWidget* w_ui = new QWidget();
    w_ui->setLayout(layout_pn);

    //Create_panel
    create_opened = false;
    create_panel = new Create_panel(this);

    //Remove_panel
    remove_opened = false;
    //FIXME
    //use it as a global variable
    std::vector<std::string> list_tags;
    list_tags.push_back("pouet");
    list_tags.push_back("prout");
    list_tags.push_back("miam");
    remove_panel = new Remove_panel(list_tags,this);


    //File
    fsys = new mySystemModel();
    fsys->setRootPath(path);
    ftree = new QTreeView();
    ftree->setModel(fsys);
    ftree->setRootIndex(fsys->index(path));

    //Grid
    grid_management = new QGridLayout();
    grid_management->setVerticalSpacing(1);
    grid_management->addWidget(b_associate,0,0,1,2);
    grid_management->addWidget(b_dissociate,0,2,1,2);
    grid_management->addWidget(b_create,0,4,1,2);
    grid_management->addWidget(b_remove,0,6,1,2);
    grid_management->addWidget(pbar,1,0,1,6);
    grid_management->addWidget(w_ui,1,6,1,1);
    grid_management->addWidget(ftree,2,0,1,8);


    this->setLayout(grid_management);

    //connect slots et signaux

//Creer Tags
    //clic creer -> afficher/fermer page
    connect(b_create, SIGNAL(clicked()), this, SLOT(show_create()));

//Supprimer Tags
    //onglet suprimer tags
    connect(b_remove, SIGNAL(clicked(bool)),this ,SLOT(show_remove()));

    //selection tags (checkbox) + ajouté validé

    //valider

    //annuler

    //bar de recherche (option)

//Associer
    //Appuyer associer + disable creer supprimer
    //selection tags (checkbox) + ajouté validé

    //valider

    //annuler

    //bar de recherche (option)

    //Nouveau tag

//DIssocier
    //Appuyer dissocier +disable creer supprimer

    //selection tags (checkbox)

    //Valider

    //annulé
//File system
    //Selection un fichier (enable associer dissocier)

    //Double clic ouverture du sous fichier

    //fleche gauche (retour)

    //fleche droite (next) (option)


}

void Management::show_create() {
    if(!create_opened) {
        grid_management->removeWidget(ftree);
        grid_management->addWidget(create_panel,2,0,1,2);
        create_panel->show();
        grid_management->addWidget(ftree,2,2,1,6);

        create_opened = true;
    }else{
        this->hide_create();
    }

}

void Management::hide_create() {
    grid_management->removeWidget(create_panel);
    create_panel->hide();
    create_panel->reset_form();
    grid_management->removeWidget(ftree);
    grid_management->addWidget(ftree,2,0,1,8);

    create_opened = false;

}

void Management::validate(QString tag_name) {
    //create a new tag

    this->hide_create();
}

void Management::show_remove() {
    if(!remove_opened) {
        grid_management->removeWidget(ftree);
        grid_management->addWidget(remove_panel,2,0,1,2);
        remove_panel->show();
        grid_management->addWidget(ftree,2,2,1,6);

        remove_opened = true;
    }else{
        this->hide_remove();
    }

}

void Management::hide_remove() {
    grid_management->removeWidget(remove_panel);
    remove_panel->hide();
    grid_management->removeWidget(ftree);
    grid_management->addWidget(ftree,2,0,1,8);

    remove_opened = false;
}
