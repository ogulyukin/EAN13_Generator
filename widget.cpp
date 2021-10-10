#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_fileButton_clicked()
{
    Filename = QFileDialog::getSaveFileName(this, "Open File",
                                            "/home",
                                            tr("Text files (*.txt);;All files (*.*)"));
    ui->label_3->setText(Filename);
}


void Widget::on_goButton_clicked()
{
    QList<QString> list;
    if(ui->ammountLineEdit->text() == "")
    {
        QMessageBox::information(this, "ОШИБКА", "Неверное значение\nколичества кодов!");
        return;
    }
    qint64 first = 0;
    qint64 last = 0;
    if(ui->firstCodeLineEdit->text().count() < 12 || ui->firstCodeLineEdit->text().count() > 13)
    {
        QMessageBox::information(this, "ОШИБКА", "Неверное значение\nпервого кода!");
        return;
    }
    QString temp = ui->firstCodeLineEdit->text();
    if(ui->firstCodeLineEdit->text().count() == 13)
    {
        temp.remove(12,1);
    }
    first = temp.toLongLong();
    qDebug() << "first: " << first;
    last = first + ui->ammountLineEdit->text().toInt();
    qDebug() << "last: " << last;

    for(qint64 i = first; i <= last; i++)
    {
        list.append(QString::number(GeneratorEAN13::generatecode(i)));
    }
    FileIO *file = new FileIO(Filename);
    bool ret = file->saveFile(list);
    delete file;
    if(ret)
    {
        QMessageBox::information(this, "УСПЕХ", "Генерация кодов\nзавершена успешно!");
    }else
    {
        QMessageBox::information(this, "ОШИБКА", "При генерация кодов\nпроизошла ошибка!");
    }

}

