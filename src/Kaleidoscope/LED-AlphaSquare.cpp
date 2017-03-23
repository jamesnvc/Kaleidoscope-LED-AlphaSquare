/* -*- mode: c++ -*-
 * Kaleidoscope-LED-AlphaSquare -- 4x4 pixel LED alphabet
 * Copyright (C) 2017  Gergely Nagy
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
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

#include <Kaleidoscope-LED-AlphaSquare.h>

namespace KaleidoscopePlugins {
  AlphaSquare::Font *AlphaSquare::font;
  cRGB AlphaSquare::color = {0x80, 0x80, 0x80};

  AlphaSquare::AlphaSquare (void) {
  }

  void
  AlphaSquare::begin (void) {
  }

  void
  AlphaSquare::display (Key key, uint8_t row, uint8_t col, cRGB keyColor) {
    if (key < Key_A || key > Key_0 || !font)
      return;

    uint16_t symbol = font->lookup (key);

    display (symbol, row, col, keyColor);
  }

  void
  AlphaSquare::display (Key key, uint8_t row, uint8_t col) {
    display (key, row, col, color);
  }

  void
  AlphaSquare::display (uint16_t symbol, uint8_t row, uint8_t col, cRGB keyColor) {
    for (uint8_t r = 0; r < 4; r++) {
      for (uint8_t c = 0; c < 4; c++) {
        uint8_t pixel = bitRead (symbol, r * 4 + c);
        if (!pixel)
          continue;

        LEDControl.led_set_crgb_at (row + r, col + c, keyColor);
      }
    }

    LEDControl.led_sync ();
  }

  void
  AlphaSquare::display (uint16_t symbol, uint8_t row, uint8_t col) {
    display (symbol, row, col, color);
  }
};

KaleidoscopePlugins::AlphaSquare AlphaSquare;
