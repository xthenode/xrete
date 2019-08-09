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
///   File: Transport.hxx
///
/// Author: $author$
///   Date: 8/9/2019
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NETWORK_TRANSPORT_HXX_
#define _XOS_NETWORK_TRANSPORT_HXX_

#include "xos/base/Base.hxx"

namespace xos {
namespace network {

namespace transport {

typedef int Domain;
enum { DomainUnspec = 0 };

typedef int Type;
enum { TypeUnspec = 0 };

typedef int Protocol;
enum { ProtocolUnspec = 0 };

} /// namespace transport

///////////////////////////////////////////////////////////////////////
///  Class: TransportT
///////////////////////////////////////////////////////////////////////
template 
<typename TDomain = transport::Domain, TDomain VDomainUnspec = transport::DomainUnspec,
 typename TType = transport::Type, TType VTypeUnspec = transport::TypeUnspec,
 typename TProtocol = transport::Protocol, TProtocol VProtocolUnspec = transport::ProtocolUnspec,
 class TImplements = Implement>

class _EXPORT_CLASS TransportT: virtual public TImplements {
public:
    typedef TImplements Implements;

    typedef TDomain tDomain;
    enum { vDomainUnspec = VDomainUnspec };
    
    typedef TType tType;
    enum { vTypeUnspec = VTypeUnspec };
    
    typedef TProtocol tProtocol;
    enum { vProtocolUnspec = VProtocolUnspec };

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual tDomain Domain() const {
        return vDomainUnspec;
    }
    virtual tType Type() const {
        return vTypeUnspec;
    }
    virtual tProtocol Protocol() const {
        return vProtocolUnspec;
    }
    
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
}; /// class _EXPORT_CLASS TransportT
typedef TransportT<> Transport;

} /// namespace network
} /// namespace xos

#endif /// _XOS_NETWORK_TRANSPORT_HXX_
