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
///   File: Main.hxx
///
/// Author: $author$
///   Date: 8/9/2019
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_APP_CONSOLE_XRETE_MAIN_HXX_
#define _XOS_APP_CONSOLE_XRETE_MAIN_HXX_

#include "xos/app/console/xrete/MainOpt.hxx"
#include "xos/network/sockets/Connection.hxx"
#include "xos/network/sockets/Addresses.hxx"
#include "xos/network/sockets/ip/v4/tcp/Transport.hxx"
#include "xos/network/sockets/ip/v4/Endpoint.hxx"
#include "xos/network/sockets/posix/Interface.hxx"

namespace xos {
namespace app {
namespace console {
namespace xrete {

///////////////////////////////////////////////////////////////////////
///  Class: MainT
///////////////////////////////////////////////////////////////////////
template
<class TExtends = MainOpt, class TImplements = typename TExtends::Implements>

class _EXPORT_CLASS MainT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef MainT Derives;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    MainT(): _run(0), 
        _clientHost("localhost"), _serverHost("*"),
        _clientPort(80), _serverPort(8080) {
    }
    virtual ~MainT() {
    }
private:
    MainT(const MainT &copy): _run(0) {
    }

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    int (Derives::*_run)(int argc, char_t**argv, char_t** env);
    virtual int Run(int argc, char_t**argv, char_t** env) {
        int err = 0;
        if ((_run)) {
            err = (this->*_run)(argc, argv, env);
        } else {
            err = this->DefaultRun(argc, argv, env);
        }
        return err;
    }
    virtual int Ip4TcpClientRun(int argc, char_t**argv, char_t** env) {
        int err = 0;
        this->OutLLn("try {...", NULL);
        try {
            network::sockets::ip::v4::tcp::Transport transport;
            network::sockets::ip::v4::Address address(Host());
            network::sockets::ip::v4::Endpoint endpoint(address, Port());
            network::sockets::posix::Interface socket(transport);
            network::sockets::Connection connection(endpoint);
            this->OutLLn("...} try", NULL);
        } catch (const Exception& e) {
            this->OutLLn("...catch (const Exception& e(\"", e.StatusToString().Chars(), "\"))", NULL);
            err = 1;
        } catch (...) {
            this->OutLLn("...catch (...)", NULL);
            err = 1;
        }
        return err;
    }
    virtual int DefaultRun(int argc, char_t**argv, char_t** env) {
        int err = Ip4TcpClientRun(argc, argv, env);
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const String& Host() const {
        return _clientHost;
    }
    virtual unsigned Port() const {
        return _clientPort;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    String _clientHost, _serverHost;
    unsigned _clientPort, _serverPort;
}; /// class _EXPORT_CLASS MainT
typedef MainT<> Main;

} /// namespace xrete
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// _XOS_APP_CONSOLE_XRETE_MAIN_HXX_
