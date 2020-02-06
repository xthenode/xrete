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
#ifndef _NETWORK_ADDRESS_HXX_
#define _NETWORK_ADDRESS_HXX_

#include "xos/base/Base.hxx"

namespace xos {
namespace network {

namespace address {

typedef int Family;
enum { FamilyUnspec };

typedef int Version;
enum { VersionUnspec };

typedef int Index;
enum {
    FirstIndex = 0,
    LastIndex = -1
};

} /// namespace address

namespace sockets {

class _EXPORTED_ Address;

} /// namespace sockets

///////////////////////////////////////////////////////////////////////
///  Class: AddressT
///////////////////////////////////////////////////////////////////////
template 
<typename TFamily = address::Family, TFamily VFamilyUnspec = address::FamilyUnspec,
 typename TVersion = address::Version, TVersion VVersionUnspec = address::VersionUnspec,
 class TSocketsAddress = sockets::Address,
 class TImplements = Implement>

class _EXPORTED_ AddressT: virtual public TImplements {
public:
    typedef TImplements Implements;

    typedef TSocketsAddress tSocketsAddress;

    typedef TFamily tFamily;
    enum { vFamilyUnspec = VFamilyUnspec };
    
    typedef TVersion tVersion;
    enum { vVersionUnspec = VVersionUnspec };

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const tSocketsAddress* const_SocketsAddress() const {
        return this->SocketsAddress();
    }
    virtual tSocketsAddress* SocketsAddress() const {
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual tFamily Family() const {
        return vFamilyUnspec;
    }
    virtual tVersion Version() const {
        return vVersionUnspec;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
}; /// class _EXPORTED_ AddressT
typedef AddressT<> Address;

} /// namespace network
} /// namespace xos

#endif /// _NETWORK_ADDRESS_HXX_
