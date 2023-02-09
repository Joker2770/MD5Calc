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

#include "widget.h"
#include <qsciscintilla.h>

#include <QCryptographicHash>

Widget::Widget(QWidget *parent, QsciScintilla* pEdit)
    : QWidget(parent)
{
    this->m_gl = new QGridLayout(this);
    this->m_gl_result = new QGridLayout();
    this->m_gb_result = new QGroupBox();
    this->m_hbl = new QHBoxLayout();
    this->m_lb_result = new QLabel();
    this->m_lb_description = new QLabel();

    this->resize(450, 300);
    this->m_pEdit = pEdit;

    this->m_hbl->addWidget(this->m_btn_calc);
    this->m_hbl->addWidget(this->m_btn_cancel);
    this->m_gl_result->addWidget(this->m_lb_result);
    this->m_gb_result->setLayout(this->m_gl_result);
    this->m_gl->addWidget(this->m_lb_description, 0, 0);
    this->m_gl->addWidget(this->m_gb_result, 0, 1);
    this->m_gl->addLayout(this->m_hbl, 0, 2);

    connect(this->m_btn_calc, SIGNAL(clicked()), this, SLOT(this->OnCalcMD5()));
    connect(this->m_btn_cancel, SIGNAL(clicked()), this, SLOT(close()));
}

Widget::~Widget()
{
    if (nullptr != this->m_lb_result)
    {
        delete this->m_lb_result;
        this->m_lb_result = nullptr;
    }
    if (nullptr != this->m_lb_description)
    {
        delete this->m_lb_description;
        this->m_lb_description = nullptr;
    }
    if (nullptr != this->m_hbl)
    {
        delete this->m_hbl;
        this->m_hbl = nullptr;
    }
    if (nullptr != this->m_gb_result)
    {
        delete this->m_gb_result;
        this->m_gb_result = nullptr;
    }
    if (nullptr != this->m_gl_result)
    {
        delete this->m_gl_result;
        this->m_gl_result = nullptr;
    }
    if (nullptr != this->m_gl)
    {
        delete this->m_gl;
        this->m_gl = nullptr;
    }
}

void Widget::OnCalcMD5()
{
    QString data=m_pEdit->selectedText();
    if (data.isEmpty())
    {
        return;
    }

    QByteArray md5 = QCryptographicHash::hash(data.toUtf8(), QCryptographicHash::Md5);
    QString strMD5 = md5.toHex();

    this->m_lb_result->setText(strMD5);
}

