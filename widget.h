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
