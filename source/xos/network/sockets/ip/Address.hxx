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
///   File: Address.hxx
///
/// Author: $author$
///   Date: 8/9/2019
///////////////////////////////////////////////////////////////////////
#ifndef _NETWORK_SOCKETS_IP_ADDRESS_HXX_
#define _NETWORK_SOCKETS_IP_ADDRESS_HXX_

#include "xos/network/sockets/Address.hxx"

namespace xos {
namespace network {
namespace sockets {
namespace ip {

///////////////////////////////////////////////////////////////////////
///  Class: AddressT
///////////////////////////////////////////////////////////////////////
template 
<class TExtends = sockets::Address, 
 class TImplements = typename TExtends::Implements>

class _EXPORTED_ AddressT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef typename Extends::AddrIndex AddrIndex;
    typedef typename Extends::SockAddrAttached SockAddrAttached;
    typedef typename Extends::SockAddr SockAddr;
    typedef typename Extends::SockLen SockLen;
    typedef typename Extends::tSocketsAddress tSocketsAddress;
    typedef typename Extends::tFamily tFamily;
    typedef typename Extends::tVersion tVersion;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    AddressT(const AddressT& copy): Extends(copy) {
    }
    AddressT() {
    }
    virtual ~AddressT() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
}; /// class _EXPORTED_ AddressT
typedef AddressT<> Address;

} /// namespace ip
} /// namespace sockets
} /// namespace network
} /// namespace xos

#endif /// _NETWORK_SOCKETS_IP_ADDRESS_HXX_
