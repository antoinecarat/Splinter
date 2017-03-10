#ifndef MANAGEMENT_H
#define MANAGEMENT_H

#include <QWidget>
#include <QtWidgets>
#include "mysystemmodel.h"
#include "create_panel.h"
#include "remove_panel.h"
class Management : public QWidget
{
    Q_OBJECT
public:
    explicit Management(QWidget *parent = 0);

signals:

public slots:
    void show_create();
    void hide_create();
    void validate(QString tag_name);
    void show_remove();
    void hide_remove();

private:
    QLineEdit* name_tag;
    QPushButton* b_create;
    QPushButton* b_remove;
    QPushButton* b_associate;
    QPushButton* b_dissociate;
    QLineEdit* pbar;
    QPushButton* b_previous;
    QPushButton* b_next;
    mySystemModel* fsys;
    QGridLayout* grid_management;
    QTreeView* ftree;
    Create_panel* create_panel;
    Remove_panel* remove_panel;
    bool create_opened;
    bool remove_opened;

};

#endif // MANAGEMENT_H
