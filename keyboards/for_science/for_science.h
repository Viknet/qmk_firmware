/* Copyright 2017 Paul James (paul@peej.co.uk)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#pragma once

#include "quantum.h"

#define ___ KC_NO

#define LAYOUT_split_4x5_3( \
    L00, L01, L02, L03, L04, R00, R01, R02, R03, R04, \
    L10, L11, L12, L13, L14, R10, R11, R12, R13, R14, \
    L20, L21, L22, L23, L24, R20, R21, R22, R23, R24, \
    L30, L31, L32, L33, L34, R30, R31, R32, R33, R34, \
              LT1, LT2, LT3, RT1, RT2, RT3 \
) \
{ \
    { L00, L01, L02, L03, L04 }, \
    { L10, L11, L12, L13, L14 }, \
    { L20, L21, L22, L23, L24 }, \
    { L30, L31, L32, L33, L34 }, \
    { ___, ___, LT1, LT2, LT3 }, \
    { R04, R03, R02, R01, R00 }, \
    { R14, R13, R12, R11, R10 }, \
    { R24, R23, R22, R21, R20 }, \
    { R34, R33, R32, R31, R30 }, \
    { ___, ___, RT3, RT2, RT1 } \
}

#define LAYOUT_ortho_5x5( \
    L00, L01, L02, L03, L04, \
    L10, L11, L12, L13, L14, \
    L20, L21, L22, L23, L24, \
    L30, L31, L32, L33, L34, \
              LT1, LT2, LT3  \
) { \
    { L00, L01, L02, L03, L04 }, \
    { L10, L11, L12, L13, L14 }, \
    { L20, L21, L22, L23, L24 }, \
    { L30, L31, L32, L33, L34 }, \
    { ___, ___, LT1, LT2, LT3 }, \
    { ___, ___, ___, ___, ___ }, \
    { ___, ___, ___, ___, ___ }, \
    { ___, ___, ___, ___, ___ }, \
    { ___, ___, ___, ___, ___ }, \
    { ___, ___, ___, ___, ___ }  \
}
