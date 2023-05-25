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

#include <QObject>
#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QDir>
#include <QApplication>
#include <functional>
#include <qsciscintilla.h>
#include <pluginGl.h>

#define NDD_EXPORTDLL

#if defined(Q_OS_WIN)
    #if defined(NDD_EXPORTDLL)
        #define NDD_EXPORT __declspec(dllexport)
    #else
        #define NDD_EXPORT __declspec(dllimport)
    #endif
#else
    #define NDD_EXPORT __attribute__((visibility("default")))
#endif

#ifdef __cplusplus
    extern "C" {
#endif

    NDD_EXPORT bool NDD_PROC_IDENTIFY(NDD_PROC_DATA* pProcData);
    NDD_EXPORT int NDD_PROC_MAIN(QWidget* pNotepad, const QString& strFileName, std::function<QsciScintilla* ()>getCurEdit, std::function<bool(int, void*)> pluginCallBack, NDD_PROC_DATA* procData);

#ifdef __cplusplus
    }
#endif

static NDD_PROC_DATA s_procData;
static QWidget* s_pMainNotepad = nullptr;
std::function<QsciScintilla* ()> s_getCurEdit;

bool NDD_PROC_IDENTIFY(NDD_PROC_DATA* pProcData)
{
    if(pProcData == NULL)
    {
        return false;
    }
    pProcData->m_strPlugName = QObject::tr("MD5Calc");
    pProcData->m_strComment = QObject::tr("MD5 Calculation. <https://github.com/Joker2770/MD5Calc.git>");

    pProcData->m_version = QString("v0.0.3");
    pProcData->m_auther = QString("Jintao Yang");

    pProcData->m_menuType = 0;

    return true;
}

int NDD_PROC_MAIN(QWidget* pNotepad, const QString &strFileName, std::function<QsciScintilla*()>getCurEdit, std::function<bool(int, void*)> pluginCallBack, NDD_PROC_DATA* pProcData)
{
    QsciScintilla* pEdit = getCurEdit();
    if (pEdit == nullptr)
    {
        return -1;
    }

    if (pProcData != nullptr)
    {
        s_procData = *pProcData;
    }

    s_pMainNotepad = pNotepad;
    s_getCurEdit = getCurEdit;

    Widget* p = new Widget(pNotepad,pEdit);

    p->setWindowFlag(Qt::Window);
    p->show();

    return 0;
}

