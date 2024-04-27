#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "StyleHelper.h"
#include <QApplication>
#include <QColorSpace>
#include <QDebug>
#include <ctime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    srand(time(NULL));
    ui->setupUi(this);
    int n = 3;
    SetColorRightButton(1);
    SetColorLeftButton(1);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            QPushButton* button = new QPushButton("");
            button->setMinimumSize(300/n, 300/n);
            button->setStyleSheet(SH.GameButton());
            connect(button, &QPushButton::clicked, this, &MainWindow::on_GameButton_clicked);
            ui->Buttons->addWidget(button, i, j);
        }
    }
    FirstPlayer = 0;
    SecondPlayer = 0;
    ui->QuitButton->setEnabled(false);
    EndGame();
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::BotVsBot);
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::SetColorRightButton(bool k)
{
    if(k == 1){
        ui->FirstLeftButton->setStyleSheet(SH.ActiveButton());
        ui->FirstRightButton->setStyleSheet(SH.NotActiveButton());
    }
    else {
        ui->FirstLeftButton->setStyleSheet(SH.NotActiveButton());
        ui->FirstRightButton->setStyleSheet(SH.ActiveButton());
    }
}

void MainWindow::SetColorLeftButton(bool k)
{
    if(k == 1){
        ui->SecondLeftButton->setStyleSheet(SH.ActiveButton());
        ui->SecondRightButton->setStyleSheet(SH.NotActiveButton());
    }
    else {
        ui->SecondLeftButton->setStyleSheet(SH.NotActiveButton());
        ui->SecondRightButton->setStyleSheet(SH.ActiveButton());
    }
}

void MainWindow::on_GameButton_clicked()
{
    QPushButton* clickedButton = qobject_cast<QPushButton*>(sender());
    int temp_i = 0, temp_j = 0;
    clickedButton->setText(Symbols[k]);
    clickedButton->setEnabled(false);
    clickedButton->setStyleSheet(clickedButton->styleSheet() + SH.StyleHelper::SymbolsColor(k, clickedButton->minimumHeight()));
    k = (k+1)%2;
    Draw();
    Win_Position();
    if(FirstPlayer || SecondPlayer){
        while(qobject_cast<QPushButton*>(ui->Buttons->itemAtPosition(temp_i, temp_j)->widget())->text() != "") {
            temp_i = rand() % (ui->Buttons->columnCount());
            temp_j = rand() % (ui->Buttons->columnCount());
        }
        qobject_cast<QPushButton*>(ui->Buttons->itemAtPosition(temp_i, temp_j)->widget())->setText(Symbols[k]);
        qobject_cast<QPushButton*>(ui->Buttons->itemAtPosition(temp_i, temp_j)->widget())->setEnabled(false);
        qobject_cast<QPushButton*>(ui->Buttons->itemAtPosition(temp_i, temp_j)->widget())->setStyleSheet(clickedButton->styleSheet() + SH.StyleHelper::SymbolsColor(k, clickedButton->minimumHeight()));
        k = (k+1)%2;
    }
    Draw();
    Win_Position();
}

void MainWindow::on_FirstLeftButton_clicked()
{
    SetColorRightButton(1);
    FirstPlayer = 0;
}

void MainWindow::on_FirstRightButton_clicked()
{
    SetColorRightButton(0);
    FirstPlayer = 1;
}


void MainWindow::on_SecondLeftButton_clicked()
{
    SetColorLeftButton(1);
    SecondPlayer = 0;
}


void MainWindow::on_SecondRightButton_clicked()
{
    SetColorLeftButton(0);
    SecondPlayer = 1;
}


void MainWindow::on_QuitButton_clicked()
{
    EndGame();
    ui->Win_table->setText("Player #" + QString::number(k+1) + " give up");
    ButtonClear(true);
}

void MainWindow::Draw()
{
    for(int i = 0; i < ui->Buttons->rowCount(); i++){
        for(int j = 0; j < ui->Buttons->columnCount(); j++){
            QPushButton* Button = qobject_cast<QPushButton*>(ui->Buttons->itemAtPosition(i, j)->widget());
            if(Button->text() == "") return;
        }
    }
    num = -1;
    EndGame();
    ui->Win_table->setText("Draw");
    ButtonClear(true);
}

void MainWindow::EndGame(){
    for(int i = 0; i < ui->Buttons->rowCount(); i++){
        for(int j = 0; j < ui->Buttons->columnCount(); j++){
            QPushButton* Button = qobject_cast<QPushButton*>(ui->Buttons->itemAtPosition(i, j)->widget());
            Button->setEnabled(false);
        }
    }
}

void MainWindow::Win_Position(){
    int l = 1;
    for(int i = 0; i < ui->Buttons->rowCount(); i++){
        for(int j = 0; j < ui->Buttons->columnCount() - 1; j++){
            QPushButton* Button1 = qobject_cast<QPushButton*>(ui->Buttons->itemAtPosition(i, j)->widget());
            QPushButton* Button2 = qobject_cast<QPushButton*>(ui->Buttons->itemAtPosition(i, j+1)->widget());
            if(Button1->text() == Button2->text() && Button1->text() != "") l++;
        }
        if(l == ui->Buttons->rowCount()) {
            EndGame();
            ui->Win_table->setText(qobject_cast<QPushButton*>(ui->Buttons->itemAtPosition(i, 0)->widget())->text() + " win!");
            ButtonClear(true);
            num = -1;
        }
        l = 1;
    }

    for(int i = 0; i < ui->Buttons->rowCount(); i++){
        for(int j = 0; j < ui->Buttons->columnCount() - 1; j++){
            QPushButton* Button1 = qobject_cast<QPushButton*>(ui->Buttons->itemAtPosition(j, i)->widget());
            QPushButton* Button2 = qobject_cast<QPushButton*>(ui->Buttons->itemAtPosition(j+1, i)->widget());
            if(Button1->text() == Button2->text() && Button1->text() != "") l++;
        }
        if(l == ui->Buttons->rowCount()) {
            EndGame();
            ui->Win_table->setText(qobject_cast<QPushButton*>(ui->Buttons->itemAtPosition(0, i)->widget())->text() + " win!");
            ButtonClear(true);
            num = -1;
        }
        l = 1;
    }
    for(int i = 0; i < ui->Buttons->rowCount() - 1; i++){
            QPushButton* Button1 = qobject_cast<QPushButton*>(ui->Buttons->itemAtPosition(i, i)->widget());
            QPushButton* Button2 = qobject_cast<QPushButton*>(ui->Buttons->itemAtPosition(i+1, i+1)->widget());
            if(Button1->text() == Button2->text() && Button1->text() != "") l++;
        }
    if(l == ui->Buttons->rowCount()) {
        EndGame();
        ui->Win_table->setText(qobject_cast<QPushButton*>(ui->Buttons->itemAtPosition(0, 0)->widget())->text() + " win!");
        ButtonClear(true);
        num = -1;
    }
    l = 1;

    for(int i = 0; i < ui->Buttons->rowCount() - 1; i++){
        QPushButton* Button1 = qobject_cast<QPushButton*>(ui->Buttons->itemAtPosition(i, ui->Buttons->rowCount() - 1 - i)->widget());
        QPushButton* Button2 = qobject_cast<QPushButton*>(ui->Buttons->itemAtPosition(i+1, ui->Buttons->rowCount() - 2 - i)->widget());
        if(Button1->text() == Button2->text() && Button1->text() != "") l++;
    }
    if(l == ui->Buttons->rowCount()) {
        EndGame();
        ui->Win_table->setText(qobject_cast<QPushButton*>(ui->Buttons->itemAtPosition(0, ui->Buttons->rowCount() - 1)->widget())->text() + " win!");
        ButtonClear(true);
        num = -1;
    }
}

void MainWindow::ButtonClear(bool l){
    ui->PlayButton->setEnabled(l);
    ui->QuitButton->setEnabled((l+1)%2);
    ui->FirstLeftButton->setEnabled(l);
    ui->FirstRightButton->setEnabled(l);
    ui->SecondLeftButton->setEnabled(l);
    ui->SecondRightButton->setEnabled(l);
}

void MainWindow::BotVsBot(){
    int temp_i = rand() % (ui->Buttons->columnCount());
    int temp_j = rand() % (ui->Buttons->columnCount());
    while(qobject_cast<QPushButton*>(ui->Buttons->itemAtPosition(temp_i, temp_j)->widget())->text() != "") {
        temp_i = rand() % (ui->Buttons->columnCount());
        temp_j = rand() % (ui->Buttons->columnCount());
    }
    QPushButton* Button2 = qobject_cast<QPushButton*>(ui->Buttons->itemAtPosition(temp_i, temp_j)->widget());
    Button2->setText(Symbols[k]);
    Button2->setEnabled(false);
    Button2->setStyleSheet( Button2->styleSheet() + SH.StyleHelper::SymbolsColor(k, Button2->minimumHeight()));
    k = (k+1)%2;
    Draw();
    Win_Position();
    if(num == -1) timer->stop();
}

void MainWindow::on_PlayButton_clicked()
{
    ButtonClear(false);
    k = 0; int temp_i = rand() % (ui->Buttons->columnCount()), temp_j = rand() % (ui->Buttons->columnCount());
    ui->Win_table->setText("TicTacToe");
    for(int i = 0; i < ui->Buttons->rowCount(); i++){
        for(int j = 0; j < ui->Buttons->columnCount(); j++){
            QPushButton* Button = qobject_cast<QPushButton*>(ui->Buttons->itemAtPosition(i, j)->widget());
            qobject_cast<QPushButton*>(ui->Buttons->itemAtPosition(i, j)->widget())->setStyleSheet(SH.GameButton() + "QPushButton{color:#ff8600; font:0pt}");
            qobject_cast<QPushButton*>(ui->Buttons->itemAtPosition(i, j)->widget())->setText("");
            Button->setEnabled(true);
        }
    }
    if(FirstPlayer && SecondPlayer){
        timer->start(200);
        num = 0;
    }
    else if(FirstPlayer){
        QPushButton* Button2 = qobject_cast<QPushButton*>(ui->Buttons->itemAtPosition(temp_i, temp_j)->widget());
        while(Button2->text() != "") {
            temp_i = rand() % (ui->Buttons->columnCount());
            temp_j = rand() % (ui->Buttons->columnCount());
        }
                Button2->setText(Symbols[k]);
                Button2->setEnabled(false);
                Button2->setStyleSheet( Button2->styleSheet() + SH.StyleHelper::SymbolsColor(k, Button2->minimumHeight()));
                k = (k+1)%2;
        }
}

