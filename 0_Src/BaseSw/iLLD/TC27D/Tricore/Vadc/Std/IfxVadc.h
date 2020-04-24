/**
 * \file IfxVadc.h
 * \brief VADC  basic functionality
 * \ingroup IfxLld_Vadc
 *
 * \version iLLD_1_0_1_8_0
 * \copyright Copyright (c) 2017 Infineon Technologies AG. All rights reserved.
 *
 *
 *                                 IMPORTANT NOTICE
 *
 *
 * Infineon Technologies AG (Infineon) is supplying this file for use
 * exclusively with Infineon's microcontroller products. This file can be freely
 * distributed within development tools that are supporting such microcontroller
 * products.
 *
 * THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 * INFINEON SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL,
 * OR CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *
 * \defgroup IfxLld_Vadc_Std_Enum Enumerations
 * \ingroup IfxLld_Vadc_Std
 * \defgroup IfxLld_Vadc_Std_Background_Autoscan Background Autoscan Functions
 * \ingroup IfxLld_Vadc_Std
 * \defgroup IfxLld_Vadc_Std_ChannelScan Channel Scan Functions
 * \ingroup IfxLld_Vadc_Std
 * \defgroup IfxLld_Vadc_Std_QueueRequest Queue Request Functions
 * \ingroup IfxLld_Vadc_Std
 * \defgroup IfxLld_Vadc_Std_IO IO Pin Configuration Functions
 * \ingroup IfxLld_Vadc_Std
 * \defgroup IfxLld_Vadc_Std_Frequency Frequency Calculation
 * \ingroup IfxLld_Vadc_Std
 * \defgroup IfxLld_Vadc_Std_Group Group Functions
 * \ingroup IfxLld_Vadc_Std
 * \defgroup IfxLld_Vadc_Std_Module Module Functions
 * \ingroup IfxLld_Vadc_Std
 * \defgroup IfxLld_Vadc_Std_Channel Channel Functions
 * \ingroup IfxLld_Vadc_Std
 * \defgroup IfxLld_Vadc_Std_Emux Emux Functions
 * \ingroup IfxLld_Vadc_Std
 */

#ifndef IFXVADC_H
#define IFXVADC_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "_Impl/IfxVadc_cfg.h"
#include "_PinMap/IfxVadc_PinMap.h"
#include "IfxVadc_bf.h"
#include "Cpu/Std/IfxCpu_Intrinsics.h"
#include "Scu/Std/IfxScuCcu.h"
#include "Scu/Std/IfxScuWdt.h"
#include "IfxCcu6_reg.h"
#include "IfxCcu6_bf.h"

/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Vadc_Std_Enum
 * \{ */
/** \brief Defined in MODULE_VADC.G[x].ARBCFG.B.ANONS and ANONC
 */
typedef enum
{
    IfxVadc_AnalogConverterMode_off             = 0, /**< \brief Analog Converter off */
    IfxVadc_AnalogConverterMode_slowStandby     = 1, /**< \brief Slow Standby Mode */
    IfxVadc_AnalogConverterMode_fastStandby     = 2, /**< \brief Fast Standby Mode */
    IfxVadc_AnalogConverterMode_normalOperation = 3  /**< \brief Normal operation mode */
} IfxVadc_AnalogConverterMode;

/** \brief Arbitration round length defined in MODULE_VADC.G[x].ARBCFG.ARBRND(x=0,1,..,11)
 */
typedef enum
{
    IfxVadc_ArbitrationRounds_4_slots  = 0,  /**< \brief An arbitration round contains 4 arbitration slots. */
    IfxVadc_ArbitrationRounds_8_slots  = 1,  /**< \brief An arbitration round contains 8 arbitration slots. */
    IfxVadc_ArbitrationRounds_16_slots = 2,  /**< \brief An arbitration round contains 16 arbitration slots. */
    IfxVadc_ArbitrationRounds_20_slots = 3   /**< \brief An arbitration round contains 20 arbitration slots. */
} IfxVadc_ArbitrationRounds;

/** \brief Boundary Extension defined in MODULE_VADC.G[x].CHCTR[y].B.BNDSELX(x=0,1,...,11;y=0,1....,16)
 */
typedef enum
{
    IfxVadc_BoundaryExtension_standard            = 0,   /**< \brief Boundary Standard mode. BNDSELU/BNDSELL as Boundaries */
    IfxVadc_BoundaryExtension_fastCompareResult1  = 1,   /**< \brief Fast compare mode use as upper boundary  Channel result   1 */
    IfxVadc_BoundaryExtension_fastCompareResult2  = 2,   /**< \brief Fast compare mode use as upper boundary  Channel result   2 */
    IfxVadc_BoundaryExtension_fastCompareResult3  = 3,   /**< \brief Fast compare mode use as upper boundary  Channel result   3 */
    IfxVadc_BoundaryExtension_fastCompareResult4  = 4,   /**< \brief Fast compare mode use as upper boundary  Channel result   4 */
    IfxVadc_BoundaryExtension_fastCompareResult5  = 5,   /**< \brief Fast compare mode use as upper boundary  Channel result   5 */
    IfxVadc_BoundaryExtension_fastCompareResult6  = 6,   /**< \brief Fast compare mode use as upper boundary  Channel result   6 */
    IfxVadc_BoundaryExtension_fastCompareResult7  = 7,   /**< \brief Fast compare mode use as upper boundary  Channel result   7 */
    IfxVadc_BoundaryExtension_fastCompareResult8  = 8,   /**< \brief Fast compare mode use as upper boundary  Channel result   8 */
    IfxVadc_BoundaryExtension_fastCompareResult9  = 9,   /**< \brief Fast compare mode use as upper boundary  Channel result   9 */
    IfxVadc_BoundaryExtension_fastCompareResult10 = 10,  /**< \brief Fast compare mode use as upper boundary  Channel result  10 */
    IfxVadc_BoundaryExtension_fastCompareResult11 = 11,  /**< \brief Fast compare mode use as upper boundary  Channel result  11 */
    IfxVadc_BoundaryExtension_fastCompareResult12 = 12,  /**< \brief Fast compare mode use as upper boundary  Channel result  12 */
    IfxVadc_BoundaryExtension_fastCompareResult13 = 13,  /**< \brief Fast compare mode use as upper boundary  Channel result  13 */
    IfxVadc_BoundaryExtension_fastCompareResult14 = 14,  /**< \brief Fast compare mode use as upper boundary  Channel result  14 */
    IfxVadc_BoundaryExtension_fastCompareResult15 = 15   /**< \brief Fast compare mode use as upper boundary  Channel result  15 */
} IfxVadc_BoundaryExtension;

/** \brief BoundarySel defined in MODULE_VADC.G[x].CHCTR[y].B.BNDSELL(x=0,1,...,11;y=0,1....,16)
 */
typedef enum
{
    IfxVadc_BoundarySelection_group0  = 0,  /**< \brief Use group class 0 */
    IfxVadc_BoundarySelection_group1  = 1,  /**< \brief Use group class 1 */
    IfxVadc_BoundarySelection_global0 = 2,  /**< \brief Use global class 0 */
    IfxVadc_BoundarySelection_global1 = 3   /**< \brief Use global class 1 */
} IfxVadc_BoundarySelection;

/** \brief VADC Channels
 */
typedef enum
{
    IfxVadc_ChannelId_none = -1,  /**< \brief None of VADC channels */
    IfxVadc_ChannelId_0    = 0,   /**< \brief Channel 0 */
    IfxVadc_ChannelId_1    = 1,   /**< \brief Channel 1 */
    IfxVadc_ChannelId_2    = 2,   /**< \brief Channel 2 */
    IfxVadc_ChannelId_3    = 3,   /**< \brief Channel 3 */
    IfxVadc_ChannelId_4    = 4,   /**< \brief Channel 4 */
    IfxVadc_ChannelId_5    = 5,   /**< \brief Channel 5 */
    IfxVadc_ChannelId_6    = 6,   /**< \brief Channel 6 */
    IfxVadc_ChannelId_7    = 7    /**< \brief Channel 7 */
} IfxVadc_ChannelId;

/** \brief ADC channel reference defined in MODULE_VADC.G[x].CHCTR[y].B.REFSEL(x=0,1,...,11;y=0,1....,16)
 */
typedef enum
{
    IfxVadc_ChannelReference_standard = 0,  /**< \brief use Varef as reference */
    IfxVadc_ChannelReference_channel0 = 1   /**< \brief use CH0 as reference */
} IfxVadc_ChannelReference;

/** \brief ADC channel resolution defined in MODULE_VADC.G[x].CHCTR[y].B.ICLASS[y].B.CMS(x=0,1,...,11;y=0,1)
 */
typedef enum
{
    IfxVadc_ChannelResolution_12bit     = 0, /**< \brief 12-bit conversion */
    IfxVadc_ChannelResolution_10bit     = 1, /**< \brief 10-bit conversion */
    IfxVadc_ChannelResolution_8bit      = 2, /**< \brief 8-bit conversion */
    IfxVadc_ChannelResolution_10bitFast = 5  /**< \brief 10-bit cfast compare mode */
} IfxVadc_ChannelResolution;

/** \brief Channel Result defined in MODULE_VADC.G[x].CHCTR[y].B.RESREG(x=0,1,...,11;y=0,1....,16)
 */
typedef enum
{
    IfxVadc_ChannelResult_0 = 0,      /**< \brief Use Channel result 0  */
    IfxVadc_ChannelResult_1,          /**< \brief Use Channel result 1  */
    IfxVadc_ChannelResult_2,          /**< \brief Use Channel result 2  */
    IfxVadc_ChannelResult_3,          /**< \brief Use Channel result 3  */
    IfxVadc_ChannelResult_4,          /**< \brief Use Channel result 4  */
    IfxVadc_ChannelResult_5,          /**< \brief Use Channel result 5  */
    IfxVadc_ChannelResult_6,          /**< \brief Use Channel result 6  */
    IfxVadc_ChannelResult_7,          /**< \brief Use Channel result 7  */
    IfxVadc_ChannelResult_8,          /**< \brief Use Channel result 8  */
    IfxVadc_ChannelResult_9,          /**< \brief Use Channel result 9  */
    IfxVadc_ChannelResult_10,         /**< \brief Use Channel result 10  */
    IfxVadc_ChannelResult_11,         /**< \brief Use Channel result 11  */
    IfxVadc_ChannelResult_12,         /**< \brief Use Channel result 12  */
    IfxVadc_ChannelResult_13,         /**< \brief Use Channel result 13  */
    IfxVadc_ChannelResult_14,         /**< \brief Use Channel result 14  */
    IfxVadc_ChannelResult_15          /**< \brief Use Channel result 15  */
} IfxVadc_ChannelResult;

/** \brief External Multiplexer Channel Selection Style as defined in
 * Ifx_VADC.G[x].EMUXCTR.B.EMXCSS
 */
typedef enum
{
    IfxVadc_ChannelSelectionStyle_channelNumber = 0,  /**< \brief selects an arbitrary channel */
    IfxVadc_ChannelSelectionStyle_binary        = 1   /**< \brief Each bit of bitfield EMUXCH selects the
                                                       * associated channel for EMUX control */
} IfxVadc_ChannelSelectionStyle;

/** \brief type of conversion
 */
typedef enum
{
    IfxVadc_ConversionType_Compatible = 0  /**< \brief Compatible Timing Mode */
} IfxVadc_ConversionType;

/** \brief Specifies the External Coding scheme(binary/gray)
 * defined in Ifx_VADC.G[x].EMUXCTR.B.EMXCOD
 */
typedef enum
{
    IfxVadc_EmuxCodingScheme_binary = 0,  /**< \brief Output the Channel Number in Binary code */
    IfxVadc_EmuxCodingScheme_gray   = 1   /**< \brief Output the channel number in gray code */
} IfxVadc_EmuxCodingScheme;

/** \brief Specifies the Emux interface
 */
typedef enum
{
    IfxVadc_EmuxInterface_0 = 0,  /**< \brief Emux Interface 0 */
    IfxVadc_EmuxInterface_1 = 1   /**< \brief Emux Interface 1 */
} IfxVadc_EmuxInterface;

/** \brief External Multiplexer sample time control
 * defined in Ifx_VADC.G[x].EMUXCTR.B.EMXST
 */
typedef enum
{
    IfxVadc_EmuxSampleTimeControl_settingChanges = 0,  /**< \brief Use STCE Whenever Setting Changes */
    IfxVadc_EmuxSampleTimeControl_always         = 1   /**< \brief Use STCE for each conversion of an external channel */
} IfxVadc_EmuxSampleTimeControl;

/** \brief specifies the External Channel Start select value
 * defined in Ifx_VADC.G[x].EMUXCTR.B.EMUXSET
 */
typedef enum
{
    IfxVadc_EmuxSelectValue_0 = 0,      /**< \brief Start Selection Value 0  */
    IfxVadc_EmuxSelectValue_1,          /**< \brief Start Selection Value 1  */
    IfxVadc_EmuxSelectValue_2,          /**< \brief Start Selection Value 2  */
    IfxVadc_EmuxSelectValue_3,          /**< \brief Start Selection Value 3  */
    IfxVadc_EmuxSelectValue_4,          /**< \brief Start Selection Value 4  */
    IfxVadc_EmuxSelectValue_5,          /**< \brief Start Selection Value 5  */
    IfxVadc_EmuxSelectValue_6,          /**< \brief Start Selection Value 6  */
    IfxVadc_EmuxSelectValue_7           /**< \brief Start Selection Value 7  */
} IfxVadc_EmuxSelectValue;

/** \brief Specifies External Multiplexer Mode
 * define in Ifx_VADC.G[x].EMUXCTR.B.EMUXMODE
 */
typedef enum
{
    IfxVadc_ExternalMultiplexerMode_softwareControl = 0,  /**< \brief Disable The Emux Control */
    IfxVadc_ExternalMultiplexerMode_steady          = 1,  /**< \brief select steady mode */
    IfxVadc_ExternalMultiplexerMode_singleStep      = 2,  /**< \brief Select single step mode */
    IfxVadc_ExternalMultiplexerMode_sequence        = 3   /**< \brief Select Sequence Mode */
} IfxVadc_ExternalMultiplexerMode;

/** \brief FIFO mode enable
 */
typedef enum
{
    IfxVadc_FifoMode_seperateResultRegister = 0,  /**< \brief seperate Result Register */
    IfxVadc_FifoMode_fifoStructure          = 1,  /**< \brief fifoStructure */
    IfxVadc_FifoMode_maximumMode            = 2,  /**< \brief copy new result if bigger */
    IfxVadc_FifoMode_minimumMode            = 3   /**< \brief copy new result if it is smaller */
} IfxVadc_FifoMode;

/** \brief gating mode defined in MODULE_VADC.BRSMR.ENGT
 */
typedef enum
{
    IfxVadc_GatingMode_disabled   = 0,  /**< \brief Gating is disabled, no conversion request are issued */
    IfxVadc_GatingMode_always     = 1,  /**< \brief Conversion request is issued if at least 1 conversion pending bit is set */
    IfxVadc_GatingMode_gatingHigh = 2,  /**< \brief Conversion request is issued if at least 1 conversion pending bit is set and the gating signal is high */
    IfxVadc_GatingMode_gatingLow  = 3   /**< \brief Conversion request is issued if at least 1 conversion pending bit is set and the gating signal is low */
} IfxVadc_GatingMode;

/** \brief External trigger gating defined in MODULE_VADC.G[x].QCTRLy.GTSEL(x=0,1,..,11;y=0,1,..,7)
 */
typedef enum
{
    IfxVadc_GatingSource_0 = 0,      /**< \brief Input signal REQGTx_0  */
    IfxVadc_GatingSource_1,          /**< \brief Input signal REQGTx_1  */
    IfxVadc_GatingSource_2,          /**< \brief Input signal REQGTx_2  */
    IfxVadc_GatingSource_3,          /**< \brief Input signal REQGTx_3  */
    IfxVadc_GatingSource_4,          /**< \brief Input signal REQGTx_4  */
    IfxVadc_GatingSource_5,          /**< \brief Input signal REQGTx_5  */
    IfxVadc_GatingSource_6,          /**< \brief Input signal REQGTx_6  */
    IfxVadc_GatingSource_7,          /**< \brief Input signal REQGTx_7  */
    IfxVadc_GatingSource_8,          /**< \brief Input signal REQGTx_8  */
    IfxVadc_GatingSource_9,          /**< \brief Input signal REQGTx_9  */
    IfxVadc_GatingSource_10,         /**< \brief Input signal REQGTx_10  */
    IfxVadc_GatingSource_11,         /**< \brief Input signal REQGTx_11  */
    IfxVadc_GatingSource_12,         /**< \brief Input signal REQGTx_12  */
    IfxVadc_GatingSource_13,         /**< \brief Input signal REQGTx_13  */
    IfxVadc_GatingSource_14,         /**< \brief Input signal REQGTx_14  */
    IfxVadc_GatingSource_15          /**< \brief Input signal REQGTx_15  */
} IfxVadc_GatingSource;

/** \brief inputClass defined in MODULE_VADC.G[x].CHCTR[y].B.ICLSEL(x=0,1,...,11;y=0,1....,16)
 */
typedef enum
{
    IfxVadc_InputClasses_group0  = 0,  /**< \brief Use group class 0 */
    IfxVadc_InputClasses_group1  = 1,  /**< \brief Use group class 1 */
    IfxVadc_InputClasses_global0 = 2,  /**< \brief Use global class 0 */
    IfxVadc_InputClasses_global1 = 3   /**< \brief Use global class 1 */
} IfxVadc_InputClasses;

/** \brief ADC channel limit check defined in MODULE_VADC.G[x].CHCTR[y].B.CHEVMODE(x=0,1,...,11;y=0,1....,16)
 */
typedef enum
{
    IfxVadc_LimitCheck_noCheck            = 0,  /**< \brief Normal compare mode Event Never Fast Compare mode Event Never */
    IfxVadc_LimitCheck_eventIfInArea      = 1,  /**< \brief Normal compare mode Event If result is inside the boundary band    Fast Compare mode Event If result switches to high (above comp. value) */
    IfxVadc_LimitCheck_eventIfOutsideArea = 2,  /**< \brief Normal compare mode Event If result is outside the boundary band   Fast Compare mode Event If result switches to low (below comp. value) */
    IfxVadc_LimitCheck_always             = 3   /**< \brief Normal compare mode Event Always   Fast Compare mode Event Always */
} IfxVadc_LimitCheck;

/** \brief Low Power Supply Voltage Select
 */
typedef enum
{
    IfxVadc_LowSupplyVoltageSelect_5V = 0,  /**< \brief 5V Power Supply is Connected */
    IfxVadc_LowSupplyVoltageSelect_3V = 1   /**< \brief 3.3V Power Supply is Connected */
} IfxVadc_LowSupplyVoltageSelect;

/** \brief Access protection for Group registers defined in MODULE_VADC.ACCPROT0.U
 */
typedef enum
{
    IfxVadc_Protection_channelControl0       = 0,   /**< \brief Access control for GxCHCTR0 */
    IfxVadc_Protection_channelControl1       = 1,   /**< \brief Access control for GxCHCTR1 */
    IfxVadc_Protection_channelControl2       = 2,   /**< \brief Access control for GxCHCTR2 */
    IfxVadc_Protection_channelControl3       = 3,   /**< \brief Access control for GxCHCTR3 */
    IfxVadc_Protection_channelControl4       = 4,   /**< \brief Access control for GxCHCTR4 */
    IfxVadc_Protection_channelControl5       = 5,   /**< \brief Access control for GxCHCTR5 */
    IfxVadc_Protection_channelControl6       = 6,   /**< \brief Access control for GxCHCTR6 */
    IfxVadc_Protection_channelControl7       = 7,   /**< \brief Access control for GxCHCTR7 */
    IfxVadc_Protection_channelControl8       = 8,   /**< \brief Access control for GxCHCTR8 */
    IfxVadc_Protection_channelControl9       = 9,   /**< \brief Access control for GxCHCTR9 */
    IfxVadc_Protection_channelControl10      = 10,  /**< \brief Access control for GxCHCTR10 */
    IfxVadc_Protection_channelControl11      = 11,  /**< \brief Access control for GxCHCTR11 */
    IfxVadc_Protection_channelControl12      = 12,  /**< \brief Access control for GxCHCTR12 */
    IfxVadc_Protection_channelControl13      = 13,  /**< \brief Access control for GxCHCTR13 */
    IfxVadc_Protection_channelControl14      = 14,  /**< \brief Access control for GxCHCTR14 */
    IfxVadc_Protection_externalMultiplexer   = 15,  /**< \brief Access control for EMUXSEL, GxEMUXCTR */
    IfxVadc_Protection_initGroup0            = 16,  /**< \brief Access control for GxARBCFG, GxARBPR, GxCHASS, GxRRASS, GxICLASS0/1, GxSYNCTR */
    IfxVadc_Protection_initGroup1            = 17,  /**< \brief Access control for GxARBCFG, GxARBPR, GxCHASS, GxRRASS, GxICLASS0/1, GxSYNCTR */
    IfxVadc_Protection_initGroup2            = 18,  /**< \brief Access control for GxARBCFG, GxARBPR, GxCHASS, GxRRASS, GxICLASS0/1, GxSYNCTR */
    IfxVadc_Protection_initGroup3            = 19,  /**< \brief Access control for GxARBCFG, GxARBPR, GxCHASS, GxRRASS, GxICLASS0/1, GxSYNCTR */
    IfxVadc_Protection_initGroup4            = 20,  /**< \brief Access control for GxARBCFG, GxARBPR, GxCHASS, GxRRASS, GxICLASS0/1, GxSYNCTR */
    IfxVadc_Protection_initGroup5            = 21,  /**< \brief Access control for GxARBCFG, GxARBPR, GxCHASS, GxRRASS, GxICLASS0/1, GxSYNCTR */
    IfxVadc_Protection_initGroup6            = 22,  /**< \brief Access control for GxARBCFG, GxARBPR, GxCHASS, GxRRASS, GxICLASS0/1, GxSYNCTR */
    IfxVadc_Protection_initGroup7            = 23,  /**< \brief Access control for GxARBCFG, GxARBPR, GxCHASS, GxRRASS, GxICLASS0/1, GxSYNCTR */
    IfxVadc_Protection_initGroup8            = 24,  /**< \brief Access control for GxARBCFG, GxARBPR, GxCHASS, GxRRASS, GxICLASS0/1, GxSYNCTR */
    IfxVadc_Protection_initGroup9            = 25,  /**< \brief Access control for GxARBCFG, GxARBPR, GxCHASS, GxRRASS, GxICLASS0/1, GxSYNCTR */
    IfxVadc_Protection_initGroup10           = 26,  /**< \brief Access control for GxARBCFG, GxARBPR, GxCHASS, GxRRASS, GxICLASS0/1, GxSYNCTR */
    IfxVadc_Protection_initGroup11           = 27,  /**< \brief Access control for GxARBCFG, GxARBPR, GxCHASS, GxRRASS, GxICLASS0/1, GxSYNCTR */
    IfxVadc_Protection_initGroup12           = 28,  /**< \brief Access control for GxARBCFG, GxARBPR, GxCHASS, GxRRASS, GxICLASS0/1, GxSYNCTR */
    IfxVadc_Protection_initGroup13           = 29,  /**< \brief Access control for GxARBCFG, GxARBPR, GxCHASS, GxRRASS, GxICLASS0/1, GxSYNCTR */
    IfxVadc_Protection_initGroup14           = 30,  /**< \brief Access control for GxARBCFG, GxARBPR, GxCHASS, GxRRASS, GxICLASS0/1, GxSYNCTR */
    IfxVadc_Protection_globalConfig          = 31,  /**< \brief Access control for GLOBCFG */
    IfxVadc_Protection_serviceGroup0         = 32,  /**< \brief Access control for GxSEFLAG, GxSEVNP, GxCEFLAG, GxCEVNP0/1/2, GxREFLAG, GxREVNP0/1, GxSRACT */
    IfxVadc_Protection_serviceGroup1         = 33,  /**< \brief Access control for GxSEFLAG, GxSEVNP, GxCEFLAG, GxCEVNP0/1/2, GxREFLAG, GxREVNP0/1, GxSRACT */
    IfxVadc_Protection_serviceGroup2         = 34,  /**< \brief Access control for GxSEFLAG, GxSEVNP, GxCEFLAG, GxCEVNP0/1/2, GxREFLAG, GxREVNP0/1, GxSRACT */
    IfxVadc_Protection_serviceGroup3         = 35,  /**< \brief Access control for GxSEFLAG, GxSEVNP, GxCEFLAG, GxCEVNP0/1/2, GxREFLAG, GxREVNP0/1, GxSRACT */
    IfxVadc_Protection_serviceGroup4         = 36,  /**< \brief Access control for GxSEFLAG, GxSEVNP, GxCEFLAG, GxCEVNP0/1/2, GxREFLAG, GxREVNP0/1, GxSRACT */
    IfxVadc_Protection_serviceGroup5         = 37,  /**< \brief Access control for GxSEFLAG, GxSEVNP, GxCEFLAG, GxCEVNP0/1/2, GxREFLAG, GxREVNP0/1, GxSRACT */
    IfxVadc_Protection_serviceGroup6         = 38,  /**< \brief Access control for GxSEFLAG, GxSEVNP, GxCEFLAG, GxCEVNP0/1/2, GxREFLAG, GxREVNP0/1, GxSRACT */
    IfxVadc_Protection_serviceGroup7         = 39,  /**< \brief Access control for GxSEFLAG, GxSEVNP, GxCEFLAG, GxCEVNP0/1/2, GxREFLAG, GxREVNP0/1, GxSRACT */
    IfxVadc_Protection_serviceGroup8         = 40,  /**< \brief Access control for GxSEFLAG, GxSEVNP, GxCEFLAG, GxCEVNP0/1/2, GxREFLAG, GxREVNP0/1, GxSRACT */
    IfxVadc_Protection_serviceGroup9         = 41,  /**< \brief Access control for GxSEFLAG, GxSEVNP, GxCEFLAG, GxCEVNP0/1/2, GxREFLAG, GxREVNP0/1, GxSRACT */
    IfxVadc_Protection_serviceGroup10        = 42,  /**< \brief Access control for GxSEFLAG, GxSEVNP, GxCEFLAG, GxCEVNP0/1/2, GxREFLAG, GxREVNP0/1, GxSRACT */
    IfxVadc_Protection_serviceGroup11        = 43,  /**< \brief Access control for GxSEFLAG, GxSEVNP, GxCEFLAG, GxCEVNP0/1/2, GxREFLAG, GxREVNP0/1, GxSRACT */
    IfxVadc_Protection_serviceGroup12        = 44,  /**< \brief Access control for GxSEFLAG, GxSEVNP, GxCEFLAG, GxCEVNP0/1/2, GxREFLAG, GxREVNP0/1, GxSRACT */
    IfxVadc_Protection_serviceGroup13        = 45,  /**< \brief Access control for GxSEFLAG, GxSEVNP, GxCEFLAG, GxCEVNP0/1/2, GxREFLAG, GxREVNP0/1, GxSRACT */
    IfxVadc_Protection_serviceGroup14        = 46,  /**< \brief Access control for GxSEFLAG, GxSEVNP, GxCEFLAG, GxCEVNP0/1/2, GxREFLAG, GxREVNP0/1, GxSRACT */
    IfxVadc_Protection_testFunction          = 47,  /**< \brief Access control for GLOBTF */
    IfxVadc_Protection_resultRegisterGroup0  = 48,  /**< \brief Access control for GxRCRx(x=0,1,..,15), GxBOUND, GxRESx(x=0 .. 15) */
    IfxVadc_Protection_resultRegisterGroup1  = 49,  /**< \brief Access control for GxRCRx(x=0,1,..,15), GxBOUND, GxRESx(x=0 .. 15) */
    IfxVadc_Protection_resultRegisterGroup2  = 50,  /**< \brief Access control for GxRCRx(x=0,1,..,15), GxBOUND, GxRESx(x=0 .. 15) */
    IfxVadc_Protection_resultRegisterGroup3  = 51,  /**< \brief Access control for GxRCRx(x=0,1,..,15), GxBOUND, GxRESx(x=0 .. 15) */
    IfxVadc_Protection_resultRegisterGroup4  = 52,  /**< \brief Access control for GxRCRx(x=0,1,..,15), GxBOUND, GxRESx(x=0 .. 15) */
    IfxVadc_Protection_resultRegisterGroup5  = 53,  /**< \brief Access control for GxRCRx(x=0,1,..,15), GxBOUND, GxRESx(x=0 .. 15) */
    IfxVadc_Protection_resultRegisterGroup6  = 54,  /**< \brief Access control for GxRCRx(x=0,1,..,15), GxBOUND, GxRESx(x=0 .. 15) */
    IfxVadc_Protection_resultRegisterGroup7  = 55,  /**< \brief Access control for GxRCRx(x=0,1,..,15), GxBOUND, GxRESx(x=0 .. 15) */
    IfxVadc_Protection_resultRegisterGroup8  = 56,  /**< \brief Access control for GxRCRx(x=0,1,..,15), GxBOUND, GxRESx(x=0 .. 15) */
    IfxVadc_Protection_resultRegisterGroup9  = 57,  /**< \brief Access control for GxRCRx(x=0,1,..,15), GxBOUND, GxRESx(x=0 .. 15) */
    IfxVadc_Protection_resultRegisterGroup10 = 58,  /**< \brief Access control for GxRCRx(x=0,1,..,15), GxBOUND, GxRESx(x=0 .. 15) */
    IfxVadc_Protection_resultRegisterGroup11 = 59,  /**< \brief Access control for GxRCRx(x=0,1,..,15), GxBOUND, GxRESx(x=0 .. 15) */
    IfxVadc_Protection_resultRegisterGroup12 = 60,  /**< \brief Access control for GxRCRx(x=0,1,..,15), GxBOUND, GxRESx(x=0 .. 15) */
    IfxVadc_Protection_resultRegisterGroup13 = 61,  /**< \brief Access control for GxRCRx(x=0,1,..,15), GxBOUND, GxRESx(x=0 .. 15) */
    IfxVadc_Protection_resultRegisterGroup14 = 62   /**< \brief Access control for GxRCRx(x=0,1,..,15), GxBOUND, GxRESx(x=0 .. 15) */
} IfxVadc_Protection;

/** \brief Arbitration priority, Group x,defined in MODULE_VADC.G[x].ARBPR.PRIOy(x=0,1,...,11;y=0,1,2)
 */
typedef enum
{
    IfxVadc_RequestSlotPriority_lowest  = 0, /**< \brief Lowest priority */
    IfxVadc_RequestSlotPriority_low     = 1, /**< \brief Lowpriority */
    IfxVadc_RequestSlotPriority_high    = 2, /**< \brief High priority */
    IfxVadc_RequestSlotPriority_highest = 3  /**< \brief Highest priority */
} IfxVadc_RequestSlotPriority;

/** \brief Request source start mode defined in MODULE_VADC.G[x].ARBPR.CSMy(x=0,1,...,11;y=0,1,2)
 */
typedef enum
{
    IfxVadc_RequestSlotStartMode_waitForStart       = 0, /**< \brief Wait for start */
    IfxVadc_RequestSlotStartMode_cancelInjectRepeat = 1  /**< \brief Cancel-Inject-Repeat */
} IfxVadc_RequestSlotStartMode;

/** \brief Request sources
 */
typedef enum
{
    IfxVadc_RequestSource_queue      = 0, /**< \brief 8 stage Queue request */
    IfxVadc_RequestSource_scan       = 1, /**< \brief scan request */
    IfxVadc_RequestSource_background = 2  /**< \brief background scan request */
} IfxVadc_RequestSource;

/** \brief Enable/disable the sensitivity of the module to sleep signal\n
 * Definition in Ifx_VADC.CLC.B.EDIS
 */
typedef enum
{
    IfxVadc_SleepMode_enable  = 0, /**< \brief enables sleep mode */
    IfxVadc_SleepMode_disable = 1  /**< \brief disables sleep mode */
} IfxVadc_SleepMode;

/** \brief Service Node defined in MODULE_VADC.G[x].SRACT.U(x= 0,1,..,11)
 */
typedef enum
{
    IfxVadc_SrcNr_group0  = 0,  /**< \brief service request line 0 of group */
    IfxVadc_SrcNr_group1  = 1,  /**< \brief service request line 1 of group */
    IfxVadc_SrcNr_group2  = 2,  /**< \brief service request line 2 of group */
    IfxVadc_SrcNr_group3  = 3,  /**< \brief service request line 3 of group */
    IfxVadc_SrcNr_shared0 = 4,  /**< \brief Select shared service request line 0 */
    IfxVadc_SrcNr_shared1 = 5,  /**< \brief Select shared service request line 1 */
    IfxVadc_SrcNr_shared2 = 6,  /**< \brief Select shared service request line 2 */
    IfxVadc_SrcNr_shared3 = 7   /**< \brief Select shared service request line 3 */
} IfxVadc_SrcNr;

/** \brief API return values defined in
 * MODULE_VADC.G[x].QSR0.U,MODULE_VADC.G[x].ASPND.U
 * MODULE_VADC.BRSPND[x](x=0,1,...,11)
 */
typedef enum
{
    IfxVadc_Status_noError              = 0, /**< \brief No error during api execution */
    IfxVadc_Status_notInitialised       = 1, /**< \brief Appropriate initialisation not done */
    IfxVadc_Status_invalidGroup         = 2, /**< \brief Invalid group number */
    IfxVadc_Status_invalidChannel       = 3, /**< \brief Invalid channel number */
    IfxVadc_Status_queueFull            = 4, /**< \brief Queue is full */
    IfxVadc_Status_noAccess             = 5, /**< \brief Access to the group/channel is disabled */
    IfxVadc_Status_channelsStillPending = 6  /**< \brief Conversion for some of the channels are still pending */
} IfxVadc_Status;

/** \brief trigger definition defined in MODULE_VADC.G[x].QCTRL0.XTMODE(x=0,1,..,11)
 */
typedef enum
{
    IfxVadc_TriggerMode_noExternalTrigger = 0,  /**< \brief No external trigger */
    IfxVadc_TriggerMode_uponFallingEdge   = 1,  /**< \brief Trigger event upon a falling edge */
    IfxVadc_TriggerMode_uponRisingEdge    = 2,  /**< \brief Trigger event upon a rising edge */
    IfxVadc_TriggerMode_uponAnyEdge       = 3   /**< \brief Trigger event upon any edge */
} IfxVadc_TriggerMode;

/** \brief Trigger request source defined in MODULE_VADC.G[x].QCTRLy.XTSEL(x=0,1,..,11;y=0,1,..,7)
 */
typedef enum
{
    IfxVadc_TriggerSource_0 = 0,      /**< \brief Input signal REQTRx_0  */
    IfxVadc_TriggerSource_1,          /**< \brief Input signal REQTRx_1  */
    IfxVadc_TriggerSource_2,          /**< \brief Input signal REQTRx_2  */
    IfxVadc_TriggerSource_3,          /**< \brief Input signal REQTRx_3  */
    IfxVadc_TriggerSource_4,          /**< \brief Input signal REQTRx_4  */
    IfxVadc_TriggerSource_5,          /**< \brief Input signal REQTRx_5  */
    IfxVadc_TriggerSource_6,          /**< \brief Input signal REQTRx_6  */
    IfxVadc_TriggerSource_7,          /**< \brief Input signal REQTRx_7  */
    IfxVadc_TriggerSource_8,          /**< \brief Input signal REQTRx_8  */
    IfxVadc_TriggerSource_9,          /**< \brief Input signal REQTRx_9  */
    IfxVadc_TriggerSource_10,         /**< \brief Input signal REQTRx_10  */
    IfxVadc_TriggerSource_11,         /**< \brief Input signal REQTRx_11  */
    IfxVadc_TriggerSource_12,         /**< \brief Input signal REQTRx_12  */
    IfxVadc_TriggerSource_13,         /**< \brief Input signal REQTRx_13  */
    IfxVadc_TriggerSource_14,         /**< \brief Input signal REQTRx_14  */
    IfxVadc_TriggerSource_15          /**< \brief Input signal REQTRx_15  */
} IfxVadc_TriggerSource;

/** \} */

/** \addtogroup IfxLld_Vadc_Std_Background_Autoscan
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief access function to enable/disable  wait for read mode for result registers
 * \param group pointer to the VADC group
 * \param resultIdx result register index
 * \param waitForRead wait for read mode enabled/disabled
 * \return None
 */
IFX_INLINE void IfxVadc_configureWaitForReadMode(Ifx_VADC_G *group, uint32 resultIdx, boolean waitForRead);

/** \brief access function to enable/disable  wait for read mode for global result register
 * \param vadc pointer to the VADC
 * \param waitForRead wait for read mode enabled/disabled
 * \return None
 */
IFX_INLINE void IfxVadc_configureWaitForReadModeForGlobalResultRegister(Ifx_VADC *vadc, boolean waitForRead);

/** \brief Enables the background sacn external trigger.
 * \param vadc pointer to the base of VADC registers.
 * \return None
 */
IFX_INLINE void IfxVadc_enableBackgroundScanSlotExternalTrigger(Ifx_VADC *vadc);

/** \brief Gets the background scan gating mode.
 * \param vadc pointer to the base of VADC registers.
 * \return background scan gating mode.
 */
IFX_INLINE IfxVadc_GatingMode IfxVadc_getBackgroundScanGatingMode(Ifx_VADC *vadc);

/** \brief Gets the gating input selection.
 * \param vadc pointer to the base of VADC registers.
 * \return background scan gating input selection.
 */
IFX_INLINE IfxVadc_GatingSource IfxVadc_getBackgroundScanGatingSource(Ifx_VADC *vadc);

/** \brief Gets the requested background scan slot priority.
 * \param vadcG pointer to VADC group registers.
 * \return requested background scan slot priority.
 */
IFX_INLINE IfxVadc_RequestSlotPriority IfxVadc_getBackgroundScanSlotPriority(Ifx_VADC_G *vadcG);

/** \brief Gets the requested background scan slot start mode.
 * \param vadcG pointer to VADC group registers.
 * \return requested background scan slot start mode.
 */
IFX_INLINE IfxVadc_RequestSlotStartMode IfxVadc_getBackgroundScanSlotStartMode(Ifx_VADC_G *vadcG);

/** \brief Gets the background scan trigger input.
 * \param vadc pointer to the base of VADC registers.
 * \return Gets the background scan external trigger source.
 */
IFX_INLINE IfxVadc_TriggerSource IfxVadc_getBackgroundScanTriggerInput(Ifx_VADC *vadc);

/** \brief Gets the background scan external trigger mode.
 * \param vadc pointer to the base of VADC registers.
 * \return background scan external trigger mode.
 */
IFX_INLINE IfxVadc_TriggerMode IfxVadc_getBackgroundScanTriggerMode(Ifx_VADC *vadc);

/** \brief get global input class resolution
 * \param vadc Pointer to the VADC Group
 * \param inputClassNum global input class number
 * \return ADC input class channel resolution.
 */
IFX_INLINE IfxVadc_ChannelResolution IfxVadc_getGlobalResolution(Ifx_VADC *vadc, uint8 inputClassNum);

/** \brief return conversion result stored in the Global result Register
 * \param vadc pointer to the VADC module
 * \return global result register
 *
 * \code
 * Ifx_VADC* vadc = &MODULE_VADC; // module pointer
 * IfxVadc_GroupId groupId = IfxVadc_GroupId0; // for group 0
 * uint32 channels = (1 << 5) | (1 << 2); // enable channel #5 and #2
 * uint32 mask = (1 << 7) | (1 << 5) | (1 << 2); // modify the selection for channel #7, #5 and #2; channel #7 will be disabled
 *
 * //confiure wait for read mode for global result register
 * IfxVadc_configureWaitForReadModeForGlobalResultRegister(vadc, TRUE);
 *
 * // configure background scan
 * IfxVadc_setBackgroundScan(vadc, groupId, channels, mask);
 *
 * // enable auto scan
 * IfxVadc_SetAutoBackgroundScan(vadc, TRUE);
 *
 * // start the background scan
 * IfxVadc_startBackgroundScan(vadc);
 *
 * Ifx_VADC_GLOBRES result;
 * result = IfxVadc_getGlobalResult (vadc);
 *
 * \endcode
 *
 */
IFX_INLINE Ifx_VADC_GLOBRES IfxVadc_getGlobalResult(Ifx_VADC *vadc);

/** \brief get global input class sample time in sec
 * \param vadc Pointer to the VADC Group Register space
 * \param inputClassNum ADC input class number
 * \param analogFrequency ADC module analog frequency in Hz.
 * \return ADC input class channel sample time in sec.
 */
IFX_INLINE float32 IfxVadc_getGlobalSampleTime(Ifx_VADC *vadc, uint8 inputClassNum, float32 analogFrequency);

/** \brief Get conversion result for the group
 * \param group pointer to the VADC group
 * \param results pointer to scaled conversion results
 * \param resultOffset offset for the first result
 * \param numResults number of results
 * \return None
 *
 * \code
 * Ifx_VADC* vadc = &MODULE_VADC
 * Ifx_VADC_G* group = &MODULE_VADC.G[0]; // for group 0
 * uint32 channels = (1 << 5) | (1 << 2); // enable channel #5 and #2
 * uint32 mask = (1 << 7) | (1 << 5) | (1 << 2); // modify the selection for channel #7, #5 and #2; channel #7 will be disabled
 *
 * //confiure wait for read mode for global result register
 * IfxVadc_configureWaitForReadMode(group,IfxVadc_ChannelResult0, TRUE);
 * IfxVadc_configureWaitForReadMode(group,IfxVadc_ChannelResult1, TRUE);
 *
 * // configure scan
 * IfxVadc_setScan(group, channels, mask);
 *
 * // enable auto scan
 * IfxVadc_setAutoScan(group, TRUE);
 *
 * // start the scan
 * IfxVadc_startScan(group);
 *
 * // wait for conversion to finish
 *
 * // fetch the 2 results of conversion for group 0
 * Ifx_VADC_RES results[10];
 * result = IfxVadc_getGroupResult(group, results, 0, 2);
 * \endcode
 *
 */
IFX_INLINE void IfxVadc_getGroupResult(Ifx_VADC_G *group, Ifx_VADC_RES *results, uint32 resultOffset, uint32 numResults);

/** \brief Get conversion result (Function does not care about the alignment)
 * value = raw * gain + offset.
 * \param group pointer to the VADC group
 * \param resultIdx result register index
 * \return scaled Conversion result
 *
 * \code
 * Ifx_VADC_G* group = &MODULE_VADC.G[0]; // for group 0
 * uint32 channels = (1 << 5) | (1 << 2); // enable channel #5 and #2
 * uint32 mask = (1 << 7) | (1 << 5) | (1 << 2); // modify the selection for channel #7, #5 and #2; channel #7 will be disabled
 *
 * //confiure wait for read mode for global result register
 * IfxVadc_configureWaitForReadMode(group,IfxVadc_ChannelResult0, TRUE);
 * IfxVadc_configureWaitForReadMode(group,IfxVadc_ChannelResult1, TRUE);
 *
 * // configure scan
 * IfxVadc_setScan(group, channels, mask);
 *
 * // enable auto scan
 * IfxVadc_setAutoScan(group, TRUE);
 *
 * // start the scan
 * IfxVadc_startScan(group);
 *
 * // wait for conversion to finish
 *
 * // fetch the result of conversion from result register 0 for group 0
 * Ifx_VADC_RES result;
 * result = IfxVadc_getResult(group, IfxVadc_ChannelResult0);
 * \endcode
 *
 */
IFX_INLINE Ifx_VADC_RES IfxVadc_getResult(Ifx_VADC_G *group, uint32 resultIdx);

/** \brief Returns the auto background scan status.
 * \param vadc pointer to the base of VADC registers.
 * \return TRUE if enabled otherwise FALSE.
 */
IFX_INLINE boolean IfxVadc_isAutoBackgroundScanEnabled(Ifx_VADC *vadc);

/** \brief Returns the background scan slot requested status.
 * \param vadcG pointer to VADC group registers.
 * \return background scan slot requested status.
 */
IFX_INLINE boolean IfxVadc_isRequestBackgroundScanSlotEnabled(Ifx_VADC_G *vadcG);

/** \brief Enables/Disables continuous background auto scan
 * \param vadc pointer to the base of VADC registers.
 * \param autoBackgroundScanEnable whether auto background scan enabled or not.
 * \return None
 */
IFX_INLINE void IfxVadc_setAutoBackgroundScan(Ifx_VADC *vadc, boolean autoBackgroundScanEnable);

/** \brief configures a background scan; can also stop autoscan if all channels are 0
 * \param vadc pointer to the VADC module registers
 * \param groupId group index
 * \param channels specifies the channels which should be enabled/disabled
 * \param mask specifies the channels which should be modified
 * \return None
 *
 * Background scan can be enabled/disabled for the given channels which are selected with the mask
 *
 * \code
 * Ifx_VADC* vadc = &MODULE_VADC; // module pointer
 * IfxVadc_GroupId groupId = IfxVadc_GroupId0; // for group 0
 * uint32 channels = (1 << 5) | (1 << 2); // enable channel #5 and #2
 * uint32 mask = (1 << 7) | (1 << 5) | (1 << 2); // modify the selection for channel #7, #5 and #2; channel #7 will be disabled
 *
 * //confiure wait for read mode for global result register
 * IfxVadc_configureWaitForReadModeForGlobalResultRegister(vadc, TRUE);
 *
 * // configure background scan
 * IfxVadc_setBackgroundScan(vadc, groupId, channels, mask);
 *
 * // enable auto scan
 * IfxVadc_setAutoBackgroundScan(vadc, TRUE);
 *
 * // start the background scan
 * IfxVadc_startBackgroundScan(vadc);
 * \endcode
 *
 */
IFX_INLINE void IfxVadc_setBackgroundScan(Ifx_VADC *vadc, IfxVadc_GroupId groupId, uint32 channels, uint32 mask);

/** \brief Sets the background scan slot gating configurations.
 * \param vadc pointer to the base of VADC registers.
 * \param gatingSource gate input for group.
 * \param gatingMode gating mode. High level, Low Level  or Gating disabled.
 * \return None
 */
IFX_INLINE void IfxVadc_setBackgroundScanSlotGatingConfig(Ifx_VADC *vadc, IfxVadc_GatingSource gatingSource, IfxVadc_GatingMode gatingMode);

/** \brief Sets the background scan exteranal trigger operating configurations.
 * \param vadc pointer to the base of VADC registers.
 * \param triggerMode trigger mode. Rising, falling any edge leads to an trigger event.
 * \param triggerSource trigger input for group.
 * \return None
 */
IFX_INLINE void IfxVadc_setBackgroundScanSlotTriggerConfig(Ifx_VADC *vadc, IfxVadc_TriggerMode triggerMode, IfxVadc_TriggerSource triggerSource);

/** \brief Starts a background scan
 * \param vadc pointer to the VADC module
 * \return None
 *
 * \see IfxVadc_setBackgroundScan
 *
 */
IFX_INLINE void IfxVadc_startBackgroundScan(Ifx_VADC *vadc);

/** \brief Get debug conversion result
 * \param group pointer to the VADC group
 * \param resultIdx result register index
 * \return Debug conversion result.
 */
IFX_INLINE Ifx_VADC_RESD IfxVadc_getDebugResult(Ifx_VADC_G *group, uint32 resultIdx);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Gives the background scan status for a group
 * \param vadc pointer to the VADC module
 * \return IfxVadc_Status
 */
IFX_EXTERN IfxVadc_Status IfxVadc_getBackgroundScanStatus(Ifx_VADC *vadc);

/** \brief Get conversion result (Function does not care about the alignment)
 * value = raw * gain + offset.
 * \param vadc VADC module pointer
 * \param group pointer to the VADC group
 * \param channel channel Id
 * \param sourceType type of request source
 * \return scaled Conversion result
 *
 * \code
 * Ifx_VADC vadc;
 * vadc.vadc = &MODULE_VADC;
 * Ifx_VADC_G* group = &MODULE_VADC.G[0]; // for group 0
 * uint32 channels = (1 << 5) | (1 << 2); // enable channel #5 and #2
 * uint32 mask = (1 << 7) | (1 << 5) | (1 << 2); // modify the selection for channel #7, #5 and #2; channel #7 will be disabled
 *
 * //confiure wait for read mode for global result register
 * IfxVadc_configureWaitForReadMode(group,IfxVadc_ChannelResult0, TRUE);
 * IfxVadc_configureWaitForReadMode(group,IfxVadc_ChannelResult1, TRUE);
 *
 * // configure scan
 * IfxVadc_setScan(group, channels, mask);
 *
 * // start the scan
 * IfxVadc_startScan(group);
 *
 * // wait for conversion to finish
 *
 * // fetch the result of conversion for channel 2 of group 0
 * Ifx_VADC_RESresult2;
 * result = IfxVadc_getResultBasedOnRequestSource(&vadc, group, IfxVadc_ChannelId2, IfxVadc_RequestSource_scan);
 * Ifx_VADC_RESresult5;
 * result = IfxVadc_getResultBasedOnRequestSource(&vadc, group, IfxVadc_ChannelId5, IfxVadc_RequestSource_scan);
 * \endcode
 *
 */
IFX_EXTERN Ifx_VADC_RES IfxVadc_getResultBasedOnRequestSource(Ifx_VADC *vadc, Ifx_VADC_G *group, IfxVadc_ChannelId channel, IfxVadc_RequestSource sourceType);

/** \} */

/** \addtogroup IfxLld_Vadc_Std_ChannelScan
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Disables the scan slot external trigger.
 * \param vadcG pointer to VADC group registers.
 * \return None
 */
IFX_INLINE void IfxVadc_disableScanSlotExternalTrigger(Ifx_VADC_G *vadcG);

/** \brief Enables the scan slot external trigger.
 * \param vadcG pointer to VADC group registers.
 * \return None
 */
IFX_INLINE void IfxVadc_enableScanSlotExternalTrigger(Ifx_VADC_G *vadcG);

/** \brief Gets the request scan slot gating mode.
 * \param vadcG pointer to VADC group registers.
 * \return requested scan slot gating mode.
 */
IFX_INLINE IfxVadc_GatingMode IfxVadc_getScanSlotGatingMode(Ifx_VADC_G *vadcG);

/** \brief Gets the request scan slot gating input.
 * \param vadcG pointer to VADC group registers.
 * \return request scan slot gating input.
 */
IFX_INLINE IfxVadc_GatingSource IfxVadc_getScanSlotGatingSource(Ifx_VADC_G *vadcG);

/** \brief Gets the request scan slot priority.
 * \param vadcG pointer to VADC group registers.
 * \return request scan slot priority.
 */
IFX_INLINE IfxVadc_RequestSlotPriority IfxVadc_getScanSlotPriority(Ifx_VADC_G *vadcG);

/** \brief Gets the request scan slot start mode.
 * \param vadcG pointer to VADC group registers.
 * \return request scan slot start mode.
 */
IFX_INLINE IfxVadc_RequestSlotStartMode IfxVadc_getScanSlotStartMode(Ifx_VADC_G *vadcG);

/** \brief Gets the requested scan slot trigger input.
 * \param vadcG pointer to VADC group registers.
 * \return requested scan slot trigger input.
 */
IFX_INLINE IfxVadc_TriggerSource IfxVadc_getScanSlotTriggerInput(Ifx_VADC_G *vadcG);

/** \brief Gets the requested scan slot trigger mode.
 * \param vadcG pointer to VADC group registers.
 * \return requested scan slot trigger mode.
 */
IFX_INLINE IfxVadc_TriggerMode IfxVadc_getScanSlotTriggerMode(Ifx_VADC_G *vadcG);

/** \brief Gets the auto scan enable status.
 * \param vadcG pointer to VADC group registers.
 * \return TRUE if auto scan enabled otherwise FALSE.
 */
IFX_INLINE boolean IfxVadc_isAutoScanEnabled(Ifx_VADC_G *vadcG);

/** \brief Returns the scan slot requested status.
 * \param vadcG pointer to VADC group registers.
 * \return TRUE if scan slot request enabled otherwise FALSE.
 */
IFX_INLINE boolean IfxVadc_isRequestScanSlotEnabled(Ifx_VADC_G *vadcG);

/** \brief Enables/Disables continuous auto scan
 * \param vadcG pointer to VADC group registers.
 * \param autoscanEnable whether autoscan is enabled or not.
 * \return None
 */
IFX_INLINE void IfxVadc_setAutoScan(Ifx_VADC_G *vadcG, boolean autoscanEnable);

/** \brief Sets the scan slot gating configuration.
 * \param vadcG pointer to VADC group registers.
 * \param gatingSource gate input for group.
 * \param gatingMode gating mode. High level, Low Level  or Gating disabled.
 * \return None
 */
IFX_INLINE void IfxVadc_setScanSlotGatingConfig(Ifx_VADC_G *vadcG, IfxVadc_GatingSource gatingSource, IfxVadc_GatingMode gatingMode);

/** \brief Sets the scan slot trigger operating configurations.
 * \param vadcG pointer to VADC group registers.
 * \param triggerMode trigger mode. Rising, falling any edge leads to an trigger event.
 * \param triggerSource trigger input for group.
 * \return None
 */
IFX_INLINE void IfxVadc_setScanSlotTriggerConfig(Ifx_VADC_G *vadcG, IfxVadc_TriggerMode triggerMode, IfxVadc_TriggerSource triggerSource);

/** \brief Starts an autoscan on the specified group
 * \param group pointer to the VADC group
 * \return None
 *
 * See \ref IfxVadc_setScan
 *
 */
IFX_INLINE void IfxVadc_startScan(Ifx_VADC_G *group);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Gives the scan status for a group
 * \param group pointer to the VADC group
 * \return IfxVadc_Status
 */
IFX_EXTERN IfxVadc_Status IfxVadc_getScanStatus(Ifx_VADC_G *group);

/** \brief Configures an (auto-)scan
 * \param group pointer to the VADC group
 * \param channels specifies the channels which should be enabled/disabled
 * \param mask specifies the channels which should be modified
 * \return None
 *
 * (Auto-)Scan can be enabled/disabled for the given channels which are selected with the mask
 *
 * \code
 * Ifx_VADC_G* group = &MODULE_VADC.G[0]; // for group 0
 * uint32 channels = (1 << 5) | (1 << 2); // enable channel #5 and #2
 * uint32 mask = (1 << 7) | (1 << 5) | (1 << 2); // modify the selection for channel #7, #5 and #2; channel #7 will be disabled
 *
 * // configure scan
 * IfxVadc_setScan(group, channels, mask);
 *
 * // enable Auto-Scan
 * IfxVadc_setAutoScan(group, TRUE);
 *
 * // start the scan
 * IfxVadc_startScan(group);
 * \endcode
 *
 */
IFX_EXTERN void IfxVadc_setScan(Ifx_VADC_G *group, uint32 channels, uint32 mask);

/** \} */

/** \addtogroup IfxLld_Vadc_Std_QueueRequest
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Add an entry to the queue of a group for the specified channel with the following options set:
 * refill incase of aborted conversion
 * source interrupt enable/disable
 * external trigger control of the aborted conversion
 * \param group pointer to the VADC group
 * \param channel specifies channel Id
 * \param options specifies the refill, source interrupt enable/disable and external trigger control selection
 * \return None
 *
 * \code
 *
 * Ifx_VADC_G* group = &MODULE_VADC.G[0]; // for group 0
 * IfxVadc_ChannelId channel = 1; // for channel 1
 * // Add channel 1 to queue of group 0 with the refill turned on
 * IfxVadc_addToQueue(qroup, channel, (1<<IFX_VADC_G_QBUR0_RF_OFF));
 * \endcode
 *
 */
IFX_INLINE void IfxVadc_addToQueue(Ifx_VADC_G *group, IfxVadc_ChannelId channel, uint32 options);

/** \brief Clears all the queue entries including backup stage.
 * \param vadcG pointer to VADC group registers.
 * \param flushQueue Whether queue is cleared or not.
 * \return None
 */
IFX_INLINE void IfxVadc_clearQueue(Ifx_VADC_G *vadcG, boolean flushQueue);

/** \brief Disables the external trigger.
 * \param vadcG pointer to VADC group registers.
 * \return None
 */
IFX_INLINE void IfxVadc_disableQueueSlotExternalTrigger(Ifx_VADC_G *vadcG);

/** \brief Enables the external trigger.
 * \param vadcG pointer to VADC group registers.
 * \return None
 */
IFX_INLINE void IfxVadc_enableQueueSlotExternalTrigger(Ifx_VADC_G *vadcG);

/** \brief Gets the requested queue slot gating mode.
 * \param vadcG pointer to VADC group registers.
 * \return requested queue slot gating mode.
 */
IFX_INLINE IfxVadc_GatingMode IfxVadc_getQueueSlotGatingMode(Ifx_VADC_G *vadcG);

/** \brief Gets the requested queue slot gating input.
 * \param vadcG pointer to VADC group registers.
 * \return requested queue slot gating input.
 */
IFX_INLINE IfxVadc_GatingSource IfxVadc_getQueueSlotGatingSource(Ifx_VADC_G *vadcG);

/** \brief Gets the request queue slot priority.
 * \param vadcG pointer to VADC group registers.
 * \return requested queue slot priority.
 */
IFX_INLINE IfxVadc_RequestSlotPriority IfxVadc_getQueueSlotPriority(Ifx_VADC_G *vadcG);

/** \brief Gets the requested queue slot start mode.
 * \param vadcG pointer to VADC group registers.
 * \return requested queue slot start mode.
 */
IFX_INLINE IfxVadc_RequestSlotStartMode IfxVadc_getQueueSlotStartMode(Ifx_VADC_G *vadcG);

/** \brief Gets the requested queue slot trigger input.
 * \param vadcG pointer to VADC group registers.
 * \return requested queue slot trigger input.
 */
IFX_INLINE IfxVadc_TriggerSource IfxVadc_getQueueSlotTriggerInput(Ifx_VADC_G *vadcG);

/** \brief Gets the requested queue slot trigger mode.
 * \param vadcG pointer to VADC group registers.
 * \return requested queue slot trigger mode.
 */
IFX_INLINE IfxVadc_TriggerMode IfxVadc_getQueueSlotTriggerMode(Ifx_VADC_G *vadcG);

/** \brief Returns the queue slot requested status.
 * \param vadcG pointer to VADC group registers.
 * \return TRUE if queue slot request enabled otherwise FALSE.
 */
IFX_INLINE boolean IfxVadc_isRequestQueueSlotEnabled(Ifx_VADC_G *vadcG);

/** \brief Sets the gating configurations.
 * \param vadcG pointer to VADC group registers.
 * \param gatingSource gate input for group.
 * \param gatingMode gating mode. High level, Low Level  or Gating disabled.
 * \return None
 */
IFX_INLINE void IfxVadc_setQueueSlotGatingConfig(Ifx_VADC_G *vadcG, IfxVadc_GatingSource gatingSource, IfxVadc_GatingMode gatingMode);

/** \brief Sets the trigger operating configurations.
 * \param vadcG pointer to VADC group registers.
 * \param triggerMode trigger mode. Rising, falling any edge leads to an trigger event.
 * \param triggerSource trigger input for group.
 * \return None
 */
IFX_INLINE void IfxVadc_setQueueSlotTriggerOperatingConfig(Ifx_VADC_G *vadcG, IfxVadc_TriggerMode triggerMode, IfxVadc_TriggerSource triggerSource);

/** \brief Starts a queue of a group by generating a trigger event through software
 * \param group pointer to the VADC group
 * \return None
 */
IFX_INLINE void IfxVadc_startQueue(Ifx_VADC_G *group);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Gives the status of the Queue of a group by returning non zero value if the Queue is full
 * \param group pointer to the VADC group
 * \return status of the Queue
 *
 * \code
 * Ifx_VADC_G* group = &MODULE_VADC.G[0]; // for group 0
 * boolean queueFull = (IfxVadc_getQueueStatus(group)==IfxVadc_Status_queueFull)?TRUE:FALSE; // get Queue status for group 0
 * \endcode
 *
 */
IFX_EXTERN IfxVadc_Status IfxVadc_getQueueStatus(Ifx_VADC_G *group);

/** \} */

/** \addtogroup IfxLld_Vadc_Std_IO
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Initializes a EMUX output
 * \param emux the Emux Pin which should be configured
 * \param outputMode the pin output mode which should be configured
 * \param padDriver the pad driver mode which should be configured
 * \return None
 */
IFX_INLINE void IfxVadc_initEmuxPin(const IfxVadc_Emux_Out *emux, IfxPort_OutputMode outputMode, IfxPort_PadDriver padDriver);

/** \brief Initializes a GxBFL output
 * \param gxBfl the GxBFL Pin which should be configured
 * \param outputMode the pin output mode which should be configured
 * \param padDriver the pad driver mode which should be configured
 * \return None
 */
IFX_INLINE void IfxVadc_initGxBflPin(const IfxVadc_GxBfl_Out *gxBfl, IfxPort_OutputMode outputMode, IfxPort_PadDriver padDriver);

/** \} */

/** \addtogroup IfxLld_Vadc_Std_Frequency
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Calculate the time using analog frequency.
 * \param analogFrequency analog frequency in Hz.
 * \param sampleTime sample time in sec.
 * \return sample time in sec.
 */
IFX_INLINE uint32 IfxVadc_calculateSampleTime(float32 analogFrequency, float32 sampleTime);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Returns the configured Fadci VADC analog clock frequency in Hz.
 * \param vadc pointer to the base of VADC registers
 * \return Returns the configured Fadci VADC analog clock frequency in Hz.
 */
IFX_EXTERN float32 IfxVadc_getAdcAnalogFrequency(Ifx_VADC *vadc);

/** \brief Returns the configured Fadcd VADC digital clock frequency in Hz.
 * \param vadc pointer to the base of VADC registers
 * \return Returns the configured Fadcd VADC digital clock frequency in Hz.
 */
IFX_EXTERN float32 IfxVadc_getAdcDigitalFrequency(Ifx_VADC *vadc);

/** \} */

/** \addtogroup IfxLld_Vadc_Std_Group
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Clears the all group requests.
 * \param vadcG pointer to VADC group registers.
 * \return None
 */
IFX_INLINE void IfxVadc_clearAllResultRequests(Ifx_VADC_G *vadcG);

/** \brief Gets the ADC group arbitration round length.
 * \param vadcG pointer to VADC group registers.
 * \return ADC group arbitration round length.
 */
IFX_INLINE IfxVadc_ArbitrationRounds IfxVadc_getArbiterRoundLength(Ifx_VADC_G *vadcG);

/** \brief Gets the channel esult service request node pointer 0.
 * \param vadcG pointer to VADC group registers.
 * \return channel result service request node pointer 0.
 */
IFX_INLINE Ifx_VADC_G_REVNP0 IfxVadc_getChannelResultServiceRequestNodePointer0(Ifx_VADC_G *vadcG);

/** \brief Gets the channel esult service request node pointer 1.
 * \param vadcG pointer to VADC group registers.
 * \return channel result service request node pointer 1.
 */
IFX_INLINE Ifx_VADC_G_REVNP1 IfxVadc_getChannelResultServiceRequestNodePointer1(Ifx_VADC_G *vadcG);

/** \brief Gets the channel service request node pointer.
 * \param vadcG pointer to VADC group registers.
 * \return channel service request node pointer.
 */
IFX_INLINE Ifx_VADC_G_CEVNP0 IfxVadc_getChannelServiceRequestNodePointer0(Ifx_VADC_G *vadcG);

/** \brief Gets the configured master index.
 * \param vadcG pointer to VADC group registers.
 * \return configured master kernel index.
 */
IFX_INLINE uint8 IfxVadc_getMasterIndex(Ifx_VADC_G *vadcG);

/** \brief Resets the ADC group.
 * \param vadcG pointer to VADC group registers.
 * \return None
 */
IFX_INLINE void IfxVadc_resetGroup(Ifx_VADC_G *vadcG);

/** \brief Sets analog converter group number.
 * \param vadcG pointer to VADC group registers.
 * \param analogConverterMode group analog converter mode.
 * \return None
 */
IFX_INLINE void IfxVadc_setAnalogConvertControl(Ifx_VADC_G *vadcG, IfxVadc_AnalogConverterMode analogConverterMode);

/** \brief Sets the arbiter round length.
 * \param vadcG pointer to VADC group registers.
 * \param arbiterRoundLength arbiter round length.
 * \return None
 */
IFX_INLINE void IfxVadc_setArbitrationRoundLength(Ifx_VADC_G *vadcG, IfxVadc_ArbitrationRounds arbiterRoundLength);

/** \brief Sets the ADC input class channel resolution.
 * \param vadcG pointer to VADC group registers.
 * \param inputClassNum input class number.
 * \param resolution ADC input class channel resolution.
 * \return None
 */
IFX_INLINE void IfxVadc_setGroupResolution(Ifx_VADC_G *vadcG, uint8 inputClassNum, IfxVadc_ChannelResolution resolution);

/** \brief Sets the ADC input class sample time.
 * \param vadcG pointer to VADC group registers.
 * \param inputClassNum input class number.
 * \param analogFrequency ADC analog frequency in Hz.
 * \param sampleTime request sample time in sec for input class.
 * \return None
 */
IFX_INLINE void IfxVadc_setGroupSampleTime(Ifx_VADC_G *vadcG, uint8 inputClassNum, float32 analogFrequency, float32 sampleTime);

/** \brief Sets the master index.
 * \param vadcG pointer to VADC group registers.
 * \param masterIndex master index.
 * \return None
 */
IFX_INLINE void IfxVadc_setMasterIndex(Ifx_VADC_G *vadcG, uint8 masterIndex);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Sets the Arbiter slot configurations.
 * \param vadcG pointer to VADC group registers.
 * \param slotEnable enable/disable of slot.
 * \param prio channel request priority.
 * \param mode Channel Slot start mode.
 * \param slot channel slot Request source.
 * \return None
 */
IFX_EXTERN void IfxVadc_setArbiterPriority(Ifx_VADC_G *vadcG, boolean slotEnable, IfxVadc_RequestSlotPriority prio, IfxVadc_RequestSlotStartMode mode, IfxVadc_RequestSource slot);

/** \} */

/** \addtogroup IfxLld_Vadc_Std_Module
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Disable VADC Module
 * \param vadc Pointer to VADC Module
 * \return None
 */
IFX_INLINE void IfxVadc_disableModule(Ifx_VADC *vadc);

/** \brief Enable VADC kernel.
 * \param vadc pointer to the base of VADC registers.
 * \return None
 */
IFX_INLINE void IfxVadc_enableModule(Ifx_VADC *vadc);

/** \brief gets ADC Calibration Flag CAL status.
 * \param vadc pointer to VADC group registers.
 * \param adcCalGroupNum ADC CAL group number.
 * \return CAL group status.
 */
IFX_INLINE uint8 IfxVadc_getAdcCalibrationActiveState(Ifx_VADC *vadc, uint8 adcCalGroupNum);

/** \brief Gets the global control configuration value.
 * \param vadc pointer to the base of VADC registers.
 * \return global control configuration value.
 */
IFX_INLINE Ifx_VADC_GLOBCFG IfxVadc_getGlobalConfigValue(Ifx_VADC *vadc);

/** \brief get SUCAL bit field status
 * \param vadc Pointer to VADC Module
 * \return Indicate the start-up calibration phase
 */
IFX_INLINE boolean IfxVadc_getStartupCalibration(Ifx_VADC *vadc);

/** \brief initiates the calibration pulse phase.
 * \param vadc pointer to the base of VADC registers
 * \return None
 */
IFX_INLINE void IfxVadc_initiateStartupCalibration(Ifx_VADC *vadc);

/** \brief Sets the channel conversion mode.
 * \param vadc pointer to VADC module registers.
 * \param inputClassNum global input class  number.
 * \param resolution ADC channel resolution.
 * \return None
 */
IFX_INLINE void IfxVadc_setGlobalResolution(Ifx_VADC *vadc, uint8 inputClassNum, IfxVadc_ChannelResolution resolution);

/** \brief Sets the sample time of ADC global class.
 * \param vadc pointer to VADC module registers.
 * \param inputClassNum global input class  number.
 * \param analogFrequency ADC analog frequency in Hz.
 * \param sampleTime the requested sample time for input class in sec.
 * \return None
 */
IFX_INLINE void IfxVadc_setGlobalSampleTime(Ifx_VADC *vadc, uint8 inputClassNum, float32 analogFrequency, float32 sampleTime);

/** \brief Sets the sensitivity of the module to sleep signal
 * \param vadc pointer to VADC registers
 * \param mode mode selection (enable/disable)
 * \return None
 */
IFX_INLINE void IfxVadc_setSleepMode(Ifx_VADC *vadc, IfxVadc_SleepMode mode);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Disable write access to the VADC config/control registers.
 * \param vadc pointer to the base of VADC registers.
 * \param protectionSet Index of the bit in the ACCPROTx {x=0/1} for which write access is to be disabled.
 * \return None
 */
IFX_EXTERN void IfxVadc_disableAccess(Ifx_VADC *vadc, IfxVadc_Protection protectionSet);

/** \brief Disables the post calibration.
 * \param vadc pointer to the base of VADC registers.
 * \param group Index of the group.
 * \param disable disable or not.
 * \return None
 */
IFX_EXTERN void IfxVadc_disablePostCalibration(Ifx_VADC *vadc, IfxVadc_GroupId group, boolean disable);

/** \brief Enable write access to the VADC config/control registers.
 * \param vadc pointer to the base of VADC registers.
 * \param protectionSet Index of the bit in the ACCPROTx {x=0/1} for which write access is to be enabled.
 * \return None
 */
IFX_EXTERN void IfxVadc_enableAccess(Ifx_VADC *vadc, IfxVadc_Protection protectionSet);

/** \brief Enables the CCU6 based ADC group synchronisation as workaround for Erratum ADC_TC.068
 * \param vadc pointer to the base of VADC registers.
 * \param ccu6Num selects CCU60 or CCU61
 * \return None
 */
IFX_EXTERN void IfxVadc_enableGroupSync(Ifx_VADC *vadc, uint32 ccu6Num);

/** \brief Module Frequency in Hz
 * \return Module Frequency in Hz.
 */
IFX_EXTERN float32 IfxVadc_getAdcModuleFrequency(void);

/** \brief Gives the SRC source address.
 * \param group Index of the group
 * \param index SRC number
 * \return SRC source address
 */
IFX_EXTERN volatile Ifx_SRC_SRCR *IfxVadc_getSrcAddress(IfxVadc_GroupId group, IfxVadc_SrcNr index);

/** \brief Initialises ADC arbiter clock.
 * \param vadc pointer to the base of VADC registers
 * \param arbiterClockDivider ADC arbiter clock divider.
 * \return None
 */
IFX_EXTERN void IfxVadc_initialiseAdcArbiterClock(Ifx_VADC *vadc, uint32 arbiterClockDivider);

/** \brief Initialises the ADC Converter clock.
 * \param vadc pointer to the base of VADC registers
 * \param converterClockDivider ADC converter clock divider.
 * \return None
 */
IFX_EXTERN void IfxVadc_initialiseAdcConverterClock(Ifx_VADC *vadc, uint32 converterClockDivider);

/** \brief Configure the FadcD vadc digital clock.
 * \param vadc pointer to the base of VADC registers.
 * \param fAdcD ADC digital clock frequency in Hz.
 * \return calculated ADC digital clock frequency in Hz.
 */
IFX_EXTERN uint32 IfxVadc_initializeFAdcD(Ifx_VADC *vadc, uint32 fAdcD);

/** \brief Configure the ADC analog clock.
 * \param vadc pointer to the base of VADC registers.
 * \param fAdcI ADC analog clock clock frequency in Hz. Range = [5000000, 10000000].
 * \return ADC analog clock frequency in Hz.
 */
IFX_EXTERN uint32 IfxVadc_initializeFAdcI(Ifx_VADC *vadc, uint32 fAdcI);

/** \brief Return the post calibration status
 * \param vadc Pointer to VADC module
 * \param group specifies Group ID
 * \return TRUE if the post calibration is enabled for the group else false
 */
IFX_EXTERN boolean IfxVadc_isPostCalibration(Ifx_VADC *vadc, IfxVadc_GroupId group);

/** \brief Resets the kernel.
 * \param vadc pointer to the base of VADC registers.
 * \return None
 */
IFX_EXTERN void IfxVadc_resetKernel(Ifx_VADC *vadc);

/** \brief Select Low Power Supply Voltage
 * \param vadc Pointer to Module space
 * \param supplyVoltage Select Supply Voltage
 * \return None
 */
IFX_EXTERN void IfxVadc_selectPowerSupplyVoltage(Ifx_VADC *vadc, IfxVadc_LowSupplyVoltageSelect supplyVoltage);

/** \brief Starts ADC calibration and wait for the end of the calibration process.
 * \param vadc pointer to the base of VADC registers.
 * \return None
 */
IFX_EXTERN void IfxVadc_startupCalibration(Ifx_VADC *vadc);

/** \} */

/** \addtogroup IfxLld_Vadc_Std_Channel
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Clears the channel request.
 * \param vadcG pointer to VADC group registers.
 * \param channelId channel id whose request to be cleared.
 * \return None
 */
IFX_INLINE void IfxVadc_clearChannelRequest(Ifx_VADC_G *vadcG, IfxVadc_ChannelId channelId);

/** \brief Enables the FIFO mode.
 * \param vadcG pointer to VADC group registers.
 * \param resultRegister channel result register.
 * \param fifoMode FIFO mode .
 * \return None
 */
IFX_INLINE void IfxVadc_enableFifoMode(Ifx_VADC_G *vadcG, IfxVadc_ChannelResult resultRegister, IfxVadc_FifoMode fifoMode);

/**
 * \param vadcG pointer to VADC group registers.
 * \param resultRegister channel result register.
 * \return None
 */
IFX_INLINE void IfxVadc_enableServiceRequest(Ifx_VADC_G *vadcG, IfxVadc_ChannelResult resultRegister);

/** \brief Gets the group's assigned channels.
 * \param vadcG pointer to VADC group registers.
 * \return group's assigned channels.
 */
IFX_INLINE Ifx_VADC_G_CHASS IfxVadc_getAssignedChannels(Ifx_VADC_G *vadcG);

/** \brief Gets the current ADC channel control configurations.
 * \param vadcG pointer to VADC group registers.
 * \param channelIndex ADC channel number.
 * \return current ADC channel control configuration.
 */
IFX_INLINE Ifx_VADC_CHCTR IfxVadc_getChannelControlConfig(Ifx_VADC_G *vadcG, IfxVadc_ChannelId channelIndex);

/** \brief Gets the channel input class
 * \param vadcG pointer to VADC Group register space
 * \param channelIndex specifies channel ID
 * \return Input class
 */
IFX_INLINE IfxVadc_InputClasses IfxVadc_getChannelInputClass(Ifx_VADC_G *vadcG, IfxVadc_ChannelId channelIndex);

/** \brief Gets the ADC input class channel resolution.
 * \param vadcG pointer to VADC group registers.
 * \param inputClassNum ADC input class number.
 * \return ADC input class channel resolution.
 */
IFX_INLINE IfxVadc_ChannelResolution IfxVadc_getGroupResolution(Ifx_VADC_G *vadcG, uint8 inputClassNum);

/** \brief Gets the ADC input class channel sample time.
 * \param vadcG pointer to VADC group registers.
 * \param inputClassNum ADC input class number.
 * \param analogFrequency ADC module analog frequency in Hz.
 * \return ADC input class channel sample time in sec.
 */
IFX_INLINE float32 IfxVadc_getGroupSampleTime(Ifx_VADC_G *vadcG, uint8 inputClassNum, float32 analogFrequency);

/** \brief Sets the channels with low priority as background channel.
 * \param vadcG pointer to VADC group registers.
 * \param channelIndex group channel id.
 * \return None
 */
IFX_INLINE void IfxVadc_setBackgroundPriorityChannel(Ifx_VADC_G *vadcG, IfxVadc_ChannelId channelIndex);

/** \brief Sets the target for result background source.
 * \param vadcG pointer to VADC group registers.
 * \param channelIndex group channel id.
 * \param globalResultUsage whether storage in global result register.
 * \return None
 */
IFX_INLINE void IfxVadc_setBackgroundResultTarget(Ifx_VADC_G *vadcG, IfxVadc_ChannelId channelIndex, boolean globalResultUsage);

/** \brief Selects boundary extension.
 * \param vadcG pointer to VADC group registers.
 * \param channelIndex group channel id.
 * \param boundaryMode boundary extension mode.
 * \return None
 */
IFX_INLINE void IfxVadc_setBoundaryMode(Ifx_VADC_G *vadcG, IfxVadc_ChannelId channelIndex, IfxVadc_BoundaryExtension boundaryMode);

/** \brief Sets the channel event service request line.
 * \param vadcG pointer to VADC group registers.
 * \param channelSrcNr channel event Service Node.
 * \param channel channel number.
 * \return None
 */
IFX_INLINE void IfxVadc_setChannelEventNodePointer0(Ifx_VADC_G *vadcG, IfxVadc_SrcNr channelSrcNr, IfxVadc_ChannelId channel);

/** \brief Sets the channel input class.
 * \param vadcG pointer to VADC group registers.
 * \param channelIndex group channel id.
 * \param inputClass group input class.
 * \return None
 */
IFX_INLINE void IfxVadc_setChannelInputClass(Ifx_VADC_G *vadcG, IfxVadc_ChannelId channelIndex, IfxVadc_InputClasses inputClass);

/** \brief Sets the channel event mode.
 * \param vadcG pointer to VADC group registers.
 * \param channelIndex group channel id.
 * \param limitCheck channel event mode.
 * \return None
 */
IFX_INLINE void IfxVadc_setChannelLimitCheckMode(Ifx_VADC_G *vadcG, IfxVadc_ChannelId channelIndex, IfxVadc_LimitCheck limitCheck);

/** \brief Sets channel as priority channel with in the group.
 * \param vadcG pointer to VADC group registers.
 * \param channelIndex group channel id.
 * \return None
 */
IFX_INLINE void IfxVadc_setGroupPriorityChannel(Ifx_VADC_G *vadcG, IfxVadc_ChannelId channelIndex);

/** \brief Sets group's lower boundary.
 * \param vadcG pointer to VADC group registers.
 * \param channelIndex group channel id.
 * \param lowerBoundary group lower boundary.
 * \return None
 */
IFX_INLINE void IfxVadc_setLowerBoundary(Ifx_VADC_G *vadcG, IfxVadc_ChannelId channelIndex, IfxVadc_BoundarySelection lowerBoundary);

/** \brief Selects the refernce input.
 * \param vadcG pointer to VADC group registers.
 * \param channelIndex group channel id.
 * \param reference reference input.
 * \return None
 */
IFX_INLINE void IfxVadc_setReferenceInput(Ifx_VADC_G *vadcG, IfxVadc_ChannelId channelIndex, IfxVadc_ChannelReference reference);

/** \brief Sets result event node pointer 0.
 * \param vadcG pointer to VADC group registers.
 * \param resultSrcNr channel result event service node.
 * \param resultRegister channel result register.
 * \return None
 */
IFX_INLINE void IfxVadc_setResultNodeEventPointer0(Ifx_VADC_G *vadcG, IfxVadc_SrcNr resultSrcNr, IfxVadc_ChannelResult resultRegister);

/** \brief Sets result event node pointer 1.
 * \param vadcG pointer to VADC group registers.
 * \param resultSrcNr channel result event service node.
 * \param resultRegister channel result register.
 * \return None
 */
IFX_INLINE void IfxVadc_setResultNodeEventPointer1(Ifx_VADC_G *vadcG, IfxVadc_SrcNr resultSrcNr, IfxVadc_ChannelResult resultRegister);

/** \brief Sets result store position.
 * \param vadcG pointer to VADC group registers.
 * \param channelIndex group channel id.
 * \param rightAlignedStorage result store position.
 * \return None
 */
IFX_INLINE void IfxVadc_setResultPosition(Ifx_VADC_G *vadcG, IfxVadc_ChannelId channelIndex, boolean rightAlignedStorage);

/** \brief Sets channel synchronization request.
 * \param vadcG pointer to VADC group registers.
 * \param channelIndex group channel id.
 * \param synchonize whether channel synchronize or stand alone operation.
 * \return None
 */
IFX_INLINE void IfxVadc_setSyncRequest(Ifx_VADC_G *vadcG, IfxVadc_ChannelId channelIndex, boolean synchonize);

/** \brief Sets group's upper boundary.
 * \param vadcG pointer to VADC group registers.
 * \param channelIndex group channel id.
 * \param upperBoundary group upper boundary.
 * \return None
 */
IFX_INLINE void IfxVadc_setUpperBoundary(Ifx_VADC_G *vadcG, IfxVadc_ChannelId channelIndex, IfxVadc_BoundarySelection upperBoundary);

/** \brief Sets the group result register.
 * \param vadcG pointer to VADC group registers.
 * \param channelIndex group channel id.
 * \param resultRegister result register for group result storage.
 * \return None
 */
IFX_INLINE void IfxVadc_storeGroupResult(Ifx_VADC_G *vadcG, IfxVadc_ChannelId channelIndex, IfxVadc_ChannelResult resultRegister);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief get channel conversion timing
 * \param vadc Pointer to VADC module
 * \param group specifies the Group
 * \param inputClass Input class used
 * \param analogFrequency ADC module analog frequency fadci in Hz.
 * \param moduleFrequency ADC module frequency fvadc in Hz.
 * \param conversionMode specifies the conversion mode (Standard conversion mode)
 * \return Channel conversion Time in sec
 */
IFX_EXTERN float32 IfxVadc_getChannelConversionTime(Ifx_VADC *vadc, IfxVadc_GroupId group, IfxVadc_InputClasses inputClass, float32 analogFrequency, float32 moduleFrequency, IfxVadc_ConversionType conversionMode);

/** \} */

/** \addtogroup IfxLld_Vadc_Std_Emux
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief get global input class resolution
 * \param vadc Pointer to VADC Module space
 * \param inputClassNum global input class number
 * \return External channel resolution for global input class
 */
IFX_INLINE IfxVadc_ChannelResolution IfxVadc_getEmuxGlobalResolution(Ifx_VADC *vadc, uint8 inputClassNum);

/** \brief Get the sample time of ADC global class for external channel.
 * \param vadc pointer to VADC Module space
 * \param inputClassNum Adc input class number
 * \param analogFrequency ADC module analog frequency in Hz.
 * \return ADC input class external channel sample time in sec.
 */
IFX_INLINE float32 IfxVadc_getEmuxGlobalSampleTime(Ifx_VADC *vadc, uint8 inputClassNum, float32 analogFrequency);

/** \brief get the external channel resolution
 * \param vadcG Pointer to VADC group register space
 * \param inputClassNum Adc input class number
 * \return Adc input class External channel resolution
 */
IFX_INLINE IfxVadc_ChannelResolution IfxVadc_getEmuxGroupResolution(Ifx_VADC_G *vadcG, uint8 inputClassNum);

/** \brief Gets the ADC input class sample time of external channel.
 * \param vadcG Pointer to Register Group space
 * \param inputClassNum ADC input class number
 * \param analogFrequency ADC module analog frequency in Hz.
 * \return ADC input class external channel sample time in sec.
 */
IFX_INLINE float32 IfxVadc_getEmuxGroupSampleTime(Ifx_VADC_G *vadcG, uint8 inputClassNum, float32 analogFrequency);

/** \brief set the external channel resolution of Global class
 * \param vadc pointer to VADC Module space
 * \param inputClassNum Global Input Class Number
 * \param resolution External Channel resolution
 * \return None
 */
IFX_INLINE void IfxVadc_setEmuxGlobalResolution(Ifx_VADC *vadc, uint8 inputClassNum, IfxVadc_ChannelResolution resolution);

/** \brief Sets the sample time of ADC global class for external channel.
 * \param vadc Pointer to VADC Module space
 * \param inputClassNum Adc input class number
 * \param analogFrequency ADC analog Frequency in HZ
 * \param sampleTime the requested sample time for input class in sec
 * \return None
 */
IFX_INLINE void IfxVadc_setEmuxGlobalSampleTime(Ifx_VADC *vadc, uint8 inputClassNum, float32 analogFrequency, float32 sampleTime);

/** \brief set the external channel resolution of ADC input class
 * \param vadcG pointer to VADC Group Register space
 * \param inputClassNum input class number
 * \param resolution input class external channel resolution
 * \return None
 */
IFX_INLINE void IfxVadc_setEmuxGroupResolution(Ifx_VADC_G *vadcG, uint8 inputClassNum, IfxVadc_ChannelResolution resolution);

/** \brief Sets the ADC input class sample time for external channel.
 * \param vadcG Pointer to VADC Group Register Space
 * \param inputClassNum input class number
 * \param analogFrequency ADC analog frequency in Hz.
 * \param sampleTime request sample time in sec for input class.
 * \return None
 */
IFX_INLINE void IfxVadc_setEmuxGroupSampletime(Ifx_VADC_G *vadcG, uint8 inputClassNum, float32 analogFrequency, float32 sampleTime);

/** \brief Sets the Emux Interface for a particular group
 * \param vadc Pointer to VADC Module Space
 * \param emuxInterface specifies the EmuxInterface
 * \param group specifies the group ID
 * \return None
 */
IFX_INLINE void IfxVadc_setEmuxInterfaceForGroup(Ifx_VADC *vadc, IfxVadc_EmuxInterface emuxInterface, IfxVadc_GroupId group);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/**
 * \param vadc pointer to Module space
 * \param vadcG Pointer to VADC group register space
 * \param mode External Multiplexer mode
 * \param channels Specifies channel Id
 * \param startChannel specifies the external channel value from which conversion to be carried out
 * \param code Output the channel number in binary code/gray code
 * \param sampleTimeControl specifies when to use a sample time for external channel
 * \param channelSelectionStyle External Multiplexer Channel Selection Style
 * \return None
 */
IFX_EXTERN void IfxVadc_configExternalMultiplexerMode(Ifx_VADC *vadc, Ifx_VADC_G *vadcG, IfxVadc_ExternalMultiplexerMode mode, uint8 channels, IfxVadc_EmuxSelectValue startChannel, IfxVadc_EmuxCodingScheme code, IfxVadc_EmuxSampleTimeControl sampleTimeControl, IfxVadc_ChannelSelectionStyle channelSelectionStyle);

/** \} */

/******************************************************************************/
/*---------------------Inline Function Implementations------------------------*/
/******************************************************************************/

IFX_INLINE void IfxVadc_addToQueue(Ifx_VADC_G *group, IfxVadc_ChannelId channel, uint32 options)
{
    group->QINR0.U = channel | options;
}


IFX_INLINE uint32 IfxVadc_calculateSampleTime(float32 analogFrequency, float32 sampleTime)
{
    uint32 ticks;

    ticks = (uint32)(sampleTime * analogFrequency) - 2;

    if (ticks > 31)
    {
        ticks = (ticks / 16) + 15;
    }

    ticks = __minu(ticks, 0xFFu);

    return ticks;
}


IFX_INLINE void IfxVadc_clearAllResultRequests(Ifx_VADC_G *vadcG)
{
    vadcG->REFCLR.U = 0x0000FFFFu;
}


IFX_INLINE void IfxVadc_clearChannelRequest(Ifx_VADC_G *vadcG, IfxVadc_ChannelId channelId)
{
    vadcG->CEFCLR.U = 1 << channelId;
}


IFX_INLINE void IfxVadc_clearQueue(Ifx_VADC_G *vadcG, boolean flushQueue)
{
    vadcG->QMR0.B.FLUSH = flushQueue;
}


IFX_INLINE void IfxVadc_configureWaitForReadMode(Ifx_VADC_G *group, uint32 resultIdx, boolean waitForRead)
{
    group->RCR[resultIdx].B.WFR = waitForRead;
}


IFX_INLINE void IfxVadc_configureWaitForReadModeForGlobalResultRegister(Ifx_VADC *vadc, boolean waitForRead)
{
    vadc->GLOBRCR.B.WFR = waitForRead;
}


IFX_INLINE void IfxVadc_disableModule(Ifx_VADC *vadc)
{
    uint16 passwd = IfxScuWdt_getCpuWatchdogPassword();
    IfxScuWdt_clearCpuEndinit(passwd);
    vadc->CLC.B.DISR = 1;
    IfxScuWdt_setCpuEndinit(passwd);
}


IFX_INLINE void IfxVadc_disableQueueSlotExternalTrigger(Ifx_VADC_G *vadcG)
{
    vadcG->QMR0.B.ENTR = 0; /* disable external trigger */
}


IFX_INLINE void IfxVadc_disableScanSlotExternalTrigger(Ifx_VADC_G *vadcG)
{
    vadcG->ASMR.B.ENTR = 0; /* disable external trigger */
}


IFX_INLINE void IfxVadc_enableBackgroundScanSlotExternalTrigger(Ifx_VADC *vadc)
{
    vadc->BRSMR.B.ENTR = 1; /* enable external trigger */
}


IFX_INLINE void IfxVadc_enableFifoMode(Ifx_VADC_G *vadcG, IfxVadc_ChannelResult resultRegister, IfxVadc_FifoMode fifoMode)
{
    vadcG->RCR[resultRegister].B.FEN = fifoMode;
}


IFX_INLINE void IfxVadc_enableModule(Ifx_VADC *vadc)
{
    uint16 passwd = IfxScuWdt_getCpuWatchdogPassword();

    IfxScuWdt_clearCpuEndinit(passwd);
    vadc->CLC.U = 0x00000000;
    IfxScuWdt_setCpuEndinit(passwd);
}


IFX_INLINE void IfxVadc_enableQueueSlotExternalTrigger(Ifx_VADC_G *vadcG)
{
    vadcG->QMR0.B.ENTR = 1;     /* enable external trigger */
}


IFX_INLINE void IfxVadc_enableScanSlotExternalTrigger(Ifx_VADC_G *vadcG)
{
    vadcG->ASMR.B.ENTR = 1; /* enable external trigger */
}


IFX_INLINE void IfxVadc_enableServiceRequest(Ifx_VADC_G *vadcG, IfxVadc_ChannelResult resultRegister)
{
    vadcG->RCR[resultRegister].B.SRGEN = 1;
}


IFX_INLINE uint8 IfxVadc_getAdcCalibrationActiveState(Ifx_VADC *vadc, uint8 adcCalGroupNum)
{
    uint8 status;
    status = vadc->G[adcCalGroupNum].ARBCFG.B.CAL;
    return status;
}


IFX_INLINE IfxVadc_ArbitrationRounds IfxVadc_getArbiterRoundLength(Ifx_VADC_G *vadcG)
{
    return (IfxVadc_ArbitrationRounds)vadcG->ARBCFG.B.ARBRND;
}


IFX_INLINE Ifx_VADC_G_CHASS IfxVadc_getAssignedChannels(Ifx_VADC_G *vadcG)
{
    Ifx_VADC_G_CHASS assignChannels;
    assignChannels.U = vadcG->CHASS.U;
    return assignChannels;
}


IFX_INLINE IfxVadc_GatingMode IfxVadc_getBackgroundScanGatingMode(Ifx_VADC *vadc)
{
    return (IfxVadc_GatingMode)vadc->BRSMR.B.ENGT;
}


IFX_INLINE IfxVadc_GatingSource IfxVadc_getBackgroundScanGatingSource(Ifx_VADC *vadc)
{
    return (IfxVadc_GatingSource)vadc->BRSCTRL.B.GTSEL;
}


IFX_INLINE IfxVadc_RequestSlotPriority IfxVadc_getBackgroundScanSlotPriority(Ifx_VADC_G *vadcG)
{
    return (IfxVadc_RequestSlotPriority)vadcG->ARBPR.B.PRIO2;
}


IFX_INLINE IfxVadc_RequestSlotStartMode IfxVadc_getBackgroundScanSlotStartMode(Ifx_VADC_G *vadcG)
{
    return (IfxVadc_RequestSlotStartMode)vadcG->ARBPR.B.CSM2;
}


IFX_INLINE IfxVadc_TriggerSource IfxVadc_getBackgroundScanTriggerInput(Ifx_VADC *vadc)
{
    return (IfxVadc_TriggerSource)vadc->BRSCTRL.B.XTSEL;
}


IFX_INLINE IfxVadc_TriggerMode IfxVadc_getBackgroundScanTriggerMode(Ifx_VADC *vadc)
{
    return (IfxVadc_TriggerMode)vadc->BRSCTRL.B.XTMODE;
}


IFX_INLINE Ifx_VADC_CHCTR IfxVadc_getChannelControlConfig(Ifx_VADC_G *vadcG, IfxVadc_ChannelId channelIndex)
{
    Ifx_VADC_CHCTR tempChctr;
    tempChctr.U = vadcG->CHCTR[channelIndex].U;
    return tempChctr;
}


IFX_INLINE IfxVadc_InputClasses IfxVadc_getChannelInputClass(Ifx_VADC_G *vadcG, IfxVadc_ChannelId channelIndex)
{
    return (IfxVadc_InputClasses)vadcG->CHCTR[channelIndex].B.ICLSEL;
}


IFX_INLINE Ifx_VADC_G_REVNP0 IfxVadc_getChannelResultServiceRequestNodePointer0(Ifx_VADC_G *vadcG)
{
    Ifx_VADC_G_REVNP0 resultServiceRequestNodePtr0;
    resultServiceRequestNodePtr0.U = vadcG->REVNP0.U;
    return resultServiceRequestNodePtr0;
}


IFX_INLINE Ifx_VADC_G_REVNP1 IfxVadc_getChannelResultServiceRequestNodePointer1(Ifx_VADC_G *vadcG)
{
    Ifx_VADC_G_REVNP1 resultServiceRequestNodePtr1;
    resultServiceRequestNodePtr1.U = vadcG->REVNP1.U;
    return resultServiceRequestNodePtr1;
}


IFX_INLINE Ifx_VADC_G_CEVNP0 IfxVadc_getChannelServiceRequestNodePointer0(Ifx_VADC_G *vadcG)
{
    Ifx_VADC_G_CEVNP0 serviceRequestNodePtr;
    serviceRequestNodePtr.U = vadcG->CEVNP0.U;
    return serviceRequestNodePtr;
}


IFX_INLINE IfxVadc_ChannelResolution IfxVadc_getEmuxGlobalResolution(Ifx_VADC *vadc, uint8 inputClassNum)
{
    return (IfxVadc_ChannelResolution)vadc->GLOBICLASS[inputClassNum].B.CME;
}


IFX_INLINE float32 IfxVadc_getEmuxGlobalSampleTime(Ifx_VADC *vadc, uint8 inputClassNum, float32 analogFrequency)
{
    return (float32)(IFXVADC_SAMPLETIME_MIN + vadc->GLOBICLASS[inputClassNum].B.STCE) / analogFrequency;
}


IFX_INLINE IfxVadc_ChannelResolution IfxVadc_getEmuxGroupResolution(Ifx_VADC_G *vadcG, uint8 inputClassNum)
{
    return (IfxVadc_ChannelResolution)vadcG->ICLASS[inputClassNum].B.CME;
}


IFX_INLINE float32 IfxVadc_getEmuxGroupSampleTime(Ifx_VADC_G *vadcG, uint8 inputClassNum, float32 analogFrequency)
{
    return (float32)(IFXVADC_SAMPLETIME_MIN + vadcG->ICLASS[inputClassNum].B.STCE) / analogFrequency;
}


IFX_INLINE Ifx_VADC_GLOBCFG IfxVadc_getGlobalConfigValue(Ifx_VADC *vadc)
{
    Ifx_VADC_GLOBCFG globCfg;
    globCfg.U = vadc->GLOBCFG.U;
    return globCfg;
}


IFX_INLINE IfxVadc_ChannelResolution IfxVadc_getGlobalResolution(Ifx_VADC *vadc, uint8 inputClassNum)
{
    return (IfxVadc_ChannelResolution)vadc->GLOBICLASS[inputClassNum].B.CMS;
}


IFX_INLINE Ifx_VADC_GLOBRES IfxVadc_getGlobalResult(Ifx_VADC *vadc)
{
    Ifx_VADC_GLOBRES tmpGlobalResult;

    tmpGlobalResult.U = vadc->GLOBRES.U;

    return tmpGlobalResult;
}


IFX_INLINE float32 IfxVadc_getGlobalSampleTime(Ifx_VADC *vadc, uint8 inputClassNum, float32 analogFrequency)
{
    uint32 sampleTime = vadc->GLOBICLASS[inputClassNum].B.STCS;

    if (sampleTime > 16)
    {
        sampleTime = (sampleTime - 15) * 16;
    }

    return (float32)(IFXVADC_SAMPLETIME_MIN + sampleTime) / analogFrequency;
}


IFX_INLINE IfxVadc_ChannelResolution IfxVadc_getGroupResolution(Ifx_VADC_G *vadcG, uint8 inputClassNum)
{
    return (IfxVadc_ChannelResolution)vadcG->ICLASS[inputClassNum].B.CMS;
}


IFX_INLINE void IfxVadc_getGroupResult(Ifx_VADC_G *group, Ifx_VADC_RES *results, uint32 resultOffset, uint32 numResults)
{
    uint32 idx;

    for (idx = 0; idx < numResults; idx++)
    {
        results[idx].U = group->RES[resultOffset + idx].U;
    }
}


IFX_INLINE float32 IfxVadc_getGroupSampleTime(Ifx_VADC_G *vadcG, uint8 inputClassNum, float32 analogFrequency)
{
    uint32 sampleTime = vadcG->ICLASS[inputClassNum].B.STCS;

    if (sampleTime > 16)
    {
        sampleTime = (sampleTime - 15) * 16;
    }

    return (float32)(IFXVADC_SAMPLETIME_MIN + sampleTime) / analogFrequency;
}


IFX_INLINE uint8 IfxVadc_getMasterIndex(Ifx_VADC_G *vadcG)
{
    uint8 masterIndex = 0;
    masterIndex = vadcG->SYNCTR.B.STSEL;
    return masterIndex;
}


IFX_INLINE IfxVadc_GatingMode IfxVadc_getQueueSlotGatingMode(Ifx_VADC_G *vadcG)
{
    return (IfxVadc_GatingMode)vadcG->QMR0.B.ENGT;
}


IFX_INLINE IfxVadc_GatingSource IfxVadc_getQueueSlotGatingSource(Ifx_VADC_G *vadcG)
{
    return (IfxVadc_GatingSource)vadcG->QCTRL0.B.GTSEL;
}


IFX_INLINE IfxVadc_RequestSlotPriority IfxVadc_getQueueSlotPriority(Ifx_VADC_G *vadcG)
{
    return (IfxVadc_RequestSlotPriority)vadcG->ARBPR.B.PRIO0;
}


IFX_INLINE IfxVadc_RequestSlotStartMode IfxVadc_getQueueSlotStartMode(Ifx_VADC_G *vadcG)
{
    return (IfxVadc_RequestSlotStartMode)vadcG->ARBPR.B.CSM0;
}


IFX_INLINE IfxVadc_TriggerSource IfxVadc_getQueueSlotTriggerInput(Ifx_VADC_G *vadcG)
{
    return (IfxVadc_TriggerSource)vadcG->QCTRL0.B.XTSEL;
}


IFX_INLINE IfxVadc_TriggerMode IfxVadc_getQueueSlotTriggerMode(Ifx_VADC_G *vadcG)
{
    return (IfxVadc_TriggerMode)vadcG->QCTRL0.B.XTMODE;
}


IFX_INLINE Ifx_VADC_RES IfxVadc_getResult(Ifx_VADC_G *group, uint32 resultIdx)
{
    Ifx_VADC_RES tmpResult;

    tmpResult.U = group->RES[resultIdx].U;

    return tmpResult;
}


IFX_INLINE IfxVadc_GatingMode IfxVadc_getScanSlotGatingMode(Ifx_VADC_G *vadcG)
{
    return (IfxVadc_GatingMode)vadcG->ASMR.B.ENGT;
}


IFX_INLINE IfxVadc_GatingSource IfxVadc_getScanSlotGatingSource(Ifx_VADC_G *vadcG)
{
    return (IfxVadc_GatingSource)vadcG->ASCTRL.B.GTSEL;
}


IFX_INLINE IfxVadc_RequestSlotPriority IfxVadc_getScanSlotPriority(Ifx_VADC_G *vadcG)
{
    return (IfxVadc_RequestSlotPriority)vadcG->ARBPR.B.PRIO1;
}


IFX_INLINE IfxVadc_RequestSlotStartMode IfxVadc_getScanSlotStartMode(Ifx_VADC_G *vadcG)
{
    return (IfxVadc_RequestSlotStartMode)vadcG->ARBPR.B.CSM1;
}


IFX_INLINE IfxVadc_TriggerSource IfxVadc_getScanSlotTriggerInput(Ifx_VADC_G *vadcG)
{
    return (IfxVadc_TriggerSource)vadcG->ASCTRL.B.XTSEL;
}


IFX_INLINE IfxVadc_TriggerMode IfxVadc_getScanSlotTriggerMode(Ifx_VADC_G *vadcG)
{
    return (IfxVadc_TriggerMode)vadcG->ASCTRL.B.XTMODE;
}


IFX_INLINE boolean IfxVadc_getStartupCalibration(Ifx_VADC *vadc)
{
    return (boolean)vadc->GLOBCFG.B.SUCAL;
}


IFX_INLINE void IfxVadc_initEmuxPin(const IfxVadc_Emux_Out *emux, IfxPort_OutputMode outputMode, IfxPort_PadDriver padDriver)
{
    IfxPort_setPinModeOutput(emux->pin.port, emux->pin.pinIndex, outputMode, emux->select);
    IfxPort_setPinPadDriver(emux->pin.port, emux->pin.pinIndex, padDriver);
}


IFX_INLINE void IfxVadc_initGxBflPin(const IfxVadc_GxBfl_Out *gxBfl, IfxPort_OutputMode outputMode, IfxPort_PadDriver padDriver)
{
    IfxPort_setPinModeOutput(gxBfl->pin.port, gxBfl->pin.pinIndex, outputMode, gxBfl->select);
    IfxPort_setPinPadDriver(gxBfl->pin.port, gxBfl->pin.pinIndex, padDriver);
}


IFX_INLINE void IfxVadc_initiateStartupCalibration(Ifx_VADC *vadc)
{
    vadc->GLOBCFG.B.SUCAL = 1;
}


IFX_INLINE boolean IfxVadc_isAutoBackgroundScanEnabled(Ifx_VADC *vadc)
{
    return (boolean)vadc->BRSMR.B.SCAN;
}


IFX_INLINE boolean IfxVadc_isAutoScanEnabled(Ifx_VADC_G *vadcG)
{
    return (boolean)vadcG->ASMR.B.SCAN;
}


IFX_INLINE boolean IfxVadc_isRequestBackgroundScanSlotEnabled(Ifx_VADC_G *vadcG)
{
    return (boolean)vadcG->ARBPR.B.ASEN2;
}


IFX_INLINE boolean IfxVadc_isRequestQueueSlotEnabled(Ifx_VADC_G *vadcG)
{
    return (boolean)vadcG->ARBPR.B.ASEN0;
}


IFX_INLINE boolean IfxVadc_isRequestScanSlotEnabled(Ifx_VADC_G *vadcG)
{
    return (boolean)vadcG->ARBPR.B.ASEN1;
}


IFX_INLINE void IfxVadc_resetGroup(Ifx_VADC_G *vadcG)
{
    vadcG->ARBCFG.B.ANONC = IfxVadc_AnalogConverterMode_off;   /* turn off group */
}


IFX_INLINE void IfxVadc_setAnalogConvertControl(Ifx_VADC_G *vadcG, IfxVadc_AnalogConverterMode analogConverterMode)
{
    vadcG->ARBCFG.B.ANONC = analogConverterMode;
}


IFX_INLINE void IfxVadc_setArbitrationRoundLength(Ifx_VADC_G *vadcG, IfxVadc_ArbitrationRounds arbiterRoundLength)
{
    vadcG->ARBCFG.B.ARBRND = arbiterRoundLength;
}


IFX_INLINE void IfxVadc_setAutoBackgroundScan(Ifx_VADC *vadc, boolean autoBackgroundScanEnable)
{
    vadc->BRSMR.B.SCAN = autoBackgroundScanEnable;
}


IFX_INLINE void IfxVadc_setAutoScan(Ifx_VADC_G *vadcG, boolean autoscanEnable)
{
    vadcG->ASMR.B.SCAN = autoscanEnable;
}


IFX_INLINE void IfxVadc_setBackgroundPriorityChannel(Ifx_VADC_G *vadcG, IfxVadc_ChannelId channelIndex)
{
    vadcG->CHASS.U &= ~(1 << channelIndex);
}


IFX_INLINE void IfxVadc_setBackgroundResultTarget(Ifx_VADC_G *vadcG, IfxVadc_ChannelId channelIndex, boolean globalResultUsage)
{
    vadcG->CHCTR[channelIndex].B.RESTBS = globalResultUsage;
}


IFX_INLINE void IfxVadc_setBackgroundScan(Ifx_VADC *vadc, IfxVadc_GroupId groupId, uint32 channels, uint32 mask)
{
    channels                = (vadc->BRSSEL[groupId].U & ~mask) | channels;
    vadc->BRSSEL[groupId].U = channels;
}


IFX_INLINE void IfxVadc_setBackgroundScanSlotGatingConfig(Ifx_VADC *vadc, IfxVadc_GatingSource gatingSource, IfxVadc_GatingMode gatingMode)
{
    Ifx_VADC_BRSCTRL brsctrl;
    brsctrl.U          = vadc->BRSCTRL.U;
    brsctrl.B.GTWC     = 1;
    brsctrl.B.GTSEL    = gatingSource;
    vadc->BRSCTRL.U    = brsctrl.U;
    vadc->BRSMR.B.ENGT = gatingMode;
}


IFX_INLINE void IfxVadc_setBackgroundScanSlotTriggerConfig(Ifx_VADC *vadc, IfxVadc_TriggerMode triggerMode, IfxVadc_TriggerSource triggerSource)
{
    Ifx_VADC_BRSCTRL brsctrl;
    brsctrl.U        = vadc->BRSCTRL.U;
    brsctrl.B.XTWC   = 1;
    brsctrl.B.XTMODE = triggerMode;
    brsctrl.B.XTSEL  = triggerSource;
    vadc->BRSCTRL.U  = brsctrl.U;
}


IFX_INLINE void IfxVadc_setBoundaryMode(Ifx_VADC_G *vadcG, IfxVadc_ChannelId channelIndex, IfxVadc_BoundaryExtension boundaryMode)
{
    vadcG->CHCTR[channelIndex].B.BNDSELX = boundaryMode;
}


IFX_INLINE void IfxVadc_setChannelEventNodePointer0(Ifx_VADC_G *vadcG, IfxVadc_SrcNr channelSrcNr, IfxVadc_ChannelId channel)
{
    vadcG->CEVNP0.U &= ~(IFX_VADC_G_CEVNP0_CEV0NP_MSK << (channel * 4));
    vadcG->CEVNP0.U |= (channelSrcNr << (channel * 4));
}


IFX_INLINE void IfxVadc_setChannelInputClass(Ifx_VADC_G *vadcG, IfxVadc_ChannelId channelIndex, IfxVadc_InputClasses inputClass)
{
    vadcG->CHCTR[channelIndex].B.ICLSEL = inputClass;
}


IFX_INLINE void IfxVadc_setChannelLimitCheckMode(Ifx_VADC_G *vadcG, IfxVadc_ChannelId channelIndex, IfxVadc_LimitCheck limitCheck)
{
    vadcG->CHCTR[channelIndex].B.CHEVMODE = limitCheck;
}


IFX_INLINE void IfxVadc_setEmuxGlobalResolution(Ifx_VADC *vadc, uint8 inputClassNum, IfxVadc_ChannelResolution resolution)
{
    vadc->GLOBICLASS[inputClassNum].B.CME = resolution;
}


IFX_INLINE void IfxVadc_setEmuxGlobalSampleTime(Ifx_VADC *vadc, uint8 inputClassNum, float32 analogFrequency, float32 sampleTime)
{
    vadc->GLOBICLASS[inputClassNum].B.STCE = IfxVadc_calculateSampleTime(analogFrequency, sampleTime);
}


IFX_INLINE void IfxVadc_setEmuxGroupResolution(Ifx_VADC_G *vadcG, uint8 inputClassNum, IfxVadc_ChannelResolution resolution)
{
    vadcG->ICLASS[inputClassNum].B.CME = resolution;
}


IFX_INLINE void IfxVadc_setEmuxGroupSampletime(Ifx_VADC_G *vadcG, uint8 inputClassNum, float32 analogFrequency, float32 sampleTime)
{
    vadcG->ICLASS[inputClassNum].B.STCE = IfxVadc_calculateSampleTime(analogFrequency, sampleTime);
}


IFX_INLINE void IfxVadc_setEmuxInterfaceForGroup(Ifx_VADC *vadc, IfxVadc_EmuxInterface emuxInterface, IfxVadc_GroupId group)
{
    if (emuxInterface == IfxVadc_EmuxInterface_0)
    {
        vadc->EMUXSEL.B.EMUXGRP0 = group;
    }
    else
    {
        vadc->EMUXSEL.B.EMUXGRP1 = group;
    }
}


IFX_INLINE void IfxVadc_setGlobalResolution(Ifx_VADC *vadc, uint8 inputClassNum, IfxVadc_ChannelResolution resolution)
{
    vadc->GLOBICLASS[inputClassNum].B.CMS = resolution;
}


IFX_INLINE void IfxVadc_setGlobalSampleTime(Ifx_VADC *vadc, uint8 inputClassNum, float32 analogFrequency, float32 sampleTime)
{
    vadc->GLOBICLASS[inputClassNum].B.STCS = IfxVadc_calculateSampleTime(analogFrequency, sampleTime);
}


IFX_INLINE void IfxVadc_setGroupPriorityChannel(Ifx_VADC_G *vadcG, IfxVadc_ChannelId channelIndex)
{
    vadcG->CHASS.U |= (1 << channelIndex);
}


IFX_INLINE void IfxVadc_setGroupResolution(Ifx_VADC_G *vadcG, uint8 inputClassNum, IfxVadc_ChannelResolution resolution)
{
    vadcG->ICLASS[inputClassNum].B.CMS = resolution;
}


IFX_INLINE void IfxVadc_setGroupSampleTime(Ifx_VADC_G *vadcG, uint8 inputClassNum, float32 analogFrequency, float32 sampleTime)
{
    vadcG->ICLASS[inputClassNum].B.STCS = IfxVadc_calculateSampleTime(analogFrequency, sampleTime);
}


IFX_INLINE void IfxVadc_setLowerBoundary(Ifx_VADC_G *vadcG, IfxVadc_ChannelId channelIndex, IfxVadc_BoundarySelection lowerBoundary)
{
    vadcG->CHCTR[channelIndex].B.BNDSELL = lowerBoundary;
}


IFX_INLINE void IfxVadc_setMasterIndex(Ifx_VADC_G *vadcG, uint8 masterIndex)
{
    vadcG->SYNCTR.B.STSEL = (masterIndex % 4);
    vadcG->SYNCTR.U      |= (0x00000008U << (masterIndex % 4));
}


IFX_INLINE void IfxVadc_setQueueSlotGatingConfig(Ifx_VADC_G *vadcG, IfxVadc_GatingSource gatingSource, IfxVadc_GatingMode gatingMode)
{
    Ifx_VADC_G_QCTRL0 qctrl0;
    qctrl0.U           = vadcG->QCTRL0.U;
    qctrl0.B.GTWC      = 1;
    qctrl0.B.GTSEL     = gatingSource;
    vadcG->QCTRL0.U    = qctrl0.U;
    vadcG->QMR0.B.ENGT = gatingMode;
}


IFX_INLINE void IfxVadc_setQueueSlotTriggerOperatingConfig(Ifx_VADC_G *vadcG, IfxVadc_TriggerMode triggerMode, IfxVadc_TriggerSource triggerSource)
{
    Ifx_VADC_G_QCTRL0 qctrl0;
    qctrl0.U        = vadcG->QCTRL0.U;
    qctrl0.B.XTWC   = 1;
    qctrl0.B.XTMODE = triggerMode;
    qctrl0.B.XTSEL  = triggerSource;
    vadcG->QCTRL0.U = qctrl0.U;
}


IFX_INLINE void IfxVadc_setReferenceInput(Ifx_VADC_G *vadcG, IfxVadc_ChannelId channelIndex, IfxVadc_ChannelReference reference)
{
    vadcG->CHCTR[channelIndex].B.REFSEL = reference;
}


IFX_INLINE void IfxVadc_setResultNodeEventPointer0(Ifx_VADC_G *vadcG, IfxVadc_SrcNr resultSrcNr, IfxVadc_ChannelResult resultRegister)
{
    vadcG->REVNP0.U &= ~(IFX_VADC_G_REVNP0_REV0NP_MSK << (resultRegister * 4));
    vadcG->REVNP0.U |= (resultSrcNr << (resultRegister * 4));
}


IFX_INLINE void IfxVadc_setResultNodeEventPointer1(Ifx_VADC_G *vadcG, IfxVadc_SrcNr resultSrcNr, IfxVadc_ChannelResult resultRegister)
{
    vadcG->REVNP1.U &= ~(IFX_VADC_G_REVNP1_REV8NP_MSK << ((resultRegister - IfxVadc_ChannelResult_8) * 4));
    vadcG->REVNP1.U |= (resultSrcNr << ((resultRegister - IfxVadc_ChannelResult_8) * 4));
}


IFX_INLINE void IfxVadc_setResultPosition(Ifx_VADC_G *vadcG, IfxVadc_ChannelId channelIndex, boolean rightAlignedStorage)
{
    vadcG->CHCTR[channelIndex].B.RESPOS = rightAlignedStorage;
}


IFX_INLINE void IfxVadc_setScanSlotGatingConfig(Ifx_VADC_G *vadcG, IfxVadc_GatingSource gatingSource, IfxVadc_GatingMode gatingMode)
{
    Ifx_VADC_G_ASCTRL asctrl;
    asctrl.U           = vadcG->ASCTRL.U;
    asctrl.B.GTWC      = 1;
    asctrl.B.GTSEL     = gatingSource;
    vadcG->ASCTRL.U    = asctrl.U;
    vadcG->ASMR.B.ENGT = gatingMode;
}


IFX_INLINE void IfxVadc_setScanSlotTriggerConfig(Ifx_VADC_G *vadcG, IfxVadc_TriggerMode triggerMode, IfxVadc_TriggerSource triggerSource)
{
    Ifx_VADC_G_ASCTRL asctrl;
    asctrl.U        = vadcG->ASCTRL.U;
    asctrl.B.XTWC   = 1;
    asctrl.B.XTMODE = triggerMode;
    asctrl.B.XTSEL  = triggerSource;
    vadcG->ASCTRL.U = asctrl.U;
}


IFX_INLINE void IfxVadc_setSleepMode(Ifx_VADC *vadc, IfxVadc_SleepMode mode)
{
    uint16 passwd = IfxScuWdt_getCpuWatchdogPassword();
    IfxScuWdt_clearCpuEndinit(passwd);
    vadc->CLC.B.EDIS = mode;
    IfxScuWdt_setCpuEndinit(passwd);
}


IFX_INLINE void IfxVadc_setSyncRequest(Ifx_VADC_G *vadcG, IfxVadc_ChannelId channelIndex, boolean synchonize)
{
    vadcG->CHCTR[channelIndex].B.SYNC = synchonize;
}


IFX_INLINE void IfxVadc_setUpperBoundary(Ifx_VADC_G *vadcG, IfxVadc_ChannelId channelIndex, IfxVadc_BoundarySelection upperBoundary)
{
    vadcG->CHCTR[channelIndex].B.BNDSELU = upperBoundary;
}


IFX_INLINE void IfxVadc_startBackgroundScan(Ifx_VADC *vadc)
{
    vadc->BRSMR.B.LDEV = 1;     /* execute Load event to start the conversion */
}


IFX_INLINE void IfxVadc_startQueue(Ifx_VADC_G *group)
{
    group->QMR0.B.TREV = 1;
}


IFX_INLINE void IfxVadc_startScan(Ifx_VADC_G *group)
{
    group->ASMR.B.LDEV = 1;     /* set Load event. Channels stored in ASSEL will be copied into pending register and conversion will start */
}


IFX_INLINE void IfxVadc_storeGroupResult(Ifx_VADC_G *vadcG, IfxVadc_ChannelId channelIndex, IfxVadc_ChannelResult resultRegister)
{
    vadcG->CHCTR[channelIndex].B.RESREG = resultRegister;
}


IFX_INLINE Ifx_VADC_RESD IfxVadc_getDebugResult(Ifx_VADC_G *group, uint32 resultIdx)
{
    Ifx_VADC_RESD tmpResult;

    tmpResult.U = group->RESD[resultIdx].U;

    return tmpResult;
}


#endif /* IFXVADC_H */
