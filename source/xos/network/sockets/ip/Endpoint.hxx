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
///   File: Endpoint.hxx
///
/// Author: $author$
///   Date: 8/10/2019
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NETWORK_SOCKETS_IP_ENDPOINT_HXX_
#define _XOS_NETWORK_SOCKETS_IP_ENDPOINT_HXX_

#include "xos/network/sockets/ip/Address.hxx"
#include "xos/network/sockets/Endpoint.hxx"

namespace xos {
namespace network {
namespace sockets {
namespace ip {

///////////////////////////////////////////////////////////////////////
///  Class: EndpointT
///////////////////////////////////////////////////////////////////////
template 
<class TExtends = sockets::Endpoint, class TImplements = typename TExtends::Implements>

class _EXPORTED_ EndpointT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    EndpointT(const Address& address, unsigned port) {
    }
    EndpointT(const EndpointT& copy) {
    }
    EndpointT() {
    }
    virtual ~EndpointT() {
    }

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void Init() {
    }
    virtual void Fini() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
}; /// class _EXPORTED_ EndpointT
typedef EndpointT<> Endpoint;

} /// namespace ip
} /// namespace sockets
} /// namespace network
} /// namespace xos

#endif /// _XOS_NETWORK_SOCKETS_IP_ENDPOINT_HXX_
