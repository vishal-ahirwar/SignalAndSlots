#include <QCoreApplication>
#include<QApplication>
#include<QWidget>
#include<QProgressBar>
#include<QSpinBox>
#include<QHBoxLayout>
#include<QTimer>

//...
class TestWidget:public QWidget
{
public:
    explicit TestWidget(QWidget*parent=nullptr);
    void onTimerTimeout();
private:
    QProgressBar*progress_bar{};
};

//default constructor
TestWidget::TestWidget(QWidget*parent):QWidget{parent}
{
    //layout
    QHBoxLayout*layout{new QHBoxLayout(this)};
    layout->setContentsMargins(QMargins(50,50,0,50));

    //QTimer
    QTimer*timer{new QTimer};
    timer->setInterval(1000);

    //progress bar
    progress_bar={new QProgressBar()};
    progress_bar->setMaximum(100);
    progress_bar->setMinimum(0);
    progress_bar->setMinimumWidth(256);
    layout->addWidget(progress_bar);

    //connecting spin box value change signal to progress bar setvalue function/slot
    connect(timer,&QTimer::timeout,this,&TestWidget::onTimerTimeout);
    timer->start();
};

void TestWidget::onTimerTimeout()
{
    progress_bar->setValue(progress_bar->value()+2);
};

int main(int argc, char *argv[])
{
    //QApplication is required in order to build widget applications in qt.
    QApplication a(argc, argv);

    //creating an object of TestWidget class
    TestWidget widget{};

    //calling inherited function show from QWidget base class
    widget.show();

    //calling event loop
    return a.exec();
}
