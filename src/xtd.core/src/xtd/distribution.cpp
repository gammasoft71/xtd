#include "../../include/xtd/distribution"

using namespace xtd;

distribution::distribution(const xtd::ustring& name, const xtd::version& version, const xtd::ustring& code_name, const xtd::ustring& description, const xtd::ustring& id, const id_collection& like_ids, const xtd::ustring& version_string, const xtd::uri& home, const xtd::uri& bug_repport) : name_(name), version_(version), code_name_(code_name), description_(description), id_(id), like_ids_(like_ids), version_string_(version_string), home_(home), bug_repport_(bug_repport) {
}

const xtd::uri& distribution::bug_repport() const noexcept {
  return bug_repport_;
}

const xtd::ustring& distribution::code_name() const noexcept {
  return code_name_;
}

const xtd::ustring& distribution::description() const noexcept {
  return description_;
}

const xtd::uri& distribution::home() const noexcept {
  return home_;
}

const xtd::ustring& distribution::id() const noexcept {
  return id_;
}

const distribution::id_collection& distribution::like_ids() const noexcept {
  return like_ids_;
}

const xtd::ustring& distribution::name() const noexcept {
  return name_;
}

const xtd::version& distribution::version() const noexcept {
  return version_;
}

const xtd::ustring& distribution::version_string() const noexcept {
  return version_string_;
}

xtd::ustring distribution::to_string() const noexcept {
  return description();
}
