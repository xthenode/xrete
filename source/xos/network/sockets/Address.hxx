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
#ifndef _NETWORK_SOCKETS_ADDRESS_HXX_
#define _NETWORK_SOCKETS_ADDRESS_HXX_

#include "xos/network/Address.hxx"
#include "xos/base/Attached.hxx"
#include "xos/logger/Interface.hxx"

#include <sys/socket.h>
#include <sys/un.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <netdb.h>

namespace xos {
namespace network {
namespace sockets {

typedef socklen_t SockLen;
typedef struct sockaddr SockAddr;

///////////////////////////////////////////////////////////////////////
///  Class: AddressT
///////////////////////////////////////////////////////////////////////
template 
<typename TSockLen = SockLen,
 typename TSockAddr = SockAddr,
 typename TSockAddrAttached = TSockAddr*,
 typename TAddrIndex = address::Index,
 TAddrIndex VFirstAddrIndex = address::FirstIndex,
 TAddrIndex VLastAddrIndex = address::LastIndex,
 class TImplement = network::Address,
 class TImplements = AttacherT<TSockAddrAttached, int, 0, TImplement>,
 class TExtends = Extend>

class _EXPORT_CLASS AddressT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef TImplement Implement;

    typedef TAddrIndex AddrIndex;
    enum { 
        FirstAddrIndex = VFirstAddrIndex,
        LastAddrIndex = VLastAddrIndex
    };
    
    typedef TSockAddrAttached SockAddrAttached;
    typedef TSockAddr SockAddr;
    typedef TSockLen SockLen;
    
    typedef typename Implement::tSocketsAddress tSocketsAddress;

    typedef typename Implement::tFamily tFamily;
    enum { vFamilyUnspec = Implement::vFamilyUnspec };
    
    typedef typename Implement::tVersion tVersion;
    enum { vVersionUnspec = Implement::vVersionUnspec };

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    AddressT(const AddressT& copy): _socketAddressLen(copy._socketAddressLen) {
    }
    AddressT(): _socketAddressLen(0) {
    }
    virtual ~AddressT() {
    }
    
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual SockAddrAttached AttachFirst(const String& host) {
        SockAddrAttached (AddressT::*attach)(const char* host) = &AddressT::AttachFirst;
        return this->Attach(attach, host);
    }
    virtual SockAddrAttached AttachLast(const String& host) {
        SockAddrAttached (AddressT::*attach)(const char* host) = &AddressT::AttachLast;
        return this->Attach(attach, host);
    }
    virtual SockAddrAttached Attach(const String& host) {
        SockAddrAttached (AddressT::*attach)(const char* host) = &AddressT::Attach;
        return this->Attach(attach, host);
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual SockAddrAttached AttachFirst(const char* host) {
        if ((host)) { return this->Attach(host, FirstAddrIndex); }
        return this->Attach();
    }
    virtual SockAddrAttached AttachLast(const char* host) {
        if ((host)) { return this->Attach(host, LastAddrIndex); }
        return this->Attach();
    }
    virtual SockAddrAttached Attach(const char* host) {
        if ((host)) { return this->Attach(host, FirstAddrIndex); }
        return this->Attach();
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual SockAddrAttached Attach(const char* host, AddrIndex index) {
        SockAddrAttached saddr = 0;
        struct addrinfo* addrs = 0;
        int err = 0;

        LOG_DEBUG("getaddrinfo(\"" << host << "\",...)...");
        if (!(err = getaddrinfo(host, 0, 0, &addrs))) {
            const tFamily family = this->Family();
            struct addrinfo* addr = 0;
            AddrIndex addr_i = 0;

            LOG_DEBUG("...getaddrinfo(\"" << host << "\",...) family = " << family);
            for (addr_i = 0, addr = addrs; addr; addr = addr->ai_next) {
                const tFamily addrfamily = addr->ai_family;
                char addrhost[NI_MAXHOST];

                LOG_DEBUG("getnameinfo(...)... family = " << addrfamily);
                if (!(err = getnameinfo
                    (addr->ai_addr, addr->ai_addrlen, addrhost, sizeof(addrhost)-1, 0, 0, 0))) {

                    addrhost[sizeof(addrhost)-1] = 0;
                    LOG_DEBUG("...getnameinfo(..., addrhost = \"" << addrhost << "\",...)");
                    if (family == (addrfamily)) {
                        if ((addr_i == index) || ((LastAddrIndex == index) && !(addr->ai_next))) {
                            LOG_DEBUG("...found family " << family << " address[" << addr_i << "]");
                            saddr = this->Attach(addr->ai_addr, addr->ai_addrlen);
                            break;
                        } else {
                            ++addr_i;
                        }
                    }
                } else {
                    LOG_ERROR("...failed " << this->LastError() << " on getnameinfo(...)");
                }
            }
            freeaddrinfo(addrs);
        } else {
            LOG_ERROR("...failed " << this->LastError() << " on getaddrinfo(\"" << host << "\",...)");
        }
        return saddr;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual SockAddrAttached Attach(const SockAddrAttached socketAddress, SockLen socketAddressLen) {
        return 0;
    }
    virtual SockAddrAttached Attach() {
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual SockAddrAttached SocketAddress(SockLen& len) const {
        len = SocketAddressLen();
        return this->AttachedTo();
    }
    virtual SockAddrAttached SocketAddress() const {
        return this->AttachedTo();
    }
    virtual SockLen SetSocketAddressLen(SockLen to) {
        _socketAddressLen = to;
        return _socketAddressLen;
    }
    virtual SockLen SocketAddressLen() const {
        return _socketAddressLen;
    }
    virtual operator SockAddrAttached() const {
        return this->SocketAddress();
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int LastError() const {
        return errno;
    }

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual SockAddrAttached Attach
    (SockAddrAttached (AddressT::*attach)(const char* host), const String& host) {
        if ((attach)) {
            SockAddrAttached sockAddr = 0;
            const char* chars = 0;

            if ((chars = host.HasChars())) {
                sockAddr = (this->*attach)(chars);
            } else {
                sockAddr = (this->*attach)(0);
            }
            return  sockAddr;
        }
        return  0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void CopyAddr(SockAddr& toAddr, const SockAddr& addr, SockLen addrLen) const {
        ::memcpy(&toAddr, &addr, addrLen);
    }
    virtual void InitAddr(SockAddr& addr, SockLen addrLen) const {
        ::memset(&addr, 0, addrLen);
    }
    virtual void Init() {
    }
    virtual void Fini() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    SockLen _socketAddressLen;
}; /// class _EXPORT_CLASS AddressT
typedef AddressT<> AddressExtends;

class _EXPORT_CLASS Address: virtual public AddressExtends::Implements, public AddressExtends {
public:
    typedef AddressExtends::Implements Implements;
    typedef AddressExtends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    Address(const Address& copy): Extends(copy) {
    }
    Address() {
    }
    virtual ~Address() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual tSocketsAddress* SocketsAddress() const {
        return ((tSocketsAddress*)this);
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
}; /// class _EXPORT_CLASS Address

} /// namespace sockets
} /// namespace network
} /// namespace xos

#endif /// _NETWORK_SOCKETS_ADDRESS_HXX_
