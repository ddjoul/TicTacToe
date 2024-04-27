#ifndef STYLEHELPER_H
#define STYLEHELPER_H
#include <QString>
class StyleHelper{
public:
    QString ActiveButton(){
        return "QPushButton{background-color:rgb(66, 75, 79); border: 1px solid rgb(66, 75, 79); border-radius: 10px;}"
               "QPushButton:hover{background-color:rgb(56, 65, 69);}";
    }
    QString NotActiveButton(){
        return "QPushButton{background-color:rgb(48, 53, 57); border: 1px solid rgb(66, 75, 79); border-radius: 10px;}"
               "QPushButton:hover{background-color:rgb(38, 43, 47);}";
    }
    QString GameButton(){
        return "QPushButton{background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(74, 84, 89, 255), stop:1 rgba(66, 75, 79, 255));"
               "border: 1px solid #4a5459;}"
            "QPushButton:hover{background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(64, 74, 79, 255), stop:1 rgba(56, 65, 69, 255));}";
    }
    QString SymbolsColor(int k, int size){
        if(k == 0) return  "QPushButton{color:#2690db; font:" + QString::number(120 * size / 300) +"pt;}";
                return "QPushButton{color:#ff8600; font:" + QString::number(120* size/300) +"pt;}";
    }
};

#endif // STYLEHELPER_H
