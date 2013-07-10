#ifndef DOCUMENTWIDGET_H
#define DOCUMENTWIDGET_H

#include <QWidget>
#include <QGraphicsScene>

#include "elements.h"
#include "mygview.h"
#include "groupsmodel.h"


class DocumentWidget : public QWidget
{
    Q_OBJECT
public:
    explicit DocumentWidget(QWidget *parent = 0, QString filename = "");
    ~DocumentWidget();
    

    void moveMultiply(quint32 newValX, quint32 newValY);
    void moveSingle(quint32 newValX, quint32 newValY);
    int count() { return elem->itemsCount(); }
    int selectedCount() { return scene->selectedItems().count(); }


    void makeRotate(double rx1, double ry1, double rx2, double ry2);
    void flipH();
    void flipV();

    QList<int> getGroups() { return groups; }
    void selectAll();

    void deleteSelected();
    void addChip(Chip *chip);
    void sortByX();
    void sortByY();
    void sortByTape();
    void rotateSelected(double angle);
    void rotateSelectedPersonal(int angle);
    void selectNLastItems(int n);
    void testRotate(double angle);
    bool hasChanged() { return changed; }
    void selectByGroup(QModelIndex index);

    GroupsModel *getGroupsModel();
    FilterProxyModel *getProxyModel();

    void findMatchGroups();
    void rotateSelected(int angle);
    QList<Chip *> getSelectedElements();
    void pasteElements(QList<Chip *> *pasteBuffer);
    void updateScene();
    bool saveToSVG();
signals:
    void selectedElement(Chip *);
    void selectionChanged(int);
    void selectionChanged(Chip *);
    void groupsChanged(QList<int>);
    void mousePos(QPoint);
public slots:
    bool save();
    void setSelectedTape(int tape);
    void setSelectedGroup(uint id);

private slots:
    void countSelectedItems();
    void acceptCoords(QPointF point);

private:
    void drawBorders();
    MyGView *view;
    QGraphicsScene *scene;
    Elements *elem;
    FilterProxyModel *proxy;
    QList<int> groups;
    bool saveToBinary(QString fileName, int num, bool selectedOnly);
    void rescanGroups();
    bool changed;
    char divisor;
    
};

#endif // DOCUMENTWIDGET_H
