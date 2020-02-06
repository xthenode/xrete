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
# build QtCreator .pri file for xrete
########################################################################

UNAME = $$system(uname)

contains(UNAME,Uname) {
BUILD_OS = XRETE_OS
} else {
BUILD_OS = os
} # contains(UNAME,Uname)

#BUILD_CPP_VERSION = 11

########################################################################
# xos
#
# pkg-config --cflags --libs xos
#

# build xos INCLUDEPATH
#
build_xos_INCLUDEPATH += \

# build xos DEFINES
#
build_xos_DEFINES += \

# build xos FRAMEWORKS
#
build_xos_FRAMEWORKS += \

# build xos LIBS
#
build_xos_LIBS += \

########################################################################
# xrostra
#
# pkg-config --cflags --libs xrostra
#

# build xrostra INCLUDEPATH
#
build_xrostra_INCLUDEPATH += \

# build xrostra DEFINES
#
build_xrostra_DEFINES += \

# build xrostra FRAMEWORKS
#
build_xrostra_FRAMEWORKS += \

# build xrostra LIBS
#
build_xrostra_LIBS += \

########################################################################
# xnadir
#
# pkg-config --cflags --libs xnadir
#

# build xnadir INCLUDEPATH
#
build_xnadir_INCLUDEPATH += \

# build xnadir DEFINES
#
build_xnadir_DEFINES += \

# build xnadir FRAMEWORKS
#
build_xnadir_FRAMEWORKS += \

# build xnadir LIBS
#
build_xnadir_LIBS += \

########################################################################
# xfila
#
# pkg-config --cflags --libs xfila
#

# build xfila INCLUDEPATH
#
build_xfila_INCLUDEPATH += \

# build xfila DEFINES
#
build_xfila_DEFINES += \

# build xfila FRAMEWORKS
#
build_xfila_FRAMEWORKS += \

# build xfila LIBS
#
build_xfila_LIBS += \

########################################################################
# xcrono
#
# pkg-config --cflags --libs xcrono
#

# build xcrono INCLUDEPATH
#
build_xcrono_INCLUDEPATH += \

# build xcrono DEFINES
#
build_xcrono_DEFINES += \

# build xcrono FRAMEWORKS
#
build_xcrono_FRAMEWORKS += \

# build xcrono LIBS
#
build_xcrono_LIBS += \

########################################################################
# xrete

# build xrete INCLUDEPATH
#
build_xrete_INCLUDEPATH += \
$${build_xcrono_INCLUDEPATH} \
$${build_xfila_INCLUDEPATH} \
$${build_xnadir_INCLUDEPATH} \
$${build_xrostra_INCLUDEPATH} \
$${build_xos_INCLUDEPATH} \


# build xrete DEFINES
#
build_xrete_DEFINES += \
$${build_xos_DEFINES} \
$${build_xrostra_DEFINES} \
$${build_xnadir_DEFINES} \
$${build_xfila_DEFINES} \
$${build_xcrono_DEFINES} \


# build xrete FRAMEWORKS
#
build_xrete_FRAMEWORKS += \
$${build_xcrono_FRAMEWORKS} \
$${build_xfila_FRAMEWORKS} \
$${build_xnadir_FRAMEWORKS} \
$${build_xrostra_FRAMEWORKS} \
$${build_xos_FRAMEWORKS} \


# build xrete LIBS
#
build_xrete_LIBS += \
$${build_xcrono_LIBS} \
$${build_xfila_LIBS} \
$${build_xnadir_LIBS} \
$${build_xrostra_LIBS} \
$${build_xos_LIBS} \


