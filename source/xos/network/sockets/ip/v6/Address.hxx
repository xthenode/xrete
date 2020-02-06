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
#ifndef _NETWORK_SOCKETS_IP_V6_ADDRESS_HXX_
#define _NETWORK_SOCKETS_IP_V6_ADDRESS_HXX_

#include "xos/network/sockets/ip/Address.hxx"

namespace xos {
namespace network {
namespace sockets {
namespace ip {
namespace v6 {

typedef struct sockaddr_in6 SockAddr;

///////////////////////////////////////////////////////////////////////
///  Class: AddressT
///////////////////////////////////////////////////////////////////////
template 
<typename TVersionSockAddr = v6::SockAddr,
 class TExtends = ip::Address, 
 class TImplements = typename TExtends::Implements>

class _EXPORTED_ AddressT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef TVersionSockAddr VersionSockAddr;
    typedef typename Extends::AddrIndex AddrIndex;
    typedef typename Extends::SockAddrAttached SockAddrAttached;
    typedef typename Extends::SockAddr SockAddr;
    typedef typename Extends::SockLen SockLen;
    typedef typename Extends::tSocketsAddress tSocketsAddress;
    typedef typename Extends::tFamily tFamily;
    typedef typename Extends::tVersion tVersion;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    AddressT(const String& host, AddrIndex index) {
        this->Init();
        if (!(this->Attach(host, index))) {
            LOG_ERROR("...failed on Attach(host, index) throw Exception(ExceptionFailed)...")
            throw Exception(ExceptionFailed);
        }
    }
    AddressT(const String& host) {
        this->Init();
        if (!(this->Attach(host))) {
            LOG_ERROR("...failed on Attach(host) throw Exception(ExceptionFailed)...")
            throw Exception(ExceptionFailed);
        }
    }
    AddressT(const char* host, AddrIndex index) {
        this->Init();
        if (!(this->Attach(host, index))) {
            LOG_ERROR("...failed on Attach(host, index) throw Exception(ExceptionFailed)...")
            throw Exception(ExceptionFailed);
        }
    }
    AddressT(const char* host) {
        this->Init();
        if (!(this->Attach(host))) {
            LOG_ERROR("...failed on Attach(host) throw Exception(ExceptionFailed)...")
            throw Exception(ExceptionFailed);
        }
    }
    AddressT(const SockAddrAttached socketAddress, SockLen socketAddressLen) {
        this->Init();
        if (!(this->Attach(socketAddress, socketAddressLen))) {
            LOG_ERROR("...failed on Attach(socketAddress, socketAddressLen) throw Exception(ExceptionFailed)...")
            throw Exception(ExceptionFailed);
        }
    }
    AddressT(const AddressT& copy): Extends(copy) {
        this->Copy(copy);
    }
    AddressT() {
        this->Init();
        if (!(this->Attach())) {
            LOG_ERROR("...failed on Attach() throw Exception(ExceptionFailed)...")
            throw Exception(ExceptionFailed);
        }
    }
    virtual ~AddressT() {
        this->Fini();
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    using Extends::Attach;
    virtual SockAddrAttached Attach(const SockAddrAttached socketAddress, SockLen socketAddressLen) {
        if ((socketAddress) && (socketAddressLen == (this->SocketAddressLen()))) {
            if (this->Family() == (socketAddress->sa_family)) {
                SockAddrAttached attached = 0;
                if ((attached = this->Attach())) {
                    const VersionSockAddr& sockAddr = (const VersionSockAddr&)(*socketAddress);
                    _socketAddress.sin6_addr = sockAddr.sin6_addr;
                }
                return attached;
            }
        }
        return 0;
    }
    virtual SockAddrAttached Attach() {
        this->InitAddr(_socketAddress, this->SetSocketAddressLen(this->SocketAddressLen()));
        _socketAddress.sin6_family = this->Family();
        _socketAddress.sin6_addr = in6addr_any;
        _socketAddress.sin6_port = htons(0);
        return Extends::Attach((SockAddrAttached)(&_socketAddress));
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual SockLen SocketAddressLen() const {
        return ((SockLen)sizeof(_socketAddress));
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual tFamily Family() const {
        return AF_INET6;
    }
    virtual tVersion Version() const {
        return 6;
    }

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    using Extends::CopyAddr;
    virtual void CopyAddr(VersionSockAddr& toAddr, const VersionSockAddr& addr, SockLen addrLen) const {
        this->CopyAddr((SockAddr&)toAddr, (const SockAddr&)addr, addrLen);
    }
    using Extends::InitAddr;
    virtual void InitAddr(VersionSockAddr& addr, SockLen addrLen) const {
        this->InitAddr((SockAddr&)addr, addrLen);
    }
    virtual void Copy(const AddressT& copy) {
        this->CopyAddr(_socketAddress, copy._socketAddress, this->SocketAddressLen());
    }
    virtual void Init() {
        this->InitAddr(_socketAddress, this->SocketAddressLen());
    }
    virtual void Fini() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    VersionSockAddr _socketAddress;
}; /// class _EXPORTED_ AddressT
typedef AddressT<> Address;

} /// namespace v6
} /// namespace ip
} /// namespace sockets
} /// namespace network
} /// namespace xos

#endif /// _NETWORK_SOCKETS_IP_V6_ADDRESS_HXX_
