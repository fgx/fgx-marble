SET (TARGET vehicletracking)
PROJECT (${TARGET})

include_directories(
 ${CMAKE_CURRENT_SOURCE_DIR}
 ${CMAKE_CURRENT_BINARY_DIR}
 ${QT_INCLUDE_DIR}
)
if( QT4_FOUND )
  include( ${QT_USE_FILE} )
endif()

set( ${TARGET}_SRC vehicletracking.cpp)
marble_qt4_automoc( ${${TARGET}_SRC} )
add_executable( ${TARGET} ${${TARGET}_SRC} )

target_link_libraries( ${TARGET} marblewidget )
if (QT4_FOUND)
  target_link_libraries( ${TARGET} ${QT_QTCORE_LIBRARY} ${QT_QTMAIN_LIBRARY} )
else()
  target_link_libraries( ${TARGET} ${Qt5Core_LIBRARIES} )
endif()

install( TARGETS ${TARGET} RUNTIME DESTINATION ${MARBLE_EXAMPLES_INSTALL_DIR}/${TARGET} )
install( FILES ${${TARGET}_SRC} DESTINATION ${MARBLE_EXAMPLES_INSTALL_DIR}/${TARGET} )
