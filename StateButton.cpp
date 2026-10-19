#include "StateButton.h"



StateButton::StateButton(QWidget *parent): QToolButton(parent)
{
    QMenu *menu = new QMenu(this);
    this->setMenu(menu);
    this->setPopupMode(QToolButton::MenuButtonPopup);
    
    m_actionGroup = new QActionGroup(this);

    setCheckable(true);

    connect(this, &QToolButton::toggled, this, &StateButton::updateButtonIcon);
}

void StateButton::setOnIcon(const QIcon &icon)
{
    m_onIcon = icon;
    if(isChecked())
        updateButtonIcon(true);
}

void StateButton::setOffIcon(const QIcon &icon)
{
    m_offIcon = icon;
    if(!isChecked())
        updateButtonIcon(false);
}

void StateButton::updateButtonIcon(bool checked)
{
    setIcon(checked ? m_onIcon : m_offIcon);
}

void StateButton::addMode(ButtonMode mode)
{
    m_modes.push_back(mode);
    int index = m_modes.size() - 1;

    QAction *action = new QAction(mode.title, this);
    action->setCheckable(true); 

    m_actionGroup->addAction(action);
    this->menu()->addAction(action);

    connect(action, &QAction::triggered, this, [this, index]() {
        setModeIndex(index);
    });

    if (m_modes.size() == 1) {
        action->setChecked(true);
        setModeIndex(0);
    }
}

void StateButton::setModeIndex(int index)
{
    if (index < 0 || index >= m_modes.size()) return;

    m_currentModeIndex = index;

    m_onIcon = m_modes[index].onIcon;
    m_offIcon = m_modes[index].offIcon;

    setToolTip(m_modes[index].title);

    updateButtonIcon(isChecked());
    
    qDebug() << "current:" << m_modes[index].title;
}