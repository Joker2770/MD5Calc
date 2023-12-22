#pragma once
#include <QObject>
#include <QWidget>
#include <QPointer>
#include "widget.h"

class QMenu;

class InstanceObj :public QObject
{
public:
	InstanceObj(QWidget* pNotepad);
	~InstanceObj();

public slots:
	void doMainWork();

public:
	QWidget* m_pNotepad;
	QPointer<Widget> m_pMainToolWin;
private:
	InstanceObj(const InstanceObj& other) = delete;
	InstanceObj& operator=(const InstanceObj& other) = delete;
};