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
#ifndef _XOS_NETWORK_SOCKETS_IP_V4_ENDPOINT_HXX_
#define _XOS_NETWORK_SOCKETS_IP_V4_ENDPOINT_HXX_

#include "xos/network/sockets/ip/v4/Address.hxx"
#include "xos/network/sockets/ip/Endpoint.hxx"

namespace xos {
namespace network {
namespace sockets {
namespace ip {
namespace v4 {

///////////////////////////////////////////////////////////////////////
///  Class: EndpointT
///////////////////////////////////////////////////////////////////////
template 
<class TExtends = ip::Endpoint, class TImplements = typename TExtends::Implements>

class _EXPORT_CLASS EndpointT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    EndpointT(const Address& address, unsigned port): _address(address), _port(port) {
        this->Init();
    }
    EndpointT(const EndpointT& copy) {
    }
    EndpointT(unsigned port): _port(port) {
        this->Init();
    }
    EndpointT(): _port(0) {
        this->Init();
    }
    virtual ~EndpointT() {
        this->Fini();
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual sockets::Address* AddressAttached() const {
        return (sockets::Address*)&_address;
    }

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void Init() {
        _address.AttachPort(_port);
    }
    virtual void Fini() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    Address _address;
    unsigned _port;
}; /// class _EXPORT_CLASS EndpointT
typedef EndpointT<> Endpoint;

} /// namespace v4
} /// namespace ip
} /// namespace sockets
} /// namespace network
} /// namespace xos

#endif /// _XOS_NETWORK_SOCKETS_IP_V4_ENDPOINT_HXX_
