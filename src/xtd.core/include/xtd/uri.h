/// @file
/// @brief Contains xtd::uri class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "iequatable.h"
#include "uri_components.h"
#include "uri_format.h"
#include "uri_host_name_type.h"
#include "uri_kind.h"
#include "uri_partial.h"
#include "ustring.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Provides an object representation of a uniform resource identifier (URI) and easy access to the parts of the URI.
  /// @code
  /// class uri : public xtd::iequatable<uri>, public xtd::object
  /// @endcode
  /// @par Inheritance
  /// xtd::object → xtd::uri
  /// @par Implements
  /// xtd::iequatable <>
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system
  /// @par Examples
  /// The following example creates an instance of the xtd::uri class and uses it to create a xtd::net::web_request instance.
  /// @code
  /// uri contoso("http://www.contoso.com/");
  ///
  /// auto wr = web_request::create(contoso);
  /// @endcode
  /// The following code snippet shows example values of the various properties on the class.
  /// @include uri.cpp
  /// @remarks A URI is a compact representation of a resource available to your application on the intranet or Internet. The xtd::uri class defines the properties and methods for handling URIs, including parsing, comparing, and combining. The xtd::uri class properties are read-only; to create a modifiable object, use the xtd::uri_builder class.
  /// @remarks Relative URIs (for example, "/new/index.htm") must be expanded with respect to a base URI so that they are absolute. The xtd::uri::make_relative_uri method is provided to convert absolute URIs to relative URIs when necessary.
  /// @remarks The xtd::uri constructors do not escape URI strings if the string is a well-formed URI including a scheme identifier.
  /// @remarks The xtd::uri properties return a canonical data representation in escaped encoding, with all characters with Unicode values greater than 127 replaced with their hexadecimal equivalents. To put the URI in canonical form, the xtd::uri constructor performs the following steps:
  /// * Converts the URI scheme to lowercase.
  /// * Converts the host name to lowercase.
  /// * If the host name is an IPv6 address, the canonical IPv6 address is used. ScopeId and other optional IPv6 data are removed.
  /// * Removes default and empty port numbers.
  /// * Canonicalizes the path for hierarchical URIs by compacting sequences such as /./, /../, //, including escaped representations. Note that there are some schemes for which escaped representations are noy compacted.
  /// * For hierarchical URIs, if the host is not terminated with a forward slash (/), one is added.
  /// * By default, any reserved characters in the URI are escaped in accordance with RFC 2396. This behavior changes if International Resource Identifiers or International Domain Name parsing is enabled in which case reserved characters in the URI are escaped in accordance with RFC 3986 and RFC 3987.
  /// @remarks As part of canonicalization in the constructor for some schemes, escaped representations are compacted. The schemes for which URI will compact escaped sequences include the following: file, http, https, net.pipe, and net.tcp. For some other schemes, these sequences are not compacted. The following code snippet shows how compacting looks in practice. The escaped sequences are unescaped, if necessary, and then compacted.
  /// @code
  /// auto uri = xtd::uri("http://myUrl/../.."); // http scheme, unescaped
  /// // OR
  /// auto uri = xtd::uri("http://myUrl/%2E%2E/%2E%2E"); // http scheme, escaped
  /// // OR
  /// var uri = xtd::uri("ftp://myUrl/../.."); // ftp scheme, unescaped
  /// // OR
  /// var uri = xtd:::uri("ftp://myUrl/%2E%2E/%2E%2E"); // ftp scheme, escaped
  ///
  /// console::write_line("Absolute uri: {}", uri.absolute_uri());
  /// console::write_line("Path And query: {}", uri.path_and_query());
  /// @endcode
  /// When this code executes, it returns output similar to the following text.
  /// @code
  /// Absolute uri: http://myurl/
  /// Path And query: /
  /// @endcode
  /// @remarks You can transform the contents of the xtd::uri class from an escape encoded URI reference to a readable URI reference by using the xtd::uri::to_string method. Note that some reserved characters might still be escaped in the output of the xtd::uri::to_string method. This is to support unambiguous reconstruction of a URI from the value returned by xtd::uri::to_string.
  /// @remarks Some URIs include a fragment identifier or a query or both. A fragment identifier is any text that follows a number sign (#), not including the number sign; the fragment text is stored in the xtd::uri::fragment property. Query information is any text that follows a question mark (?) in the URI; the query text is stored in the xtd::uri::query property.
  /// @note The URI class supports the use of IP addresses in both quad-notation for IPv4 protocol and colon-hexadecimal for IPv6 protocol. Remember to enclose the IPv6 address in square brackets, as in http://[::1].
  /// @par International Resource Identifier Support
  /// Web addresses are typically expressed using uniform resource identifiers that consist of a very restricted set of characters:
  /// * Upper and lower case ASCII letters from the English alphabet.
  /// * Digits from 0 to 9.
  /// * A small number of other ASCII symbols.
  /// The specifications for URIs are documented in RFC 2396, RFC 2732, RFC 3986, and RFC 3987 published by the Internet Engineering Task Force (IETF).
  /// <br><br>With the growth of the Internet, there is a growing need to identify resources using languages other than English. Identifiers which facilitate this need and allow non-ASCII characters (characters in the Unicode/ISO 10646 character set) are known as International Resource Identifiers (IRIs). The specifications for IRIs are documented in RFC 3987 published by IETF. Using IRIs allows a URL to contain Unicode characters.
  /// @par Implicit File Path Support
  /// xtd::uri can also be used to represent local file system paths. These paths can be represented explicitly in URIs that begin with the file:// scheme, and implicitly in URIs that do not have the file:// scheme. As a concrete example, the following two URIs are both valid, and represent the same file path:
  /// @code
  /// auto uri1 = uri("C:/test/path/file.txt") // Implicit file path.
  /// auto uri2 = uri("file:///C:/test/path/file.txt") // Explicit file path.
  /// @endcode
  /// These implicit file paths are not compliant with the URI specification and so should be avoided when possible. When using Unix-based systems, implicit file paths can be especially problematic, because an absolute implicit file path is indistinguishable from a relative path. When such ambiguity is present, xtd::uri default to interpreting the path as an absolute URI.
  /// @par Security Considerations
  /// Because of security concerns, your application should use caution when accepting xtd::uri instances from untrusted sources and with dont_escape set to true in the constructor. You can check a URI string for validity by calling the xtd::uri::is_well_formed_original_string method.
  /// <br><br>When dealing with untrusted user input, confirm assumptions about the newly created xtd::uri instance before trusting its properties. This can be done in the following way:
  /// @code
  /// ustring user_input = ...;
  ///
  /// auto base_uri = uri("https://myWebsite/files/");
  ///
  /// if (!uri::try_create(base_uri, user_input, new_uri)) {
  ///   // Fail: invalid input.
  /// }
  ///
  /// if (!base_uri.isbase_of(new_uri)) {
  ///   // Fail: the uri base has been modified - the created uri is not rooted in the original directory.
  /// }
  /// @endcode
  /// This validation can be used in other cases, like when dealing with UNC paths, by simply changing the base_uri:
  /// @code
  /// aauto base_uri = uri(@"\\host\share\some\directory\name\");
  /// @endcode
  class core_export_ uri : public xtd::iequatable<uri>, public xtd::object {
  public:
    /// @name Fields
    
    /// @{
    /// @brief Specifies the characters that separate the communication protocol scheme from the address portion of the URI. This field is read-only.
    /// @par Examples
    /// The following example creates a string from xtd::uri::uri_scheme_http, xtd::uri::scheme_delimiter, and an address. A xtd::uri instance is then created from the string.
    /// @code
    /// ustring address = "www.contoso.com";
    /// ustring uri_string = ustring::format("{0}{1}{2}/", uri::uri_scheme_http, uri::scheme_delimiter, address);
    /// uri result(uri_string);
    /// if (result.is_well_formed_original_string())
    ///   console::write_line("{0} is a well formed uri", uri_string);
    /// else
    ///   console::write_line("{0} is not a well formed uri", uri_string);
    /// @endcode
    inline static const xtd::ustring scheme_delimiter = "://";
    
    /// @brief Specifies that the URI is a pointer to a file. This field is read-only.
    /// @par Examples
    /// The following example creates a xtd::uri instance and determines whether the scheme is xtd::uri::uri_scheme_file.
    /// @code
    /// uri address2("file://server/filename.ext");
    /// if (address2.scheme() == uri::uri_scheme_file)
    ///   console::write_line("uri is a file");
    /// @endcode
    inline static const xtd::ustring uri_scheme_file = "file";
    
    /// @brief Specifies that the URI is accessed through the File Transfer Protocol (FTP). This field is read-only.
    /// @par Examples
    /// The following example creates a xtd::uri instance and determines whether the scheme is xtd::uri::uri_scheme_ftp.
    /// @code
    /// uri address7("ftp://contoso/files/testfile.txt");
    /// if (address7.scheme() == uri::uri_scheme_ftp)
    ///   console::write_line("uri is ftp protocol");
    /// @endcode
    inline static const xtd::ustring uri_scheme_ftp = "ftp";
    
    /// @brief Specifies that the URI is accessed through the Gopher protocol. This field is read-only.
    /// @par Examples
    /// The following example creates a xtd::uri instance and determines whether the scheme is xtd::uri::uri_scheme_gopher.
    /// @code
    /// uri address6("gopher://example.contoso.com/");
    /// if (address6.scheme() == uri::uri_scheme_gopher)
    ///   console::write_line("uri is gopher protocol");
    /// @endcode
    inline static const xtd::ustring uri_scheme_gopher = "gopher";
    
    /// @brief Specifies that the URI is accessed through the Hypertext Transfer Protocol (HTTP). This field is read-only.
    /// @par Examples
    /// The following example creates a xtd::uri instance and determines whether the scheme is xtd::uri::uri_scheme_http.
    /// @code
    /// uri address1("http://www.contoso.com/index.htm#search");
    /// console::write_line("address 1 {0} a valid scheme name",
    ///                     uri::check_scheme_name(address1.scheme()) ? " has" : " does not have");
    ///
    /// if (address1.scheme == uri::uri_scheme_http)
    ///   console::write_line("uri is HTTP type");
    ///
    /// console::write_line(address1.host_name_type());
    /// @endcode
    inline static const xtd::ustring uri_scheme_http = "http";
    
    /// @brief Specifies that the URI is accessed through the Hypertext Transfer Protocol (HTTPS). This field is read-only.
    /// @par Examples
    /// The following example creates a xtd::uri instance and determines whether the scheme is xtd::uri::uri_scheme_https.
    /// @code
    /// uri address8("https://example.contoso.com");
    /// if (address8.scheme() == uri::uri_scheme_https)
    ///   console::write_line("uri is HTTPS protocol.");
    /// @endcode
    inline static const xtd::ustring uri_scheme_https = "https";
    
    /// @brief Specifies that the URI is an e-mail address and is accessed through the Simple Mail Transport Protocol (SMTP). This field is read-only.
    /// @par Examples
    /// The following example creates a xtd::uri instance and determines whether the scheme is xtd::uri::uri_scheme_mailto.
    /// @code
    /// uri address3("mailto:user@contoso.com?subject=uri");
    /// if (address3.scheme() == uri::uri_scheme_mailto)
    ///   console::write_line("uri is an email address");
    /// @endcode
    inline static const xtd::ustring uri_scheme_mailto = "mailto";
    
    /// @brief Specifies that the URI is accessed through the NetPipe scheme used by Windows Communication Foundation (WCF). This field is read-only.
    inline static const xtd::ustring uri_scheme_net_pipe = "net.pipe";
    
    /// @brief Specifies that the URI is accessed through the NetTcp scheme used by Windows Communication Foundation (WCF). This field is read-only.
    inline static const xtd::ustring uri_scheme_net_tcp = "net.tcp";
    
    /// @brief Specifies that the URI is an Internet news group and is accessed through the Network News Transport Protocol (NNTP). This field is read-only.
    /// @par Examples
    /// The following example creates a xtd::uri instance and determines whether the scheme is xtd::uri::uri_scheme_news.
    /// @code
    /// uri address4("news:123456@contoso.com");
    /// if (address4.scheme() == uri::uri_scheme_news)
    ///   console::write_line("uri is an Internet news group");
    /// @endcode
    inline static const xtd::ustring uri_scheme_news = "news";
    
    /// @brief Specifies that the URI is an Internet news group and is accessed through the Network News Transport Protocol (NNTP). This field is read-only.
    /// @par Examples
    /// The following example creates a xtd::uri instance and determines whether the scheme is xtd::uri::uri_scheme_nntp.
    /// @code
    /// Uri address5("nntp://news.contoso.com/123456@contoso.com");
    /// if (address5.scheme() == uri::uri_scheme_nntp)
    ///   console::write_line("uri is nntp protocol");
    /// @endcode
    inline static const xtd::ustring uri_scheme_nntp = "nntp";
    /// @}
    
    /// @name Constructors
    
    /// @{
    /// @brief Initializes a new instance of the xtd::uri class.
    uri() = default;
    
    /// @cond
    uri(const xtd::uri& uri) = default;
    uri& operator =(const uri&) = default;
    /// @endcond
    
    /// @brief Initializes a new instance of the xtd::uri class with the specified URI.
    /// @param uri_string : A string that identifies the resource to be represented by the xtd::uri instance. Note that an IPv6 address in string form must be enclosed within brackets. For example, "http://[2607:f8b0:400d:c06::69]".
    /// @exception xtd::uri_format_exception uri_string is empty.<br>-or-<br>The scheme specified in uri_string is not correctly formed. See xtd::uricheck_scheme_name.<br>-or-<br>The password specified in uri_string is not valid.<br>-or-<br>The host name specified in uri_string is not valid.<br>-or-<br>The file name specified in uri_string is not valid.<br>-or-<br>The user name specified in uri_string is not valid.<br>-or-<or>The host or authority name specified in uri_string cannot be terminated by backslashes.<br>-or-<br>The port number specified in uri_string is not valid or cannot be parsed.<br>-or-<br>The length of uri_string exceeds 65519 characters.<br>-or-<br>The length of the scheme specified in uri_string exceeds 1023 characters.<br>-or-<br>There is an invalid character sequence in uri_string.<br>-or-<br>The MS-DOS path specified in uri_string must start with c:\\.
    /// @par Examples
    /// The following example creates a xtd::uri instance with the URI http://www.contoso.com/.
    /// @code
    /// auto my_uri = uri("http://www.contoso.com/");
    /// @endcode
    /// @remarks This constructor creates a xtd::uri instance from a URI string. It parses the URI, puts it in canonical format, and makes any required escape encodings.
    /// @remarks This constructor does not ensure that the xtd::uri refers to an accessible resource.
    /// @remarks This constructor assumes that the string parameter references an absolute URI and is equivalent to calling the xtd::uri constructor with xtd::uri_kind set to xtd::uri_kind::absolute. If the string parameter passed to the constructor is a relative URI, this constructor will throw a xtd::uri_format_exception.
    explicit uri(const xtd::ustring& uri_string);
    
    /// @brief Initializes a new instance of the xtd::uri class with the specified URI. This constructor allows you to specify if the URI string is a relative URI, absolute URI, or is indeterminate.
    /// @param uri_string : A string that identifies the resource to be represented by the xtd::uri instance. Note that an IPv6 address in string form must be enclosed within brackets. For example, "http://[2607:f8b0:400d:c06::69]".
    /// @param uri_kind : Specifies whether the URI string is a relative URI, absolute URI, or is indeterminate.
    /// @exception xtd::uri_format_exception uri_string contains a relative URI and uri_kind is xtd::uri_kind::absolute.<br>-or-<br>uri_string contains an absolute URI and uri_kind is xtd::uri_kind::relative.<br>-or-<br>uri_string is empty.<br>-or-<br>The scheme specified in uri_string is not correctly formed. See CheckSchemeName(String).<br>-or-<br>uri_string contains too many slashes.<br>-or-<br>The password specified in uri_string is not valid.<br>-or-<br>The host name specified in uri_string is not valid.<br>-or-<br>The file name specified in uri_string is not valid.<br>-or-<br>The user name specified in uri_string is not valid.<br>-or-<br>The host or authority name specified in uri_string cannot be terminated by backslashes.<br>-or-<br>The port number specified in uri_string is not valid or cannot be parsed.<br>-or-<br>The length of uri_string exceeds 65519 characters.<br>-or-<br>The length of the scheme specified in uri_string exceeds 1023 characters.<br>-or-<br>There is an invalid character sequence in uri_string.<br>-or-<br>The MS-DOS path specified in uri_string must start with c:\\.
    /// @remarks Relative and absolute URIs have different restrictions on their format. For example, a relative URI does not require a scheme or an authority. The value you specify in uri_kind must match the type of URI passed in uri_string. However, if xtd::uri::relative_orA_asolute is specified, the URI string can be relative or absolute.
    uri(const xtd::ustring& uri, xtd::uri_kind uri_kind);
    
    /// @brief Initializes a new instance of the xtd::uri class based on the specified base URI and relative URI string.
    /// @param base_uri : The base URI.
    /// @param relative_uri : The relative URI to add to the base URI.
    /// @exception xtd::uri_format_exception The URI formed by combining base_uri and relative_uri is empty or contains only spaces.<br>-or-<br>The scheme specified in the URI formed by combining base_uri and relative_uri is not valid.<br>-or-<br>The URI formed by combining base_uri and relative_uri contains too many slashes.<br>-or-<br>The password specified in the URI formed by combining base_uri and relative_uri is not valid.<br>-or-<br>The host name specified in the URI formed by combining base_uri and relative_uri is not valid.<br>-or-<br>The file name specified in the URI formed by combining base_uri and relative_uri is not valid.<br>-or-<br>The user name specified in the URI formed by combining base_uri and relative_uri is not valid.<br>-or-<br>The host or authority name specified in the URI formed by combining base_uri and relative_uri cannot be terminated by backslashes.<br>-or-<br>The port number specified in the URI formed by combining base_uri and relative_uri is not valid or cannot be parsed.<br>-or-<br>The length of the URI formed by combining base_uri and relative_uri exceeds 65519 characters.<br>-or-<br>The length of the scheme specified in the URI formed by combining base_uri and relative_uri exceeds 1023 characters.<br>-or-<br>There is an invalid character sequence in the URI formed by combining base_uri and relative_uri.<br>-or-<br>The MS-DOS path specified in uriString must start with c:\\.
    /// @par Examples
    /// The following example creates a new instance of the xtd::uri class by combining the relative URIs http://www.contoso.com and catalog/shownew.htm to form the absolute URI http://www.contoso.com/catalog/shownew.htm.
    /// @code
    /// auto base_uri = uri("http://www.contoso.com");
    /// auto my_uri = uri(base_uri, "catalog/shownew.htm");
    ///
    /// console::write_line(my_uri.to_string());
    /// @endcode
    /// @remarks This constructor creates a xtd::uri instance by combining the base_uri and the relative_uri. If relative_uri is an absolute URI (containing a scheme, host name, and optionally a port number), the xtd::uri instance is created using only relative_uri.
    /// @remarks If the base_uri has relative parts (like /api), then the relative part must be terminated with a slash, (like /api/), if the relative part of base_uri is to be preserved in the constructed xtd::uri.
    /// @remarks Additionally, if the relative_uri begins with a slash, then it will replace any relative part of the base_uri
    /// @remarks This constructor does not ensure that the xtd::uri refers to an accessible resource.
    uri(const uri& base_uri, const xtd::ustring& relative_uri);
    
    /// @brief Initializes a new instance of the xtd::uri class based on the combination of a specified base xtd::uri instance and a relative xtd::uri instance.
    /// @param base_uri : An absolute xtd::uri that is the base for the new xtd::uri instance.
    /// @param relative_uri : A relative xtd::uri instance that is combined with base_uri.
    /// @exception xtd::uri_format_exception The URI formed by combining base_uri and relative_uri is empty or contains only spaces.<br>-or-<br>The scheme specified in the URI formed by combining base_uri and relative_uri is not valid.<br>-or-<br>The URI formed by combining base_uri and relative_uri contains too many slashes.<br>-or-<br>The password specified in the URI formed by combining base_uri and relative_uri is not valid.<br>-or-<br>The host name specified in the URI formed by combining base_uri and relative_uri is not valid.<br>-or-<br>The file name specified in the URI formed by combining base_uri and relative_uri is not valid.<br>-or-<br>The user name specified in the URI formed by combining base_uri and relative_uri is not valid.<br>-or-<br>The host or authority name specified in the URI formed by combining base_uri and relative_uri cannot be terminated by backslashes.<br>-or-<br>The port number specified in the URI formed by combining base_uri and relative_uri is not valid or cannot be parsed.<br>-or-<br>The length of the URI formed by combining base_uri and relative_uri exceeds 65519 characters.<br>-or-<br>The length of the scheme specified in the URI formed by combining base_uri and relative_uri exceeds 1023 characters.<br>-or-<br>There is an invalid character sequence in the URI formed by combining base_uri and relative_uri.<br>-or-<br>The MS-DOS path specified in uriString must start with c:\\.
    /// @par Examples
    /// This example creates an absolute xtd::uri instance, absolute_uri, and a relative xtd::uri instance, relative_uri. A new xtd::uri instance, combined_uri, is then created from these two instances.
    /// @code
    /// // Create an absolute xtd::ri from a string.
    /// auti absolute_uri = uri("http://www.contoso.com/");
    ///
    /// // Create a relative xtd::uri from a string and uri_kind::relative for
    /// // creating a relative xtd::uri.
    /// auto relative_uri = uri("/catalog/shownew.htm?date=today", uri_kind::relative);
    ///
    /// // Check whether the new xtd::uri is absolute or relative.
    /// if (!relative_uri.is_absolute_uri())
    ///   console::write_line("{0} is a relative xtd::uri.", relative_uri);
    ///
    /// // Create a new xtd::uri from an absolute xtd::uri and a relative xtd::uri.
    /// auto combined_uri = uri(absolute_uri, relative_uri);
    /// console::write_line(combined_uri.absolute_uri());
    /// @endcode
    /// @remarks This constructor creates a new xtd::uri instance by combining an absolute xtd::uri instance, base_uri, with a relative xtd::uri instance, relative_uri. If relative_uri is an absolute xtd::uri instance (containing a scheme, host name, and optionally a port number), the xtd::uri instance is created using only relative_uri.
    /// @remarks If the base_uri has relative parts (like /api), then the relative part must be terminated with a slash, (like /api/), if the relative part of base_uri is to be preserved in the constructed xtd::uri.
    /// @remarks Additionally, if the relative_uri begins with a slash, then it will replace any relative part of the base_uri
    /// @remarks This constructor does not ensure that the xtd::uri refers to an accessible resource.
    uri(const uri& base_uri, const uri& relative_uri);
    /// @}
    
    /// @name Properties
    
    /// @{
    /// @brief Gets the absolute path of the URI.
    /// @return The absolute path to the resource.
    /// @exception xtd::invalid_operation_exception This instance represents a relative URI, and this property is valid only for absolute URIs.
    /// @par Examples
    /// The following example writes the path /catalog/shownew.htm to the console.
    /// @code
    /// auto base_uri = uri("http://www.contoso.com/");
    /// auto my_uri = uri(base_uri, "catalog/shownew.htm?date=today");
    ///
    /// console::write_line(my_uri.absolute_path());
    /// @endcode
    /// @remarks The xtd::uri::absolute_path property contains the path information that the server uses to resolve requests for information. Typically this is the path to the desired information on the server's file system, although it also can indicate the application or script the server must run to provide the information.
    /// @remarks The path information does not include the scheme, host name, or query portion of the URI.
    xtd::ustring absolute_path() const;
    
    /// @brief Gets the absolute URI.
    /// @return The entire URI.
    /// @exception xtd::invalid_operation_exception This instance represents a relative URI, and this property is valid only for absolute URIs.
    /// @par Examples
    /// The following example writes the complete contents of the xtd::uri instance to the console. In the example shown, http://www.contoso.com/catalog/shownew.htm?date=today is written to the console.
    /// @code
    /// auto base_uri = uri("http://www.contoso.com");
    /// auto my_uri = uri(base_uri,"catalog/shownew.htm?date=today");
    /// console::write_line(my_uri.absolute_uri());
    /// @endcode
    /// @remarks The xtd::uri::absolute_uri property includes the entire URI stored in the xtd::uri instance, including all fragments and query strings.
    xtd::ustring absolute_uri();
    
    /// @brief Gets the Domain Name System (DNS) host name or IP address and the port number for a server.
    /// @return The authority component of the URI represented by this instance.
    /// @exception xtd::invalid_operation_exception This instance represents a relative URI, and this property is valid only for absolute URIs.
    /// @par Examples
    /// The following example writes the host name (www.contoso.com) and port number (8080) of the server to the console.
    /// @code
    /// auto base_uri = uri("http://www.contoso.com:8080/");
    /// auto my_uri = uri(base_uri,"shownew.htm?date=today");
    ///
    /// console::write_line(my_uri.authority());
    /// @endcode
    /// @remarks The xtd::uri::authority property is typically a server DNS host name or IP address. This property might include the service port number if it differs from the default port for the URI. If the xtd::uri::authority component contains reserved characters, these are escaped in the string value returned by this property.
    xtd::ustring authority() const;
    
    /// @brief Gets an unescaped host name that is safe to use for DNS resolution.
    /// @return The host part of the URI in a format suitable for DNS resolution; or the original host string, if it is already suitable for resolution.
    /// @exception xtd::invalid_operation_exception This instance represents a relative URI, and this property is valid only for absolute URIs.
    /// @par Examples
    /// The following example creates a xtd::uri instance from a string. It illustrates the difference between the value returned from xtd::uri::host, which returns the host name or address specified in the URI, and the value returned from xtd::uri::dns_safe_host, which returns an address that is safe to use in DNS resolution.
    /// @code
    /// // Create new Uri using a string address.
    /// auto address = uri("http://[fe80::200:39ff:fe36:1a2d%254]/temp/example.htm");
    ///
    /// // Make the address DNS safe.
    ///
    /// // The following outputs "[fe80::200:39ff:fe36:1a2d]".
    /// console::write_line(address.host());
    ///
    /// // The following outputs "fe80::200:39ff:fe36:1a2d%254".
    /// console::write_line(address.dns_safe_host());
    /// @endcode
    /// As explained in Remarks, unescape the host name before resolving it. You can use the xtd::uri::unescape_data_string method to unescape the host name, and you can resolve it by calling the xtd::uri::get_host_entry method.
    /// @remarks For IPv6 addresses, the brackets ([]) are removed and the xtd::uri::scope_id property is set, if one was specified when this instance was constructed.
    xtd::ustring dns_safe_host() const;
    
    /// @brief Gets the escaped URI fragment.
    /// @return string A string that contains any URI fragment information.
    /// @exception xtd::invalid_operation_exception This instance represents a relative URI, and this property is valid only for absolute URIs.
    /// @remarks The fragment property gets any text following a fragment marker (#) in the URI, including the fragment marker itself. Given the URI http://www.contoso.com/index.htm#main, the fragment property would return #main.
    /// @remarks The fragment property is not considered in any equals comparison.
    xtd::ustring fragment() const;
    
    /// @brief Gets the host component of this instance.
    /// @return string A string that contains the host name. This is usually the DNS host name or IP address of the server.
    /// @exception xtd::invalid_operation_exception This instance represents a relative URI, and this property is valid only for absolute URIs.
    /// @remarks Unlike the authority property, this property value does not include the port number.
    xtd::ustring host() const;
    
    /// @brief Gets the type of the host name specified in the URI.
    /// @return xtd::uri_host_name_type A member of the xtd::uri_host_name_type enumeration.
    /// @exception xtd::invalid_operation_exception This instance represents a relative URI, and this property is valid only for absolute URIs.
    xtd::uri_host_name_type host_name_type() const;
    
    /// @brief Gets the RFC 3490 compliant International Domain Name of the host, using Punycode as appropriate. This string, after being unescaped if necessary, is safe to use for DNS resolution.
    /// @return The hostname, formatted with Punycode according to the IDN standard.
    /// @exception xtd::invalid_operation_exception This instance represents a relative URI, and this property is valid only for absolute URIs.
    /// @remarks This property is provided for the use of lower-level networking protocols that require the domain name in Punycode form. If your code does not require that specific format, use xtd::uri::host for the hostname.
    /// @remarks The deprecated xtd::uri::dns_safe_host property is dependent on app.config settings, which cannot be changed by Windows Store applications. xtd::uri::idn_host is provided as the preferred alternative to using xtd::uri::dns_safe_host, because xtd::uri::idn_host is guaranteed to always be DNS safe, no matter what the current app.config settings might be.
    /// @remarks If you used an escaped string to construct this instance (for example, "http://[fe80::200:39ff:fe36:1a2d%254]/temp/example.htm"), then xtd::uri::idn_host returns an escaped string. You should unescape any escaped string returned from IdnHost before using that string for DNS resolution. Be aware that if you used an invalid unescaped string to construct this instance (for example, "http://[fe80::200:39ff:fe36:1a2d%4]/temp/example.htm"), then IdnHost returns an unescaped string.
    xtd::ustring idn_host() const;
    
    /// @brief Gets whether the xtd::uri instance is absolute.
    /// @return bool A bool value that is true if the xtd::uri instance is absolute; otherwise, false.
    /// @remarks This property is true if the string or xtd::uri instance that was passed into the constructor can be parsed as an absolute xtd::uri instance, which contains a scheme, an authority, and a path. Otherwise, the xtd::uri instance is treated as relative and might omit the scheme or other URI components.
    bool is_absolute_uri() const;
    
    /// @brief Gets whether the port value of the URI is the default for this scheme.
    /// @return bool A bool value that is true if the value in the port property is the default port for this scheme; otherwise, false.
    /// @exception xtd::invalid_operation_exception This instance represents a relative URI, and this property is valid only for absolute URIs.
    bool is_default_port() const;
    
    /// @brief Gets a value indicating whether the specified xtd::uri is a file URI.
    /// @return bool A bool value that is true if the xtd::uri is a file URI; otherwise, false.
    /// @exception xtd::invalid_operation_exception This instance represents a relative URI, and this property is valid only for absolute URIs.
    /// @remarks The is_file property is true when the scheme property equals uri_scheme_file.
    bool is_file() const;
    
    /// @brief Gets whether the specified xtd::uri references the local host.
    /// @return bool A bool value that is true if this xtd::uri references the local host; otherwise, false.
    /// @exception xtd::invalid_operation_exception This instance represents a relative URI, and this property is valid only for absolute URIs.
    /// @remarks is_loopback returns true if the URI specified when this instance was created was 127.0.0.1, loopback, or localhost, or if the URI did not specify host information (for example, file:///c:Dir/file.txt). All other URIs return false.
    bool is_loopback() const;
    
    /// @brief Gets whether the specified xtd::uri is a universal naming convention (UNC) path.
    /// @return bool A bool value that is true if the xtd::uri is a UNC path; otherwise, false.
    /// @exception xtd::invalid_operation_exception This instance represents a relative URI, and this property is valid only for absolute URIs.
    /// @remarks The is_unc property is true if the specified xtd::uri instance is a UNC path (such as \\server\folder or file://server/folder). This property always returns true if the URI has the file:// scheme and specifies a host component.
    bool is_unc() const;
    
    /// @brief Gets the original URI string that was passed to the xtd::uri constructor.
    /// @return string A string containing the exact URI specified when this instance was constructed; otherwise, Empty.
    /// @exception xtd::invalid_operation_exception This instance represents a relative URI, and this property is valid only for absolute URIs.
    /// @remarks If the URI specified to the constructor contained leading or trailing spaces, these spaces are preserved.
    /// @remarks The value returned by this property differs from to_string and absolute_uri. to_string returns the canonically unescaped form of the URI. absolute_uri returns the canonically escaped form of the URI.
    /// @remarks When International Resource Identifier (URI) and Internationalized Domain Name (IDN) support are enabled, original_string returns the original non normalized string with Punycode host name if one was used to initialize the xtd::uri instance. Punycode names contain only ASCII characters and always start with the xn-- prefix.
    /// @remarks For more information on URI support, see the Remarks section for the xtd::uri class.
    /// @remarks When a xtd::uri object is serialized, the original_string is not preserved. The serialization process uses the fully escaped and canonicalized absolute_uri property when serializing. For a xtd::uri that contains an IPv6 address, the IPv6 address and the scope ID are included in the serialized xtd::uri object.
    xtd::ustring local_path() const;
    
    /// @brief Gets the original URI string that was passed to the xtd::uri constructor.
    /// @return string A string containing the exact URI specified when this instance was constructed; otherwise, Empty.
    /// @exception xtd::invalid_operation_exception This instance represents a relative URI, and this property is valid only for absolute URIs.
    /// @remarks If the URI specified to the constructor contained leading or trailing spaces, these spaces are preserved.
    /// @remarks The value returned by this property differs from to_string and absolute_uri. to_string returns the canonically unescaped form of the URI. absolute_uri returns the canonically escaped form of the URI.
    /// @remarks When International Resource Identifier (URI) and Internationalized Domain Name (IDN) support are enabled, original_string returns the original non normalized string with Punycode host name if one was used to initialize the xtd::uri instance. Punycode names contain only ASCII characters and always start with the xn-- prefix.
    /// @remarks For more information on URI support, see the Remarks section for the xtd::uri class.
    /// @remarks When a xtd::uri object is serialized, the original_string is not preserved. The serialization process uses the fully escaped and canonicalized absolute_uri property when serializing. For a xtd::uri that contains an IPv6 address, the IPv6 address and the scope ID are included in the serialized xtd::uri object.
    const xtd::ustring& original_string() const;
    
    /// @brief Gets the absolute_path and query properties separated by a question mark (?).
    /// @return string A string that contains the absolute_path and query properties separated by a question mark (?).
    /// @exception xtd::invalid_operation_exception This instance represents a relative URI, and this property is valid only for absolute URIs.
    /// @remarks The path_and_query property contains the absolute path on the server and the query information sent with the request. It is identical to concatenating the absolute_path and query properties.
    /// @remarks The path_and_query property is escaped according to RFC 2396 by default. If International Resource Identifiers (IRIs) or Internationalized Domain Name (IDN) parsing is enabled, the path_and_query property is escaped according to RFC 3986 and RFC 3987.
    /// @remarks For more information on URI support, see the Remarks section for the xtd::uri class.
    xtd::ustring path_and_query() const;
    
    /// @brief Gets the port number of this URI.
    /// @return int32 An int32 value that contains the port number for this URI.
    /// @exception xtd::invalid_operation_exception This instance represents a relative URI, and this property is valid only for absolute URIs.
    /// @remarks The port number defines the protocol port used for contacting the server referenced in the URI. If a port is not specified as part of the URI, the port property returns the default value for the protocol. If there is no default port number, this property returns -1.
    int32 port() const;
    
    /// @brief Gets any query information included in the specified URI.
    /// @return string A string that contains any query information included in the specified URI.
    /// @exception xtd::invalid_operation_exception This instance represents a relative URI, and this property is valid only for absolute URIs.
    /// @remarks The query property contains any query information included in the URI. query information is separated from the path information by a question mark (?) and continues to the end of the URI. The query information returned includes the leading question mark.
    /// @remarks The query information is escaped according to RFC 2396 by default. If International Resource Identifiers (IRIs) or Internationalized Domain Name (IDN) parsing is enabled, the query information is escaped according to RFC 3986 and RFC 3987.
    /// @remarks For more information on URI support, see the Remarks section for the xtd::uri class.
    xtd::ustring query() const;
    
    /// @brief Gets the scheme name for this URI.
    /// @return string A string that contains the scheme for this URI, converted to lowercase.
    /// @exception xtd::invalid_operation_exception This instance represents a relative URI, and this property is valid only for absolute URIs.
    /// @remarks The scheme property returns the scheme used to initialize the xtd::uri instance. This property does not indicate that the scheme used to initialize the xtd::uri instance was recognized.
    /// @remarks The following table shows examples of some possible values returned by the scheme property.
    /// | Scheme   | Description                                                                                    |
    /// | -------- | ---------------------------------------------------------------------------------------------- |
    /// | file     | The resource is a file on the local computer.                                                  |
    /// | ftp      | The resource is accessed through FTP.                                                          |
    /// | gopher   | The resource is accessed through the Gopher protocol.                                          |
    /// | http     | The resource is accessed through HTTP.                                                         |
    /// | https    | The resource is accessed through SSL-encrypted HTTP.                                           |
    /// | ldap     | The resource is accessed through the LDAP protocol.                                            |
    /// | mailto   | The resource is an e-mail address and accessed through the SMTP protocol.                      |
    /// | net.pipe | The resource is accessed through a named pipe.                                                 |
    /// | net.tcp  | The resource is accessed from TCP endpoint.                                                    |
    /// | news     | The resource is accessed through the NNTP protocol.                                            |
    /// | nntp     | The resource is accessed through the NNTP protocol.                                            |
    /// | telnet   | The resource is accessed through the TELNET protocol.                                          |
    /// | uuid     | The resource is accessed through a unique UUID endpoint name for communicating with a service. |
    xtd::ustring scheme() const;
    
    /// @brief Gets an array containing the path segments that make up the specified URI.
    /// @return Array<Srtring> A string array that contains the path segments that make up the specified URI.
    /// @exception xtd::invalid_operation_exception This instance represents a relative URI, and this property is valid only for absolute URIs.
    /// @remarks The segments property returns an array of strings containing the "segments" (substrings) that form the URI's absolute path. The first segment is obtained by parsing the absolute path from its first character until you reach a slash (/) or the end of the path. Each additional segment begins at the first character after the preceding segment, and terminates with the next slash or the end of the path. (A URI's absolute path contains everything after the host and port and before the query and fragment.)
    /// @remarks The following example shows the absolute path and segments for two URIs. The second example illustrates that the fragment and query are not part of the absolute path and therefore are not segments.
    /// @remarks Absolute URI
    /// @remarks     http://www.contoso.com/Chapters/Chapter1/Sections/Section1.htm
    /// @remarks Absolute path
    /// @remarks     /Chapters/Chapter1/Sections/Section1.htm
    /// @remarks segments
    /// @remarks     /Chapters/Chapter1/Sections/Section1.htm
    /// @remarks Absolute URI
    /// @remarks     http://www.contoso.com/Chapters/Chapter1/Sections/Section1.htm#page1?answer=NO
    /// @remarks Absolute path
    /// @remarks     /Chapters/Chapter1/Sections/Section1.htm
    /// @remarks segments
    /// @remarks     /Chapters/Chapter1/Sections/Section1.htm
    /// @remarks Note that because the absolute path starts with a '/', the first segment contains it and nothing else.
    std::vector<xtd::ustring> segments() const;
    
    /// @brief Gets the user name, password, or other user-specific information associated with the specified URI.
    /// @return string A string that contains the user information associated with the URI. The returned value does not include the '@' character reserved for delimiting the user information part of the URI.
    /// @exception xtd::invalid_operation_exception This instance represents a relative URI, and this property is valid only for absolute URIs.
    /// @remarks The value returned by this property is usually in the format "userName:password".
    xtd::ustring user_info() const;
    /// @}
    
    /// @name Methods
    
    /// @{
    /// @brief Determines whether the specified scheme name is valid.
    /// @param scheme The scheme name to validate.
    /// @return bool A bool value that is true if the scheme name is valid; otherwise, false.
    /// @remarks This method checks the scheme name for validity according to RFC 2396 by default. If International Resource Identifiers (IRIs) or Internationalized Domain Name (IDN) parsing is enabled, this method checks the scheme name for validity according to RFC 3986. The scheme name must begin with a letter and must contain only letters, digits, and the characters ".", "+", or "-".
    /// @remarks For more information on URI support, see the Remarks section for the xtd::uri class.
    static bool check_scheme_name(const xtd::ustring& scheme);
    
    /// @brief Converts a string to its escaped representation.
    /// @param value The string to escape.
    /// @return string A string that contains the escaped representation of stringToEscape.
    /// @exception ArgumentNullException value is null.
    /// @exception UriFormatException The length of value exceeds 32766 characters.
    /// @remarks By default, the escape_data_string method converts all characters except for RFC 2396 unreserved characters to their hexadecimal representation. If International Resource Identifiers (IRIs) or Internationalized Domain Name (IDN) parsing is enabled, the escape_data_string method converts all characters, except for RFC 3986 unreserved characters, to their hexadecimal representation. All Unicode characters are converted to UTF-8 format before being escaped.
    /// @remarks This method assumes that stringToEscape has no escape sequences in it.
    /// @remarks By default, the string is escaped according to RFC 2396. If International Resource Identifiers (IRIs) or Internationalized Domain Name (IDN) parsing is enabled, the string is escaped according to RFC 3986 and RFC 3987. See these RFCs for a definition of reserved and unreserved characters.
    /// @remarks For more information on URI support, see the Remarks section for the xtd::uri class.
    static xtd::ustring escape_data_string(const xtd::ustring& value);
    
    /// @brief Converts a URI string to its escaped representation.
    /// @param value The string to escape.
    /// @return string A string that contains the escaped representation of stringToEscape.
    /// @exception ArgumentNullException value is null.
    /// @exception UriFormatException The length of value exceeds 32766 characters.
    /// @remarks Use the escape_uri_string method to prepare an unescaped URI string to be a parameter to the xtd::uri constructor.
    /// @remarks By default, the escape_uri_string method converts all characters, except RFC 2396 unreserved characters, to their hexadecimal representation. If International Resource Identifiers (IRIs) or Internationalized Domain Name (IDN) parsing is enabled, the escape_uri_string method converts all characters, except for RFC 3986 unreserved characters, to their hexadecimal representation. All Unicode characters are converted to UTF-8 format before being escaped.
    /// @remarks This method assumes that stringToEscape has no escape sequences in it.
    /// @remarks By default, the string is escaped according to RFC 2396. If International Resource Identifiers (IRIs) or Internationalized Domain Name (IDN) parsing is enabled, the string is escaped according to RFC 3986 and RFC 3987. See these RFCs for a definition of reserved and unreserved characters.
    /// @remarks For more information on URI support, see the Remarks section for the xtd::uri class.
    static xtd::ustring escape_uri_string(const xtd::ustring& value);
    
    /// @brief Gets the decimal value of a hexadecimal digit.
    /// @param digit The hexadecimal digit (0-9, a-f, A-F) to convert.
    /// @return int32 An int32 value that contains a number from 0 to 15 that corresponds to the specified hexadecimal digit.
    /// @exception ArgumentException digit is not a valid hexadecimal digit (0-9, a-f, A-F).
    /// @remarks The from_hex method converts a character representing a hexadecimal digit (0-9, a-f, A-F) to its decimal value (0 to 15). If digit is not a valid hexadecimal digit, an ArgumentException exception is thrown.
    static int32 from_hex(char digit);
    
    /// @brief Gets the specified components of the current instance using the specified escaping for special characters.
    /// @param components A bitwise combination of the xtd::uri_components values that specifies which parts of the current instance to return to the caller.
    /// @param format One of the xtd::uri_format values that controls how special characters are escaped.
    /// @return string A string that contains the components.
    /// @exception xtd::invalid_operation_exception This instance represents a relative URI, and this property is valid only for absolute URIs.
    /// @remarks When query or fragment is specified alone, the return value includes the delimiter. The scheme, user_info, host, port, and Path components do not include the delimiter. For all other xtd::uri_components values, and combinations of values, the delimiters are included in the returned value.
    /// @remarks The components are returned in the order that they appear in the URI. For example, if scheme is specified, it appears first.
    /// @remarks When International Resource Identifier (URI) and Internationalized Domain Name (IDN) support are enabled, the number of characters returned in the string increases. Punycode names used to support URI contain only ASCII characters and always start with the xn-- prefix. When URI and IDN are enabled, Unicode surrogate characters are handled correctly by the get_components method.
    /// @remarks For more information on URI support, see the Remarks section for the xtd::uri class.
    xtd::ustring get_components(xtd::uri_components components, xtd::uri_format format) const;
    
    /// @brief Gets the specified portion of a xtd::uri instance.
    /// @param part = One of the xtd::uri_partial values that specifies the end of the URI portion to return.
    /// @return string A string that contains the specified portion of the xtd::uri instance.
    /// @exception xtd::invalid_operation_exception This instance represents a relative URI, and this property is valid only for absolute URIs.
    /// @exception ArgumentException The specified part is not valid.
    /// @remarks The get_left_part method returns a string containing the leftmost portion of the URI string, ending with the portion specified by part.
    /// @remarks get_left_part includes delimiters in the following cases:
    /// @remarks   * scheme includes the scheme delimiter.
    /// @remarks   * authority does not include the path delimiter.
    /// @remarks   * Path includes any delimiters in the original URI up to the query or fragment delimiter.
    /// @remarks   * query includes the Path, plus the query and its delimiter.
    /// @remarks The following examples show a URI and the results of calling get_left_part with scheme, authority, Path, or query.
    /// | URI                                         | Scheme  | Autority                | Path                                       | Query                                       |
    /// | ------------------------------------------- | ------- | ----------------------- | ------------------------------------------ | ------------------------------------------- |
    /// | http://www.contoso.com/index.htm?date=today | http:// | http://www.contoso.com  | http://www.contoso.com/index.htm           | http://www.contoso.com/index.htm?date=today |
    /// | http://www.contoso.com/index.htm#main       | http:// | http://www.contoso.com  | http://www.contoso.com/index.htm           | http://www.contoso.com/index.htm            |
    /// | mailto:user@contoso.com?subject=uri         | mailto: | mailto:user@contoso.com | mailto:user@contoso.com?subject=uri        | <None>                                      |
    /// | nntp://news.contoso.com/123456@contoso.com  | nntp:// | nntp://news.contoso.com | nntp://news.contoso.com/123456@contoso.com | nntp://news.contoso.com/123456@contoso.com  |
    /// | news:123456@contoso.com                     | news:   | news:123456@contoso.com | news:123456@contoso.com                    | <None>                                      |
    /// | file://server/filename.ext                  | file:// | file://server           | file://server/filename.ext                 | file://server/filename.ext                  |
    xtd::ustring get_left_part(xtd::uri_partial part) const;
    
    /// @brief Converts a specified character into its hexadecimal equivalent.
    /// @param character The character to convert to hexadecimal representation.
    /// @return string The hexadecimal representation of the specified character.
    /// @exception ArgumentOutOfRangeException character is greater than 255.
    static xtd::ustring hex_escape(char character);
    
    /// @brief Converts a specified hexadecimal representation of a character to the character.
    /// @param pattern The hexadecimal representation of a character.
    /// @param index The location in pattern where the hexadecimal representation of a character begins.
    /// @return Char The character represented by the hexadecimal encoding at position index. If the character at index is not hexadecimal encoded, the character at index is returned. The value of index is incremented to point to the character following the one returned.
    /// @exception ArgumentOutOfRangeException index is less than 0 or greater than or equal to the number of characters in pattern.
    static char hex_unescape(const xtd::ustring& pattern, size_t& index);
    
    /// @brief Determines whether the current xtd::uri instance is a base of the specified xtd::uri instance.
    /// @param uri The specified xtd::uri instance to test.
    /// @return bool true if the current xtd::uri instance is a base of uri; otherwise, false.
    /// @exception ArgumentNullException uri is null.
    /// @remarks IsBaseOf is used to compare the current xtd::uri instance to a specified xtd::uri to determine whether this URI is a base for the specified xtd::uri. When comparing two xtd::uri objects to determine a base relationship, the user information (user_info) is not evaluated. When comparing two URIs (uri1 and uri2), uri1 is the base of uri2 if, when you ignore everything in uri2 after the last slash (/), the two URIs are identical. Using http://host/path/path/file?query as the base URI, the following table shows whether it is a base for other URIs.
    /// | URI                                   | http://host/path/path/file?query is base of |
    /// | ------------------------------------- | ------------------------------------------- |
    /// | http://host/path/path/file/           | yes                                         |
    /// | http://host/path/path/#fragment       | yes                                         |
    /// | http://host/path/path/MoreDir/"       | yes                                         |
    /// | http://host/path/path/OtherFile?Query | yes                                         |
    /// | http://host/path/path/                | yes                                         |
    /// | http://host/path/path/file            | yes                                         |
    /// | http://host/path/path                 | no                                          |
    /// | http://host/path/path?query           | no                                          |
    /// | http://host/path/path#fragment        | no                                          |
    /// | http://host/path/path2/               | no                                          |
    /// | http://host/path/path2/MoreDir        | no                                          |
    /// | http://host/path/File                 | no                                          |
    bool is_base_of(const xtd::uri& uri) const;
    
    /// @brief  Determines whether a specified character is a valid hexadecimal digit.
    /// @param character The character to validate.
    /// @return bool A bool value that is true if the character is a valid hexadecimal digit; otherwise false.
    /// @remarks Hexadecimal digits are the digits 0 to 9 and the letters A-F or a-f.
    static bool is_hex_digit(char character);
    
    /// @brief Determines whether a character in a string is hexadecimal encoded.
    /// @param pattern The string to check.
    /// @param index The location in pattern to check for hexadecimal encoding.
    /// @return bool A bool value that is true if pattern is hexadecimal encoded at the specified location; otherwise, false.
    /// @remarks The is_hex_encoding method checks for hexadecimal encoding that follows the pattern "%hexhex" in a string, where "hex" is a digit from 0 to 9 or a letter from A-F (case-insensitive).
    static bool is_hex_encoding(const xtd::ustring& pattern, size_t index);
    
    /// @brief Indicates whether the string used to construct this xtd::uri was well-formed and is not required to be further escaped.
    /// @return bool A bool value that is true if the string was well-formed; else false.
    /// @remarks The string is considered to be well-formed in accordance with RFC 2396 and RFC 2732 by default. If International Resource Identifiers (IRIs) or Internationalized Domain Name (IDN) parsing is enabled, the string is considered to be well-formed in accordance with RFC 3986 and RFC 3987
    /// @remarks The string is considered poorly formed, causing the method to return false, if any of the following conditions occur.
    /// | Error                                                                                      | Example                                       |
    /// | ------------------------------------------------------------------------------------------ | --------------------------------------------- |
    /// | The string is not correctly escaped.                                                       | http://www.contoso.com/path???/file name      |
    /// | The string is an absolute xtd::uri that represents an implicit file xtd::uri.              | c:\\directory\filename                        |
    /// | The string is an absolute URI that is missing a slash before the path.                     | file://c:/directory/filename                  |
    /// | The string contains unescaped backslashes even if they are treated as forward slashes.     | http:\\host/path/file                         |
    /// | The string represents a hierarchical absolute xtd::uri and does not contain "://".         | www.contoso.com/path/file                     |
    /// | The parser for the xtd::uri.scheme indicates that the original string was not well-formed. | The example depends on the scheme of the URI. |
    /// @remarks By default, the string used to construct this xtd::uri are considered well-formed in accordance with RFC 2396 and RFC 2732.
    /// @remarks When International Resource Identifier (URI) and Internationalized Domain Name (IDN) support are enabled, the string used to construct this xtd::uri are considered well-formed in accordance with RFC 3986 and RFC 3987. Punycode names used to support URI contain only ASCII characters and always start with the xn-- prefix.
    /// @remarks For more information on URI support, see the Remarks section for the xtd::uri class.
    bool is_well_formed_original_string();
    
    /// @brief Indicates whether the string is well-formed by attempting to construct a URI with the string and ensures that the string does not require further escaping.
    /// @param uri_string The string used to attempt to construct a xtd::uri.
    /// @param uri_kind The type of the xtd::uri in uri_string.
    /// @return bool A bool value that is true if the string was well-formed; else false.
    /// @remarks By default, the string is considered well-formed in accordance with RFC 2396 and RFC 2732. If International Resource Identifiers (IRIs) or Internationalized Domain Name (IDN) parsing is enabled, the string is considered well-formed in accordance with RFC 3986 and RFC 3987.
    /// @remarks The string is considered poorly formed, causing the method to return false, if any of the following conditions occur
    /// | Error                                                                                      | Example                                       |
    /// | ------------------------------------------------------------------------------------------ | --------------------------------------------- |
    /// | The string is not correctly escaped.                                                       | http://www.contoso.com/path???/file name      |
    /// | The string is an absolute xtd::uri that represents an implicit file xtd::uri.              | c:\\directory\filename                        |
    /// | The string is an absolute URI that is missing a slash before the path.                     | file://c:/directory/filename                  |
    /// | The string contains unescaped backslashes even if they are treated as forward slashes.     | http:\\host/path/file                         |
    /// | The string represents a hierarchical absolute xtd::uri and does not contain "://".         | www.contoso.com/path/file                     |
    /// | The parser for the xtd::uri.scheme indicates that the original string was not well-formed. | The example depends on the scheme of the URI. |
    /// @remarks For more information on URI support, see the Remarks section for the xtd::uri class.
    static bool is_well_formed_uri_string(const xtd::ustring& uri_string, xtd::uri_kind uri_kind);
    
    /// @brief Converts a string to its unescaped representation.
    /// @param value The string to unescape.
    /// @return string A string that contains the unescaped representation of stringToUnescape.
    /// @exception ArgumentNullException value is null.
    /// @remarks You should use this method with care. Unescaping a string that has been previously unescaped can lead to ambiguities and errors.
    /// @remarks Many Web browsers escape spaces inside of URIs into plus ("+") characters; however, the unescape_data_string method does not convert plus characters into spaces because this behavior is not standard across all URI schemes.
    static xtd::ustring unescape_data_string(const xtd::ustring& value);
    
    bool equals(const xtd::uri& uri) const noexcept override;
    
    /// @brief Gets a canonical string representation for the specified xtd::uri instance.
    /// @return string A string instance that contains the unescaped canonical representation of the xtd::uri instance. All characters are unescaped except #, ?, and %.
    /// @remarks The string returned by this method does not contain port information when the port is the default port for the scheme.
    xtd::ustring to_string() const noexcept override;
    /// @}
    
  private:
    static ustring format_componant(const ustring& str, uri_format format);
    static ustring format_host_componant(const ustring& str, uri_format format);
    static bool need_to_escape_data_char(char character);
    static bool need_to_escape_uri_char(char character);
    void set_fragment(xtd::ustring& escapeUri);
    void set_host(xtd::ustring& escapeUri);
    void set_path(xtd::ustring& escapeUri);
    void set_port(xtd::ustring& escapeUri);
    void set_query(xtd::ustring& escapeUri);
    void set_scheme(xtd::ustring& escapeUri);
    void set_uri(const xtd::ustring& uri, xtd::uri_kind kind);
    void set_user_info(xtd::ustring& escapeUri);
    
    xtd::ustring original_uri_;
    xtd::ustring scheme_;
    xtd::ustring scheme_delimiter_;
    xtd::ustring user_info_;
    xtd::ustring host_;
    xtd::ustring port_;
    xtd::ustring path_;
    xtd::ustring query_;
    xtd::ustring fragment_;
    xtd::uri_kind kind_ = xtd::uri_kind::absolute;
  };
}
