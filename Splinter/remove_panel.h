#ifndef REMOVE_PANEL_H
#define REMOVE_PANEL_H

#include <QtWidgets>

class Remove_panel : public QWidget
{
    Q_OBJECT
public:
    Remove_panel(std::vector<std::string>, QWidget *parent);
signals:

public slots:

private:
    QPushButton* b_back;
    QPushButton* b_validate;
    std::vector<QCheckBox*> list_cb;


};

#endif // REMOVE_PANEL_H
