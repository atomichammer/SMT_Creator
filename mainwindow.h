#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QGraphicsScene"
#include <QGraphicsRectItem>
#include <QModelIndex>
#include <QShortcut>
#include <QAction>
#include <QLabel>
#include <QDataWidgetMapper>
#include "groupsmodel.h"
#include "mygview.h"
#include "myelem.h"
#include "elements.h"
#include "documentwidget.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void loadFile(const QString &fileName);
    void makeRotate();
    void flipH();
    void flipV();

    void closeEvent(QCloseEvent *event);
    bool maybeSave();
    void updateLastFilesMenu();


    void createShortCuts();
public slots:
    void setTape(int x);
    bool openFile(QString extension);
    void handleMessage(const QString& message);
    void tabChanged(int i);
    void updateGroupsList(QList<int> groups);
    void pasteElements();
    void copyElements();
signals:
    void needToShow();

private slots:
    void openRecentFile();
    bool tabClose(int index);
    void loadElement(Chip *chip);
    void acceptCoords(QPoint point);

    void selectAll();
    void selectionChanged(int count);
    void on_sbZeroX_valueChanged(int );
    void on_sbZeroY_valueChanged(int );
    void on_sbStepsPerMm_valueChanged(int );
    void on_pbSet_clicked();
    void on_lwGroups_clicked(QModelIndex index);
    void on_pbSetGroupTape_clicked();
    void on_pbSub90_clicked();
    void on_pbAdd90_clicked();
    void on_pbRotateAll_clicked();
    void on_actionImport_SMT_triggered();
    void on_actionImport_CSV_triggered();
    void on_actionSave_SMT_triggered();
    void on_actionSort_By_triggered();
    void on_actionAddPart_activated();
    void on_actionBasicSettings_triggered();
    void on_actionFlipH_triggered();
    void on_actionFlipV_triggered();
    void on_actionDeleteSelected_triggered();
    void on_slPos_valueChanged(int value);
    void on_pbRotate_clicked();
    void on_actionMove_and_Rotate_triggered();

    void on_pbRemoveGroup_clicked();

    void on_listView_clicked(const QModelIndex &index);

    void on_pbRestore_clicked();

    void on_actionShow_Groups_Dialog_triggered();

    void on_actionBasicGroupsDialog_triggered();

    void on_pbRotSel_clicked();

    void on_actionChangeGroup_triggered();

private:
    Ui::MainWindow *ui;

    QShortcut *shortcutSelectAll;


    QLabel *lbCount;
    QLabel *lbSelected;
    QLabel *lbCoords;

    void createActions();
    void setGroupTape(int tape);
    void getVisibleChips();
    void setRotationAngle(int arg);
    void createGroup();
    void removeGroup();
    void renameGroup();
    void rotate(double angle);
    void loadSMT();
    void sortByX();
    void sortByY();
    void sortByTape();
    void Rotate180();

    QTabWidget *tabWidget;
    DocumentWidget *docWidget;
    QDataWidgetMapper *mapper;
    QDataWidgetMapper *mapper2;
    QMenu *recentMenu;

    enum { MaxRecentFiles = 5 };
    QAction *recentFileActs[MaxRecentFiles];

    bool changed;
    QList<Chip*> clipboard;

};

#endif // MAINWINDOW_H
