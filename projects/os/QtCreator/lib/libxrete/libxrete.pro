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
#   File: libxrete.pro
#
# Author: $author$
#   Date: 8/9/2019
#
# QtCreator .pro file for xrete library libxrete
########################################################################
include(../../../../../build/QtCreator/xrete.pri)
include(../../../../QtCreator/xrete.pri)
include(../../xrete.pri)
include(../../../../QtCreator/lib/libxrete/libxrete.pri)

TARGET = $${libxrete_TARGET}
TEMPLATE = $${libxrete_TEMPLATE}
CONFIG += $${libxrete_CONFIG}

########################################################################
# INCLUDEPATH
#
INCLUDEPATH += \
$${libxrete_INCLUDEPATH} \

# DEFINES
# 
DEFINES += \
$${libxrete_DEFINES} \

########################################################################
# OBJECTIVE_HEADERS
#
OBJECTIVE_HEADERS += \
$${libxrete_OBJECTIVE_HEADERS} \

# OBJECTIVE_SOURCES
#
OBJECTIVE_SOURCES += \
$${libxrete_OBJECTIVE_SOURCES} \

########################################################################
# HEADERS
#
HEADERS += \
$${libxrete_HEADERS} \
$${OBJECTIVE_HEADERS} \

# SOURCES
#
SOURCES += \
$${libxrete_SOURCES} \

########################################################################


