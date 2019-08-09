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
#   File: xrete.pri
#
# Author: $author$
#   Date: 8/9/2019
#
# QtCreator .pri file for xrete executable xrete
########################################################################

########################################################################
# xrete

# xrete_exe TARGET
#
xrete_exe_TARGET = xrete

# xrete_exe INCLUDEPATH
#
xrete_exe_INCLUDEPATH += \
$${xrete_INCLUDEPATH} \

# xrete_exe DEFINES
#
xrete_exe_DEFINES += \
$${xrete_DEFINES} \

########################################################################
# xrete_exe OBJECTIVE_HEADERS
#
#xrete_exe_OBJECTIVE_HEADERS += \
#$${XRETE_SRC}/xrete/base/Base.hh \

# xrete_exe OBJECTIVE_SOURCES
#
#xrete_exe_OBJECTIVE_SOURCES += \
#$${XRETE_SRC}/xrete/base/Base.mm \

########################################################################
# xrete_exe HEADERS
#
xrete_exe_HEADERS += \
\
$${XRETE_SRC}/xos/network/Address.hxx \
$${XRETE_SRC}/xos/network/sockets/Address.hxx \
$${XRETE_SRC}/xos/network/sockets/ip/Address.hxx \
$${XRETE_SRC}/xos/network/sockets/ip/v4/Address.hxx \
$${XRETE_SRC}/xos/network/sockets/ip/v6/Address.hxx \
$${XRETE_SRC}/xos/network/sockets/Addresses.hxx \
\
$${XRETE_SRC}/xos/network/Transport.hxx \
$${XRETE_SRC}/xos/network/sockets/Transport.hxx \
$${XRETE_SRC}/xos/network/sockets/ip/Transport.hxx \
$${XRETE_SRC}/xos/network/sockets/ip/tcp/Transport.hxx \
$${XRETE_SRC}/xos/network/sockets/ip/udp/Transport.hxx \
\
$${XRETE_SRC}/xos/app/console/xrete/MainOpt.hxx \
$${XRETE_SRC}/xos/app/console/xrete/Main.hxx \

# xrete_exe SOURCES
#
xrete_exe_SOURCES += \
\
$${XRETE_SRC}/xos/network/sockets/Addresses.cxx \
$${XRETE_SRC}/xos/network/sockets/ip/tcp/Transport.cxx \
\
$${XRETE_SRC}/xos/app/console/xrete/MainOpt.cxx \
$${XRETE_SRC}/xos/app/console/xrete/Main.cxx \

########################################################################
# xrete_exe FRAMEWORKS
#
xrete_exe_FRAMEWORKS += \
$${xrete_FRAMEWORKS} \

# xrete_exe LIBS
#
xrete_exe_LIBS += \
$${xrete_LIBS} \


