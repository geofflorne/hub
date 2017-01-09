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

#ifndef __HUBMAINWIDGET_H__
#define __HUBMAINWIDGET_H__

#include <QWidget>

class QLabel;

class HubValueWidget;

class HubMainWidget : public QWidget
{
	Q_OBJECT

public:
	explicit HubMainWidget(QWidget *parent = 0);

public slots:
	void updateDisplay();

private:
	int gear;
	int rpm;
	int speed;
	
	HubValueWidget *m_ect;
	HubValueWidget *m_eot;
	HubValueWidget *m_tps;
	HubValueWidget *m_batt;

	HubValueWidget *m_gear;
	
	HubValueWidget *m_rpm;
	HubValueWidget *m_speed;
};

#endif
