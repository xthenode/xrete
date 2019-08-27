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
#ifndef _XOS_NETWORK_SOCKETS_ENDPOINT_HXX_
#define _XOS_NETWORK_SOCKETS_ENDPOINT_HXX_

#include "xos/network/sockets/Address.hxx"
#include "xos/network/Endpoint.hxx"

namespace xos {
namespace network {
namespace sockets {

///////////////////////////////////////////////////////////////////////
///  Class: EndpointT
///////////////////////////////////////////////////////////////////////
template 
<class TAddress = Address,
 class TExtends = Extend, class TImplements = typename TExtends::Implements>

class _EXPORT_CLASS EndpointT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef TAddress Address;
    typedef typename Address::Attached SockAddrAttached;
    
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    EndpointT(const EndpointT& copy) {
    }
    EndpointT() {
    }
    virtual ~EndpointT() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual SockAddrAttached SocketAddress(SockLen& len) const {
        len = this->SocketAddressLen();
        return this->SocketAddress();
    }
    virtual SockAddrAttached SocketAddress() const {
        Address* address = 0;
        if ((address = this->AddressAttached())) {
            return address->SocketAddress();
        }
        return 0;
    }
    virtual SockLen SocketAddressLen() const {
        Address* address = 0;
        if ((address = this->AddressAttached())) {
            return address->SocketAddressLen();
        }
        return 0;
    }
    virtual operator SockAddrAttached () const {
        return this->SocketAddress();
    }
    virtual Address* AddressAttached() const {
        return 0;
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
}; /// class _EXPORT_CLASS EndpointT
typedef EndpointT<> Endpoint;

} /// namespace sockets
} /// namespace network
} /// namespace xos

#endif /// _XOS_NETWORK_SOCKETS_ENDPOINT_HXX_
