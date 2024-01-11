# uri

Demonstrates the [xtd::uri](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1uri.html) various properties.

## Sources

[src/uri.cpp](src/uri.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
absolute_path: /Home/Index.htm
absolute_uri: https://user:password@www.contoso.com:80/Home/Index.htm?q1=v1%26q2=v2#FragmentName
dns_safe_host: www.contoso.com
fragment: #FragmentName
host: www.contoso.com
host_name_type: dns
idn_host: www.contoso.com
is_absolute_uri: true
is_default_port: false
is_file: false
is_loopback: false
is_unc: false
local_path: /Home/Index.htm
original_string: https://user:password@www.contoso.com:80/Home/Index.htm?q1=v1&q2=v2#FragmentName
path_and_query: /Home/Index.htm?q1=v1%26q2=v2
port: 80
query: ?q1=v1%26q2=v2
scheme: https
segments: /, Home/, Index.htm
user_info: user:password
```
