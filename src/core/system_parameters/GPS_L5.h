/*!
 * \file GPS_L5.h
 * \brief  Defines system parameters for GPS L5 signal
 * \author Javier Arribas, 2017. jarribas(at)cttc.es
 *
 * -----------------------------------------------------------------------------
 *
 * GNSS-SDR is a Global Navigation Satellite System software-defined receiver.
 * This file is part of GNSS-SDR.
 *
 * Copyright (C) 2010-2020  (see AUTHORS file for a list of contributors)
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 * -----------------------------------------------------------------------------
 */


#ifndef GNSS_SDR_GPS_L5_H
#define GNSS_SDR_GPS_L5_H

#include "GPS_CNAV.h"
#include "gnss_frequencies.h"
#include <cstdint>

/** \addtogroup Core
 * \{ */
/** \addtogroup System_Parameters
 * \{ */


// carrier and code frequencies
constexpr double GPS_L5_FREQ_HZ = FREQ5;              //!< L5 [Hz]
constexpr double GPS_L5I_CODE_RATE_CPS = 10.23e6;     //!< GPS L5I code rate [chips/s]
constexpr double GPS_L5I_PERIOD_S = 0.001;            //!< GPS L5I code period [seconds]
constexpr double GPS_L5I_SYMBOL_PERIOD_S = 0.01;      //!< GPS L5I symbol period [seconds]
constexpr double GPS_L5Q_CODE_RATE_CPS = 10.23e6;     //!< GPS L5Q code rate [chips/s]
constexpr double GPS_L5Q_PERIOD_S = 0.001;            //!< GPS L5Q code period [seconds]
constexpr int32_t GPS_L5Q_CODE_LENGTH_CHIPS = 10230;  //!< GPS L5Q code length [chips]
constexpr int32_t GPS_L5I_CODE_LENGTH_CHIPS = 10230;  //!< GPS L5I code length [chips]
constexpr int32_t GPS_L5I_PERIOD_MS = 1;              //!< GPS L5I code period [ms]
constexpr int32_t GPS_L5I_SYMBOL_PERIOD_MS = 10;      //!< GPS L5I symbol period [ms]

constexpr int32_t GPS_L5_HISTORY_DEEP = 5;

// optimum parameters
constexpr uint32_t GPS_L5_OPT_ACQ_FS_SPS = 10000000;  //!< Sampling frequency that maximizes the acquisition SNR while using a non-multiple of chip rate

constexpr int32_t GPS_L5I_INIT_REG[210] =
    {266, 365, 804, 1138,
        1509, 1559, 1756, 2084,
        2170, 2303, 2527, 2687,
        2930, 3471, 3940, 4132,
        4332, 4924, 5343, 5443,
        5641, 5816, 5898, 5918,
        5955, 6243, 6345, 6477,
        6518, 6875, 7168, 7187,
        7329, 7577, 7720, 7777,
        8057, 5358, 3550, 3412,
        819,
        4608, 3698, 962, 3001,
        4441, 4937, 3717, 4730,
        7291, 2279, 7613, 5723,
        7030, 1475, 2593, 2904,
        2056, 2757, 3756, 6205,
        5053, 6437,
        7789, 2311, 7432, 5155,
        1593, 5841, 5014, 1545,
        3016, 4875, 2119, 229,
        7634, 1406, 4506, 1819,
        7580, 5446, 6053, 7958,
        5267, 2956, 3544, 1277,
        2996, 1758, 3360, 2718,
        3754, 7440, 2781, 6756,
        7314, 208, 5252, 696,
        527, 1399, 5879, 6868,
        217, 7681, 3788, 1337,
        2424, 4243, 5686, 1955,
        4791, 492, 1518, 6566,
        5349, 506, 113, 1953,
        2797, 934, 3023, 3632,
        1330, 4909, 4867, 1183,
        3990, 6217, 1224, 1733,
        2319, 3928, 2380, 841,
        5049, 7027, 1197, 7208,
        8000, 152, 6762, 3745,
        4723, 5502, 4796, 123,
        8142, 5091, 7875, 330,
        5272, 4912, 374, 2045,
        6616, 6321, 7605, 2570,
        2419, 1234, 1922, 4317,
        5110, 825, 958, 1089,
        7813, 6058, 7703, 6702,
        1714, 6371, 2281, 1986,
        6282, 3201, 3760, 1056,
        6233, 1150, 2823, 6250,
        645, 2401, 1639, 2946,
        7091, 923, 7045, 6493,
        1706, 5836, 926, 6086,
        950, 5905, 3240, 6675,
        3197, 1555, 3589, 4555,
        5671, 6948, 4664, 2086,
        5950, 5521, 1515};


constexpr int32_t GPS_L5Q_INIT_REG[210] =
    {
        1701, 323, 5292, 2020,
        5429, 7136, 1041, 5947,
        4315, 148, 535, 1939,
        5206, 5910, 3595, 5135,
        6082, 6990, 3546, 1523,
        4548, 4484, 1893, 3961,
        7106, 5299, 4660, 276,
        4389, 3783, 1591, 1601,
        749, 1387, 1661, 3210,
        708,
        4226, 5604, 6375, 3056,
        1772, 3662, 4401, 5218,
        2838, 6913, 1685, 1194,
        6963, 5001, 6694, 991,
        7489, 2441, 639, 2097,
        2498, 6470, 2399, 242,
        3768, 1186,
        5246, 4259, 5907, 3870,
        3262, 7387, 3069, 2999,
        7993, 7849, 4157, 5031,
        5986, 4833, 5739, 7846,
        898, 2022, 7446, 6404,
        155, 7862, 7795, 6121,
        4840, 6585, 429, 6020,
        200, 1664, 1499, 7298,
        1305, 7323, 7544, 4438,
        2485, 3387, 7319, 1853,
        5781, 1874, 7555, 2132,
        6441, 6722, 1192, 2588,
        2188, 297, 1540, 4138,
        5231, 4789, 659, 871,
        6837, 1393, 7383, 611,
        4920, 5416, 1611, 2474,
        118, 1382, 1092, 7950,
        7223, 1769, 4721, 1252,
        5147, 2165, 7897, 4054,
        3498, 6571, 2858, 8126,
        7017, 1901, 181, 1114,
        5195, 7479, 4186, 3904,
        7128, 1396, 4513, 5967,
        2580, 2575, 7961, 2598,
        4508, 2090, 3685, 7748,
        684, 913, 5558, 2894,
        5858, 6432, 3813, 3573,
        7523, 5280, 3376, 7424,
        2918, 5793, 1747, 7079,
        2921, 2490, 4119, 3373,
        977, 681, 4273, 5419,
        5626, 1266, 5804, 2414,
        6444, 4757, 427, 5452,
        5182, 6606, 6531, 4268,
        3115, 6835, 862, 4856,
        2765, 37, 1943, 7977,
        2512, 4451, 4071};

constexpr int32_t GPS_L5_CNAV_DATA_PAGE_BITS = 300;  //!< GPS L5 CNAV page length, including preamble and CRC [bits]
constexpr int32_t GPS_L5_SYMBOLS_PER_BIT = 2;
constexpr int32_t GPS_L5_SAMPLES_PER_SYMBOL = 10;
constexpr int32_t GPS_L5_CNAV_DATA_PAGE_SYMBOLS = 600;
constexpr int32_t GPS_L5_CNAV_DATA_PAGE_DURATION_S = 6;
constexpr int32_t GPS_L5I_NH_CODE_LENGTH = 10;
constexpr int32_t GPS_L5I_NH_CODE[10] = {0, 0, 0, 0, 1, 1, 0, 1, 0, 1};
constexpr int32_t GPS_L5Q_NH_CODE_LENGTH = 20;
constexpr int32_t GPS_L5Q_NH_CODE[20] = {0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 1, 1, 1, 0};
constexpr char GPS_L5I_NH_CODE_STR[11] = "0000110101";
constexpr char GPS_L5Q_NH_CODE_STR[21] = "00000100110101001110";


/** \} */
/** \} */
#endif  // GNSS_SDR_GPS_L5_H
