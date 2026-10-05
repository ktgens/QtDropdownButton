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
    qDebug() << "added mode " << mode.title;
}