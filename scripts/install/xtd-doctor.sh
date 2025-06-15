#!/usr/bin/env bash

# Détection du support des couleurs ANSI
COLOR_ENABLED=true
if [[ ! -t 1 || "$TERM" == "dumb" || "$NO_COLOR" == "1" ]]; then
  COLOR_ENABLED=false
fi

if $COLOR_ENABLED; then
  RED='\033[1;31m'
  GREEN='\033[1;32m'
  YELLOW='\033[1;33m'
  CYAN='\033[1;36m'
  BOLD='\033[1m'
  RESET='\033[0m'
else
  RED=''
  GREEN=''
  YELLOW=''
  CYAN=''
  BOLD=''
  RESET=''
fi

# Affiche un titre de section
section() {
  echo -e "${CYAN}${BOLD}==> $1${RESET}"
}

# Affiche un succès
ok() {
  echo -e "${GREEN}✔ $1${RESET}"
}

# Affiche un avertissement
warn() {
  echo -e "${YELLOW}⚠ $1${RESET}"
}

# Affiche une erreur
error() {
  echo -e "${RED}✖ $1${RESET}"
}

# Début du script
section "Système"
uname -a

section "GCC"
if command -v gcc &>/dev/null; then
  gcc_version=$(gcc --version | head -n1)
  ok "gcc trouvé : $gcc_version"
else
  error "gcc non trouvé"
fi

if command -v g++ &>/dev/null; then
  gpp_version=$(g++ --version | head -n1)
  ok "g++ trouvé : $gpp_version"
else
  error "g++ non trouvé"
fi

section "Clang"
if command -v clang &>/dev/null; then
  clang_version=$(clang --version | head -n1)
  ok "clang trouvé : $clang_version"
else
  warn "clang non trouvé"
fi

section "xtd"
if [ -d .git ]; then
  branch=$(git rev-parse --abbrev-ref HEAD)
  commit=$(git rev-parse --short HEAD)
  status=$(git status --short)
  ok "Répertoire git détecté (branche : $branch, commit : $commit)"
  if [ -n "$status" ]; then
    warn "Modifications non commit :"
    echo "$status"
  else
    ok "Aucun changement local"
  fi
else
  warn "Pas de dépôt git détecté"
fi

section "CMake"
if command -v cmake &>/dev/null; then
  cmake_version=$(cmake --version | head -n1)
  ok "CMake trouvé : $cmake_version"
else
  error "CMake non trouvé"
fi

section "Flatpak"
if command -v flatpak &>/dev/null; then
  flatpak list --app | grep -i code &>/dev/null && warn "VS Code installé via Flatpak"
else
  ok "Flatpak non détecté (ou pas installé)"
fi

section "Résumé"
echo -e "${BOLD}Ce rapport est généré par xtd-doctor.sh — conçu pour t’éviter de perdre la tête 🤯${RESET}"

# Fin du script