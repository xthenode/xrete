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
#ifndef _XOS_NETWORK_SOCKETS_POSIX_INTERFACE_HXX_
#define _XOS_NETWORK_SOCKETS_POSIX_INTERFACE_HXX_

#include "xos/network/sockets/Interface.hxx"
#include "xos/base/Opened.hxx"

namespace xos {
namespace network {
namespace sockets {
namespace posix {

namespace socket {

typedef int AttachedTo;
typedef int UnattachedTo;
enum { Unattached = -1 };

} /// namespace socket

///////////////////////////////////////////////////////////////////////
///  Class: InterfaceT
///////////////////////////////////////////////////////////////////////
template 
<class TAttacher = AttacherT
 <socket::AttachedTo, socket::UnattachedTo, socket::Unattached, sockets::Interface>,
 class TAttached = AttachedT
 <socket::AttachedTo, socket::UnattachedTo, socket::Unattached, TAttacher, sockets::Extend>,
 class TOpened = OpenedT
 <socket::AttachedTo, socket::UnattachedTo, socket::Unattached, TAttacher, TAttached>,
 class TImplements = TAttacher, class TExtends = TOpened>

class _EXPORT_CLASS InterfaceT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef typename Extends::Transport Transport;
    typedef typename Extends::Attached Attached;
    enum { Unattached = Extends::Unattached };
    
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    InterfaceT(const Transport& transport) {
        if (!(this->Open(transport))) {
            LOG_ERROR("...failed on Open(transport) throw OpenException(OpenFailed)...");
            throw OpenException(OpenFailed);
        }
    }
    InterfaceT(Domain domain, Type type, Protocol protocol) {
        if (!(this->Open(domain, type, protocol))) {
            LOG_ERROR("...failed on Open(domain, type, protocol) throw OpenException(CloseFailed)...");
            throw OpenException(CloseFailed);
        }
    }
    InterfaceT(const InterfaceT& copy): Extends(copy.AttachedTo()) {
    }
    InterfaceT() {
    }
    virtual ~InterfaceT() {
        if (!(this->Closed())) {
            LOG_ERROR("...throw OpenException(CloseFailed)...");
            throw OpenException(CloseFailed);
        }
    }
    
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    using Implements::Open;
    virtual bool Open(Domain domain, Type type, Protocol protocol) {
        Attached detached = ((Attached)Unattached);

        if (((Attached)Unattached) != (detached = OpenAttached(domain, type, protocol))) {
            this->SetIsOpen();
            return true;
        }
        return false;
    }
    virtual Attached OpenAttached(Domain domain, Type type, Protocol protocol) {
        Attached detached = ((Attached)Unattached);

        if ((this->Closed())) {
            if (((Attached)Unattached) != (detached = OpenDetached(domain, type, protocol))) {
                this->Attach(detached);
            }
        }
        return detached;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    using Implements::Connect;
    virtual bool Connect(const SockAddr* addr, SockLen addrlen) {
        Attached detached = ((Attached)Unattached);

        if ((0 <= (detached = this->AttachedTo())) && (addr) && (addrlen)) {
            int err = 0;

            LOG_DEBUG("::connect(..., addrlen = " << addrlen << ")...");
            if (!(err = ::connect(detached, addr, addrlen))) {
                LOG_DEBUG("...::connect(..., addrlen = " << addrlen << ")...");
                return true;
            } else {
                LOG_ERROR("...failed errno = " << errno << " on ::connect(..., addrlen = " << addrlen << ")");
            }
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t Send(const void* buf, size_t len, SendFlags flags) { 
        Attached detached = ((Attached)Unattached);
        if ((0 <= (detached = this->AttachedTo())) && (buf) && (len)) {
            ssize_t count = 0;
            LOG_DEBUG_TRACE((len > 1), "::send(..., len = " << len << ", flags = " << flags << ")...");
            if (0 <= (count = ::send(detached, buf, len, flags))) {
                LOG_DEBUG_TRACE((len > 1), "..." << count << " = ::send(..., len = " << len << ", flags = " << flags << ")...");
                return count;
            } else {
                XOS_LOG_ERROR("...failed errno = " << errno << " on ::send(..., len = " << len << ", flags = " << flags << ")");
            }
        }
        return 0; 
    }
    virtual ssize_t Recv(void* buf, size_t len, RecvFlags flags) { 
        Attached detached = ((Attached)Unattached);
        if ((0 <= (detached = this->AttachedTo())) && (buf) && (len)) {
            ssize_t count = 0;
            LOG_DEBUG_TRACE((len > 1), "::recv(..., len = " << len << ", flags = " << flags << ")...");
            if (0 <= (count = ::recv(detached, buf, len, flags))) {
                LOG_DEBUG_TRACE((len > 1), "..." << count << " = ::recv(..., len = " << len << ", flags = " << flags << ")...");
                return count;
            } else {
                XOS_LOG_ERROR("...failed errno = " << errno << " on ::recv(..., len = " << len << ", flags = " << flags << ")");
            }
        }
        return 0; 
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual Attached OpenDetached(Domain domain, Type type, Protocol protocol) const {
        Attached detached = ((Attached)Unattached);

        LOG_DEBUG("::socket(domain = " << domain << ", type = " << type << ", protocol = " << protocol << ")...");
        if (0 <= (detached = ::socket(domain, type, protocol))) {
            LOG_DEBUG("...::socket(domain = " << domain << ", type = " << type << ", protocol = " << protocol << ")");
        } else {
            LOG_ERROR("failed errno = " << errno << " on ::socket(domain = " << domain << ", type = " << type << ", protocol = " << protocol << ")");
        }
        return detached;
    }
    virtual bool CloseDetached(Attached detached) const {
        if (0 <= (detached)) {
            int err = 0;

            LOG_DEBUG("::close(" << detached << ")...");
            if (!(err = ::close(detached))) {
                LOG_DEBUG("...::close(" << detached << ")");
                return true;
            } else {
                LOG_ERROR("failed errno = " << errno << " on ::close(" << detached << ")");
            }
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
}; /// class _EXPORT_CLASS InterfaceT
typedef InterfaceT<> Interface;

} /// namespace posix
} /// namespace sockets
} /// namespace network
} /// namespace xos

#endif /// _XOS_NETWORK_SOCKETS_POSIX_INTERFACE_HXX_
