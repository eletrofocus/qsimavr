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



#include "pluginswindow.h"
#include "ui_pluginswindow.h"

PluginsWindow::PluginsWindow(QWidget *parent, PluginManager *manager) :
    QDialog(parent),
    ui(new Ui::PluginsWindow)
{
    ui->setupUi(this);

    model.reset(new PluginTableModel(manager));
    ui->tableView->setModel(model.data());
}

PluginsWindow::~PluginsWindow()
{
    delete ui;
}
