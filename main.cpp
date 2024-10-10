#include <QCoreApplication>
#include<QApplication>
#include<QWidget>
#include<QProgressBar>
#include<QSpinBox>
#include<QHBoxLayout>

//...
class TestWidget:public QWidget
{
public:
    explicit TestWidget(QWidget*parent=nullptr);
};

//default constructor
TestWidget::TestWidget(QWidget*parent):QWidget{parent}
{
    //layout
    QHBoxLayout*layout{new QHBoxLayout(this)};
    layout->setContentsMargins(QMargins(50,50,0,50));

    //spin box
    QSpinBox*spin_box{new QSpinBox()};
    spin_box->setMaximum(100);
    spin_box->setMinimum(0);
    layout->addWidget(spin_box);

    //progress bar
    QProgressBar*progress_bar{new QProgressBar()};
    progress_bar->setMaximum(100);
    progress_bar->setMinimum(0);
    progress_bar->setMinimumWidth(256);
    layout->addWidget(progress_bar);

    //connecting spin box value change signal to progress bar setvalue function/slot
    connect(spin_box,&QSpinBox::valueChanged,progress_bar,&QProgressBar::setValue);
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
