
/// @file
/// @brief Contains address family constants.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
/// @cond
#ifndef __XTD_CORE_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <cstdint>

/// @brief Unknown address family.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native address_family
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t ADDRESS_FAMILY_UNKNOWN = -1;

/// @brief Unspecified address family.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native address_family
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t ADDRESS_FAMILY_UNSPECIFIED = 0;

/// @brief Unix local to host address.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native address_family
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t ADDRESS_FAMILY_UNIX = 1;

/// @brief Address for IP version 4.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native address_family
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t ADDRESS_FAMILY_INTER_NETWORK = 2;

/// @brief ARPANET IMP address.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native address_family
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t ADDRESS_FAMILY_IMP_LINK = 3;

/// @brief Address for PUP protocols.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native address_family
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t ADDRESS_FAMILY_PUP = 4;

/// @brief Address for MIT CHAOS protocols.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native address_family
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t ADDRESS_FAMILY_CHAOS = 5;

/// @brief Address for Xerox NS protocols.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native address_family
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t ADDRESS_FAMILY_NS = 6;

/// @brief Address for ISO protocols.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native address_family
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t ADDRESS_FAMILY_ISO = 7;

/// @brief Address for OSI protocols.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native address_family
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t ADDRESS_FAMILY_OSI = 7;

/// @brief European Computer Manufacturers Association (ECMA) address.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native address_family
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t ADDRESS_FAMILY_ECMA = 8;

/// @brief Address for Datakit protocols.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native address_family
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t ADDRESS_FAMILY_DATA_KIT = 9;

/// @brief Addresses for CCITT protocols, such as X.25.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native address_family
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t ADDRESS_FAMILY_CCITT = 10;

/// @brief IBM SNA address.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native address_family
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t ADDRESS_FAMILY_SNA = 11;

/// @brief DECnet address.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native address_family
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t ADDRESS_FAMILY_DEC_NET = 12;

/// @brief Direct data-link interface address.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native address_family
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t ADDRESS_FAMILY_DATA_LINK = 13;

/// @brief LAT address.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native address_family
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t ADDRESS_FAMILY_LAT = 14;

/// @brief NSC Hyperchannel address.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native address_family
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t ADDRESS_FAMILY_HYPER_CHANNEL = 15;

/// @brief AppleTalk address.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native address_family
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t ADDRESS_FAMILY_APPLE_TALK = 16;

/// @brief NetBios address.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native address_family
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t ADDRESS_FAMILY_NET_BIOS = 17;

/// @brief VoiceView address.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native address_family
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t ADDRESS_FAMILY_VOICE_VIEW = 18;

/// @brief FireFox address.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native address_family
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t ADDRESS_FAMILY_FIRE_FOX = 19;

/// @brief Banyan address.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native address_family
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t ADDRESS_FAMILY_BANYAN = 21;

/// @brief Native ATM services address.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native address_family
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t ADDRESS_FAMILY_ATM = 22;

/// @brief Address for IP version 6.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native address_family
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t ADDRESS_FAMILY_INTER_NETWORK_V6 = 23;

/// @brief Address for Microsoft cluster products.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native address_family
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t ADDRESS_FAMILY_CLUSTER = 24;

/// @brief IEEE 1284.4 workgroup address.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native address_family
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t ADDRESS_FAMILY_IEEE12844 = 25;

/// @brief IrDA address.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native address_family
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t ADDRESS_FAMILY_IRDA = 26;

/// @brief Address for Network Designers OSI gateway-enabled protocols.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native address_family
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t ADDRESS_FAMILY_NETWORK_DESIGNERS = 28;

/// @brief MAX address.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native address_family
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t ADDRESS_FAMILY_MAX = 29;
