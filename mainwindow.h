#ifndef MAINPAGE_H
#define MAINPAGE_H

#include <QMainWindow>
#include <QInputEvent>
#include <QGraphicsDropShadowEffect>
#include <QToolBar>
#include <QPushButton>
#include <QVBoxLayout>
#include <QPropertyAnimation>
#include <QParallelAnimationGroup>
#include <QListView>
#include <QShortcut>
#include <QListWidgetItem>
#include <QMessageBox>
#include <thread>
#include <unistd.h>
#include "dictionary.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class mainpage; }
QT_END_NAMESPACE

class mainpage : public QMainWindow
{
    Q_OBJECT

public:
    mainpage(QWidget *parent = nullptr);
    bool eventFilter(QObject *obj, QEvent *event);
    ~mainpage();
    Dictionary myDict;
    int eventchecker = -1;
    int word_or_def=0;

private slots:
    void on_datasetBtt_clicked();

    void on_recommendationBar_itemClicked(QListWidgetItem *item);

    void on_quizBtt_clicked();

    void on_pushButton_21_clicked();

     bool isInFavList(std::string);


    void on_pushButton_3_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_20_clicked();



    void on_pushButton_clicked();
    bool isTrue(QString def);
    void on_pushButton_22_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_17_clicked();

    void on_favlistBtt_clicked();

private:
    Ui::mainpage *ui;
    void getPrediction(std::string s);
};

#endif // MAINPAGE_H
