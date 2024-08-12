/*
Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See th
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

/* define master side */
#define MASTER_LEFT
//#define MASTER_RIGHT


/* key matrix size */
#define MATRIX_ROWS 10
#define MATRIX_COLS 6


/*  define RGB/OLED mirror */
#define SPLIT_TRANSPORT_MIRROR
#define SPLIT_LAYER_STATE_ENABLE


/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5


/* disable action for LOCKING_XXX */
#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE


/* disable action features */
#define NO_MUSIC_MODE
