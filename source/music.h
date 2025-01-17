/*
 * Copyright (c) 2015-2016, Freescale Semiconductor, Inc.
 * Copyright 2016-2017 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef _MUSIC_H_
#define _MUSIC_H_

#if defined(__GNUC__) /* GNU Compiler */
#ifndef __ALIGN_END
#define __ALIGN_END __attribute__((aligned(4)))
#endif
#ifndef __ALIGN_BEGIN
#define __ALIGN_BEGIN
#endif
#else
#ifndef __ALIGN_END
#define __ALIGN_END
#endif
#ifndef __ALIGN_BEGIN
#if defined(__CC_ARM) || defined(__ARMCC_VERSION) /* ARM Compiler */
#define __ALIGN_BEGIN __attribute__((aligned(4)))
#elif defined(__ICCARM__) /* IAR Compiler */
#define __ALIGN_BEGIN
#endif
#endif
#endif

/*!
 * @brief One period of sine wave in 108 32-bit samples.
 * One sample contains two 16-bit channels.
 */
//__ALIGN_BEGIN uint8_t g_Music[] __ALIGN_END = {
//    0x00U, 0x00U, 0x00U, 0x00U, 0x71U, 0x07U, 0x71U, 0x07U, 0xDCU, 0x0EU, 0xDCU, 0x0EU, 0x39U, 0x16U, 0x39U, 0x16U,
//    0x84U, 0x1DU, 0x84U, 0x1DU, 0xB5U, 0x24U, 0xB5U, 0x24U, 0xC6U, 0x2BU, 0xC6U, 0x2BU, 0xB2U, 0x32U, 0xB2U, 0x32U,
//    0x71U, 0x39U, 0x71U, 0x39U, 0xFFU, 0x3FU, 0xFFU, 0x3FU, 0x55U, 0x46U, 0x55U, 0x46U, 0x6FU, 0x4CU, 0x6FU, 0x4CU,
//    0x46U, 0x52U, 0x46U, 0x52U, 0xD6U, 0x57U, 0xD6U, 0x57U, 0x19U, 0x5DU, 0x19U, 0x5DU, 0x0CU, 0x62U, 0x0CU, 0x62U,
//    0xABU, 0x66U, 0xABU, 0x66U, 0xF0U, 0x6AU, 0xF0U, 0x6AU, 0xD9U, 0x6EU, 0xD9U, 0x6EU, 0x61U, 0x72U, 0x61U, 0x72U,
//    0x87U, 0x75U, 0x87U, 0x75U, 0x46U, 0x78U, 0x46U, 0x78U, 0x9EU, 0x7AU, 0x9EU, 0x7AU, 0x8BU, 0x7CU, 0x8BU, 0x7CU,
//    0x0DU, 0x7EU, 0x0DU, 0x7EU, 0x21U, 0x7FU, 0x21U, 0x7FU, 0xC7U, 0x7FU, 0xC7U, 0x7FU, 0xFEU, 0x7FU, 0xFEU, 0x7FU,
//    0xC7U, 0x7FU, 0xC7U, 0x7FU, 0x21U, 0x7FU, 0x21U, 0x7FU, 0x0DU, 0x7EU, 0x0DU, 0x7EU, 0x8BU, 0x7CU, 0x8BU, 0x7CU,
//    0x9EU, 0x7AU, 0x9EU, 0x7AU, 0x46U, 0x78U, 0x46U, 0x78U, 0x87U, 0x75U, 0x87U, 0x75U, 0x61U, 0x72U, 0x61U, 0x72U,
//    0xD9U, 0x6EU, 0xD9U, 0x6EU, 0xF0U, 0x6AU, 0xF0U, 0x6AU, 0xABU, 0x66U, 0xABU, 0x66U, 0x0CU, 0x62U, 0x0CU, 0x62U,
//    0x19U, 0x5DU, 0x19U, 0x5DU, 0xD6U, 0x57U, 0xD6U, 0x57U, 0x46U, 0x52U, 0x46U, 0x52U, 0x6FU, 0x4CU, 0x6FU, 0x4CU,
//    0x55U, 0x46U, 0x55U, 0x46U, 0xFFU, 0x3FU, 0xFFU, 0x3FU, 0x71U, 0x39U, 0x71U, 0x39U, 0xB2U, 0x32U, 0xB2U, 0x32U,
//    0xC6U, 0x2BU, 0xC6U, 0x2BU, 0xB5U, 0x24U, 0xB5U, 0x24U, 0x84U, 0x1DU, 0x84U, 0x1DU, 0x39U, 0x16U, 0x39U, 0x16U,
//    0xDCU, 0x0EU, 0xDCU, 0x0EU, 0x71U, 0x07U, 0x71U, 0x07U, 0x00U, 0x00U, 0x00U, 0x00U, 0x8FU, 0xF8U, 0x8FU, 0xF8U,
//    0x24U, 0xF1U, 0x24U, 0xF1U, 0xC7U, 0xE9U, 0xC7U, 0xE9U, 0x7CU, 0xE2U, 0x7CU, 0xE2U, 0x4BU, 0xDBU, 0x4BU, 0xDBU,
//    0x3AU, 0xD4U, 0x3AU, 0xD4U, 0x4EU, 0xCDU, 0x4EU, 0xCDU, 0x8FU, 0xC6U, 0x8FU, 0xC6U, 0x01U, 0xC0U, 0x01U, 0xC0U,
//    0xABU, 0xB9U, 0xABU, 0xB9U, 0x91U, 0xB3U, 0x91U, 0xB3U, 0xBAU, 0xADU, 0xBAU, 0xADU, 0x2AU, 0xA8U, 0x2AU, 0xA8U,
//    0xE7U, 0xA2U, 0xE7U, 0xA2U, 0xF4U, 0x9DU, 0xF4U, 0x9DU, 0x55U, 0x99U, 0x55U, 0x99U, 0x10U, 0x95U, 0x10U, 0x95U,
//    0x27U, 0x91U, 0x27U, 0x91U, 0x9FU, 0x8DU, 0x9FU, 0x8DU, 0x79U, 0x8AU, 0x79U, 0x8AU, 0xBAU, 0x87U, 0xBAU, 0x87U,
//    0x62U, 0x85U, 0x62U, 0x85U, 0x75U, 0x83U, 0x75U, 0x83U, 0xF3U, 0x81U, 0xF3U, 0x81U, 0xDFU, 0x80U, 0xDFU, 0x80U,
//    0x39U, 0x80U, 0x39U, 0x80U, 0x02U, 0x80U, 0x02U, 0x80U, 0x39U, 0x80U, 0x39U, 0x80U, 0xDFU, 0x80U, 0xDFU, 0x80U,
//    0xF3U, 0x81U, 0xF3U, 0x81U, 0x75U, 0x83U, 0x75U, 0x83U, 0x62U, 0x85U, 0x62U, 0x85U, 0xBAU, 0x87U, 0xBAU, 0x87U,
//    0x79U, 0x8AU, 0x79U, 0x8AU, 0x9FU, 0x8DU, 0x9FU, 0x8DU, 0x27U, 0x91U, 0x27U, 0x91U, 0x10U, 0x95U, 0x10U, 0x95U,
//    0x55U, 0x99U, 0x55U, 0x99U, 0xF4U, 0x9DU, 0xF4U, 0x9DU, 0xE7U, 0xA2U, 0xE7U, 0xA2U, 0x2AU, 0xA8U, 0x2AU, 0xA8U,
//    0xBAU, 0xADU, 0xBAU, 0xADU, 0x91U, 0xB3U, 0x91U, 0xB3U, 0xABU, 0xB9U, 0xABU, 0xB9U, 0x01U, 0xC0U, 0x01U, 0xC0U,
//    0x8FU, 0xC6U, 0x8FU, 0xC6U, 0x4EU, 0xCDU, 0x4EU, 0xCDU, 0x3AU, 0xD4U, 0x3AU, 0xD4U, 0x4BU, 0xDBU, 0x4BU, 0xDBU,
//    0x7CU, 0xE2U, 0x7CU, 0xE2U, 0xC7U, 0xE9U, 0xC7U, 0xE9U, 0x24U, 0xF1U, 0x24U, 0xF1U, 0x8FU, 0xF8U, 0x8FU, 0xF8U,
//};

#endif
