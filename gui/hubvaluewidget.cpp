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

HubValueWidget::HubValueWidget(QWidget *parent) : QWidget(parent)
{
	QVBoxLayout *layout = new QVBoxLayout();

	layout->setSpacing(0);

	layout->addStretch();

	m_valueLabel = new QLabel("-");
	m_valueLabel->setStyleSheet("color: #fff; font-family: 'Source Code Pro';");
	layout->addWidget(m_valueLabel);
	
	m_titleLabel = new QLabel("");
	m_titleLabel->setStyleSheet("color: #0cf; font-family: 'Source Code Pro'; font-size: 18px; font-weight: bold;");
	layout->addWidget(m_titleLabel);

	layout->addStretch();

	setLayout(layout);
	setAlignment(Qt::AlignHCenter);
	setValueSize(32);
}

void HubValueWidget::setAlignment(Qt::Alignment align)
{
	m_titleLabel->setAlignment(align | Qt::AlignVCenter);
	m_valueLabel->setAlignment(align | Qt::AlignVCenter);
}

void HubValueWidget::setValueSize(int size)
{
	QFont font;
	font.setPointSize(size);
	font.setBold(true);

	m_valueLabel->setFont(font);
}

QString HubValueWidget::title() const
{
	return m_titleLabel->text();
}

void HubValueWidget::setTitle(const QString &title)
{
	m_titleLabel->setText(title);
}

QString HubValueWidget::value() const
{
	return m_valueLabel->text();
}

void HubValueWidget::setValue(const QString &value)
{
	m_valueLabel->setText(value);
}
