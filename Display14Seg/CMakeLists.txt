set(glcd_SRCS
    glcdfactory.cpp
    glcdgraphicsscene.cpp
    glcdgui.cpp
    glcdlogic.cpp
    nt7108.cpp
    touchscreen.cpp
)

qt4_wrap_cpp(glcd_MOC
    glcdgui.h
    glcdgraphicsscene.h
    glcdlogic.h
    nt7108.h
)

qt4_wrap_ui(glcd_UI
    glcdgui.ui
)

add_library(Display14Seg SHARED
    ${glcd_SRCS}
    ${glcd_MOC}
    ${glcd_UI}
)

target_link_libraries(Display14Seg
    ${QT_LIBRARIES}
    ${SIMAVR_LIBRARIES}
)

include_directories(
    ${CMAKE_SOURCE_DIR}/QSimAVR
    ${CMAKE_CURRENT_BINARY_DIR}
    ${QT_INCLUDES}
    ${SIMAVR_INCLUDE_DIRS}
)

# Minha implementação para transferir arquivo de um diretorio para outro

add_custom_command(TARGET Display14Seg POST_BUILD 
COMMAND ${CMAKE_COMMAND} -E copy 
${CMAKE_CURRENT_BINARY_DIR}/libDisplay14Seg.so
${PROJECT_SOURCE_DIR}/build/QSimAVR)

install(TARGETS Display14Seg DESTINATION lib/qsimavr)
