########################################################################
# Copyright (c) 1988-2020 $organization$
#
# This software is provided by the author and contributors ``as is''
# and any express or implied warranties, including, but not limited to,
# the implied warranties of merchantability and fitness for a particular
# purpose are disclaimed. In no event shall the author or contributors
# be liable for any direct, indirect, incidental, special, exemplary,
# or consequential damages (including, but not limited to, procurement
# of substitute goods or services; loss of use, data, or profits; or
# business interruption) however caused and on any theory of liability,
# whether in contract, strict liability, or tort (including negligence
# or otherwise) arising in any way out of the use of this software,
# even if advised of the possibility of such damage.
#
#   File: xrete.pri
#
# Author: $author$
#   Date: 2/5/2020
#
# QtCreator .pri file for xrete
########################################################################

UNAME = $$system(uname)

contains(UNAME,Darwin) {
XRETE_OS = macosx
} else {
contains(UNAME,Linux) {
XRETE_OS = linux
} else {
XRETE_OS = windows
} # contains(UNAME,Linux)
} # contains(UNAME,Darwin)

contains(BUILD_OS,XRETE_OS) {
BUILD_OS = $${XRETE_OS}
} else {
BUILD_OS = os
} # contains(BUILD_OS,XRETE_OS)

contains(BUILD_CPP_VERSION,10) {
CONFIG += c++0x
} else {
contains(BUILD_CPP_VERSION,98|03|11|14|17) {
CONFIG += c++$${BUILD_CPP_VERSION}
} else {
} # contains(BUILD_CPP_VERSION,98|03|11|14|17)
} # contains(BUILD_CPP_VERSION,10)

contains(XROSTRA_OS,linux) {
QMAKE_CXXFLAGS += -fpermissive
}

########################################################################
# xos
XOS_THIRDPARTY_PKG_MAKE_BLD = $${XOS_THIRDPARTY_PKG}/build/$${BUILD_OS}/$${BUILD_CONFIG}
XOS_THIRDPARTY_PRJ_MAKE_BLD = $${OTHER_BLD}/$${XOS_THIRDPARTY_PRJ}/build/$${BUILD_OS}/$${BUILD_CONFIG}
XOS_THIRDPARTY_PKG_BLD = $${XOS_THIRDPARTY_PKG}/build/$${BUILD_OS}/QtCreator/$${BUILD_CONFIG}
XOS_THIRDPARTY_PRJ_BLD = $${OTHER_BLD}/$${XOS_THIRDPARTY_PRJ}/build/$${BUILD_OS}/QtCreator/$${BUILD_CONFIG}
XOS_PKG_BLD = $${OTHER_BLD}/$${XOS_PKG}/build/$${BUILD_OS}/QtCreator/$${BUILD_CONFIG}
XOS_PRJ_BLD = $${OTHER_BLD}/$${XOS_PRJ}/build/$${BUILD_OS}/QtCreator/$${BUILD_CONFIG}
#XOS_LIB = $${XOS_THIRDPARTY_PKG_MAKE_BLD}/lib
#XOS_LIB = $${XOS_THIRDPARTY_PRJ_MAKE_BLD}/lib
#XOS_LIB = $${XOS_THIRDPARTY_PKG_BLD}/lib
#XOS_LIB = $${XOS_THIRDPARTY_PRJ_BLD}/lib
XOS_LIB = $${XOS_PKG_BLD}/lib
#XOS_LIB = $${XOS_PRJ_BLD}/lib
#XOS_LIB = $${XRETE_LIB}

# xos LIBS
#
xos_LIBS += \
-L$${XOS_LIB}/lib$${XOS_NAME} \
-l$${XOS_NAME} \

########################################################################
# xrostra
XROSTRA_THIRDPARTY_PKG_MAKE_BLD = $${XROSTRA_THIRDPARTY_PKG}/build/$${BUILD_OS}/$${BUILD_CONFIG}
XROSTRA_THIRDPARTY_PRJ_MAKE_BLD = $${OTHER_BLD}/$${XROSTRA_THIRDPARTY_PRJ}/build/$${BUILD_OS}/$${BUILD_CONFIG}
XROSTRA_THIRDPARTY_PKG_BLD = $${XROSTRA_THIRDPARTY_PKG}/build/$${BUILD_OS}/QtCreator/$${BUILD_CONFIG}
XROSTRA_THIRDPARTY_PRJ_BLD = $${OTHER_BLD}/$${XROSTRA_THIRDPARTY_PRJ}/build/$${BUILD_OS}/QtCreator/$${BUILD_CONFIG}
XROSTRA_PKG_BLD = $${OTHER_BLD}/$${XROSTRA_PKG}/build/$${BUILD_OS}/QtCreator/$${BUILD_CONFIG}
XROSTRA_PRJ_BLD = $${OTHER_BLD}/$${XROSTRA_PRJ}/build/$${BUILD_OS}/QtCreator/$${BUILD_CONFIG}
#XROSTRA_LIB = $${XROSTRA_THIRDPARTY_PKG_MAKE_BLD}/lib
#XROSTRA_LIB = $${XROSTRA_THIRDPARTY_PRJ_MAKE_BLD}/lib
#XROSTRA_LIB = $${XROSTRA_THIRDPARTY_PKG_BLD}/lib
#XROSTRA_LIB = $${XROSTRA_THIRDPARTY_PRJ_BLD}/lib
XROSTRA_LIB = $${XROSTRA_PKG_BLD}/lib
#XROSTRA_LIB = $${XROSTRA_PRJ_BLD}/lib
#XROSTRA_LIB = $${XRETE_LIB}

# xrostra LIBS
#
xrostra_LIBS += \
-L$${XROSTRA_LIB}/lib$${XROSTRA_NAME} \
-l$${XROSTRA_NAME} \

########################################################################
# xnadir
XNADIR_THIRDPARTY_PKG_MAKE_BLD = $${XNADIR_THIRDPARTY_PKG}/build/$${BUILD_OS}/$${BUILD_CONFIG}
XNADIR_THIRDPARTY_PRJ_MAKE_BLD = $${OTHER_BLD}/$${XNADIR_THIRDPARTY_PRJ}/build/$${BUILD_OS}/$${BUILD_CONFIG}
XNADIR_THIRDPARTY_PKG_BLD = $${XNADIR_THIRDPARTY_PKG}/build/$${BUILD_OS}/QtCreator/$${BUILD_CONFIG}
XNADIR_THIRDPARTY_PRJ_BLD = $${OTHER_BLD}/$${XNADIR_THIRDPARTY_PRJ}/build/$${BUILD_OS}/QtCreator/$${BUILD_CONFIG}
XNADIR_PKG_BLD = $${OTHER_BLD}/$${XNADIR_PKG}/build/$${BUILD_OS}/QtCreator/$${BUILD_CONFIG}
XNADIR_PRJ_BLD = $${OTHER_BLD}/$${XNADIR_PRJ}/build/$${BUILD_OS}/QtCreator/$${BUILD_CONFIG}
#XNADIR_LIB = $${XNADIR_THIRDPARTY_PKG_MAKE_BLD}/lib
#XNADIR_LIB = $${XNADIR_THIRDPARTY_PRJ_MAKE_BLD}/lib
#XNADIR_LIB = $${XNADIR_THIRDPARTY_PKG_BLD}/lib
#XNADIR_LIB = $${XNADIR_THIRDPARTY_PRJ_BLD}/lib
XNADIR_LIB = $${XNADIR_PKG_BLD}/lib
#XNADIR_LIB = $${XNADIR_PRJ_BLD}/lib
#XNADIR_LIB = $${XRETE_LIB}

# xnadir LIBS
#
xnadir_LIBS += \
-L$${XNADIR_LIB}/lib$${XNADIR_NAME} \
-l$${XNADIR_NAME} \

########################################################################
# xfila
XFILA_THIRDPARTY_PKG_MAKE_BLD = $${XFILA_THIRDPARTY_PKG}/build/$${BUILD_OS}/$${BUILD_CONFIG}
XFILA_THIRDPARTY_PRJ_MAKE_BLD = $${OTHER_BLD}/$${XFILA_THIRDPARTY_PRJ}/build/$${BUILD_OS}/$${BUILD_CONFIG}
XFILA_THIRDPARTY_PKG_BLD = $${XFILA_THIRDPARTY_PKG}/build/$${BUILD_OS}/QtCreator/$${BUILD_CONFIG}
XFILA_THIRDPARTY_PRJ_BLD = $${OTHER_BLD}/$${XFILA_THIRDPARTY_PRJ}/build/$${BUILD_OS}/QtCreator/$${BUILD_CONFIG}
XFILA_PKG_BLD = $${OTHER_BLD}/$${XFILA_PKG}/build/$${BUILD_OS}/QtCreator/$${BUILD_CONFIG}
XFILA_PRJ_BLD = $${OTHER_BLD}/$${XFILA_PRJ}/build/$${BUILD_OS}/QtCreator/$${BUILD_CONFIG}
#XFILA_LIB = $${XFILA_THIRDPARTY_PKG_MAKE_BLD}/lib
#XFILA_LIB = $${XFILA_THIRDPARTY_PRJ_MAKE_BLD}/lib
#XFILA_LIB = $${XFILA_THIRDPARTY_PKG_BLD}/lib
#XFILA_LIB = $${XFILA_THIRDPARTY_PRJ_BLD}/lib
XFILA_LIB = $${XFILA_PKG_BLD}/lib
#XFILA_LIB = $${XFILA_PRJ_BLD}/lib
#XFILA_LIB = $${XRETE_LIB}

# xfila LIBS
#
xfila_LIBS += \
-L$${XFILA_LIB}/lib$${XFILA_NAME} \
-l$${XFILA_NAME} \

########################################################################
# xcrono
XCRONO_THIRDPARTY_PKG_MAKE_BLD = $${XCRONO_THIRDPARTY_PKG}/build/$${BUILD_OS}/$${BUILD_CONFIG}
XCRONO_THIRDPARTY_PRJ_MAKE_BLD = $${OTHER_BLD}/$${XCRONO_THIRDPARTY_PRJ}/build/$${BUILD_OS}/$${BUILD_CONFIG}
XCRONO_THIRDPARTY_PKG_BLD = $${XCRONO_THIRDPARTY_PKG}/build/$${BUILD_OS}/QtCreator/$${BUILD_CONFIG}
XCRONO_THIRDPARTY_PRJ_BLD = $${OTHER_BLD}/$${XCRONO_THIRDPARTY_PRJ}/build/$${BUILD_OS}/QtCreator/$${BUILD_CONFIG}
XCRONO_PKG_BLD = $${OTHER_BLD}/$${XCRONO_PKG}/build/$${BUILD_OS}/QtCreator/$${BUILD_CONFIG}
XCRONO_PRJ_BLD = $${OTHER_BLD}/$${XCRONO_PRJ}/build/$${BUILD_OS}/QtCreator/$${BUILD_CONFIG}
#XCRONO_LIB = $${XCRONO_THIRDPARTY_PKG_MAKE_BLD}/lib
#XCRONO_LIB = $${XCRONO_THIRDPARTY_PRJ_MAKE_BLD}/lib
#XCRONO_LIB = $${XCRONO_THIRDPARTY_PKG_BLD}/lib
#XCRONO_LIB = $${XCRONO_THIRDPARTY_PRJ_BLD}/lib
XCRONO_LIB = $${XCRONO_PKG_BLD}/lib
#XCRONO_LIB = $${XCRONO_PRJ_BLD}/lib
#XCRONO_LIB = $${XRETE_LIB}

# xcrono LIBS
#
xcrono_LIBS += \
-L$${XCRONO_LIB}/lib$${XCRONO_NAME} \
-l$${XCRONO_NAME} \

########################################################################
# xrete

# xrete INCLUDEPATH
#
xrete_INCLUDEPATH += \

# xrete DEFINES
#
xrete_DEFINES += \

# xrete LIBS
#
xrete_LIBS += \
$${xcrono_LIBS} \
$${xfila_LIBS} \
$${xnadir_LIBS} \
$${xrostra_LIBS} \
$${xos_LIBS} \
$${build_xrete_LIBS} \

contains(XRETE_OS,macosx|linux) {
xrete_LIBS += \
-lpthread \
-ldl
} else {
} # contains(XRETE_OS,macosx|linux)

contains(XRETE_OS,linux) {
xrete_LIBS += \
-lrt
} else {
} # contains(XRETE_OS,linux)


