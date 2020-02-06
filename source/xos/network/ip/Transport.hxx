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
#ifndef _XOS_NETWORK_IP_TRANSPORT_HXX_
#define _XOS_NETWORK_IP_TRANSPORT_HXX_

#include "xos/base/Base.hxx"

namespace xos {
namespace network {
namespace ip {

///////////////////////////////////////////////////////////////////////
///  Class: TransportT
///////////////////////////////////////////////////////////////////////
template <class TImplements = network::Transport>
class _EXPORTED_ TransportT: virtual public TImplements {
public:
    typedef TImplements Implements;

    TransportT(const TransportT& copy) {
    }
    TransportT() {
    }
    virtual ~TransportT() {
    }
}; /// class _EXPORTED_ TransportT
typedef TransportT<> Transport;

} /// namespace ip
} /// namespace network
} /// namespace xos

#endif /// _XOS_NETWORK_IP_TRANSPORT_HXX_
