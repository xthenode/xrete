########################################################################
# Copyright (c) 1988-2019 $organization$
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
#   File: libxrete.pri
#
# Author: $author$
#   Date: 8/9/2019
#
# QtCreator .pri file for xrete library libxrete
########################################################################

########################################################################
# libxrete

# libxrete TARGET
#
libxrete_TARGET = xrete
libxrete_TEMPLATE = lib
libxrete_CONFIG += staticlib

# libxrete INCLUDEPATH
#
libxrete_INCLUDEPATH += \
$${xrete_INCLUDEPATH} \

# libxrete DEFINES
#
libxrete_DEFINES += \
$${xrete_DEFINES} \

########################################################################
# libxrete OBJECTIVE_HEADERS
#
#libxrete_OBJECTIVE_HEADERS += \
#$${XRETE_SRC}/xrete/base/Base.hh \

# libxrete OBJECTIVE_SOURCES
#
#libxrete_OBJECTIVE_SOURCES += \
#$${XRETE_SRC}/xrete/base/Base.mm \

########################################################################
# libxrete HEADERS
#
libxrete_HEADERS += \
$${XRETE_SRC}/xos/lib/xrete/Version.h \
$${XRETE_SRC}/xos/lib/xrete/Version.hxx \

# libxrete SOURCES
#
libxrete_SOURCES += \
$${XRETE_SRC}/xos/lib/xrete/Version.cxx \

########################################################################



