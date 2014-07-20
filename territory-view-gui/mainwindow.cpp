#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtGui>

#include "sites.h"
#include "xml_parse.h"

xml_parse parse;
sites _sites;
struct site _site;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QWidget *widget = new QWidget;
    setCentralWidget(widget);

    QWidget *topFiller = new QWidget;
    topFiller->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    infoLabel = new QLabel(tr("<i>Choose a menu option, or right-click to "
                              "invoke a context menu</i>"));
    infoLabel->setFrameStyle(QFrame::StyledPanel | QFrame::Sunken);
    infoLabel->setAlignment(Qt::AlignCenter);

    textbrowser = new QTextBrowser();
    textbrowser->setFrameStyle(QFrame::StyledPanel | QFrame::Sunken);
    textbrowser->setAlignment(Qt::AlignLeft);

    QWidget *bottomFiller = new QWidget;
    bottomFiller->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);



    QVBoxLayout *layout = new QVBoxLayout;
    layout->setMargin(5);
    layout->addWidget(topFiller);
    layout->addWidget(textbrowser);
    layout->addWidget(infoLabel);
    layout->addWidget(bottomFiller);
    widget->setLayout(layout);

    createActions();
    createMenus();

    QString message = tr("A context menu is available by right-clicking");
    statusBar()->showMessage(message);

    setWindowTitle(tr("Menus"));
    setMinimumSize(160, 160);
    resize(480, 320);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// This is the right click menu
void MainWindow::contextMenuEvent(QContextMenuEvent *event)
{
    QMenu menu(this);
    menu.addAction(openAct);
    menu.addAction(exitAct);
    menu.exec(event->globalPos());
}

void MainWindow::open()
{
    infoLabel->setText(tr("Invoked <b>File|Open</b>"));

    QString filename = QFileDialog::getOpenFileName(this,
                                                    tr("Open File"), QDir::homePath());
    if (!filename.isEmpty()) {
        infoLabel->setText(tr("Opened file %1").arg(filename));
        parse.process_xml(filename.toStdString());
        //_site = new site[parse.get_num_sites()];
        if(parse.get_xml_load_status()==true)
        {
            infoLabel->setText(tr("XML successfully parsed"));
            for(int i = 1; i<parse.get_num_sites(); i++)
            {
                QString qstr_name = QString::fromStdString(parse.return_site()[i].name);
                QString qstr_type = QString::fromStdString(parse.return_site()[i].type);
                //QString qstr_x = QString::fromStdString(parse.return_site()[i].x);
                //QString qstr_y = QString::from (parse.return_site()[i].y);
                textbrowser->append(tr("Name: %1").arg(qstr_name));
                textbrowser->append(tr("Type: %1").arg(qstr_type));
            }

        }
        else
            infoLabel->setText(tr("XML parse failed"));
    }

}

void MainWindow::help()
{
    infoLabel->setText(tr("Invoked <b>Help|Help</b>"));
}

void MainWindow::createActions()
{
    openAct = new QAction(tr("&Open..."), this);
    openAct->setShortcuts(QKeySequence::Open);
    openAct->setStatusTip(tr("Open an existing file"));
    connect(openAct, SIGNAL(triggered()), this, SLOT(open()));

    exitAct = new QAction(tr("&Exit"), this);
    exitAct->setShortcuts(QKeySequence::Close);
    exitAct->setStatusTip(tr("Close the program"));
    connect(exitAct, SIGNAL(triggered()), this, SLOT(close()));

    helpAct = new QAction(tr("&Help"), this);
    helpAct->setShortcuts(QKeySequence::HelpContents);
    helpAct->setStatusTip(tr("Get help with the program"));
    connect(helpAct, SIGNAL(triggered()), this, SLOT(help()));
}

void MainWindow::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(openAct);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAct);

    helpMenu = menuBar()->addMenu(tr("&Help"));
    helpMenu->addAction(helpAct);
}

