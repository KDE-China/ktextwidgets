/*
    Copyright (C) 2001, S.R.Haque <srhaque@iee.org>.
    Copyright (C) 2002, David Faure <david@mandrakesoft.com>
    This file is part of the KDE project

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License version 2, as published by the Free Software Foundation.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Library General Public License for more details.

    You should have received a copy of the GNU Library General Public License
    along with this library; see the file COPYING.LGPL-2.  If not, write to
    the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
    Boston, MA 02110-1301, USA.
*/

#ifndef KFINDDIALOG_P_H
#define KFINDDIALOG_P_H

#include "kfinddialog.h"
#include "kfind.h"

#include <QStringList>

class KHistoryComboBox;

class QCheckBox;
class QDialogButtonBox;
class QGridLayout;
class QGroupBox;
class QMenu;
class QPushButton;

class Q_DECL_HIDDEN KFindDialog::KFindDialogPrivate
{
public:
    KFindDialogPrivate(KFindDialog *q)
        : q(q),
          regexpDialog(nullptr),
          regexpDialogQueryDone(false),
          initialShowDone(false),
          enabled(KFind::WholeWordsOnly | KFind::FromCursor |  KFind::SelectedText | KFind::CaseSensitive | KFind::FindBackwards | KFind::RegularExpression),
          findExtension(nullptr),
          buttonBox(nullptr)
    {}

    void init(bool forReplace, const QStringList &findStrings, bool hasSelection);

    void _k_slotPlaceholdersAboutToShow();
    void _k_slotOk();
    void _k_slotReject();
    void _k_slotSelectedTextToggled(bool);
    void _k_showPatterns();
    void _k_showPlaceholders();
    void _k_textSearchChanged(const QString &);

    KFindDialog *q = nullptr;
    QDialog *regexpDialog = nullptr;
    bool regexpDialogQueryDone : 1;
    bool initialShowDone : 1;
    long enabled; // uses Options to define which search options are enabled
    QStringList findStrings;
    QString pattern;
    QWidget *findExtension = nullptr;
    QDialogButtonBox *buttonBox = nullptr;

    QGroupBox *findGrp = nullptr;
    KHistoryComboBox *find = nullptr;
    QCheckBox *regExp = nullptr;
    QPushButton *regExpItem = nullptr;
    QGridLayout *findLayout = nullptr;

    QCheckBox *wholeWordsOnly = nullptr;
    QCheckBox *fromCursor = nullptr;
    QCheckBox *selectedText = nullptr;
    QCheckBox *caseSensitive = nullptr;
    QCheckBox *findBackwards = nullptr;

    QMenu *patterns = nullptr;

    // for the replace dialog

    QGroupBox *replaceGrp = nullptr;
    KHistoryComboBox *replace = nullptr;
    QCheckBox *backRef = nullptr;
    QPushButton *backRefItem = nullptr;
    QGridLayout *replaceLayout = nullptr;

    QCheckBox *promptOnReplace = nullptr;

    QMenu *placeholders = nullptr;
};

#endif // KFINDDIALOG_P_H
