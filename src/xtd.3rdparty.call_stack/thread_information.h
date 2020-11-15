#ifdef _WIN32_WCE

#pragma once;

namespace stacktrace {
  /**
  * A struct representing thread informations in WinCE.
  */
  struct ThreadInformation {
  public:
    static ThreadInformation GetThreadInformation();
    int GetId() const { return this->id; }
    virtual bool Equals(const ThreadInformation& ti) const { return &ti != NULL && this->id == ti.id; }

  private:
    explicit ThreadInformation(int id) : id(id) {}
    int id;
  };
}

#endif
