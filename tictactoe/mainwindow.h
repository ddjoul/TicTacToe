#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "StyleHelper.h"
#include <QPushButton>
#include <QTimer>
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_GameButton_clicked();
    void on_FirstLeftButton_clicked();
    void on_FirstRightButton_clicked();

    void on_SecondLeftButton_clicked();

    void on_SecondRightButton_clicked();
    void on_QuitButton_clicked();

    void on_PlayButton_clicked();

    void BotVsBot();
private:
    void ButtonClear(bool k);
    int num;
    void Win_Position();
    bool k;
    Ui::MainWindow *ui;
    StyleHelper SH;
    void SetColorRightButton(bool k);
    void SetColorLeftButton(bool k);
    bool FirstPlayer;
    bool SecondPlayer;
    void Draw();
    void EndGame();
    QString Symbols[2] = {"X", "O"};
    QTimer* timer;
};
#endif // MAINWINDOW_H
