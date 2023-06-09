/*! \copyright
 
   https://opensource.org/licenses/BSD-3-Clause
 
   Copyright 2013-2021 Marco Bacchi <marco@bacchi.at>
   
   Redistribution and use in source and binary forms, with or without 
   modification, are permitted provided that the following conditions are met:
   
   1. Redistributions of source code must retain the above copyright notice, 
   this list of conditions and the following disclaimer.
   
   2. Redistributions in binary form must reproduce the above copyright notice, 
   this list of conditions and the following disclaimer in the documentation 
   and/or other materials provided with the distribution.

   3. Neither the name of the copyright holder nor the names of its 
   contributors may be used to endorse or promote products derived from this 
   software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
   AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
   IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE 
   ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE 
   LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR 
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF 
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS 
   INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN 
   CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
   ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE 
   POSSIBILITY OF SUCH DAMAGE.
*/


#include "uigfx_font8x8_c64.h"

static const uint8_t uigfx_font8x8_c64_data [96][8] = {
        {
           0x00,     //
           0x00,     //
           0x00,     //
           0x00,     //
           0x00,     //
           0x00,     //
           0x00,     //
           0x00,     //
        },
        {
           0x18,     //       ##
           0x18,     //       ##
           0x18,     //       ##
           0x18,     //       ##
           0x00,     //
           0x00,     //
           0x18,     //       ##
           0x00,     //
        },
        {
           0x66,     //     ##  ##
           0x66,     //     ##  ##
           0x66,     //     ##  ##
           0x00,     //
           0x00,     //
           0x00,     //
           0x00,     //
           0x00,     //
        },
        {
           0x66,     //     ##  ##
           0x66,     //     ##  ##
           0xff,     //    ########
           0x66,     //     ##  ##
           0xff,     //    ########
           0x66,     //     ##  ##
           0x66,     //     ##  ##
           0x00,     //
        },
        {
           0x18,     //       ##
           0x7c,     //      #####
           0x06,     //     ##
           0x3c,     //      ####
           0x60,     //         ##
           0x3e,     //     #####
           0x18,     //       ##
           0x00,     //
        },
        {
           0x46,     //     ##   #
           0x66,     //     ##  ##
           0x30,     //        ##
           0x18,     //       ##
           0x0c,     //      ##
           0x66,     //     ##  ##
           0x62,     //     #   ##
           0x00,     //
        },
        {
           0x3c,     //      ####
           0x66,     //     ##  ##
           0x3c,     //      ####
           0x1c,     //      ###
           0xe6,     //     ##  ###
           0x66,     //     ##  ##
           0xfc,     //      ######
           0x00,     //
        },
        {
           0x60,     //         ##
           0x30,     //        ##
           0x18,     //       ##
           0x00,     //
           0x00,     //
           0x00,     //
           0x00,     //
           0x00,     //
        },
        {
           0x30,     //        ##
           0x18,     //       ##
           0x0c,     //      ##
           0x0c,     //      ##
           0x0c,     //      ##
           0x18,     //       ##
           0x30,     //        ##
           0x00,     //
        },
        {
           0x0c,     //      ##
           0x18,     //       ##
           0x30,     //        ##
           0x30,     //        ##
           0x30,     //        ##
           0x18,     //       ##
           0x0c,     //      ##
           0x00,     //
        },
        {
           0x00,     //
           0x66,     //     ##  ##
           0x3c,     //      ####
           0xff,     //    ########
           0x3c,     //      ####
           0x66,     //     ##  ##
           0x00,     //
           0x00,     //
        },
        {
           0x00,     //
           0x18,     //       ##
           0x18,     //       ##
           0x7e,     //     ######
           0x18,     //       ##
           0x18,     //       ##
           0x00,     //
           0x00,     //
        },
        {
           0x00,     //
           0x00,     //
           0x00,     //
           0x00,     //
           0x00,     //
           0x18,     //       ##
           0x18,     //       ##
           0x0c,     //      ##
        },
        {
           0x00,     //
           0x00,     //
           0x00,     //
           0x7e,     //     ######
           0x00,     //
           0x00,     //
           0x00,     //
           0x00,     //
        },
        {
           0x00,     //
           0x00,     //
           0x00,     //
           0x00,     //
           0x00,     //
           0x18,     //       ##
           0x18,     //       ##
           0x00,     //
        },
        {
           0x00,     //
           0xc0,     //          ##
           0x60,     //         ##
           0x30,     //        ##
           0x18,     //       ##
           0x0c,     //      ##
           0x06,     //     ##
           0x00,     //
        },
        {
           0x3c,     //      ####
           0x66,     //     ##  ##
           0x76,     //     ## ###
           0x6e,     //     ### ##
           0x66,     //     ##  ##
           0x66,     //     ##  ##
           0x3c,     //      ####
           0x00,     //
        },
        {
           0x18,     //       ##
           0x18,     //       ##
           0x1c,     //      ###
           0x18,     //       ##
           0x18,     //       ##
           0x18,     //       ##
           0x7e,     //     ######
           0x00,     //
        },
        {
           0x3c,     //      ####
           0x66,     //     ##  ##
           0x60,     //         ##
           0x30,     //        ##
           0x0c,     //      ##
           0x06,     //     ##
           0x7e,     //     ######
           0x00,     //
        },
        {
           0x3c,     //      ####
           0x66,     //     ##  ##
           0x60,     //         ##
           0x38,     //       ###
           0x60,     //         ##
           0x66,     //     ##  ##
           0x3c,     //      ####
           0x00,     //
        },
        {
           0x60,     //         ##
           0x70,     //        ###
           0x78,     //       ####
           0x66,     //     ##  ##
           0xfe,     //     #######
           0x60,     //         ##
           0x60,     //         ##
           0x00,     //
        },
        {
           0x7e,     //     ######
           0x06,     //     ##
           0x3e,     //     #####
           0x60,     //         ##
           0x60,     //         ##
           0x66,     //     ##  ##
           0x3c,     //      ####
           0x00,     //
        },
        {
           0x3c,     //      ####
           0x66,     //     ##  ##
           0x06,     //     ##
           0x3e,     //     #####
           0x66,     //     ##  ##
           0x66,     //     ##  ##
           0x3c,     //      ####
           0x00,     //
        },
        {
           0x7e,     //     ######
           0x66,     //     ##  ##
           0x30,     //        ##
           0x18,     //       ##
           0x18,     //       ##
           0x18,     //       ##
           0x18,     //       ##
           0x00,     //
        },
        {
           0x3c,     //      ####
           0x66,     //     ##  ##
           0x66,     //     ##  ##
           0x3c,     //      ####
           0x66,     //     ##  ##
           0x66,     //     ##  ##
           0x3c,     //      ####
           0x00,     //
        },
        {
           0x3c,     //      ####
           0x66,     //     ##  ##
           0x66,     //     ##  ##
           0x7c,     //      #####
           0x60,     //         ##
           0x66,     //     ##  ##
           0x3c,     //      ####
           0x00,     //
        },
        {
           0x00,     //
           0x00,     //
           0x18,     //       ##
           0x00,     //
           0x00,     //
           0x18,     //       ##
           0x00,     //
           0x00,     //
        },
        {
           0x00,     //
           0x00,     //
           0x18,     //       ##
           0x00,     //
           0x00,     //
           0x18,     //       ##
           0x18,     //       ##
           0x0c,     //      ##
        },
        {
           0x70,     //        ###
           0x18,     //       ##
           0x0c,     //      ##
           0x06,     //     ##
           0x0c,     //      ##
           0x18,     //       ##
           0x70,     //        ###
           0x00,     //
        },
        {
           0x00,     //
           0x00,     //
           0x7e,     //     ######
           0x00,     //
           0x7e,     //     ######
           0x00,     //
           0x00,     //
           0x00,     //
        },
        {
           0x0e,     //     ###
           0x18,     //       ##
           0x30,     //        ##
           0x60,     //         ##
           0x30,     //        ##
           0x18,     //       ##
           0x0e,     //     ###
           0x00,     //
        },
        {
           0x3c,     //      ####
           0x66,     //     ##  ##
           0x60,     //         ##
           0x30,     //        ##
           0x18,     //       ##
           0x00,     //
           0x18,     //       ##
           0x00,     //
        },
        {
           0x3c,     //      ####
           0x66,     //     ##  ##
           0x76,     //     ## ###
           0x76,     //     ## ###
           0x06,     //     ##
           0x46,     //     ##   #
           0x3c,     //      ####
           0x00,     //
        },
        {
           0x18,     //       ##
           0x3c,     //      ####
           0x66,     //     ##  ##
           0x7e,     //     ######
           0x66,     //     ##  ##
           0x66,     //     ##  ##
           0x66,     //     ##  ##
           0x00,     //
        },
        {
           0x3e,     //     #####
           0x66,     //     ##  ##
           0x66,     //     ##  ##
           0x3e,     //     #####
           0x66,     //     ##  ##
           0x66,     //     ##  ##
           0x3e,     //     #####
           0x00,     //
        },
        {
           0x3c,     //      ####
           0x66,     //     ##  ##
           0x06,     //     ##
           0x06,     //     ##
           0x06,     //     ##
           0x66,     //     ##  ##
           0x3c,     //      ####
           0x00,     //
        },
        {
           0x1e,     //     ####
           0x36,     //     ## ##
           0x66,     //     ##  ##
           0x66,     //     ##  ##
           0x66,     //     ##  ##
           0x36,     //     ## ##
           0x1e,     //     ####
           0x00,     //
        },
        {
           0x7e,     //     ######
           0x06,     //     ##
           0x06,     //     ##
           0x1e,     //     ####
           0x06,     //     ##
           0x06,     //     ##
           0x7e,     //     ######
           0x00,     //
        },
        {
           0x7e,     //     ######
           0x06,     //     ##
           0x06,     //     ##
           0x1e,     //     ####
           0x06,     //     ##
           0x06,     //     ##
           0x06,     //     ##
           0x00,     //
        },
        {
           0x3c,     //      ####
           0x66,     //     ##  ##
           0x06,     //     ##
           0x76,     //     ## ###
           0x66,     //     ##  ##
           0x66,     //     ##  ##
           0x3c,     //      ####
           0x00,     //
        },
        {
           0x66,     //     ##  ##
           0x66,     //     ##  ##
           0x66,     //     ##  ##
           0x7e,     //     ######
           0x66,     //     ##  ##
           0x66,     //     ##  ##
           0x66,     //     ##  ##
           0x00,     //
        },
        {
           0x3c,     //      ####
           0x18,     //       ##
           0x18,     //       ##
           0x18,     //       ##
           0x18,     //       ##
           0x18,     //       ##
           0x3c,     //      ####
           0x00,     //
        },
        {
           0x78,     //       ####
           0x30,     //        ##
           0x30,     //        ##
           0x30,     //        ##
           0x30,     //        ##
           0x36,     //     ## ##
           0x1c,     //      ###
           0x00,     //
        },
        {
           0x66,     //     ##  ##
           0x36,     //     ## ##
           0x1e,     //     ####
           0x0e,     //     ###
           0x1e,     //     ####
           0x36,     //     ## ##
           0x66,     //     ##  ##
           0x00,     //
        },
        {
           0x06,     //     ##
           0x06,     //     ##
           0x06,     //     ##
           0x06,     //     ##
           0x06,     //     ##
           0x06,     //     ##
           0x7e,     //     ######
           0x00,     //
        },
        {
           0xc6,     //     ##   ##
           0xee,     //     ### ###
           0xfe,     //     #######
           0xd6,     //     ## # ##
           0xc6,     //     ##   ##
           0xc6,     //     ##   ##
           0xc6,     //     ##   ##
           0x00,     //
        },
        {
           0x66,     //     ##  ##
           0x6e,     //     ### ##
           0x7e,     //     ######
           0x7e,     //     ######
           0x76,     //     ## ###
           0x66,     //     ##  ##
           0x66,     //     ##  ##
           0x00,     //
        },
        {
           0x3c,     //      ####
           0x66,     //     ##  ##
           0x66,     //     ##  ##
           0x66,     //     ##  ##
           0x66,     //     ##  ##
           0x66,     //     ##  ##
           0x3c,     //      ####
           0x00,     //
        },
        {
           0x3e,     //     #####
           0x66,     //     ##  ##
           0x66,     //     ##  ##
           0x3e,     //     #####
           0x06,     //     ##
           0x06,     //     ##
           0x06,     //     ##
           0x00,     //
        },
        {
           0x3c,     //      ####
           0x66,     //     ##  ##
           0x66,     //     ##  ##
           0x66,     //     ##  ##
           0x66,     //     ##  ##
           0x3c,     //      ####
           0x70,     //        ###
           0x00,     //
        },
        {
           0x3e,     //     #####
           0x66,     //     ##  ##
           0x66,     //     ##  ##
           0x3e,     //     #####
           0x1e,     //     ####
           0x36,     //     ## ##
           0x66,     //     ##  ##
           0x00,     //
        },
        {
           0x3c,     //      ####
           0x66,     //     ##  ##
           0x06,     //     ##
           0x3c,     //      ####
           0x60,     //         ##
           0x66,     //     ##  ##
           0x3c,     //      ####
           0x00,     //
        },
        {
           0x7e,     //     ######
           0x18,     //       ##
           0x18,     //       ##
           0x18,     //       ##
           0x18,     //       ##
           0x18,     //       ##
           0x18,     //       ##
           0x00,     //
        },
        {
           0x66,     //     ##  ##
           0x66,     //     ##  ##
           0x66,     //     ##  ##
           0x66,     //     ##  ##
           0x66,     //     ##  ##
           0x66,     //     ##  ##
           0x3c,     //      ####
           0x00,     //
        },
        {
           0x66,     //     ##  ##
           0x66,     //     ##  ##
           0x66,     //     ##  ##
           0x66,     //     ##  ##
           0x66,     //     ##  ##
           0x3c,     //      ####
           0x18,     //       ##
           0x00,     //
        },
        {
           0xc6,     //     ##   ##
           0xc6,     //     ##   ##
           0xc6,     //     ##   ##
           0xd6,     //     ## # ##
           0xfe,     //     #######
           0xee,     //     ### ###
           0xc6,     //     ##   ##
           0x00,     //
        },
        {
           0x66,     //     ##  ##
           0x66,     //     ##  ##
           0x3c,     //      ####
           0x18,     //       ##
           0x3c,     //      ####
           0x66,     //     ##  ##
           0x66,     //     ##  ##
           0x00,     //
        },
        {
           0x66,     //     ##  ##
           0x66,     //     ##  ##
           0x66,     //     ##  ##
           0x3c,     //      ####
           0x18,     //       ##
           0x18,     //       ##
           0x18,     //       ##
           0x00,     //
        },
        {
           0x7e,     //     ######
           0x60,     //         ##
           0x30,     //        ##
           0x18,     //       ##
           0x0c,     //      ##
           0x06,     //     ##
           0x7e,     //     ######
           0x00,     //
        },
        {
           0x3c,     //      ####
           0x0c,     //      ##
           0x0c,     //      ##
           0x0c,     //      ##
           0x0c,     //      ##
           0x0c,     //      ##
           0x3c,     //      ####
           0x00,     //
        },
        {
           0x00,     //
           0x03,     //    ##
           0x06,     //     ##
           0x0c,     //      ##
           0x18,     //       ##
           0x30,     //        ##
           0x60,     //         ##
           0x00,     //
        },
        {
           0x3c,     //      ####
           0x30,     //        ##
           0x30,     //        ##
           0x30,     //        ##
           0x30,     //        ##
           0x30,     //        ##
           0x3c,     //      ####
           0x00,     //
        },
        {
           0x00,     //
           0x18,     //       ##
           0x3c,     //      ####
           0x7e,     //     ######
           0x18,     //       ##
           0x18,     //       ##
           0x18,     //       ##
           0x18,     //       ##
        },
        {
           0x00,     //
           0x00,     //
           0x00,     //
           0x00,     //
           0x00,     //
           0x00,     //
           0x00,     //
           0xff,     //    ########
        },
        {
           0x06,     //     ##
           0x0c,     //      ##
           0x18,     //       ##
           0x00,     //
           0x00,     //
           0x00,     //
           0x00,     //
           0x00,     //
        },
        {
           0x00,     //
           0x00,     //
           0x3c,     //      ####
           0x60,     //         ##
           0x7c,     //      #####
           0x66,     //     ##  ##
           0x7c,     //      #####
           0x00,     //
        },
        {
           0x00,     //
           0x06,     //     ##
           0x06,     //     ##
           0x3e,     //     #####
           0x66,     //     ##  ##
           0x66,     //     ##  ##
           0x3e,     //     #####
           0x00,     //
        },
        {
           0x00,     //
           0x00,     //
           0x3c,     //      ####
           0x06,     //     ##
           0x06,     //     ##
           0x06,     //     ##
           0x3c,     //      ####
           0x00,     //
        },
        {
           0x00,     //
           0x60,     //         ##
           0x60,     //         ##
           0x7c,     //      #####
           0x66,     //     ##  ##
           0x66,     //     ##  ##
           0x7c,     //      #####
           0x00,     //
        },
        {
           0x00,     //
           0x00,     //
           0x3c,     //      ####
           0x66,     //     ##  ##
           0x7e,     //     ######
           0x06,     //     ##
           0x3c,     //      ####
           0x00,     //
        },
        {
           0x00,     //
           0x70,     //        ###
           0x18,     //       ##
           0x7c,     //      #####
           0x18,     //       ##
           0x18,     //       ##
           0x18,     //       ##
           0x00,     //
        },
        {
           0x00,     //
           0x00,     //
           0x7c,     //      #####
           0x66,     //     ##  ##
           0x66,     //     ##  ##
           0x7c,     //      #####
           0x60,     //         ##
           0x3e,     //     #####
        },
        {
           0x00,     //
           0x06,     //     ##
           0x06,     //     ##
           0x3e,     //     #####
           0x66,     //     ##  ##
           0x66,     //     ##  ##
           0x66,     //     ##  ##
           0x00,     //
        },
        {
           0x00,     //
           0x18,     //       ##
           0x00,     //
           0x1c,     //      ###
           0x18,     //       ##
           0x18,     //       ##
           0x3c,     //      ####
           0x00,     //
        },
        {
           0x00,     //
           0x60,     //         ##
           0x00,     //
           0x60,     //         ##
           0x60,     //         ##
           0x60,     //         ##
           0x60,     //         ##
           0x3c,     //      ####
        },
        {
           0x00,     //
           0x06,     //     ##
           0x06,     //     ##
           0x36,     //     ## ##
           0x1e,     //     ####
           0x36,     //     ## ##
           0x66,     //     ##  ##
           0x00,     //
        },
        {
           0x00,     //
           0x1c,     //      ###
           0x18,     //       ##
           0x18,     //       ##
           0x18,     //       ##
           0x18,     //       ##
           0x3c,     //      ####
           0x00,     //
        },
        {
           0x00,     //
           0x00,     //
           0x66,     //     ##  ##
           0xfe,     //     #######
           0xfe,     //     #######
           0xd6,     //     ## # ##
           0xc6,     //     ##   ##
           0x00,     //
        },
        {
           0x00,     //
           0x00,     //
           0x3e,     //     #####
           0x66,     //     ##  ##
           0x66,     //     ##  ##
           0x66,     //     ##  ##
           0x66,     //     ##  ##
           0x00,     //
        },
        {
           0x00,     //
           0x00,     //
           0x3c,     //      ####
           0x66,     //     ##  ##
           0x66,     //     ##  ##
           0x66,     //     ##  ##
           0x3c,     //      ####
           0x00,     //
        },
        {
           0x00,     //
           0x00,     //
           0x3e,     //     #####
           0x66,     //     ##  ##
           0x66,     //     ##  ##
           0x3e,     //     #####
           0x06,     //     ##
           0x06,     //     ##
        },
        {
           0x00,     //
           0x00,     //
           0x7c,     //      #####
           0x66,     //     ##  ##
           0x66,     //     ##  ##
           0x7c,     //      #####
           0x60,     //         ##
           0x60,     //         ##
        },
        {
           0x00,     //
           0x00,     //
           0x3e,     //     #####
           0x66,     //     ##  ##
           0x06,     //     ##
           0x06,     //     ##
           0x06,     //     ##
           0x00,     //
        },
        {
           0x00,     //
           0x00,     //
           0x7c,     //      #####
           0x06,     //     ##
           0x3c,     //      ####
           0x60,     //         ##
           0x3e,     //     #####
           0x00,     //
        },
        {
           0x00,     //
           0x18,     //       ##
           0x7e,     //     ######
           0x18,     //       ##
           0x18,     //       ##
           0x18,     //       ##
           0x70,     //        ###
           0x00,     //
        },
        {
           0x00,     //
           0x00,     //
           0x66,     //     ##  ##
           0x66,     //     ##  ##
           0x66,     //     ##  ##
           0x66,     //     ##  ##
           0x7c,     //      #####
           0x00,     //
        },
        {
           0x00,     //
           0x00,     //
           0x66,     //     ##  ##
           0x66,     //     ##  ##
           0x66,     //     ##  ##
           0x3c,     //      ####
           0x18,     //       ##
           0x00,     //
        },
        {
           0x00,     //
           0x00,     //
           0xc6,     //     ##   ##
           0xd6,     //     ## # ##
           0xfe,     //     #######
           0x7c,     //      #####
           0x6c,     //      ## ##
           0x00,     //
        },
        {
           0x00,     //
           0x00,     //
           0x66,     //     ##  ##
           0x3c,     //      ####
           0x18,     //       ##
           0x3c,     //      ####
           0x66,     //     ##  ##
           0x00,     //
        },
        {
           0x00,     //
           0x00,     //
           0x66,     //     ##  ##
           0x66,     //     ##  ##
           0x66,     //     ##  ##
           0x7c,     //      #####
           0x30,     //        ##
           0x1e,     //     ####
        },
        {
           0x00,     //
           0x00,     //
           0x7e,     //     ######
           0x30,     //        ##
           0x18,     //       ##
           0x0c,     //      ##
           0x7e,     //     ######
           0x00,     //
        },
        {
           0x18,     //       ##
           0x0c,     //      ##
           0x0c,     //      ##
           0x0e,     //     ###
           0x0c,     //      ##
           0x0c,     //      ##
           0x18,     //       ##
           0x00,     //
        },
        {
           0x18,     //       ##
           0x18,     //       ##
           0x18,     //       ##
           0x18,     //       ##
           0x18,     //       ##
           0x18,     //       ##
           0x18,     //       ##
           0x18,     //       ##
        },
        {
           0x18,     //       ##
           0x30,     //        ##
           0x30,     //        ##
           0x70,     //        ###
           0x30,     //        ##
           0x30,     //        ##
           0x18,     //       ##
           0x00,     //
        },
        {
           0xff,     //    ########
           0xff,     //    ########
           0xff,     //    ########
           0xff,     //    ########
           0xff,     //    ########
           0xff,     //    ########
           0xff,     //    ########
           0xff,     //    ########
        },

};

static void uigfx_draw_char_font8x8_c64(uint8_t* buf, int16_t x0, int16_t y0, char ch, uigfx_color_t c)
{
    uint8_t x,y;
    uint8_t* chdat = (uint8_t*)uigfx_font8x8_c64_data[ch-32];

    for(y=0; y < 8; y++)
    {
        uint8_t rowdat = chdat[y];

        for(x=0; x < 8; x++)
        {
            if(rowdat&1)
            {
                uigfx_draw_pixel(buf,x0+x,y0+y,c);
            }

            rowdat>>=1;
        }
    }
}

const uigfx_font_t uigfx_font8x8_c64 = {8,8,uigfx_font8x8_c64_data,uigfx_draw_char_font8x8_c64};
