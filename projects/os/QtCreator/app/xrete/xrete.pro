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
#   File: xrete.pro
#
# Author: $author$
#   Date: 8/9/2019
#
# QtCreator .pro file for xrete executable xrete
########################################################################
include(../../../../../build/QtCreator/xrete.pri)
include(../../../../QtCreator/xrete.pri)
include(../../xrete.pri)
include(../../../../QtCreator/app/xrete/xrete.pri)

TARGET = $${xrete_exe_TARGET}

########################################################################
# INCLUDEPATH
#
INCLUDEPATH += \
$${xrete_exe_INCLUDEPATH} \

# DEFINES
# 
DEFINES += \
$${xrete_exe_DEFINES} \

########################################################################
# OBJECTIVE_HEADERS
#
OBJECTIVE_HEADERS += \
$${xrete_exe_OBJECTIVE_HEADERS} \

# OBJECTIVE_SOURCES
#
OBJECTIVE_SOURCES += \
$${xrete_exe_OBJECTIVE_SOURCES} \

########################################################################
# HEADERS
#
HEADERS += \
$${xrete_exe_HEADERS} \
$${OBJECTIVE_HEADERS} \

# SOURCES
#
SOURCES += \
$${xrete_exe_SOURCES} \

########################################################################
# FRAMEWORKS
#
FRAMEWORKS += \
$${xrete_exe_FRAMEWORKS} \

# LIBS
#
LIBS += \
$${xrete_exe_LIBS} \
$${FRAMEWORKS} \


