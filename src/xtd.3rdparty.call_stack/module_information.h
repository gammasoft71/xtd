#ifdef _WIN32_WCE

#pragma once;

#include <list>
#include <string>
#include <stddef.h>

namespace stacktrace {
  //---------------------------------------------------------------------------
  struct ModuleInformation;
  typedef std::list<ModuleInformation> ModuleInformations;

  //---------------------------------------------------------------------------
  /**
  * A class that computes and represents the modules in WinCE.
  */
  struct ModuleInformation {
  public:
    /**
    * Return global informations about each module and each process.
    *
    * @return ModuleInformations The modules informations.
    */
    static ModuleInformations GetModuleInformations();
    /**
    * Return global informations about each process.
    *
    * @return ModuleInformations The corresponding modules informations.
    */
    static ModuleInformations GetProcessInformations();

    ModuleInformation() : id(NULL), baseAddress(0), size(0) {}
    ModuleInformation(const ModuleInformation& mi) : id(mi.id), name(mi.name), baseAddress(mi.baseAddress), size(mi.size) {}

    intptr_t GetId() const {return this->id;}
    const std::string& GetName() const {return this->name;}
    int GetBaseAddress() const {return this->baseAddress;}
    int GetSize() const {return this->size;}

    virtual bool Equals(const ModuleInformation& mi) const { return &mi != NULL && this->id == mi.id && this->name == mi.name && this->baseAddress  == mi.baseAddress && this->size == mi.size; }

    virtual std::string ToString() const;

  private:
    ModuleInformation(intptr_t id, const std::string& name, int baseAddress, int size) : id(id), name(name), baseAddress(baseAddress), size(size) {}

    intptr_t id;
    std::string name;
    int baseAddress;
    int size;
  };
}

#endif
