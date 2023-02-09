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

    QString md5hash;
    QByteArray ba,bb;
    QCryptographicHash md(QCryptographicHash::Md5);
    ba.append(data);
    md.addData(ba);
    bb = md.result();
    md5hash.append(bb.toHex());

    this->m_lb_result->setText(md5hash);
}

