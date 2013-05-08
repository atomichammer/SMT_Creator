#ifndef BASICSETTINGS_H
#define BASICSETTINGS_H

#include <QDialog>
#include <QCloseEvent>
#include "basicsettingsmodel.h"

namespace Ui {
class BasicSettings;
}

class BasicSettings : public QDialog
{
    Q_OBJECT
    
public:
    explicit BasicSettings(QWidget *parent = 0);
    ~BasicSettings();
    
    void loadFile(const QString &fileName);
    void fileOpen();
    void saveFile();
private slots:
    void on_pbPickerX_clicked();

    void on_pbShifterX_clicked();

    void on_pbPickerY_clicked();

    void on_pbShifterY_clicked();

private:
    void closeEvent(QCloseEvent *event);
    Ui::BasicSettings *ui;
    BasicSettingsModel *model;
};

#endif // BASICSETTINGS_H
