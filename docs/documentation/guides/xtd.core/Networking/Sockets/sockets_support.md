# Sockets (xtd.core)

The [xtd::net::sockets](https://gammasoft71.github.io/xtd/reference_guides/latest/namespacextd_1_1net_1_1sockets.html) namespace contains a
cross-platform socket networking implementation. All other network-access classes in the [xtd::net](https://gammasoft71.github.io/xtd/reference_guides/latest/namespacextd_1_1net.html) namespace are built on top of this implementation of sockets.

The [socket](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1net_1_1sockets_1_1socket.html) class is a cross-platform version of 
the socket services provided relying on native interoperability with Linux, macOS, or Windows. In most cases, 
the [socket](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1net_1_1sockets_1_1socket.html) class methods simply 
marshal data into their native counterparts and handle any necessary security checks.

The [socket](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1net_1_1sockets_1_1socket.html) class supports two basic modes, 
synchronous and asynchronous. In synchronous mode, calls to functions that perform network operations (such as [send_async](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1net_1_1sockets_1_1socket.html) 
and [receive_async](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1net_1_1sockets_1_1socket.html)) 
wait until the operation completes before returning control to the calling program. In asynchronous mode, these calls return immediately.

# See also
​
* [Tutorials](/docs/documentation/Guides/Overview/Tutorials)
* [Documentation](/docs/documentation)

[//]: # (https://learn.microsoft.com/en-us/dotnet/fundamentals/networking/sockets/sockets-overview)
