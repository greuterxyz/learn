#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
class QAction;
class QActionGroup;
class QLabel;
class QMenu;
QT_END_NAMESPACE

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void contextMenuEvent(QContextMenuEvent *event);

private slots:
    void open();
    void help();

private:
    void createActions();
    void createMenus();

    Ui::MainWindow *ui;

    QString filename;

    QMenu *fileMenu;
    QMenu *helpMenu;

    QAction *openAct;
    QAction *exitAct;

    QAction *helpAct;

    QLabel *infoLabel;
};

#endif // MAINWINDOW_H
