add_subdirectory(marble-ui)
add_subdirectory(marble-qt)
if (NOT WIN32) # TODO: problem unresolved keyPressEvent
add_subdirectory(marble-mobile)
endif ()

if (NOT QTONLY)
  add_subdirectory(marble-kde)
endif()

if( QT_QTDECLARATIVE_FOUND OR Qt5Quick_FOUND )
    add_subdirectory(marble-touch)
endif( QT_QTDECLARATIVE_FOUND OR Qt5Quick_FOUND )
