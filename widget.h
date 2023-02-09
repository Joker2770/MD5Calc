/**
    A plugin for Notepad-- to calculate MD5.
    Copyright (C) 2023  Jintao Yang <yjt950840@outlook.com>

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/

#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QGroupBox>

class QsciScintilla;
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr, QsciScintilla* pEdit = nullptr);
    ~Widget();

private slots:
    void OnCalcMD5();

private:
    QsciScintilla* m_pEdit;
    QGridLayout *m_gl, *m_gl_result;
    QHBoxLayout *m_hbl;
    QGroupBox *m_gb_result;
    QLabel *m_lb_description, *m_lb_result;
    QPushButton *m_btn_calc, *m_btn_cancel;
};

#endif // WIDGET_H
