#include "remove_panel.h"
#include <iostream>
using namespace std;
Remove_panel::Remove_panel(std::vector<std::string> list_tags,QWidget *parent)
{
    b_back = new QPushButton(QString::fromUtf8("\xE2\x97\x80"));
    b_validate = new QPushButton(QString::fromUtf8("\xE2\x9C\x93"));
    b_validate->hide();
    QGroupBox* group = new QGroupBox("Supprimer tag");
    QVBoxLayout* layout = new QVBoxLayout();
    for(int i=0; i<list_tags.size(); i++) {
        QCheckBox* tmp = new QCheckBox(QString(list_tags[i].c_str()));
        list_cb.push_back(tmp);
        layout->addWidget(list_cb[i]);
    }
    group->setLayout(layout);

    QHBoxLayout* l_group = new QHBoxLayout();
    l_group->addWidget(group);
    this->setLayout(l_group);

    //TODO
    //SLIDE BAR
}
