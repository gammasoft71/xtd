
/// @file
/// @brief Contains address family constants.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
/// @cond
#ifndef __XTD_CORE_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <cstdint>

/// @internal
/// @brief Unknown address family.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native address_family
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t ADDRESS_FAMILY_UNKNOWN = -1;

/// @internal
/// @brief Unspecified address family.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native address_family
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t ADDRESS_FAMILY_UNSPECIFIED = 0;

/// @internal
/// @brief Unix local to host address.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native address_family
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t ADDRESS_FAMILY_UNIX = 1;

/// @internal
/// @brief Address for IP version 4.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native address_family
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t ADDRESS_FAMILY_INTER_NETWORK = 2;

/// @internal
/// @brief ARPANET IMP address.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native address_family
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t ADDRESS_FAMILY_IMP_LINK = 3;

/// @internal
/// @brief Address for PUP protocols.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native address_family
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t ADDRESS_FAMILY_PUP = 4;

/// @internal
/// @brief Address for MIT CHAOS protocols.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native address_family
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t ADDRESS_FAMILY_CHAOS = 5;

/// @internal
/// @brief Address for Xerox NS protocols.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native address_family
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t ADDRESS_FAMILY_NS = 6;

/// @internal
/// @brief Address for ISO protocols.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native address_family
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t ADDRESS_FAMILY_ISO = 7;

/// @internal
/// @brief Address for OSI protocols.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native address_family
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t ADDRESS_FAMILY_OSI = 7;

/// @internal
/// @brief European Computer Manufacturers Association (ECMA) address.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native address_family
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t ADDRESS_FAMILY_ECMA = 8;

/// @internal
/// @brief Address for Datakit protocols.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native address_family
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t ADDRESS_FAMILY_DATA_KIT = 9;

/// @internal
/// @brief Addresses for CCITT protocols, such as X.25.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native address_family
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t ADDRESS_FAMILY_CCITT = 10;

/// @internal
/// @brief IBM SNA address.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native address_family
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t ADDRESS_FAMILY_SNA = 11;

/// @internal
/// @brief DECnet address.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native address_family
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t ADDRESS_FAMILY_DEC_NET = 12;

/// @internal
/// @brief Direct data-link interface address.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native address_family
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t ADDRESS_FAMILY_DATA_LINK = 13;

/// @internal
/// @brief LAT address.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native address_family
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t ADDRESS_FAMILY_LAT = 14;

/// @internal
/// @brief NSC Hyperchannel address.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native address_family
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t ADDRESS_FAMILY_HYPER_CHANNEL = 15;

/// @internal
/// @brief AppleTalk address.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native address_family
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t ADDRESS_FAMILY_APPLE_TALK = 16;

/// @internal
/// @brief NetBios address.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native address_family
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t ADDRESS_FAMILY_NET_BIOS = 17;

/// @internal
/// @brief VoiceView address.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native address_family
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t ADDRESS_FAMILY_VOICE_VIEW = 18;

/// @internal
/// @brief FireFox address.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native address_family
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t ADDRESS_FAMILY_FIRE_FOX = 19;

/// @internal
/// @brief Banyan address.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native address_family
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t ADDRESS_FAMILY_BANYAN = 21;

/// @internal
/// @brief Native ATM services address.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native address_family
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t ADDRESS_FAMILY_ATM = 22;

/// @internal
/// @brief Address for IP version 6.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native address_family
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t ADDRESS_FAMILY_INTER_NETWORK_V6 = 23;

/// @internal
/// @brief Address for Microsoft cluster products.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native address_family
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t ADDRESS_FAMILY_CLUSTER = 24;

/// @internal
/// @brief IEEE 1284.4 workgroup address.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native address_family
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t ADDRESS_FAMILY_IEEE12844 = 25;

/// @internal
/// @brief IrDA address.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native address_family
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t ADDRESS_FAMILY_IRDA = 26;

/// @internal
/// @brief Address for Network Designers OSI gateway-enabled protocols.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native address_family
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t ADDRESS_FAMILY_NETWORK_DESIGNERS = 28;

/// @internal
/// @brief MAX address.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native address_family
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t ADDRESS_FAMILY_MAX = 29;
