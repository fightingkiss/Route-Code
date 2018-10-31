    /*
     * Notice: file generated by MIBMAKE from mibdmtaw.mdf
     * DO NOT EDIT THIS FILE!!!  Edit mibdmtaw.mdf
     */
#line 3 "mibdmtaw.mdf"
/*
 * $Id: mibdmtaw.h,v 1.1.1.1 2011/08/17 11:11:56 brwang Exp $
 *
 *      Copyright (c) 1998 UTT Technologies, Inc.
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

#line 31 "mibdmtaw.mdf"
#if ( ! defined( MIBDMTAW_H ))
# define MIBDMTAW_H
# include "mibaddr.h"

/*
 * Our parameter table is made external as the profile is used
 * within other profiles.
 */
extern const MibFieldComplexParams      adslDmtAwStatusParams;
extern const MibFieldComplexParams      adslDmtAwStatisticParams;


    /*
     * MibProfAdslDmtAwStatistic:
     *
     * Adsl DMTAW statistical parameters.
     *
     *  ifUpTimer Line up seconds timer.
     *
     *  rxSigPresent State if the receive signal is present or not.
     *
     *  ifUpDwnCntr Interface Up Down counter value displays the number of
     *                                  times the interface trasitions from a
     *                                  down to up state.
     *
     *  selfTestResults Hardware/firmware self test results.
     *
     *  hdlcRxCrcErrCnt Hdlc CRC error counter.
     *
     *  neTotalESCount Near end total error second counter.
     *
     *  neCurrAtten Near end current line attenuation value.
     *
     *  neCurrSNR Near end current line signal-to-noise margin value.
     *
     *  feTotalESCounter Far end total error second counter.
     *
     *  feCurrAtten Far end current line attenuation value.
     *
     *  feCurrSNR Far end current line signal-to-noise margin value.
     */
typedef struct mibProfAdslDmtAwStatistic {
#line 174 "mibdmtaw.mdf"
    AdslPortUpTime                      ifUpTimer;
#line 179 "mibdmtaw.mdf"
    int                                 rxSigPresent;
#line 184 "mibdmtaw.mdf"
    int                                 ifUpDwnCntr;
#line 191 "mibdmtaw.mdf"
    int                                 selfTestResults;
#line 196 "mibdmtaw.mdf"
    unsigned long                       hdlcRxCrcErrCnt;
#line 201 "mibdmtaw.mdf"
    unsigned long                       neTotalESCount;
#line 206 "mibdmtaw.mdf"
    unsigned long                       neCurrAtten;
#line 211 "mibdmtaw.mdf"
    signed int                          neCurrSNR;
#line 216 "mibdmtaw.mdf"
    unsigned long                       feTotalESCounter;
#line 221 "mibdmtaw.mdf"
    unsigned long                       feCurrAtten;
#line 226 "mibdmtaw.mdf"
    signed int                          feCurrSNR;
}
#if ( USERIF & CLI )
__PACK__
#endif
MibProfAdslDmtAwStatistic;

    /*
     * MibProfAdslDmtAwStatus:
     *
     * Adsl Dmt status parameters.
     *
     *  ifGrpIndex Interface groups index assigned to this physical port.
     *
     *  unitType Unit types defines if the node is operating Central Office or
     *                                  Customer Premise equipment software.
     *
     *  ifState Display of current interface state.
     *
     *  opUpRate Operational up stream rate.
     *
     *  opDownRate Operational up stream rate.
     *
     *  majorFirmwareVer Firmware major version ID.
     *
     *  minorFirmwareVer Firmwares minor version ID.
     *
     *  hardwareVer Hardware chip version.
     */
typedef struct mibProfAdslDmtAwStatus {
#line 240 "mibdmtaw.mdf"
    int                                 ifGrpIndex;
#line 245 "mibdmtaw.mdf"
    int                                 unitType;
#line 251 "mibdmtaw.mdf"
    int                                 ifState;
#line 256 "mibdmtaw.mdf"
    int                                 opUpRate;
#line 261 "mibdmtaw.mdf"
    int                                 opDownRate;
#line 266 "mibdmtaw.mdf"
    unsigned short int                  majorFirmwareVer;
#line 271 "mibdmtaw.mdf"
    unsigned short int                  minorFirmwareVer;
#line 276 "mibdmtaw.mdf"
    unsigned short int                  hardwareVer;
}
#if ( USERIF & CLI )
__PACK__
#endif
MibProfAdslDmtAwStatus;
#line 308 "mibdmtaw.mdf"

# endif /* (( ! defined( MIBADSLDMTAW_H ) ) && ( PLATFORM & (PDSL | TNT))) */
