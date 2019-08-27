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
#include "xos/network/sockets/Interface.hxx"
#include "xos/network/Connection.hxx"

namespace xos {
namespace network {
namespace sockets {

///////////////////////////////////////////////////////////////////////
///  Class: ConnectionT
///////////////////////////////////////////////////////////////////////
template 
<class TEndpoint = Endpoint,
 class TInterface = Interface, 
 class TImplements = Implement, class TExtends = Extend>

class _EXPORT_CLASS ConnectionT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef TInterface Interface;
    typedef TEndpoint Endpoint;

    typedef typename Interface::SendFlags SendFlags;
    enum { SendFlagsDefault = Interface::SendFlagsDefault };

    typedef typename Interface::RecvFlags RecvFlags;
    enum { RecvFlagsDefault = Interface::RecvFlagsDefault };
    
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    ConnectionT(Interface& socket, const Endpoint& endpoint)
    : _socket(socket), _sendFlags(SendFlagsDefault), _recvFlags(RecvFlagsDefault) {
        if (!(this->Connect(endpoint))) {
            LOG_ERROR("...throw Exception(ExceptionFailed)...");
            throw Exception(ExceptionFailed);
        }
    }
    ConnectionT(const ConnectionT& copy)
    : _socket(copy.Socket()), _sendFlags(copy._sendFlags), _recvFlags(copy._recvFlags) {
    }
    ConnectionT(Interface& socket)
    : _socket(socket), _sendFlags(SendFlagsDefault), _recvFlags(RecvFlagsDefault) {
    }
    virtual ~ConnectionT() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Connect(const Endpoint& endpoint) {
        bool success = _socket.Connect(endpoint);
        return success;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t Send(const void* buf, size_t len) {
        size_t count = _socket.Send(buf, len, _sendFlags);
        return count; 
    }
    virtual ssize_t Recv(void* buf, size_t len) { 
        size_t count = _socket.Recv(buf, len, _recvFlags);
        return count; 
    }
    
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual SendFlags SetSendFlags(const SendFlags& to) {
        _sendFlags = to;
        return _sendFlags;
    }
    virtual RecvFlags SetRecvFlags(const RecvFlags& to) {
        _recvFlags = to;
        return _recvFlags;
    }
    virtual Interface& Socket() const {
        return (Interface&)_socket;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    Interface& _socket;
    SendFlags _sendFlags;
    RecvFlags _recvFlags;
}; /// class _EXPORT_CLASS ConnectionT
typedef ConnectionT<> Connection;

} /// namespace sockets
} /// namespace network
} /// namespace xos

#endif /// _XOS_NETWORK_SOCKETS_CONNECTION_HXX_
