/*
  This file is part of the UVic Formula Motorsports Hub GUI project.

  Copyright (c) 2017 UVic Formula Motorsports

  This program is free software: you can redistribute it and/or modify it under
  the terms of the GNU General Public License as published by the Free Software
  Foundation, either version 3 of the License, or (at your option) any later
  version.

  This program is distributed in the hope that it will be useful, but WITHOUT
  ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
  FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

  You should have received a copy of the GNU General Public License along with
  this program. If not, see <http://www.gnu.org/licenses/>.
*/

#include <QApplication>
#include <QFontDatabase>
#include <QStringList>
#include <QTextStream>
#include <QWSServer>

#include "hubmainwidget.h"


int main(int argc, char **argv)
{
	QApplication app(argc, argv, QApplication::GuiServer);

	app.setOverrideCursor(QCursor(Qt::BlankCursor));
	QWSServer::setBackground(QBrush(Qt::black));

	app.setStyleSheet("QWidget { background-color: transparent; color: white; }");

	HubMainWidget mainWidget;
	mainWidget.showFullScreen();

	return app.exec();
}
