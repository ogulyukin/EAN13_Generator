#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QDebug>
#include <QMessageBox>
#include <QFileDialog>
#include "fileio.h"
#include "generatorean13.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_fileButton_clicked();

    void on_goButton_clicked();

private:
    Ui::Widget *ui;
    QString Filename;
};
#endif // WIDGET_H
