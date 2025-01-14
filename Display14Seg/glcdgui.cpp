/* *************************************************************************
 *  Copyright 2012 Jakob Gruber                                            *
 *                                                                         *
 *  This program is free software: you can redistribute it and/or modify   *
 *  it under the terms of the GNU General Public License as published by   *
 *  the Free Software Foundation, either version 2 of the License, or      *
 *  (at your option) any later version.                                    *
 *                                                                         *
 *  This program is distributed in the hope that it will be useful,        *
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of         *
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the          *
 *  GNU General Public License for more details.                           *
 *                                                                         *
 *  You should have received a copy of the GNU General Public License      *
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.  *
 ************************************************************************* */



#include "glcdgui.h"
#include "ui_glcdgui.h"

#include <QResizeEvent>
#include <QDebug>

GlcdGui::GlcdGui(QWidget *parent) :
    QWidget(parent),
    scene(this),
    ui(new Ui::GlcdGui)
{
    ui->setupUi(this);
    ui->graphicsView->setScene(&scene);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    connect(&scene, SIGNAL(pressed(QPoint)), this, SIGNAL(pressed(QPoint)));
    connect(&scene, SIGNAL(released()), this, SIGNAL(released()));
}

GlcdGui::~GlcdGui()
{
    delete ui;
}

QWidget *GlcdGui::widget()
{
    return this;
}

void GlcdGui::pageChanged(QPoint coord, uint8_t value)
{
    scene.setPage(coord, value);
}

void GlcdGui::on_btnTeste_clicked()
{
    qDebug()<<"Botao sFuncionando!!";
}
/////////////////////////////////////////////

//#include "glcdgui.h"
//#include "ui_glcdgui.h"

//#include <QResizeEvent>

//GlcdGui::GlcdGui(QWidget *parent) :
//    QWidget(parent),
//    scene(this),
//    ui(new Ui::GlcdGui)
//{
//    ui->setupUi(this);
//    ui->graphicsView->setScene(&scene);
//    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
//    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

//    connect(&scene, SIGNAL(pressed(QPoint)), this, SIGNAL(pressed(QPoint)));
//    connect(&scene, SIGNAL(released()), this, SIGNAL(released()));
//}

//GlcdGui::~GlcdGui()
//{
//    delete ui;
//}

//QWidget *GlcdGui::widget()
//{
//    return this;
//}

//void GlcdGui::pageChanged(QPoint coord, uint8_t value)
//{
//    scene.setPage(coord, value);
//}

//void GlcdGui::on_btnTeste_clicked()
//{
//    qDebug()<<"Botao sFuncionando!!";
//}

