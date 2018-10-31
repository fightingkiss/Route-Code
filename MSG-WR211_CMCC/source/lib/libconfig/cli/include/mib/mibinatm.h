    /*
     * Notice: file generated by MIBMAKE from mibinatm.mdf
     * DO NOT EDIT THIS FILE!!!  Edit mibinatm.mdf
     */
#line 3 "mibinatm.mdf"
/*
 * $Id: mibinatm.h,v 1.1.1.1 2011/08/17 11:11:56 brwang Exp $
 *
 *      Copyright (c) 1996 UTT Technologies, Inc.
 *      All rights reserved.
 *      Use of copyright notice does not imply publication.
 *
 *
 *                      CONFIDENTIAL INFORMATION
 *                      ------------------------
 *      This Document contains Confidential Information or Trade Secrets,
 *      or both, which are the property of UTT Technologies, Inc.
 *      This document may not be copied, reproduced, reduced to any
 *      electronic medium or machine readable form or otherwise duplicated
 *      and the information herein may not be used, disseminated or
 *      otherwise disclosed, except with the prior written consent of
 *      UTT Technologies, Inc.
 */

#line 32 "mibinatm.mdf"

#if (( ! defined( MIBINATM_H ) ) && ( MDF_ATM == FYES ))
#define MIBINATM_H

#include "mibgen.h"
#include "mibglob.h"

    /*
     * How to build the factory instance of this profile.
     */
extern ConstPtr
mibFactoryAtmOptions( MibProfileType	mibType,
		     Uint32		info );

    /*
     * Our parameter table is made external as the profile is used
     * within other profiles.
     */
extern const MibFieldComplexParams	atmOptionsParams;


    /*
     * Atm1483Type:
     *
     * Describes the AAL5 type of multiplexing
     *
     *  AAL5_LLC AAL5 using LLC Encapsulation for routed protocols
     *
     *  AAL5_VC AAL5 using VC based multiplexing
     */
typedef enum Atm1483Type {
#line 88 "mibinatm.mdf"
    AAL5_LLC,
#line 91 "mibinatm.mdf"
    AAL5_VC
} Atm1483Type;


static __inline__ Bool
validAtm1483Type (int x)
{
    switch (x) {
#line 88 "mibinatm.mdf"
    case AAL5_LLC:
#line 91 "mibinatm.mdf"
    case AAL5_VC:
        return TRUE;
    default:
        return FALSE;
    }
}

    /*
     * AtmOptions:
     *
     * ATM configuration options.
     *
     *  atm1483Type The type of AAL5 multiplexing.
     *
     *  vpi The VPI of this connection.
     *
     *  vci The VCI of this connection.
     *
     *  atmEnabled Hidden, for answer profile.
     */
typedef struct atmOptions {
#line 110 "mibinatm.mdf"
    Atm1483Type                         atm1483Type;
#line 115 "mibinatm.mdf"
    Uint16                              vpi;
#line 120 "mibinatm.mdf"
    Uint16                              vci;
#line 125 "mibinatm.mdf"
    Boolean                             atmEnabled;
}
#if ( USERIF & CLI )
__PACK__
#endif
AtmOptions;
#line 179 "mibinatm.mdf"

#endif /* (( ! defined( MIBINATM_H ) ) && ( MDF_ATM == FYES ) */
