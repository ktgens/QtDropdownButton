#pragma once

#include <QIcon>
#include <QToolButton>
#include <QMenu>    
#include <QDebug>
#include <QActionGroup>
#include <QAction>

struct ButtonMode
{
    QString title;
    QIcon onIcon;
    QIcon offIcon;
};

class StateButton: public QToolButton
{
    public:
        explicit StateButton(QWidget *parent = nullptr);

        void setOnIcon(const QIcon &icon);
        void setOffIcon(const QIcon &icon);

        void addMode(ButtonMode mode);

    private:
        void updateButtonIcon(bool checked);

        void setModeIndex(int index);
        
        QList<ButtonMode> m_modes;
        int m_currentModeIndex = 0;

        QActionGroup *m_actionGroup;

        QIcon m_onIcon;
        QIcon m_offIcon;
};