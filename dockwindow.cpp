#include "dockwindow.h"
#include <QTextEdit>
#include <QDockWidget>

DockWindow::DockWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle(tr("DockWindows"));
    QTextEdit *te = new QTextEdit(this);
    te->setText(tr("Main Window"));
    te->setAlignment(Qt::AlignCenter);
    setCentralWidget(te);

    // 停靠窗口1
    QDockWidget *dock = new QDockWidget(tr("DockWindow1"), this);
    dock->setFeatures(QDockWidget::DockWidgetMovable);  // 可移动
    dock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    QTextEdit *te1 = new QTextEdit();
    te1->setText(tr("Window1, The dock widget can be moved between docks by the user"""));
    dock->setWidget(te1);
    addDockWidget(Qt::RightDockWidgetArea, dock);
    // 停靠窗口2
    dock = new QDockWidget(tr("DockWindow2"), this);
    dock->setFeatures(QDockWidget::DockWidgetClosable | QDockWidget::DockWidgetFloatable);
    QTextEdit *te2 = new QTextEdit();
    te2->setText(tr("window2, The dock widget can be detached from the main widow,""and floated an independent window, and can be closed"));
    dock->setWidget(te2);
    addDockWidget(Qt::RightDockWidgetArea, dock);
    // 停靠窗口3
    dock = new QDockWidget(tr("Window3"), this);
    dock->setFeatures(QDockWidget::AllDockWidgetFeatures);
    QTextEdit *te3 = new QTextEdit();
    te3->setText(tr("Window3, The dock widget can be closed, moved, and floated"));
    dock->setWidget(te3);
    addDockWidget(Qt::RightDockWidgetArea, dock);
}

DockWindow::~DockWindow()
{

}
