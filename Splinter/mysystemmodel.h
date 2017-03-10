#ifndef MYSYSTEMMODEL_H
#define MYSYSTEMMODEL_H

#include <QtWidgets>

class mySystemModel : public QFileSystemModel
{
    Q_OBJECT
public :
    int columnCount(const QModelIndex& parent = QModelIndex()) const
    {
        return QFileSystemModel::columnCount()+1;
    }

    QVariant data(const QModelIndex& index,int role) const
    {
       if(!index.isValid()){return QFileSystemModel::data(index,role);}
       if(index.column()==columnCount()-1)
       {
           switch(role)
           {
              case(Qt::DisplayRole):
              {return QString("YourText");}
              case(Qt::TextAlignmentRole):
                  {return Qt::AlignHCenter;}
              default:{}
           }
       }
       return QFileSystemModel::data(index,role);
   }

    QVariant headerData(int section, Qt::Orientation orientation, int role) const
    {
        if (section == columnCount()-1 && orientation == Qt::Horizontal && role == Qt::DisplayRole) {
             return "Tags";
        }
        return QFileSystemModel::headerData(section, orientation, role);
    }
};

#endif // MYSYSTEMMODEL_H
