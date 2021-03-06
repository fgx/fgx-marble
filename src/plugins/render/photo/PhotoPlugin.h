//
// This file is part of the Marble Virtual Globe.
//
// This program is free software licensed under the GNU LGPL. You can
// find a copy of this license in LICENSE.txt in the top directory of
// the source code.
//
// Copyright 2009      Bastian Holst <bastianholst@gmx.de>
//

#ifndef PHOTOPLUGIN_H
#define PHOTOPLUGIN_H

#include "AbstractDataPlugin.h"
#include "DialogConfigurationInterface.h"
#include "RenderPlugin.h"
#include "RenderPluginInterface.h"

#include <QHash>

class QIcon;

namespace Ui
{
    class PhotoConfigWidget;
}

namespace Marble
{

class MarbleWidget;

class PhotoPlugin : public AbstractDataPlugin, public DialogConfigurationInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA( IID "org.kde.edu.marble.PhotoPlugin" )
    Q_INTERFACES( Marble::RenderPluginInterface )
    Q_INTERFACES( Marble::DialogConfigurationInterface )
    MARBLE_PLUGIN( PhotoPlugin )
    
 public:
    PhotoPlugin();

    explicit PhotoPlugin( const MarbleModel *marbleModel );

    ~PhotoPlugin();

    void initialize();

    QString name() const;
    
    QString guiString() const;

    QString nameId() const;
    
    QString version() const;

    QString description() const;

    QString copyrightYears() const;

    QList<PluginAuthor> pluginAuthors() const;

    QIcon icon() const;

    QDialog *configDialog();

    /**
     * @return: The settings of the item.
     */
    virtual QHash<QString,QVariant> settings() const;

    /**
     * Set the settings of the item.
     */
    virtual void setSettings( const QHash<QString,QVariant> &settings );

 protected:
    bool eventFilter( QObject *object, QEvent *event );

 private Q_SLOTS:
   void readSettings();
   void writeSettings();

   void updateSettings();
   void checkNumberOfItems( quint32 number );

 private:
    Ui::PhotoConfigWidget *ui_configWidget;
    QDialog *m_configDialog;

    MarbleWidget *m_marbleWidget;

    QStringList m_checkStateList;
};

}

#endif //PHOTOPLUGIN_H
