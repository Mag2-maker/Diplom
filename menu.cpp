#include "menu.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTableView>
#include <QLayout>
#include <QTextStream>
#include <QDebug>
#include <QFileDialog>

Menu::Menu()
{

}

void Menu::SaveFile(Ui::MainWindow *ui)
{
    //QString fileName = QFileDialog::getSaveFileName (this, tr("Save file"), "", tr("XML Files (*.xml)"));
    //QFile file("data.xlsx");
    QString strFilter="*.csv";
    QString fileName = QFileDialog::getSaveFileName(0, "Сохранить результат как","", "Текстовые файлы (*.csv);;Все файлы (*.*)",&strFilter);
    QFile file(fileName);
        if( file.open( QFile::WriteOnly | QFile::Text ) )
            {
                QTextStream ts( &file );
                QStringList strList;

                strList << "\" \"";
                for( int c = 0; c < ui->tableView->horizontalHeader()->count(); ++c )
                {
                    qDebug()<<c;
                    strList << "\""+ui->tableView->model()->headerData(c, Qt::Horizontal).toString()+"\"";
                    qDebug()<<strList;
                }
                ts << strList.join( ";" )+"\n";

                for( int r = 0; r < ui->tableView->verticalHeader()->count(); ++r )
                {
                    qDebug()<<r;
                    strList.clear();
                    strList << "\""+ui->tableView->model()->headerData(r, Qt::Vertical).toString()+"\"";
                    for( int c = 0; c < ui->tableView->horizontalHeader()->count(); ++c )
                    {
                        strList << "\""+ui->tableView->model()->data(ui->tableView->model()->index(r, c), Qt::DisplayRole).toString()+"\"";
                        qDebug()<<strList;
                    }
                    ts << strList.join( ";" )+"\n";
                }
                file.close();
            }
}
