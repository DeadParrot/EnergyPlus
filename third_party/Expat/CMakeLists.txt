include(ConfigureChecks.cmake)

INCLUDE_DIRECTORIES("${CMAKE_CURRENT_BINARY_DIR}" "${CMAKE_CURRENT_SOURCE_DIR}/lib")

if(MSVC)
  add_definitions(-D_CRT_SECURE_NO_WARNINGS)
endif(MSVC)

set(epexpat_SRCS
lib/xmlparse.c
lib/xmlrole.c
lib/xmltok.c 
lib/xmltok_impl.c 
lib/xmltok_ns.c
)

if(MSVC)
  set(epexpat_SRCS ${epexpat_SRCS} lib/libexpat.def)
endif(MSVC)

IF( MSVC )
  ADD_DEFINITIONS( "/w" )
ELSE()
  ADD_DEFINITIONS( "-w -fPIC" )
ENDIF()

add_library(epexpat STATIC ${epexpat_SRCS})

set_target_properties(
  epexpat
  PROPERTIES
  INSTALL_NAME_DIR "@executable_path"
)


