#include "research.h"

Research::Research(QWidget *parent)
{
//Tab Research
    //All/Research/Union/Inter
    b_all_tags = new QPushButton("Tags disponibles");

    sbar = new QLineEdit("  " + QString::fromUtf8("\xF0\x9F\x94\x8D") + "  Rechercher par tags");
    b_ok = new QPushButton(QString::fromUtf8("\xE2\x9C\x93"));

    QHBoxLayout* layout_sbar = new QHBoxLayout();
    layout_sbar->addWidget(sbar);
    layout_sbar->addWidget(b_ok);
    layout_sbar->setSpacing(0);
    QWidget* w_sbar = new QWidget();
    w_sbar->setLayout(layout_sbar);

    b_union = new QPushButton();
    b_union->setIcon(QIcon("/Users/margauxcherrueau/Documents/prog/8e_semestre/IHM/Splinter/Splinter/union.png"));
    QPushButton* b_inter = new QPushButton();
    b_inter->setIcon(QIcon("/Users/margauxcherrueau/Documents/prog/8e_semestre/IHM/Splinter/Splinter/inter.png"));
    b_union->setGeometry(b_inter->geometry());

    QHBoxLayout* layout_ui = new QHBoxLayout();
    layout_ui->addWidget(b_union);
    layout_ui->addWidget(b_inter);
    layout_ui->setSpacing(0);
    QWidget* bUI = new QWidget();
    bUI->setLayout(layout_ui);
    bUI->setDisabled(false);

    //File
    QString path = QDir::homePath();

    fsys = new QListWidget();
    //fsys->setRootPath(path);
    //QTreeView* ftree2 = new QTreeView();
    //ftree2->setModel(fsys);
    //ftree2->setRootIndex(fsys->index(path));

    //Grid
    QGridLayout* grid_search = new QGridLayout();
    grid_search->addWidget(b_all_tags,0,0,1,2);
    grid_search->addWidget(w_sbar,0,2,1,8);
    grid_search->addWidget(bUI,0,10,1,2);
    grid_search->addWidget(fsys,2,0,1,12);

    QWidget* search = new QWidget();
    search->setLayout(grid_search);

    QVBoxLayout* layout_research = new QVBoxLayout();
    layout_research->addWidget(search);

    this->setLayout(layout_research);


    //connecteur

//Tags Dispo
    //ouvertur fenetre quand on clic
    //bar recherche (option)
    //annulé
    //selection (checkbox)

//Bar de recherche
    //Ajout nom -> affichage fichier tagué

    //Ajout 2e nom -> enable union/intersection
    //Clic intersect -> fait l'intersection


}
