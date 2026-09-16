//////////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2023 $organization$
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
///   File: server.hpp
///
/// Author: $author$
///   Date: 10/30/2023
//////////////////////////////////////////////////////////////////////////
#ifndef XOS_UDENTIFY_FS_SERVER_HPP
#define XOS_UDENTIFY_FS_SERVER_HPP

#include "xos/udentify/server/interface.hpp"
#include "xos/io/crt/file/reader.hpp"

namespace xos {
namespace udentify {
namespace fs {

/// class servert
template 
<class TExtends = xos::udentify::server::extended::interfacet<> , 
 class TImplements = xos::udentify::server::interfacet<> >
class exported servert: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef servert derives;

    typedef typename implements::char_t char_t;
    typedef typename implements::string_t string_t;
    
    enum { 
        exception_none       = extends::exception_none, 
        exception_unexpected = extends::exception_unexpected, 
        exception_exist      = extends::exception_exist, 
        exception_not_exist  = extends::exception_not_exist 
    }; /// enum

    typedef xos::io::crt::file::reader file_t;
    typedef xos::io::crt::file::reader::sized_t file_char_t;
    
    /// constructor / destructor
    servert()
    : udentity_path_("./udentity"), 
      udentity_path_separator_("/") {
    }
    virtual ~servert() {
    }
private:
    servert(const servert &copy): extends(copy) {
        throw exception(exception_unexpected);
    }
public:

    /// password
    virtual const string_t& password
    (string_t& result, const string_t& user, const string_t& resource, const string_t& password) {
        const string_t& udentity_path_separator = this->udentity_path_separator();
        const string_t& udentity_path = this->udentity_path();
        string_t& udentity_filename = this->udentity_filename();
        string_t& udentity_content = this->udentity_content();
        file_t udentity_file;

        udentity_filename.assign(udentity_path);
        udentity_filename.append(udentity_path_separator);
        udentity_filename.append(user);
        udentity_filename.append(udentity_path_separator);
        udentity_filename.append(resource);
        udentity_filename.append(udentity_path_separator);
        udentity_filename.append(password);

        LOGGER_IS_LOGGED_INFO("(udentity_file.open(\"" << udentity_filename << "\"))...");
        if ((udentity_file.open(udentity_filename.chars()))) {
            ssize_t count = 0;
            bool success = false;

            LOGGER_IS_LOGGED_INFO("...(udentity_file.open(\"" << udentity_filename << "\"))");
            LOGGER_IS_LOGGED_INFO("udentity_content.clear()...");
            udentity_content.clear();
            LOGGER_IS_LOGGED_INFO("(0 < (count = read_content(udentity_content, udentity_file)))...");
            if ((success = (0 < (count = read_content(udentity_content, udentity_file))))) {
                LOGGER_IS_LOGGED_INFO("...(0 < (" << count << " = read_content(\"" << udentity_content << "\", udentity_file)))");
                LOGGER_IS_LOGGED_INFO("result.assign(\"" << udentity_content << "\")...");
                result.assign(udentity_content);
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on (0 < (" << count << " = read_content(\"" << udentity_content << "\", udentity_file)))");
            }
            LOGGER_IS_LOGGED_INFO("udentity_file.close()...");
            udentity_file.close();
            if ((success)) {
                return result;
            }
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on (file.open(\"" << udentity_filename << "\"))");
        }
        LOGGER_IS_LOGGED_INFO("extends::password(result, user = \"" << user << "\", resource = \"" << resource << "\", password = \"" << password << "\")...");
        extends::password(result, user, resource, password);
        LOGGER_IS_LOGGED_INFO("...extends::password(result = \"" << result << "\", user = \"" << user << "\", resource = \"" << resource << "\", password = \"" << password << "\")");
        return result;
    }

protected:
    
    /// read_content
    virtual ssize_t read_content(string_t& content, file_t& file) const {
        ssize_t count = 0, amount = 0;
        size_t size = sizeof(file_char_t);
        file_char_t fc = 0;
        
        do {
            if (0 < (amount = file.read(&fc, size))) {
                char_t c = ((char_t)fc);

                if ((c != '\r') && (c != '\n')) {
                    content.append(&c, 1);
                }
                count += amount;
                continue;
            }
            break;
        } while (0 < amount);
        return count;
    }

    /// ...udentity_content
    virtual string_t& set_udentity_content(const string_t& to) {
        string_t& udentity_content = this->udentity_content();
        udentity_content.assign(to);
        return udentity_content;
    }
    virtual string_t& udentity_content() const {
        return (string_t&)udentity_content_;
    }

    /// ...udentity_filename
    virtual string_t& set_udentity_filename(const string_t& to) {
        string_t& udentity_filename = this->udentity_filename();
        udentity_filename.assign(to);
        return udentity_filename;
    }
    virtual string_t& udentity_filename() const {
        return (string_t&)udentity_filename_;
    }

    /// ...udentity_path
    virtual const string_t& set_udentity_path(const string_t& to) {
        string_t& udentity_path_separator = this->udentity_path_separator();
        string_t& udentity_path = this->udentity_path();
        udentity_path.assign(to);
        return udentity_path;
    }
    virtual string_t& udentity_path() const {
        return (string_t&)udentity_path_;
    }

    /// ...udentity_path_separator
    virtual string_t& set_udentity_path_separator(const string_t& to) {
        string_t& udentity_path_separator = this->udentity_path_separator();
        udentity_path_separator.assign(to);
        return udentity_path_separator;
    }
    virtual string_t& udentity_path_separator() const {
        return (string_t&)udentity_path_separator_;
    }

protected:
    string_t udentity_content_, udentity_filename_, udentity_path_, udentity_path_separator_;
}; /// class servert
typedef servert<> server;

} /// namespace fs 
} /// namespace udentify 
} /// namespace xos 

#endif /// ndef XOS_UDENTIFY_FS_SERVER_HPP
