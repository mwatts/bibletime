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

#include <QList>
#include "../../backend/drivers/btmoduleset.h"


class BtBookshelfWizard;
class BtInstallThread;
class QLabel;
class QProgressBar;
class QPushButton;
class QSwordModuleInfo;
class QVBoxLayout;

class BtBookshelfInstallFinalPage final: public BtBookshelfWizardPage {

    Q_OBJECT

public: /* Methods: */

    BtBookshelfInstallFinalPage(QWidget * parent = nullptr);
    ~BtBookshelfInstallFinalPage() noexcept final override { destroyThread(); }

    void destroyThread() noexcept;

    void initializePage() final override;
    bool isComplete() const final override;
    int nextId() const final override;
    BtModuleSet selectedWorks() const;

public Q_SLOTS:
    void slotStopInstall();

private Q_SLOTS:

    void slotInstallStarted(int moduleIndex);
    void slotOneItemCompleted(int moduleIndex, bool status);
    void slotStatusUpdated(int moduleIndex, int status);
    void slotThreadFinished();

private: /* Methods: */

    void retranslateUi();

private: /* Fields: */

    QLabel * m_msgLabel;
    QLabel * m_msgLabel2;
    QProgressBar * m_progressBar;
    QPushButton * m_stopButton;
    BtInstallThread * m_thread = nullptr;
    QVBoxLayout * m_verticalLayout;

    bool m_installFailed = false;
    bool m_installCompleted = false;

    QList<CSwordModuleInfo *> m_modules;
    int m_lastStatus = -1;

}; /* class BtBookshelfInstallFinalPage */
