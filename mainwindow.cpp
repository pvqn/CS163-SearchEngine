#include "mainwindow.h"
#include "./ui_mainwindow.h"


mainpage::mainpage(QWidget *parent)
    : QMainWindow(parent)
    , myDict(Dictionary("slang", '\t'))
    , ui(new Ui::mainpage)
{

    this->setFixedSize(800, 500);
    this->setUnifiedTitleAndToolBarOnMac(false); // activate Mac-style toolbar
   // this->setAttribute(Qt::WA_TranslucentBackground);
    this->setWindowOpacity(0.985);
    QCoreApplication::instance()->installEventFilter(this);
    //ui->datasetBtt->setText("<p style='text-align:left;'>Hello</p>This text is left aligned<span style='float:right;'> This text is right aligned </span></p>");
    ui->setupUi(this);
    ui->leftpage->setGeometry(QRect(10, 10, 251, 425));
    ui->searchBar->setGeometry(10, 10, 251, 28);
    ui->recommendationBar->setGeometry(10, 50, 251, 300);
    ui->line->setGeometry(260, 0, 16, 481);
    ui->recommendationBar->setVisible(false);
   // myDict = Dictionary("slang.txt", '\t');
    //qDebug() << myDict.size << "\n";


}

void mainpage::getPrediction(std::string pref) {
    ui->recommendationBar->clear();
    std::vector<std::string> preds = myDict.prediction(pref);
    for (int i = 0; i < preds.size(); i++) {
        //qDebug() << QString::fromUtf8(preds[i]) << " ";
        QListWidgetItem* item = new QListWidgetItem;
        item->setText(QString::fromUtf8(preds[i]));
        ui->recommendationBar->addItem(item);
    }
    //qDebug() << "\n";
}

bool mainpage::eventFilter(QObject *obj, QEvent *event)
{
    if ( !dynamic_cast<QInputEvent*>( event ) ) return false;
    while ( obj != NULL ) {
        if (obj == (QObject*)ui->datasetBtt || obj == (QObject*)ui->searchbyBtt || obj == (QObject*)ui->favlistBtt || obj == (QObject*)ui->historyBtt || obj == (QObject*)ui->quizBtt) {
            QPushButton* k = (QPushButton*) obj;
            if (event->type() == QEvent::HoverEnter)
            {
                k->setStyleSheet("background-color: rgb(241, 242, 246);");
                QGraphicsDropShadowEffect* effect = new QGraphicsDropShadowEffect( );
                effect->setBlurRadius( 10 );
                effect->setOffset(1.0);
                k->setGraphicsEffect( effect );
            }
            else if (event->type() == QEvent::HoverLeave) {
                k->setStyleSheet("background-color: rgb(193, 193, 193);");
                k->setFocusPolicy(Qt::NoFocus);
                k->setGraphicsEffect( nullptr );
            }
            else if (event->type() == QEvent::MouseButtonPress) {
                QGraphicsDropShadowEffect* effect = new QGraphicsDropShadowEffect( );
                effect->setBlurRadius( 10 );
                effect->setOffset(3.0);
                k->setGraphicsEffect( effect );
                effect->setOffset(1.0);
                k->setGraphicsEffect( effect );
            }
        }
        else if (obj == (QObject*) ui->searchBar) {
            QLineEdit* k = (QLineEdit*) obj;
            if (event->type() == QEvent::KeyRelease) {
                QKeyEvent* events = static_cast<QKeyEvent*>(event);
                if (events->key() == Qt::Key_Backspace) {
                    QString temptext = k->text();
                    if (temptext.length() == 0) {
                        //ui->leftpage->setGeometry(QRect(0, 0, 251, 425) );
                        QParallelAnimationGroup* groupAni = new QParallelAnimationGroup;
                        QPropertyAnimation *animation1 = new QPropertyAnimation(ui->settingText, "geometry");
                        animation1->setDuration(100);
                        animation1->setStartValue(QRect(0, ui->settingText->geometry().y(), 251, 425));
                        animation1->setEndValue(QRect(0, 0, 251, 425));
                        groupAni->addAnimation(animation1);
                        QPropertyAnimation *animation2 = new QPropertyAnimation(ui->datasetBtt, "geometry");
                        animation2->setDuration(100);
                        animation2->setStartValue(QRect(0, ui->datasetBtt->geometry().y(), 251, 425));
                        animation2->setEndValue(QRect(0, 30, 251, 425));
                        groupAni->addAnimation(animation2);
                        QPropertyAnimation *animation3 = new QPropertyAnimation(ui->searchbyBtt, "geometry");
                        animation3->setDuration(100);
                        animation3->setStartValue(QRect(0, ui->searchbyBtt->geometry().y(), 251, 425));
                        animation3->setEndValue(QRect(0, 75, 251, 425));
                        groupAni->addAnimation(animation3);
                        QPropertyAnimation *animation4 = new QPropertyAnimation(ui->extensionText, "geometry");
                        animation4->setDuration(100);
                        animation4->setStartValue(QRect(0, ui->extensionText->geometry().y(), 251, 425));
                        animation4->setEndValue(QRect(0, 120, 251, 425));
                        groupAni->addAnimation(animation4);
                        QPropertyAnimation *animation5 = new QPropertyAnimation(ui->favlistBtt, "geometry");
                        animation5->setDuration(100);
                        animation5->setStartValue(QRect(0, ui->favlistBtt->geometry().y(), 251, 425));
                        animation5->setEndValue(QRect(0, 150, 251, 425));
                        groupAni->addAnimation(animation5);
                        QPropertyAnimation *animation6 = new QPropertyAnimation(ui->historyBtt, "geometry");
                        animation6->setDuration(100);
                        animation6->setStartValue(QRect(0, ui->historyBtt->geometry().y(), 251, 425));
                        animation6->setEndValue(QRect(0, 195, 251, 425));
                        groupAni->addAnimation(animation6);
                        QPropertyAnimation *animation7 = new QPropertyAnimation(ui->quizBtt, "geometry");
                        animation7->setDuration(100);
                        animation7->setStartValue(QRect(0, ui->quizBtt->geometry().y(), 251, 425));
                        animation7->setEndValue(QRect(0, 240, 251, 425));
                        groupAni->addAnimation(animation7);
                        QPropertyAnimation *animation8 = new QPropertyAnimation(ui->groupText, "geometry");
                        animation8->setDuration(100);
                        animation8->setStartValue(QRect(0, ui->groupText->geometry().y(), 251, 425));
                        animation8->setEndValue(QRect(0, 385, 251, 425));
                        groupAni->addAnimation(animation8);
                        QPropertyAnimation *animation9 = new QPropertyAnimation(ui->courseText, "geometry");
                        animation9->setDuration(100);
                        animation9->setStartValue(QRect(0, ui->courseText->geometry().y(), 251, 425));
                        animation9->setEndValue(QRect(0, 410, 251, 425));
                        groupAni->addAnimation(animation9);
                        groupAni->start();

                        ui->recommendationBar->setVisible(false);
                    }
                    getPrediction(temptext.toStdString());
                }
                else {
                    QString temptext = k->text();
                    if (temptext.length() > 0) {
                        QParallelAnimationGroup* groupAni = new QParallelAnimationGroup;
                        QPropertyAnimation *animation1 = new QPropertyAnimation(ui->settingText, "geometry");
                        animation1->setDuration(100);
                        animation1->setStartValue(QRect(0, ui->settingText->geometry().y(), 251, 425));
                        animation1->setEndValue(QRect(0, 315, 251, 425));
                        groupAni->addAnimation(animation1);
                        QPropertyAnimation *animation2 = new QPropertyAnimation(ui->datasetBtt, "geometry");
                        animation2->setDuration(100);
                        animation2->setStartValue(QRect(0, ui->datasetBtt->geometry().y(), 251, 425));
                        animation2->setEndValue(QRect(0, 345, 251, 425));
                        groupAni->addAnimation(animation2);
                        QPropertyAnimation *animation3 = new QPropertyAnimation(ui->searchbyBtt, "geometry");
                        animation3->setDuration(100);
                        animation3->setStartValue(QRect(0, ui->searchbyBtt->geometry().y(), 251, 425));
                        animation3->setEndValue(QRect(0, 390, 251, 425));
                        groupAni->addAnimation(animation3);
                        QPropertyAnimation *animation4 = new QPropertyAnimation(ui->extensionText, "geometry");
                        animation4->setDuration(100);
                        animation4->setStartValue(QRect(0, ui->extensionText->geometry().y(), 251, 425));
                        animation4->setEndValue(QRect(0, 435, 251, 425));
                        groupAni->addAnimation(animation4);
                        QPropertyAnimation *animation5 = new QPropertyAnimation(ui->favlistBtt, "geometry");
                        animation5->setDuration(100);
                        animation5->setStartValue(QRect(0, ui->favlistBtt->geometry().y(), 251, 425));
                        animation5->setEndValue(QRect(0, 465, 251, 425));
                        groupAni->addAnimation(animation5);
                        QPropertyAnimation *animation6 = new QPropertyAnimation(ui->historyBtt, "geometry");
                        animation6->setDuration(100);
                        animation6->setStartValue(QRect(0, ui->historyBtt->geometry().y(), 251, 425));
                        animation6->setEndValue(QRect(0, 510, 251, 425));
                        groupAni->addAnimation(animation6);
                        QPropertyAnimation *animation7 = new QPropertyAnimation(ui->quizBtt, "geometry");
                        animation7->setDuration(100);
                        animation7->setStartValue(QRect(0, ui->quizBtt->geometry().y(), 251, 425));
                        animation7->setEndValue(QRect(0, 555, 251, 425));
                        groupAni->addAnimation(animation7);
                        QPropertyAnimation *animation8 = new QPropertyAnimation(ui->groupText, "geometry");
                        animation8->setDuration(100);
                        animation8->setStartValue(QRect(0, ui->groupText->geometry().y(), 251, 425));
                        animation8->setEndValue(QRect(0, 700, 251, 425));
                        groupAni->addAnimation(animation8);
                        QPropertyAnimation *animation9 = new QPropertyAnimation(ui->courseText, "geometry");
                        animation9->setDuration(100);
                        animation9->setStartValue(QRect(0, ui->courseText->geometry().y(), 251, 425));
                        animation9->setEndValue(QRect(0, 725, 251, 425));
                        groupAni->addAnimation(animation9);
                        groupAni->start();
                        ui->recommendationBar->setVisible(true);
                    }
                    getPrediction(temptext.toStdString());
                }
            }
        }
        obj = obj->parent();
    }
    return false;
}

mainpage::~mainpage()
{
    delete ui;
}


void mainpage::on_datasetBtt_clicked()
{
    ui->searchBar->clearFocus();
}
bool mainpage::isInFavList(std::string temp)
{
    std::ifstream fin;
    fin.open("user_favlist.txt");
    std::vector<std::string> favList;
    std::string t;
    while (std::getline(fin,t))
    {
        favList.push_back(t);
    }
    fin.close();
    for (int i=0; i<favList.size(); ++i)
        if (favList[i]==temp) return true;
    return false;

}
void mainpage::on_recommendationBar_itemClicked(QListWidgetItem *item)
{
    ui->stackedWidget->setCurrentWidget(ui->page);
    ui->word_2->setText(item->text());
    ui->def_2->setText(QString::fromUtf8(myDict.search(item->text().toStdString())->def));
    //ui->word->setText(item->text());
    //ui->def->setText(QString::fromUtf8(myDict.search(item->text().toStdString())->def));
    if (isInFavList(item->text().toStdString()))
        ui->pushButton_16->setText("❤");
    else ui->pushButton_16->setText("♡");
}


void mainpage::on_quizBtt_clicked()
{
    word_or_def=0;
 ui->stackedWidget->setCurrentWidget(ui->page_2);
 myDict.random4Word();
 std::vector<TreeNode*>result=myDict.getVector();
 int index=myDict.getIndex();

 ui->textBrowser_3->setText("what is the definition of \"" + QString::fromUtf8(get_word(result[index])) + "\" ?");
 ui->pushButton->setText(QString::fromUtf8(result[0]->def));
  ui->pushButton_19->setText(QString::fromUtf8(result[1]->def));
   ui->pushButton_20->setText(QString::fromUtf8(result[2]->def));
    ui->pushButton_3->setText(QString::fromUtf8(result[3]->def));

}

bool mainpage::isTrue(QString def)
{

   if (word_or_def==0)
    if (def==QString::fromUtf8(myDict.getVector()[myDict.getIndex()]->def))
        return true;
   if (word_or_def==1)
   if (def==QString::fromUtf8(get_word(myDict.getVector()[myDict.getIndex()])))
           return true;

     return false;
}


void mainpage::on_pushButton_clicked()
{
   if (isTrue(ui->pushButton->text()))
       ui->textBrowser_3->setText("CORRECT!");
  else
   ui->textBrowser_3->setText("WRONG!");
}
void mainpage::on_pushButton_19_clicked()
{
   if (isTrue(ui->pushButton_19->text()))
       ui->textBrowser_3->setText("CORRECT!");
   else
    ui->textBrowser_3->setText("WRONG!");
}
void mainpage::on_pushButton_20_clicked()
{
   if (isTrue(ui->pushButton_20->text()))
       ui->textBrowser_3->setText("CORRECT!");
   else
  ui->textBrowser_3->setText("WRONG!");
}
void mainpage::on_pushButton_3_clicked()
{
   if (isTrue(ui->pushButton_3->text()))
       ui->textBrowser_3->setText("CORRECT!");
   else
   ui->textBrowser_3->setText("WRONG!");
}


void mainpage::on_pushButton_22_clicked()
{
    myDict.random4Word();
    std::vector<TreeNode*>result=myDict.getVector();
    int index=myDict.getIndex();
    if (word_or_def==0)
    {
        ui->textBrowser_3->setText("what is the definition of \"" + QString::fromUtf8(get_word(result[index])) + "\" ?");
        ui->pushButton->setText(QString::fromUtf8(result[0]->def));
         ui->pushButton_19->setText(QString::fromUtf8(result[1]->def));
          ui->pushButton_20->setText(QString::fromUtf8(result[2]->def));
           ui->pushButton_3->setText(QString::fromUtf8(result[3]->def));
    }
    else
    {

        ui->textBrowser_3->setText("what is the word of \"" + QString::fromUtf8(result[index]->def)+ "\" ?");
        ui->pushButton->setText(QString::fromUtf8(get_word(result[0])));
         ui->pushButton_19->setText(QString::fromUtf8(get_word(result[1])));
          ui->pushButton_20->setText(QString::fromUtf8(get_word(result[2])));
           ui->pushButton_3->setText(QString::fromUtf8(get_word(result[3])));
    }
}


void mainpage::on_pushButton_21_clicked()
{
    if (word_or_def==1) word_or_def=0; else word_or_def=1;
    myDict.random4Word();
    std::vector<TreeNode*>result=myDict.getVector();
    int index=myDict.getIndex();
    if (word_or_def==0)
    {
        ui->textBrowser_3->setText("what is the definition of \"" + QString::fromUtf8(get_word(result[index])) + "\" ?");
        ui->pushButton->setText(QString::fromUtf8(result[0]->def));
         ui->pushButton_19->setText(QString::fromUtf8(result[1]->def));
          ui->pushButton_20->setText(QString::fromUtf8(result[2]->def));
           ui->pushButton_3->setText(QString::fromUtf8(result[3]->def));
    }
    else
    {
        ui->textBrowser_3->setText("what is the word of \"" + QString::fromUtf8(result[index]->def) + "\" ?");
        ui->pushButton->setText(QString::fromUtf8(get_word(result[0])));
         ui->pushButton_19->setText(QString::fromUtf8(get_word(result[1])));
          ui->pushButton_20->setText(QString::fromUtf8(get_word(result[2])));
           ui->pushButton_3->setText(QString::fromUtf8(get_word(result[3])));
    }
}


void mainpage::on_pushButton_16_clicked()
{
    if (ui->pushButton_16->text()=="❤")
    {
        actionOnFavList(ui->word_2->text().toStdString(),true);
        ui->pushButton_16->setText("♡");
    }
    else
    {
        actionOnFavList(ui->word_2->text().toStdString(),false);
        ui->pushButton_16->setText("❤");
    }

}


void mainpage::on_pushButton_17_clicked()
{

}


void mainpage::on_favlistBtt_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_3);
    ui->listWidget->clear();
    std::ifstream fin;
    fin.open("user_favlist.txt");
    std::string t;
    int i=1;
    while (getline(fin,t))
    {
        ui->listWidget->addItem(QString::number(i)+". "+ QString::fromUtf8(t));
           ++i;
    }
    fin.close();
}


void mainpage::on_historyBtt_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_4);
    ui->listWidget_2->clear();

    std::ifstream in("history.txt");

    if (in)
    {
        std::string str;

        size_t index = 1;

        while (getline(in, str))
        {
            ui->listWidget_2->addItem(QString::number(index++) + "." + QString::fromUtf8(str.c_str()));
        }
    }
}

