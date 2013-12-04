//
// This file is part of the Marble Virtual Globe.
//
// This program is free software licensed under the GNU LGPL. You can
// find a copy of this license in LICENSE.txt in the top directory of
// the source code.
//
// Copyright 2012      Dennis Nienhüser <earthwings@gentoo.org>
//

#include <QApplication>
#include <QDir>
#include <qdebug.h>
#include <marble/MarbleWidget.h>
#include <marble/MarbleDirs.h>
#include <marble/MarbleDebug.h>

#define ADD_PLUGIN_SETTER
using namespace Marble;

int main(int argc, char** argv)
{
    QString marbleDataPath;
#ifdef ADD_PLUGIN_SETTER
    QString marblePluginPath;
#endif
    bool show_fps = false;
    int dataPathIndex=0;

    QApplication app(argc,argv);

    QStringList args = QApplication::arguments();
    if ( args.contains( "-h" ) || args.contains( "--help" ) || args.contains( "-?" ) ) {
        qWarning() << "Usage: hello-marble [options]";
        qWarning();
        qWarning() << "  --marbledatapath=<path> .... Overwrite the compile-time path to map themes and other data";
#ifdef ADD_PLUGIN_SETTER
        qWarning() << "  --marblepluginpath=<path> .. Relative path plugins";
#endif
        qWarning() << "  --debug-info ............... write (more) debugging information to the console";
        qWarning() << "  --fps ...................... Show the paint performance (paint rate) in the top left corner";
        qWarning();
        return 0;
    }

    for ( int i = 1; i < args.count(); ++i ) {
        const QString arg = args.at(i);
        if ( arg.startsWith( QLatin1String( "--marbledatapath=" ), Qt::CaseInsensitive ) ) {
            marbleDataPath = args.at(i).mid(17);
        } else if ( arg.compare( QLatin1String( "--marbledatapath" ), Qt::CaseInsensitive ) == 0 ) {
            dataPathIndex = i + 1;
            marbleDataPath = args.value( dataPathIndex );
            ++i;
#ifdef ADD_PLUGIN_SETTER
        } else if ( arg.startsWith( QLatin1String( "--marblepluginpath=" ), Qt::CaseInsensitive ) ) {
            marblePluginPath = args.at(i).mid(19);
        } else if ( arg.compare( QLatin1String( "--marblepluginpath" ), Qt::CaseInsensitive ) == 0 ) {
            dataPathIndex = i + 1;
            marblePluginPath = args.value( dataPathIndex );
            ++i;
#endif
        } else if ( arg == QLatin1String( "--debug-info" ) ) {
            MarbleDebug::setEnabled( true );
        } else if( arg == "--fps" ) {
            show_fps = true;
        } else {
            qWarning() << "Error: Unknown options! [" + arg + "] aborting...";
            return 1;
        }
    }

    if ( !marbleDataPath.isEmpty() ) {
        QDir dir(marbleDataPath);
        if (!dir.exists()) {
            qWarning() << "Error: Data directory [" + marbleDataPath + "] does NOT exist! aborting...";
            return 1;
        }
        MarbleDirs::setMarbleDataPath( marbleDataPath );
    }
#ifdef ADD_PLUGIN_SETTER
    if ( !marblePluginPath.isEmpty() ) {
        if ( !QDir::root().exists( marblePluginPath ) ) {
            qWarning() << QString( "Invalid MarblePluginPath \"%1\". Using \"%2\" instead." ).arg( marblePluginPath ).arg( MarbleDirs::pluginSystemPath() );
            return 1;
        }
        MarbleDirs::setMarblePluginPath( marblePluginPath );
    }
#endif

    // Create a Marble QWidget without a parent
    MarbleWidget *mapWidget = new MarbleWidget();
    if (show_fps)
        mapWidget->setShowFrameRate( true );

    // Load the OpenStreetMap map
    mapWidget->setMapThemeId("earth/openstreetmap/openstreetmap.dgml");

    mapWidget->show();

    return app.exec();
}
