#ifndef CREATE_PANEL_H
#define CREATE_PANEL_H

#include <QtWidgets>

class Create_panel : public QWidget
{
    Q_OBJECT
public:
    Create_panel(QWidget* parent = 0);
    void reset_form();
signals:
    void validate_form(QString tag_name);

public slots:
    void show_validate();
    void validate_panel();

private:
      QPushButton* b_back;
      QPushButton* b_validate;
      QLineEdit* tag_name;
      QGridLayout* layout;
      QWidget* w_space;
      QLabel* warning;
};

#endif // CREATE_PANEL_H
