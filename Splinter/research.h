#ifndef RESEARCH_H
#define RESEARCH_H

#include <QWidget>
#include <QtWidgets>
#include <mysystemmodel.h>

class Research : public QWidget
{
       Q_OBJECT
public:
    explicit Research(QWidget* parent = 0);

signals:

public slots:

private:
    QPushButton* b_all_tags;
    QLineEdit* sbar;
    QPushButton* b_ok;
    QPushButton* b_union;
    QPushButton* b_inter;
    QListWidget* fsys;

};

#endif // RESEARCH_H
