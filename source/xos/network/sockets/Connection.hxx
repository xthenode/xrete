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
///   File: Connection.hxx
///
/// Author: $author$
///   Date: 8/10/2019
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NETWORK_SOCKETS_CONNECTION_HXX_
#define _XOS_NETWORK_SOCKETS_CONNECTION_HXX_

#include "xos/network/sockets/Endpoint.hxx"
#include "xos/network/Connection.hxx"

namespace xos {
namespace network {
namespace sockets {

///////////////////////////////////////////////////////////////////////
///  Class: ConnectionT
///////////////////////////////////////////////////////////////////////
template 
<class TEndpoint = Endpoint, 
 class TImplements = Implement, class TExtends = Extend>

class _EXPORT_CLASS ConnectionT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef TEndpoint Endpoint;
    
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    ConnectionT(const Endpoint& endpoint) {
    }
    ConnectionT(const ConnectionT& copy) {
    }
    ConnectionT() {
    }
    virtual ~ConnectionT() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
}; /// class _EXPORT_CLASS ConnectionT
typedef ConnectionT<> Connection;

} /// namespace sockets
} /// namespace network
} /// namespace xos

#endif /// _XOS_NETWORK_SOCKETS_CONNECTION_HXX_
