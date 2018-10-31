    /*
     * Notice: file generated by MIBMAKE from mibsnmp.mdf
     * DO NOT EDIT THIS FILE!!!  Edit mibsnmp.mdf
     */
#line 3 "mibsnmp.mdf"
/*
 *	$Id: mibsnmp.h,v 1.1.1.1 2011/08/17 11:11:56 brwang Exp $
 *
 *	Copyright (c) 1995 UTT Technologies, Inc.
 *	All rights reserved.
 *	Use of copyright notice does not imply publication.
 *
 *
 *			CONFIDENTIAL INFORMATION
 *			------------------------
 *	This Document contains Confidential Information or Trade Secrets,
 *	or both, which are the property of UTT Technologies, Inc.
 *	This document may not be copied, reproduced, reduced to any
 *	electronic medium or machine readable form or otherwise duplicated
 *	and the information herein may not be used, disseminated or
 *	otherwise disclosed, except with the prior written consent of
 *	 UTT Technologies, Inc.
 */

    /*
     * Profile contains SNMP interface number to physical address
     * mappings and the administrative status of each profile.
     */
#line 29 "mibsnmp.mdf"

#if ! defined( MIBSNMP_H )
#define MIBSNMP_H

#include "mibslot.h"

    /*
     * The name of the SNMP profile is stored in this global
     * data variable.
     */
extern const char* const		mibProfSnmp;

    /*
     * The name of the SNMP State profile is stored in this global
     * data variable.
     */
extern const char* const		mibProfSnmpState;

    /*
     * The name of the SNMP If-Perm profile is stored in this
     * global data variable.
     */
extern const char* const		mibProfSnmpStateSec;

extern ConstPtr
mibFactorySnmpProfile( MibProfileType	mibType,
		       ConstPtr		mibIndex,
		       Int		mibIndexLen );

    /*
     * The field number used to index to ADMIN-STATE profile
     */
#define MIB_PROF_SNMP_STATE_INDEX	1

    /*
     * The field number used to index to SNMP-IF-PERM profile
     */
#define MIB_PROF_SNMP_STATE_SEC_INDEX	1

    /*
     * SnmpIndex:
     *
     * The data type that is an SNMP Index number.
     */
typedef Uint32			SnmpIndex;

    /*
     * A marker that indicates the SNMP Interface number is invalid.
     */
#define SNMP_IF_INVALID		0xffffffffU

    /*
     * IanaIfType:
     *
     * The data type that represent IANAifType.
     * See ianaiftype.mib
     */
typedef Uint32			IanaIfType;


    /*
     * SnmpProfile:
     *
     *
     *  snmpEnabled When set to `no' (its default value), the unit cannot be
     *                                  accessed via SNMP.
     *
     *  readCommunity The SNMP community name for read access.
     *
     *  readWriteCommunity The SNMP community name for read/write access.
     *
     *  snmpSecurity When set to `no' (its default value), we will allow access
     *                                  to all SNMP managers that know the
     *                                  community string. When set to `yes', we
     *                                  will check the source IP address
     *                                  against the ones that are in the
     *                                  read-access-host and write-access-host
     *                                  arrays before allowing access.
     *
     *  readAccessHost The IP address of a SNMP manager to give read access.
     *
     *  writeAccessHost The IP address of a SNMP manager to give write access.
     *
     *  contact The name of the contact for this device. SNMP readable and
     *                                  settable.
     *
     *  location The location of this device. SNMP readable and settable.
     *
     *  queueDepth The maximum number of SNMP packets waiting to be serviced.
     *                                  Additional packets will be dropped.
     *                                  When setting this value, you're trading
     *                                  memory resources versus SNMP retries
     *                                  (only when the box is busy and gets
     *                                  behind on servicing the SNMP packets).
     *                                  Zero indicates there is no limit.
     *
     *  mdmDiagEnabled When set to `no' (its default value), SNMP CSM modem
     *                                  card diag is disabled. A JEDEC card is
     *                                  required to turn on this feature.
     */
typedef struct snmpProfile {
#line 116 "mibsnmp.mdf"
    Bool                                snmpEnabled;
#line 121 "mibsnmp.mdf"
#if ( MDF_SNMP == FYES )
    char                                readCommunity[ MAX_COMM_NAME_LENGTH + 1 ];
#endif /* ( MDF_SNMP == FYES ) */
#line 126 "mibsnmp.mdf"
#if ( MDF_SNMP == FYES )
    char                                readWriteCommunity[ MAX_COMM_NAME_LENGTH + 1 ];
#endif /* ( MDF_SNMP == FYES ) */
#line 131 "mibsnmp.mdf"
#if ( MDF_SNMP == FYES )
    Boolean                             snmpSecurity;
#endif /* ( MDF_SNMP == FYES ) */
#line 139 "mibsnmp.mdf"
#if ( MDF_SNMP == FYES )
    IpAddress                           readAccessHost[ MAX_SNMP_ACCESS_HOST ];
#endif /* ( MDF_SNMP == FYES ) */
#line 144 "mibsnmp.mdf"
#if ( MDF_SNMP == FYES )
    IpAddress                           writeAccessHost[ MAX_SNMP_ACCESS_HOST ];
#endif /* ( MDF_SNMP == FYES ) */
#line 149 "mibsnmp.mdf"
#if ( MDF_SNMP == FYES )
    Byte                                contact[ MAX_SNMP_INFO_LEN + 1 ];
#endif /* ( MDF_SNMP == FYES ) */
#line 154 "mibsnmp.mdf"
#if ( MDF_SNMP == FYES )
    Byte                                location[ MAX_SNMP_INFO_LEN + 1 ];
#endif /* ( MDF_SNMP == FYES ) */
#line 159 "mibsnmp.mdf"
#if ( MDF_SNMP == FYES )
    Uint16                              queueDepth;
#endif /* ( MDF_SNMP == FYES ) */
#line 168 "mibsnmp.mdf"
#if ( (MDF_SNMP == FYES) && (Q_TNT) )
    Bool                                mdmDiagEnabled;
#endif /* ( (MDF_SNMP == FYES) && (Q_TNT) ) */
}
#if ( USERIF & CLI )
__PACK__
#endif
SnmpProfile;

    /*
     * AdminState:
     *
     * Values to indicate the desired state of an interface. The actual state
     * may differ from the desired state, e.g. when an interface is powering up
     * or when the desired state is changed from up to down on a running slot.
     * Changing the AdminState does not force a device to the new state. It
     * indicates that the device state should be changed in a graceful manner.
     *
     *  ADMIN_STATE_DOWN The operator desires that the addressed device
     *                                  terminate all operations and enter the
     *                                  down state.
     *
     *  ADMIN_STATE_UP The operator desires that the device be brought up in
     *                                  normal operations mode.
     *
     *  ADMIN_STATE_DIAG The operator desires that the device be brought up in
     *                                  diagnostics mode. Reserved for future
     *                                  use.
     */
typedef enum AdminState {
#line 242 "mibsnmp.mdf"
    ADMIN_STATE_DOWN = 1,
#line 246 "mibsnmp.mdf"
    ADMIN_STATE_UP,
#line 250 "mibsnmp.mdf"
#if ( 0 )
    ADMIN_STATE_DIAG
#endif /* ( 0 ) */
} AdminState;


static __inline__ Bool
validAdminState (int x)
{
    switch (x) {
#line 242 "mibsnmp.mdf"
    case ADMIN_STATE_DOWN:
#line 246 "mibsnmp.mdf"
    case ADMIN_STATE_UP:
#line 250 "mibsnmp.mdf"
#if ( 0 )
    case ADMIN_STATE_DIAG:
#endif /* ( 0 ) */
        return TRUE;
    default:
        return FALSE;
    }
}

    /*
     * SnmpOperState:
     *
     * Values to indicate the current operational state of an interface. The
     * desired (admin) state may differ from the operational state. The
     * SnmpOperState can not be changed by the user.
     *
     *  SNMP_OPER_STATE_UP The interface is up, ready to transmit and receive
     *                                  network traffic.
     *
     *  SNMP_OPER_STATE_DOWN The interface is up, unable to transmit and
     *                                  receive network traffic.
     *
     *  SNMP_OPER_STATE_TESTING The interface is in some test mode. The testing
     *                                  state indicates that no operational
     *                                  packets can be passed.
     *
     *  SNMP_OPER_STATE_UNKNOWN The interface is in some test mode. The testing
     *                                  state indicates that no operational
     *                                  packets can be passed.
     *
     *  SNMP_OPER_STATE_DORMANT The interface is up and waiting for external
     *                                  actions (such as a serial line waiting
     *                                  for an incoming connection).
     *
     *  SNMP_OPER_STATE_NOT_PRESENT The interface has missing (typically,
     *                                  hardware) component.
     *
     *  SNMP_OPER_STATE_LOWER_LAYER_DOWN The interface id down due to state of
     *                                  lower-layer interface(s).
     */
typedef enum SnmpOperState {
#line 264 "mibsnmp.mdf"
    SNMP_OPER_STATE_UP = 1,
#line 267 "mibsnmp.mdf"
    SNMP_OPER_STATE_DOWN,
#line 270 "mibsnmp.mdf"
    SNMP_OPER_STATE_TESTING,
#line 274 "mibsnmp.mdf"
    SNMP_OPER_STATE_UNKNOWN,
#line 278 "mibsnmp.mdf"
    SNMP_OPER_STATE_DORMANT,
#line 282 "mibsnmp.mdf"
    SNMP_OPER_STATE_NOT_PRESENT,
#line 285 "mibsnmp.mdf"
    SNMP_OPER_STATE_LOWER_LAYER_DOWN
} SnmpOperState;


static __inline__ Bool
validSnmpOperState (int x)
{
    switch (x) {
#line 264 "mibsnmp.mdf"
    case SNMP_OPER_STATE_UP:
#line 267 "mibsnmp.mdf"
    case SNMP_OPER_STATE_DOWN:
#line 270 "mibsnmp.mdf"
    case SNMP_OPER_STATE_TESTING:
#line 274 "mibsnmp.mdf"
    case SNMP_OPER_STATE_UNKNOWN:
#line 278 "mibsnmp.mdf"
    case SNMP_OPER_STATE_DORMANT:
#line 282 "mibsnmp.mdf"
    case SNMP_OPER_STATE_NOT_PRESENT:
#line 285 "mibsnmp.mdf"
    case SNMP_OPER_STATE_LOWER_LAYER_DOWN:
        return TRUE;
    default:
        return FALSE;
    }
}

    /*
     * TrapState:
     *
     * Values to indicate whether linkUp/linkDown traps should be generated for
     * this interface.
     *
     *  TRAP_STATE_ENABLED The operator desires that linkUp/linkDown traps
     *                                  should be generated for this interface.
     *
     *  TRAP_STATE_DISABLED The operator desires that linkUp/linkDown traps
     *                                  should not be generated for this
     *                                  interface.
     */
typedef enum TrapState {
#line 295 "mibsnmp.mdf"
    TRAP_STATE_ENABLED = 1,
#line 299 "mibsnmp.mdf"
    TRAP_STATE_DISABLED
} TrapState;


static __inline__ Bool
validTrapState (int x)
{
    switch (x) {
#line 295 "mibsnmp.mdf"
    case TRAP_STATE_ENABLED:
#line 299 "mibsnmp.mdf"
    case TRAP_STATE_DISABLED:
        return TRUE;
    default:
        return FALSE;
    }
}

    /*
     * TruthValue:
     *
     * Represents a boolean value.
     *
     *  TRUTH_VALUE_TRUE Represents TRUE.
     *
     *  TRUTH_VALUE_FALSE Represents FALSE.
     */
typedef enum TruthValue {
#line 309 "mibsnmp.mdf"
    TRUTH_VALUE_TRUE = 1,
#line 312 "mibsnmp.mdf"
    TRUTH_VALUE_FALSE
} TruthValue;


static __inline__ Bool
validTruthValue (int x)
{
    switch (x) {
#line 309 "mibsnmp.mdf"
    case TRUTH_VALUE_TRUE:
#line 312 "mibsnmp.mdf"
    case TRUTH_VALUE_FALSE:
        return TRUE;
    default:
        return FALSE;
    }
}

    /*
     * RowStatus:
     *
     * The RowStatus textual convention is used to manage the creation and
     * deletion of conceptual rows.
     *
     *  ROW_ACTIVE Indicate that the conceptual row is available for use by the
     *                                  managed device.
     *
     *  ROW_NOT_IN_SERVICE Indicate that the conceptual row exists in the
     *                                  agent, but is unavailable for use by
     *                                  the managed device.
     */
typedef enum RowStatus {
#line 322 "mibsnmp.mdf"
    ROW_ACTIVE = 1,
#line 326 "mibsnmp.mdf"
    ROW_NOT_IN_SERVICE
} RowStatus;


static __inline__ Bool
validRowStatus (int x)
{
    switch (x) {
#line 322 "mibsnmp.mdf"
    case ROW_ACTIVE:
#line 326 "mibsnmp.mdf"
    case ROW_NOT_IN_SERVICE:
        return TRUE;
    default:
        return FALSE;
    }
}

    /*
     * InetProfileType:
     *
     * Value to indicate type of connection (internet) profile.
     *
     *  INET_PROFILE_LOCAL Indicate this connection profile is created locally.
     *
     *  INET_PROFILE_RADIUS Indicate this connection profile is created on a
     *                                  RADIUS server.
     */
typedef enum InetProfileType {
#line 336 "mibsnmp.mdf"
    INET_PROFILE_LOCAL = 1,
#line 339 "mibsnmp.mdf"
    INET_PROFILE_RADIUS
} InetProfileType;


static __inline__ Bool
validInetProfileType (int x)
{
    switch (x) {
#line 336 "mibsnmp.mdf"
    case INET_PROFILE_LOCAL:
#line 339 "mibsnmp.mdf"
    case INET_PROFILE_RADIUS:
        return TRUE;
    default:
        return FALSE;
    }
}

    /*
     * SnmpStateProfile:
     *
     * A profile to store the desired state of a device. This profile is kept
     * in NVRAM to keep state over system resets. Since the device may be
     * addressed by physical address or by SNMP interface number both are
     * included. This profile thus also provides the mapping between physical
     * device and SNMP Interface number. There is a one-to-one mapping between
     * snmp interface and device. However, not every possible device will be
     * associated with an SNMP interface.
     *
     *  deviceAddr The physical address of the device whose snmp state is
     *                                  stored in this profile.
     *
     *  slotType The type of device. If, at system startup, the actual type of
     *                                  the device address is different than
     *                                  this type we know that slot cards have
     *                                  been changed and the old snmp
     *                                  interfaces can be deleted.
     *
     *  ifIndex The SNMP interface table index assigned to the device whose
     *                                  state is stored in this profile.
     *
     *  mdmIndex The SNMP modem table index number assigned to the device whose
     *                                  state is stored in this profile. This
     *                                  field is 0 for devices that are not
     *                                  modems.
     *
     *  desiredState The desired administrative state of the addressed device.
     *
     *  desiredTrapState The desired link up/down enable state of the
     *                                  interface.
     */
typedef struct snmpStateProfile {
#line 379 "mibsnmp.mdf"
    PhysicalAddress                     deviceAddr;
#line 385 "mibsnmp.mdf"
#if ( Q_TNT )
    TntSlotType                         slotType;
#endif /* ( Q_TNT ) */
#line 394 "mibsnmp.mdf"
    SnmpIndex                           ifIndex;
#line 400 "mibsnmp.mdf"
    SnmpIndex                           mdmIndex;
#line 407 "mibsnmp.mdf"
    AdminState                          desiredState;
#line 412 "mibsnmp.mdf"
    TrapState                           desiredTrapState;
}
#if ( USERIF & CLI )
__PACK__
#endif
SnmpStateProfile;

    /*
     * SnmpStateSecProfile:
     *
     * A profile to retain the SNMP ifIndex of a permanent interface such as
     * PPP over a nailed group or Frame Relay link layer. This profile built on
     * local connection profiles or RADIUS profile. This profile is created
     * whenever a local connection profile or a Frame Relay link layer profile
     * is created. It is deleted whenever a local profile is delete or changed
     * its properties such as link encapsulation, or switch from nailed group
     * (DS0 bundle) to switched DS0.
     *
     *  hostName The name of the host that the connection profile is created.
     *                                  The hostname has been checked for its
     *                                  uniqueness in the connection profile.
     *
     *  ifIndex The SNMP interface table index assigned to the device whose
     *                                  state is stored in this profile.
     *
     *  desiredState The desired administrative state of the addressed device.
     *
     *  desiredTrapState The desired link up/down enable state of the
     *                                  interface.
     *
     *  inetProfType Identify where the internet profile associates with the
     *                                  above hostname come from. Either it is
     *                                  from local storage or from RADIUS
     *                                  server.
     */
typedef struct snmpStateSecProfile {
#line 464 "mibsnmp.mdf"
    char                                hostName[ MAX_HOST_NAME_LENGTH + 1 ];
#line 471 "mibsnmp.mdf"
    SnmpIndex                           ifIndex;
#line 477 "mibsnmp.mdf"
    AdminState                          desiredState;
#line 482 "mibsnmp.mdf"
    TrapState                           desiredTrapState;
#line 487 "mibsnmp.mdf"
    Uint16                              inetProfType;
}
#if ( USERIF & CLI )
__PACK__
#endif
SnmpStateSecProfile;
#line 525 "mibsnmp.mdf"

#endif /* MIBSNMP_H */
