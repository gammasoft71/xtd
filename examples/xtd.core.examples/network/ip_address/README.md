# ip_address

Shows how to use [xtd::net::dns](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1net_1_1dns.html) class.

## Sources

[src/ip_addresses.cpp](src/ip_address.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
Using current host: !---OMITTED---!.local
address_family: inter_network
address: 192.168.1.37
address_bytes: 192168137


os_supports_ip_v4: true
os_supports_ip_v6: true

ip_v6_any: ::
ip_v6_loopback: ::1
ip_v6_none: ::
is_loopback(ip_v6_loopback): true
is_loopback(loopback):true
```
