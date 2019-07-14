/// @file
/// @brief Contains xtd::diagnostics::debug class.
#pragma once
#include <map>
#include <memory>
#include <string>
#include <stdexcept>
#include "trace_options.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::diagnostics namespace provides classes that allow you to interact with system processes, event logs, and performance counters.
  namespace diagnostics {
    /// @brief Provides the abstract base class for the listeners who monitor trace and debug output.
    /// @remarks For examples of how to implement a trace_listener, see the default_trace_listener, text_writer_trace_listener and the event_log_trace_listener classes.
    /// @remarks You must enable tracing or debugging to use a trace listener. The syntax is compiler specific. If you use other than cmake to manage your build, refer to the documentation of your build nanager.
    ///  * To enable debugging with cmake, add the add_definitions(-DDEBUG) command line in the CMakeLists.txt of your porject, or you can add #define DEBUG to the top of your file but in this case, the compiler options for debug is not activated.
    ///  * To enable tracing with cmake, add the add_definitions(-DTRACE) command line in the CMakeLists.txt of your porject, or you can add #define TRACE to the top of your file.
    /// @note <b>to Inheritors:</b> Inherit from this class to implement a custom listener for the debug and trace classes. At a minimum, you must implement the write and write_line methods. Additionally, you can implement the fail, close and flush methods.
    class trace_listener {
    public:
      /// @brief Initializes a new instance of the trace_listener class.
      /// @remarks The following table shows initial property values for an instance of trace_listener.
      /// | Property     | Default Value          |
      /// |--------------|------------------------|
      /// | name         | The empty string (""). |
      /// | indent_level | Zero.                  |
      /// | indent_size  | Four spaces.           |
      trace_listener() = default;
      
      /// @cond
      trace_listener(const trace_listener& tl) = default;
      trace_listener& operator=(const trace_listener& tl) = default;
      /// @endcond
      /// @brief Initializes a new instance of the trace_listener class using the specified name as the listener.
      /// @param name The name of the trace_listener.
      explicit trace_listener(const std::string& name);

      const std::map<std::string, std::string>& attibutes() const {return this->data_->attibutes_;}
      std::map<std::string, std::string>& attibutes() {return this->data_->attibutes_;}
      void attibutes(const std::map<std::string, std::string>& attribute) {this->data_->attibutes_ = attribute;}

      //const trace_filter& filter() const {*return this->data_->filter;}
      //void filter(const trace_filter& filer) {this->data_->filter = &filter;}
      
      unsigned int indent_level() const {return this->data_->indent_level_;}
      void indent_level(unsigned int indent_level) {this->data_->indent_level_ = indent_level;}
      
      unsigned int indent_size() const {return this->data_->indent_size_;}
      void indent_size(unsigned int indent_size) {this->data_->indent_size_ = indent_size;}

      bool is_thread_safe() const {return this->data_->is_thread_safe_;}

      const std::string& name() const {return this->data_->name_;}
      void name(const std::string& name) {this->data_->name_ = name;}
      
      const trace_options& trace_output_options() const {return this->data_->trace_output_options_;}
      void trace_output_options(const trace_options& trace_output_options) {this->data_->trace_output_options_ = trace_output_options;}

      virtual void close();
      
      virtual void flush();
      
    protected:
      bool need_indent() const {return this->data_->need_indent_;}
      void need_indent(bool need_indent) const {this->data_->need_indent_ = need_indent;}

    private:
      struct data {
        std::map<std::string, std::string> attibutes_;
        //const trace_filter* filter_;
        unsigned int indent_level_ = 0;
        unsigned int indent_size_ = 4;
        bool is_thread_safe_ = false;
        std::string name_;
        bool need_indent_ = true;
        trace_options trace_output_options_ = trace_options::none;
      };
      
      std::shared_ptr<data> data_ = std::make_shared<data>();
    };
  }
}
