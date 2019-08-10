///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2019 $organization$
///
/// This software is provided by the author and contributors ``as is'' 
/// and any express or implied warranties, including, but not limited to, 
/// the implied warranties of merchantability and fitness for a particular 
/// purpose are disclaimed. In no event shall the author or contributors 
/// be liable for any direct, indirect, incidental, special, exemplary, 
/// or consequential damages (including, but not limited to, procurement 
/// of substitute goods or services; loss of use, data, or profits; or 
/// business interruption) however caused and on any theory of liability, 
/// whether in contract, strict liability, or tort (including negligence 
/// or otherwise) arising in any way out of the use of this software, 
/// even if advised of the possibility of such damage.
///
///   File: Interface.hxx
///
/// Author: $author$
///   Date: 8/10/2019
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NETWORK_INTERFACE_HXX_
#define _XOS_NETWORK_INTERFACE_HXX_

#include "xos/base/Base.hxx"

namespace xos {
namespace network {

///////////////////////////////////////////////////////////////////////
///  Class: InterfaceT
///////////////////////////////////////////////////////////////////////
template <class TImplements = Implement>
class _EXPORT_CLASS InterfaceT: virtual public TImplements {
public:
    typedef TImplements Implements;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
}; /// class _EXPORT_CLASS InterfaceT
typedef InterfaceT<> Interface;

} /// namespace network
} /// namespace xos

#endif /// _XOS_NETWORK_INTERFACE_HXX_
