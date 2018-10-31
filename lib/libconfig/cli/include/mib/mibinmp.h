    /*
     * Notice: file generated by MIBMAKE from mibinmp.mdf
     * DO NOT EDIT THIS FILE!!!  Edit mibinmp.mdf
     */
#line 3 "mibinmp.mdf"
/*
 * $Id: mibinmp.h,v 1.1.1.1 2011/08/17 11:11:56 brwang Exp $
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

#line 31 "mibinmp.mdf"

#if (( ! defined( MIBINMP_H ) ) && ( MDF_MPP == FYES ))
#define MIBINMP_H

#include "mibgen.h"
#include "mibglob.h"

    /*
     * How to build the factory instance of this profile.
     */
extern ConstPtr
mibFactoryMpOptions( MibProfileType	mibType,
		     Uint32		info );

    /*
     * Our parameter table is made external as the profile is used
     * within other profiles.
     */
extern const MibFieldComplexParams	mpOptionsParams;


    /*
     * MpOptions:
     *
     * Mp configuration options.
     *
     *  mpEnabled Hidden, for answer profile.
     *
     *  fill1 filler.
     *
     *  baseChannelCount When the session is initially set up, and if it is a
     *                                  fixed session, the number of channels
     *                                  to be used for the call.
     *
     *  minimumChannelCount The default value for the minimum number of
     *                                  channels in a multi-channel call.
     *
     *  maximumChannelCount The default value for the maximum number of
     *                                  channels in a multi-channel call.
     *
     *  bacpEnable Enable Bandwidth Allocation Control Protocol (BACP).
     */
typedef struct st_mpOptions {
#line 81 "mibinmp.mdf"
    Boolean                             mpEnabled;
#line 87 "mibinmp.mdf"
    char                                fill1;
#line 93 "mibinmp.mdf"
    Uint16                              baseChannelCount;
#line 99 "mibinmp.mdf"
    Uint16                              minimumChannelCount;
#line 105 "mibinmp.mdf"
    Uint16                              maximumChannelCount;
#line 111 "mibinmp.mdf"
#if ( BACP == FYES )
    Boolean                             bacpEnable;
#endif /* ( BACP == FYES ) */
}
#if ( USERIF & CLI )
__PACK__
#endif
MpOptions;
#line 187 "mibinmp.mdf"

#endif /* (( ! defined( MIBINMP_H ) ) && ( MDF_MPP == FYES )) */
