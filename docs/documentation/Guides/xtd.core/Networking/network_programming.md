# Network programming (xtd.core)

xtd provides a layered, extensible, and managed implementation of Internet services that can be quickly and easily integrated into your apps. 
Your network apps can build on pluggable protocols to automatically take advantage of various Internet protocols,
or they can use a managed implementation of cross-platform socket interfaces to work with the network on the socket level.

## Internet apps

Internet apps can be classified broadly into two kinds: client apps that request information and server apps that respond to information requests from clients. 
The classic Internet client-server app is the World Wide Web, where people use browsers to access documents and other data stored on web servers worldwide.

Apps are not limited to just one of these roles; for instance, the familiar middle-tier app server responds to requests from clients by requesting data from another server,
in which case it is acting as both a server and a client.

The client app requests by identifying the requested Internet resource and the communication protocol to use for the request and response. 
If necessary, the client also provides any additional data required to complete the request, such as proxy location or authentication information (user name, password, and so on). 
Once the request is formed, the request can be sent to the server.

## Identifying resources

xtd uses a uniform resource identifier (URI) to identify the requested Internet resource and communication protocol.
The URI consists of at least three, and possibly four, fragments: the scheme identifier, which identifies the communications protocol 
for the request and response; the server identifier, which consists of either a domain name system (DNS) hostname or a TCP address 
that uniquely identifies the server on the Internet; the path identifier, which locates the requested information on the server; 
and an optional query string, which passes information from the client to the server.

The [xtd::uri](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1uri.html) type is used as a representation of a uniform 
resource identifier (URI) and easy access to the parts of the URI. To create a Uri instance you can pass it a string:

```cpp
const auto uri_string = string {"https://learn.microsoft.com/en-us/dotnet/path?key=value#bookmark"};

auto canonical_uri = uri {uri_string};
console::write_line(canonical_uri.host());
console::write_line(canonical_uri.path_and_query());
console::write_line(canonical_uri.fragment());
// Sample output:
//     learn.microsoft.com
//     /en-us/dotnet/path?key=value
//     #bookmark
```

The `uri` class automatically performs validation and canonicalization per [RFC 3986](https://datatracker.ietf.org/doc/html/rfc3986). 
These validation and canonicalization rules are used to ensure that a URI is well-formed and that the URI is in a canonical form.

## See also
​
* [Tutorials](/docs/documentation/Guides/Overview/Tutorials)
* [Documentation](/docs/documentation)

[//]: # (https://learn.microsoft.com/en-us/dotnet/fundamentals/networking/overview)
