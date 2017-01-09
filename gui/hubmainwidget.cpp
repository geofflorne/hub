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

#include <QtGui>

#include "hubvaluewidget.h"
#include "hubmainwidget.h"

HubMainWidget::HubMainWidget(QWidget *parent) : QWidget(parent, Qt::FramelessWindowHint)
{
	QHBoxLayout *layout = new QHBoxLayout();
	QGridLayout *leftLayout = new QGridLayout();
	QVBoxLayout *rightLayout = new QVBoxLayout();

	m_ect = new HubValueWidget();
	m_ect->setAlignment(Qt::AlignLeft);
	m_ect->setTitle("ECT");
	m_ect->setValue("99");
	leftLayout->addWidget(this->m_ect, 0, 0);

	m_eot = new HubValueWidget();
	m_eot->setAlignment(Qt::AlignLeft);
	m_eot->setTitle("OilT");
	m_eot->setValue("99");
	leftLayout->addWidget(this->m_eot, 0, 1);

	m_tps = new HubValueWidget();
	m_tps->setAlignment(Qt::AlignLeft);
	m_tps->setTitle("TPS");
	m_tps->setValue("99");
	leftLayout->addWidget(this->m_tps, 1, 0);

	m_batt = new HubValueWidget();
	m_batt->setValueSize(28);
	m_batt->setAlignment(Qt::AlignLeft);
	m_batt->setTitle("BatV");
	m_batt->setValue("12.3");
	leftLayout->addWidget(this->m_batt, 1, 1);

	layout->addLayout(leftLayout);

	gear = 1;
	m_gear = new HubValueWidget();
	m_gear->setValueSize(200);
	m_gear->setTitle("Gear");
	m_gear->setValue("1");
	layout->addWidget(this->m_gear);

	rightLayout->addStretch();

	rpm = 123;
	m_rpm = new HubValueWidget();
	m_rpm->setValueSize(56);
	m_rpm->setAlignment(Qt::AlignRight);
	m_rpm->setTitle("RPM");
	m_rpm->setValue("123");
	rightLayout->addWidget(m_rpm);

	speed = 12;
	m_speed = new HubValueWidget();
	m_speed->setValueSize(56);
	m_speed->setAlignment(Qt::AlignRight);
	m_speed->setTitle("km/h");
	m_speed->setValue("12");
	rightLayout->addWidget(m_speed);

	layout->addLayout(rightLayout);
	
	setLayout(layout);

	QTimer *timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), this, SLOT(updateDisplay()));
	timer->start(50);
}

void HubMainWidget::updateDisplay()
{
	rpm += 247;
	if (rpm >= 10000) rpm = 0;

	gear = rpm / 2000;
	speed = rpm / 100;
	m_gear->setValue(QString::number(this->gear));
	m_rpm->setValue(QString::number(this->rpm));
	m_speed->setValue(QString::number(this->speed));
}
