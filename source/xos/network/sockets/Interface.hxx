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
#ifndef _XOS_NETWORK_SOCKETS_INTERFACE_HXX_
#define _XOS_NETWORK_SOCKETS_INTERFACE_HXX_

#include "xos/network/sockets/Transport.hxx"
#include "xos/network/sockets/Endpoint.hxx"
#include "xos/network/Interface.hxx"
#include "xos/base/Opened.hxx"

namespace xos {
namespace network {
namespace sockets {

typedef struct msghdr MsgHdr;

typedef int Backlog;
enum {
    BacklogNone = 0,
    BacklogDefault = SOMAXCONN
};
typedef int SendFlags;
enum {
    SendFlagsDefault = 0
};
typedef int RecvFlags;
enum {
    RecvFlagsDefault = 0
};
typedef int OptLevel;
typedef int OptName;

typedef int LingerSeconds;
enum {
    LingerSecondsNone = 0,
    LingerSecondsDefault = 10
};

typedef int ShutdownHow;
enum {
    ShutdownRead,
    ShutdownWrite,
    ShutdownBoth
};

typedef transport::Domain Domain;
typedef transport::Type Type;
typedef transport::Protocol Protocol;

class _EXPORT_CLASS Interface;
namespace implemented {
class _EXPORT_CLASS Interface;
} /// namespace implemented

namespace implement {
///////////////////////////////////////////////////////////////////////
///  Class: InterfaceT
///////////////////////////////////////////////////////////////////////
template 
<class TImplemented = implemented::Interface,
 typename TDomain = Domain,
 typename TType = Type,
 typename TProtocol = Protocol,
 class TTransport = Transport,
 class TEndpoint = Endpoint,
 class TImplements = OpenerT<network::Interface> >

class _EXPORT_CLASS InterfaceT: virtual public TImplements {
public:
    typedef TImplements Implements;

    typedef TImplemented Implemented;
    typedef TTransport Transport;
    typedef TEndpoint Endpoint;
    typedef TDomain Domain;
    typedef TType Type;
    typedef TProtocol Protocol;

    typedef sockets::LingerSeconds LingerSeconds;
    enum { LingerSecondsDefault = sockets::LingerSecondsDefault };

    typedef sockets::ShutdownHow ShutdownHow;
    enum { 
        ShutdownRead = sockets::ShutdownRead,
        ShutdownWrite = sockets::ShutdownWrite,
        ShutdownBoth = sockets::ShutdownBoth,
        ShutdownHowDefault = sockets::ShutdownBoth 
    };

    typedef sockets::Backlog Backlog;
    enum { BacklogDefault = sockets::BacklogDefault };

    typedef sockets::SendFlags SendFlags;
    enum { SendFlagsDefault = sockets::SendFlagsDefault };
    
    typedef sockets::RecvFlags RecvFlags;
    enum { RecvFlagsDefault = sockets::RecvFlagsDefault };
    
    typedef sockets::OptLevel OptLevel;
    typedef sockets::OptName OptName;

    typedef sockets::MsgHdr MsgHdr;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Open(const Transport& tp) {
        Domain domain = tp.Domain();
        Type type = tp.Type();
        Protocol protocol = tp.Protocol();

        if ((this->Open(domain, type, protocol))) {
            return true;
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Connect(const Endpoint& ep) {
        SockAddr* addr = 0;
        SockLen addrlen = 0;
        if ((addr = ep.SocketAddress(addrlen))) {
            if ((this->Connect(addr, addrlen))) {
                return true;
            }
        }
        return false;
    }
    virtual bool Listen(const Endpoint& ep, Backlog backlog) {
        SockAddr* addr = 0;
        SockLen addrlen = 0;
        if ((addr = ep.SocketAddress(addrlen))) {
            if ((this->Bind(addr, addrlen))) {
                if ((this->Listen(backlog))) {
                    return true;
                }
            }
        }
        return false;
    }
    virtual bool Listen(const Endpoint& ep) {
        Backlog backlog = this->DefaultBacklog();
        if ((this->Listen(ep, backlog))) {
            return true;
        }
        return false;
    }
    virtual bool Accept(Implemented& sock, const Endpoint& ep) {
        SockAddr* addr = 0;
        SockLen addrlen = 0;
        if ((addr = ep.SocketAddress(addrlen))) {
            if ((this->Accept(sock, addr, addrlen))) {
                return true;
            }
        }
        return false;
    }
    virtual bool Bind(const Endpoint& ep) {
        SockAddr* addr = 0;
        SockLen addrlen = 0;
        if ((addr = ep.SocketAddress(addrlen))) {
            if ((this->Bind(addr, addrlen))) {
                return true;
            }
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t SendTo
    (const void* buf, size_t len, SendFlags flags, const Endpoint& ep) {
        const SockAddr* addr = 0;
        SockLen addrlen = 0;
        if ((addr = ep.SocketAddress(addrlen))) {
            ssize_t count = this->SendTo(buf, len, flags, addr, addrlen);
            return count;
        }
        return 0;
    }
    virtual ssize_t RecvFrom
    (void* buf, size_t len, RecvFlags flags, const Endpoint& ep) {
        SockAddr* addr = 0;
        SockLen addrlen = 0;
        if ((addr = ep.SocketAddress(addrlen))) {
            ssize_t count = this->RecvFrom(buf, len, flags, addr, &addrlen);
            return count;
        }
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Open(Domain domain, Type type, Protocol protocol) {
        return false;
    }
    virtual bool Close() {
        return false;
    }
    virtual bool Shutdown(ShutdownHow how) {
        return false;
    }
    virtual bool Shutdown() {
        ShutdownHow how = ShutdownBoth;
        return this->Shutdown(how);
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Connect(const SockAddr* addr, SockLen addrlen) {
        return false; 
    }
    virtual bool Bind(const SockAddr* addr, SockLen addrlen) {
        return false; 
    }
    virtual bool Accept(Implemented& sock, SockAddr* addr, SockLen& addrlen) {
        return false; 
    }
    virtual bool Listen(Backlog backlog) { 
        return false; 
    }
    virtual bool Listen() {
        Backlog backlog = this->DefaultBacklog();
        return this->Listen(backlog);
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t Send(const void* buf, size_t len, SendFlags flags) { 
        return 0; 
    }
    virtual ssize_t Recv(void* buf, size_t len, RecvFlags flags) { 
        return 0; 
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t SendTo
    (const void* buf, size_t len, SendFlags flags, const SockAddr* addr, SockLen addrlen) { 
        return 0; 
    }
    virtual ssize_t RecvFrom
    (void* buf, size_t len, RecvFlags flags, SockAddr* addr, SockLen* addrlen) { 
        return 0; 
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t SendMsg(const MsgHdr* msg, SendFlags flags) { 
        return 0; 
    }
    virtual ssize_t RecvMsg(MsgHdr* msg, RecvFlags flags) { 
        return 0; 
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool GetFamily(address::Family &family, SockAddr &addr) const { 
        return false; 
    }
    virtual bool GetName(SockAddr* addr, SockLen &addrlen) const { 
        return false; 
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool SetReuseAddrOpt(bool on = true) { 
        return false; 
    }
    virtual bool SetNoreuseAddrOpt(bool on = true) { 
        return false; 
    }
    virtual bool GetReuseAddrOpt(bool &on) const { 
        return false; 
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool SetDelayOpt(bool on = true) { 
        return false; 
    }
    virtual bool SetNodelayOpt(bool on = true) { 
        return false; 
    }
    virtual bool GetDelayOpt(bool &on) const { 
        return false; 
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool SetLingerOpt
    (bool on = true, LingerSeconds lingerSeconds = -1) {
        return false; 
    }
    virtual bool SetDontLingerOpt
    (bool on = true, LingerSeconds lingerSeconds = -1) {
        return false; 
    }
    virtual bool GetLingerOpt(bool &on, int &lingerSeconds) const {
        return false; 
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool SetOpt
    (OptLevel level, OptName name, const void* value, SockLen length) {
        return false; 
    }
    virtual bool GetOpt
    (OptLevel level, OptName name, void* value, SockLen &length) const {
        return false; 
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual Backlog DefaultBacklog() const {
        return BacklogDefault;
    }
    virtual LingerSeconds DefaultLingerSeconds() const {
        return LingerSecondsDefault;
    }
    virtual bool DefaultBindAsReuseAddr() const {
        return true;
    }
    virtual ShutdownHow DefaultShutdownHow() const {
        return ShutdownHowDefault;
    }
    virtual RecvFlags DefaultRecvFlags() const {
        return RecvFlagsDefault;
    }
    virtual SendFlags DefaultSendFlags() const {
        return SendFlagsDefault;
    }
    virtual Implemented* ImplementedInterface() const {
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
}; /// class _EXPORT_CLASS InterfaceT
typedef InterfaceT<> Interface;
} /// namespace implement

///////////////////////////////////////////////////////////////////////
///  Class: Interface
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS Interface: virtual public implement::Interface {
public:
    typedef implement::Interface Implements;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    using Implements::Accept;
    virtual bool Accept
    (Interface& sock, SockAddr* addr, SockLen& addrlen) {
        implemented::Interface* implemented = 0;
        if ((implemented = sock.ImplementedInterface())) {
            return Accept(*implemented, addr, addrlen);
        }
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual Interface* SocketsInterface() const {
        return (Interface*)this;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef xos::Extend Extend;

} /// namespace sockets
} /// namespace network
} /// namespace xos

#endif /// _XOS_NETWORK_SOCKETS_INTERFACE_HXX_
