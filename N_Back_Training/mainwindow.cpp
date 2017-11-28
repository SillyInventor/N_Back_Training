#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <list>
#include <qdatetime.h>
#include <QTimer>
#include <QPixmap>

int currentQuestion = 0;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());
}

MainWindow::~MainWindow()
{
    delete ui;

    QPixmap selected(":/imgs/imgs/selected.png");
    QPixmap notSelected(":/imgs/imgs/NotSelected.png");
}

void MainWindow::on_start_clicked()
{
    int questionTime = 3000; //in milliseconds
    int back = ui->back->value();
    int r = 0;
    int length = ui->questions->value();
    int visualQuestions [length];
    int audioQuestions [length];

    for (int i =0; i<length; i++)
    {
        if(!visualQuestions[i])
        {
            visualQuestions[i] = round(qrand()%9);
        }
        if(!audioQuestions[i])
        {
            audioQuestions[i] = round(qrand()%9);
        }
        if(i+back<length)
        {
            r = qrand()%100;
            if (r>75) {
                visualQuestions[i+back] = visualQuestions[i];
            }
            else if (r>50) {
                audioQuestions[i+back] = audioQuestions[i];
            }
            else if (r > 25) {
                visualQuestions[i+back] = visualQuestions[i];
                audioQuestions[i+back] = audioQuestions[i];
            }
        }
    }

    currentQuestion = 0;
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(questionTime);
}

void MainWindow::timeout()
{

}
