#include <iostream>

#include <DungeonGenerator.h>
#include <QDebug>
#include <QApplication>
#include <QTextEdit>
#include <QMainWindow>
#include <QMenu>
#include <QHBoxLayout>
#include <QSlider>
#include <QMenuBar>
#include <QSpinBox>
#include <QObject>

using namespace std;

void generate(QTextEdit* textEdit){
    DungeonGenerator mydungeon("tes", 100, 100);
    mydungeon.Generate();
    Grid griddata = mydungeon.GetGrid();
    textEdit->clear();

    // re-print grid
    for(Grid::iterator it=griddata.begin(); it!=griddata.end(); ++it) {
        for(GridLine::iterator itL = it->begin(); itL!=it->end(); ++itL){
            //entrance
            if(*itL==3){
                textEdit->setTextColor(QColor("cyan"));
                textEdit->insertPlainText("3");
            }
            if(*itL==4){
                textEdit->setTextColor(QColor("cyan"));
                textEdit->insertPlainText("4");
            }
            if(*itL==7){
                textEdit->setTextColor(QColor("magenta"));
                textEdit->insertPlainText("7");
            }
            if(*itL==6){
                textEdit->setTextColor(QColor("blue"));
                textEdit->insertPlainText("T");
            }
            if(*itL==8){
                textEdit->setTextColor(QColor("green"));
                textEdit->insertPlainText("8");
            }
            //floor
            if(*itL==1){
                textEdit->setTextColor(QColor("lightgray"));
                textEdit->insertPlainText("1");
            }
            //corridor
            if(*itL==2){
                textEdit->setTextColor(QColor("lightgray"));
                textEdit->insertPlainText("2");
            }
            if(*itL==0){
                textEdit->setTextColor(QColor("black"));
                textEdit->insertPlainText("0");
            }
            //door
            if(*itL==5){
                textEdit->setTextColor(QColor("yellow"));
                textEdit->insertPlainText("5");
            }
        }
        textEdit->insertPlainText("\n");
    }
}


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QMainWindow *w = new QMainWindow;
    w->setGeometry(300,300,700,700);

    QTextEdit *centralwidget = new QTextEdit();
    w->setCentralWidget(centralwidget);

    QMenuBar* menuBar = new QMenuBar();
    QMenu *fileMenu = new QMenu("Tools");
    menuBar->addMenu(fileMenu);
    QAction* action = new QAction("Generate");
    fileMenu->addAction(action);
    w->setMenuBar(menuBar);

    QObject::connect(action, &QAction::triggered,
                     [=]() { generate(centralwidget); });

    w->show();


    return a.exec();
}


