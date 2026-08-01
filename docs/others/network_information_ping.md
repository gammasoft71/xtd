# xtd::net::network_information

```cpp
#include <xtd/xtd>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::net namespace provides a simple programming interface for many of the protocols used on networks today. The xtd::net::web_request and xtd::net::web_response classes form the basis of what are called pluggable protocols, an implementation of network services that enables you to develop applications that use Internet resources without worrying about the specific details of the individual protocols.
  namespace net {
    /// @brief Provides access to network traffic data, network address information, and notification of address changes for the local computer. The namespace also contains classes that implement the Ping utility. You can use xtd::net::network_information::ping and related classes to check whether a computer is reachable across the network.
    namespace network_information {
      /// @brief Reports the status of sending an Internet Control Message Protocol (ICMP) echo message to a computer.
      /// @par Header
      /// ```cpp
      /// #include <xtd/net/network_information/ip_status>
      /// ```
      /// @par Namespace
      /// xtd::net/network_information
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core
      enum class ip_status {
        /// @brief The ICMP echo request failed for an unknown reason.
        unknown = -1,
        /// @brief The ICMP echo request succeeded; an ICMP echo reply was received. When you get this status code, the other PingReply properties contain valid data.
        success = 0,
        /// @brief The ICMP echo request failed because the network that contains the destination computer is not reachable.
        destination_network_unreachable = 11002,
        /// @brief The ICMP echo request failed because the destination computer is not reachable.
        destination_host_unreachable = 11003,
        /// @brief The ICMPv6 echo request failed because contact with the destination computer is administratively prohibited. This value applies only to IPv6.
        destination_prohibited = 11004,
        /// @brief The ICMP echo request failed because the destination computer that is specified in an ICMP echo message is not reachable, because it does not support the packet's protocol. This value applies only to IPv4. This value is described in IETF RFC 1812 as Communication Administratively Prohibited.
        destination_protocol_unreachable = 11004,
        /// @brief The ICMP echo request failed because the port on the destination computer is not available.
        destination_port_unreachable = 11005,
        /// @brief The ICMP echo request failed because of insufficient network resources.
        no_resources = 11006,
        /// @brief The ICMP echo request failed because it contains an invalid option.
        bad_option = 11007,
        /// @brief The ICMP echo request failed because of a hardware error.
        hardware_error = 11008,
        /// @brief The ICMP echo request failed because the packet containing the request is larger than the maximum transmission unit (MTU) of a node (router or gateway) located between the source and destination. The MTU defines the maximum size of a transmittable packet.
        packet_too_big = 11009,
        /// @brief The ICMP echo Reply was not received within the allotted time. The default time allowed for replies is 5 seconds. You can change this value using the Send or SendAsync methods that take a timeout parameter.
        timed_out = 11010,
        /// @brief The ICMP echo request failed because there is no valid route between the source and destination computers.
        bad_route = 11012,
        /// @brief The ICMP echo request failed because its Time to Live (TTL) value reached zero, causing the forwarding node (router or gateway) to discard the packet.
        ttl_eExpired = 11013,
        /// @brief The ICMP echo request failed because the packet was divided into fragments for transmission and all of the fragments were not received within the time allotted for reassembly. RFC 2460 specifies 60 seconds as the time limit within which all packet fragments must be received.
        ttl_reassembly_time_exceeded = 11014,
        /// @brief The ICMP echo request failed because a node (router or gateway) encountered problems while processing the packet header. This is the status if, for example, the header contains invalid field data or an unrecognized option.
        parameter_problem = 11015,
        /// @brief The ICMP echo request failed because the packet was discarded. This occurs when the source computer's output queue has insufficient storage space, or when packets arrive at the destination too quickly to be processed.
        source_quench = 11016,
        /// @brief The ICMP echo request failed because the destination IP address cannot receive ICMP echo requests or should never appear in the destination address field of any IP datagram. For example, calling Send and specifying IP address "000.0.0.0" returns this status.
        bad_destination = 11018,
        /// @brief The ICMP echo request failed because the destination computer that is specified in an ICMP echo message is not reachable; the exact cause of problem is unknown.
        destination_unreachable = 11040,
        /// @brief The ICMP echo request failed because its Time to Live (TTL) value reached zero, causing the forwarding node (router or gateway) to discard the packet.
        time_Exceeded = 11041,
        /// @brief The ICMP echo request failed because the header is invalid.
        bad_header = 11042,
        /// @brief The ICMP echo request failed because the Next Header field does not contain a recognized value. The Next Header field indicates the extension header type (if present) or the protocol above the IP layer, for example, TCP or UDP.
        unrecognized_next_Header = 11043,
        /// @brief The ICMP echo request failed because of an ICMP protocol error.
        icmp_error = 11044,
        /// @brief The ICMP echo request failed because the source address and destination address that are specified in an ICMP echo message are not in the same scope. This is typically caused by a router forwarding a packet using an interface that is outside the scope of the source address. Address scopes (link-local, site-local, and global scope) determine where on the network an address is valid.
        destination_scope_mismatch = 11045,
      };
    }
  }
}

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::net namespace provides a simple programming interface for many of the protocols used on networks today. The xtd::net::web_request and xtd::net::web_response classes form the basis of what are called pluggable protocols, an implementation of network services that enables you to develop applications that use Internet resources without worrying about the specific details of the individual protocols.
  namespace net {
    /// @brief Provides access to network traffic data, network address information, and notification of address changes for the local computer. The namespace also contains classes that implement the Ping utility. You can use xtd::net::network_information::ping and related classes to check whether a computer is reachable across the network.
    namespace network_information {
      /// @brief The exception that is thrown when an error is made adding a xtd::net::cookie to a xtd::net::cookie_container.
      /// @par Header
      /// ```cpp
      /// #include <xtd/net/network_information/ip_status>
      /// ```
      /// @par Namespace
      /// xtd::net
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core exceptions
      /// @par Examples
      /// The following example demonstrates how to throw and catch an cookie_exception.
      /// @include cookie_exception.cpp
      class ping_exception : public xtd::invalid_operation_exception {
      public:
        /// @name Public Constructors
        
        /// @{
        /// @brief Create a new instance of class cookie_exception
        /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically  xtd::diagnostics::stack_frame::current().
        /// @remarks Message is set with the default message associate to the exception.
        explicit ping_exception(const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
        /// @brief Create a new instance of class cookie_exception
        /// @param message Message string associate to the exception.
        /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically  xtd::diagnostics::stack_frame::current().
        explicit ping_exception(const std::optional<xtd::string>& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
        /// @brief Create a new instance of class cookie_exception
        /// @param message Message string associate to the exception.
        /// @param inner_exception The exception that is the cause of the current exception.
        /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically  xtd::diagnostics::stack_frame::current().
        template<typename exception_t>
        ping_exception(const std::optional<xtd::string>& message, const exception_t& inner_exception, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) : xtd::format_exception(message, inner_exception, stack_frame) {}
        /// @}
        
        /// @cond
        ping_exception(const ping_exception&) = default;
        auto operator =(const ping_exception&) -> ping_exception& = default;
        /// @endcond
      };
    }
  }
}

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::net namespace provides a simple programming interface for many of the protocols used on networks today. The xtd::net::web_request and xtd::net::web_response classes form the basis of what are called pluggable protocols, an implementation of network services that enables you to develop applications that use Internet resources without worrying about the specific details of the individual protocols.
  namespace net {
    /// @brief Provides access to network traffic data, network address information, and notification of address changes for the local computer. The namespace also contains classes that implement the Ping utility. You can use xtd::net::network_information::ping and related classes to check whether a computer is reachable across the network.
    namespace network_information {
      struct ping_options {
      public:
        bool dont_fragment = false;
        xtd::int32 ttl = 0;
      };
    }
  }
}

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::net namespace provides a simple programming interface for many of the protocols used on networks today. The xtd::net::web_request and xtd::net::web_response classes form the basis of what are called pluggable protocols, an implementation of network services that enables you to develop applications that use Internet resources without worrying about the specific details of the individual protocols.
  namespace net {
    /// @brief Provides access to network traffic data, network address information, and notification of address changes for the local computer. The namespace also contains classes that implement the Ping utility. You can use xtd::net::network_information::ping and related classes to check whether a computer is reachable across the network.
    namespace network_information {
      class ping_reply {
      public:
        ping_reply() = default;
        ping_reply(const xtd::net::ip_address& address, const xtd::array<xtd::byte>& buffer, const xtd::net::network_information::ping_options& options, xtd::int64 roudtrip_time, xtd::net::network_information::ip_status status) {
          data_->address = address;
          data_->buffer = buffer;
          data_->options = options;
          data_->roudtrip_time = roudtrip_time;
          data_->status = status;
        };
        
        auto status() const noexcept -> xtd::net::network_information::ip_status {return data_->status;}
        
      private:
        struct data {
          xtd::net::ip_address address;
          xtd::array<xtd::byte> buffer;
          xtd::net::network_information::ping_options options;
          xtd::int64 roudtrip_time = 0;
          xtd::net::network_information::ip_status status = xtd::net::network_information::ip_status::unknown;
        };
        
        xtd::ptr<data> data_ = xtd::new_ptr<data>();
      };
    }
  }
}

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::net namespace provides a simple programming interface for many of the protocols used on networks today. The xtd::net::web_request and xtd::net::web_response classes form the basis of what are called pluggable protocols, an implementation of network services that enables you to develop applications that use Internet resources without worrying about the specific details of the individual protocols.
  namespace net {
    /// @brief Provides access to network traffic data, network address information, and notification of address changes for the local computer. The namespace also contains classes that implement the Ping utility. You can use xtd::net::network_information::ping and related classes to check whether a computer is reachable across the network.
    namespace network_information {
      class ping {
      public:
        auto send(const xtd::string& host) const -> xtd::net::network_information::ping_reply {
          xtd::diagnostics::process_start_info psi;
          
#if defined(_WIN32)
          // Sous Windows : -n 1 envoie un seul paquet
          psi.file_name("ping");
          psi.arguments("-n 1 " + host);
#else
          // Sous Linux/macOS : -c 1 envoie un seul paquet
          psi.file_name("ping");
          psi.arguments("-c 1 " + host);
#endif
          
          // Configuration pour exécuter la commande proprement en arrière-plan
          psi.use_shell_execute(false);
          psi.create_no_window(true); // Masque la fenêtre de la console
          
          try {
            auto proc = xtd::diagnostics::process::start(psi);
            proc.wait_for_exit(); // Attend la fin du ping
            
            // Le code de sortie 0 signifie que l'hôte a répondu
            if (proc.exit_code() != 0) return xtd::net::network_information::ping_reply(xtd::net::ip_address::none, xtd::array<xtd::byte> {}, xtd::net::network_information::ping_options {}, 0, xtd::net::network_information::ip_status::success);
            return xtd::net::network_information::ping_reply(xtd::net::ip_address::none, xtd::array<xtd::byte> {}, xtd::net::network_information::ping_options {}, 0, xtd::net::network_information::ip_status::destination_network_unreachable);
          }
          catch (const std::exception&) {
            // Gestion d'erreur si la commande ping est introuvable
            return xtd::net::network_information::ping_reply(xtd::net::ip_address::none, xtd::array<xtd::byte> {}, xtd::net::network_information::ping_options {}, 0, xtd::net::network_information::ip_status::hardware_error);
          }
        }
      };
    }
  }
}

#include <xtd/xtd>

using namespace xtd::net::network_information;

auto main() -> int {
  auto failed = 0;
  auto tasks = list<task<>>();
  auto urls = array<string> {"www.adatum.com", "www.cohovineyard.com", "www.cohowinery.com", "www.northwindtraders.com", "www.contoso.com"};
  
  for (const auto& url : urls) {
    tasks.add(task<>::run([&failed, url] {
      auto png = ping {};
      try {
        auto reply = png.send(url);
        if (reply.status() != ip_status::success) {
          interlocked::increment(failed);
          throw timeout_exception("Unable to reach " + url + ".");
        }
      } catch (const ping_exception& e) {
        interlocked::increment(failed);
        throw;
      }
    }));
  }
  auto t = task<>::when_all(tasks);
  try {
    t.wait();
  } catch(...) {
    
  }
  
  if (t.status() == task_status::ran_to_completion) console::write_line("All ping attempts succeeded.");
  else if (t.status() == task_status::faulted) console::write_line("{} ping attempts failed", failed);
}

// This code produces the following output :
//
```