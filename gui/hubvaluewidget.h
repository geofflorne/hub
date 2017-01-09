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

#ifndef __HUBVALUEWIDGET_H__
#define __HUBVALUEWIDGET_H__

#include <QWidget>

class QLabel;
class QString;

class HubValueWidget : public QWidget
{
	Q_OBJECT

public:
	explicit HubValueWidget(QWidget *parent = 0);

	QString value() const;

	QString title() const;
	void setTitle(const QString &title);

	void setAlignment(Qt::Alignment align);
	void setValueSize(int size);

public Q_SLOTS:
	void setValue(const QString &value);

protected:
	QLabel *m_valueLabel;
	QLabel *m_titleLabel;
};

#endif
