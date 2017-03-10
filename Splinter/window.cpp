#include <window.h>
#include <mysystemmodel.h>
#include <management.h>
#include <research.h>
#include <iostream>
using namespace std;
Window::Window()
{

//Construction fenetre principale
    QTabWidget* tabs = new QTabWidget(this);
    tabs->setGeometry(this->geometry());

    Management* management = new Management();
    Research* research = new Research();



    tabs->addTab(management,"Gerer des tags");
    tabs->addTab(research,"Recherche");

    QVBoxLayout* l_final = new QVBoxLayout();
    l_final->addWidget(tabs);

    this->setLayout(l_final);

}


