/*********
*
* In the name of the Father, and of the Son, and of the Holy Spirit.
*
* This file is part of BibleTime's source code, https://bibletime.info/
*
* Copyright 1999-2021 by the BibleTime developers.
* The BibleTime source code is licensed under the GNU General Public License
* version 2.0.
*
**********/

#pragma once

#include "btbookshelfwizardpage.h"

#include <QStringList>


class BtInstallMgr;
class BtListModel;
class QPushButton;
class QTableView;
class QVBoxLayout;

class BtBookshelfSourcesPage final: public BtBookshelfWizardPage {

    Q_OBJECT

public: /* Methods: */

    BtBookshelfSourcesPage(QWidget * parent = nullptr);

    bool isComplete() const final override;
    void initializePage() final override;
    int nextId() const final override;
    QStringList selectedSources() const;

private Q_SLOTS:

    void slotButtonClicked(int row);

private: /* Methods: */

    void retranslateUi();
    void selectSourcesInModel(QStringList const & sources);
    void updateSourcesModel();

private: /* Fields: */

    bool m_firstTimeInit = true;
    QTableView * m_sourcesTableView;
    QVBoxLayout * m_verticalLayout;
    BtListModel * m_model;

}; /* class BtBookshelfSourcesPage */
