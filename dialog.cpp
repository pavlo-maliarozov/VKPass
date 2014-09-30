#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    /* Разрешение на автоматическую загрузку картинок в странице*/
        QWebSettings::globalSettings()->setAttribute(QWebSettings::AutoLoadImages,true);
        /* Разрешение на запуск java-скриптов*/
        QWebSettings::globalSettings()->setAttribute(QWebSettings::JavascriptEnabled, true);
        /* Разрешение  на использование плагинов*/
        QWebSettings::globalSettings()->setAttribute(QWebSettings::PluginsEnabled, true);

        this->connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(buttonClicked()));

        }

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_4_clicked()
{
    ui->webView->back();
}

void Dialog::on_pushButton_clicked()
{
    ui->webView->forward();
}

void Dialog::on_pushButton_2_clicked()
{
    ui->webView->reload();
}

void Dialog::on_pushButton_3_clicked()
{
    ui->webView->load("http://"+ui->lineEdit->text());
}

void Dialog::on_pushButton_5_clicked()
{

    QString password = ui->webView->page()->mainFrame()->
            evaluateJavaScript("document.getElementById('quick_pass').value").toString();
    //QMessageBox::information(this, "Password", password);
    QString filename = "C:/code/pass.txt";
    QFile file(filename);
    QTextStream out(&file);
    if(!file.open(QFile::WriteOnly |
                      QFile::Text))
        {
            qDebug() << " Could not open file for writing";
            return;
        }
    out << password;
    file.flush();
    file.close();
}
