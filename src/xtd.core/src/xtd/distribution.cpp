#include "../../include/xtd/distribution.h"

using namespace xtd;

distribution::distribution(const xtd::string& name, const xtd::version& version, const xtd::string& code_name, const xtd::string& description, const xtd::string& id, const id_collection& like_ids, const xtd::string& version_string, const xtd::uri& home, const xtd::uri& bug_repport) : name_(name), version_(version), code_name_(code_name), description_(description), id_(id), like_ids_(like_ids), version_string_(version_string), home_(home), bug_repport_(bug_repport) {
}

const xtd::uri& distribution::bug_repport() const noexcept {
  return bug_repport_;
}

const xtd::string& distribution::code_name() const noexcept {
  return code_name_;
}

const xtd::string& distribution::description() const noexcept {
  return description_;
}

const xtd::uri& distribution::home() const noexcept {
  return home_;
}

const xtd::string& distribution::id() const noexcept {
  return id_;
}

const distribution::id_collection& distribution::like_ids() const noexcept {
  return like_ids_;
}

const xtd::string& distribution::name() const noexcept {
  return name_;
}

const xtd::version& distribution::version() const noexcept {
  return version_;
}

const xtd::string& distribution::version_string() const noexcept {
  return version_string_;
}

xtd::string distribution::to_string() const noexcept {
  return description();
}
