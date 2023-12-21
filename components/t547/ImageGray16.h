#pragma once

#include "esphome/components/image/image.h"
 
class ImageGray16 : public image::Image 
{
    public:
        ImageGray16(const uint8_t *data_start, int width, int height,  esphome::image::ImageType type);
        void drawInverted(int x, int y, esphome::display::Display *display, esphome::Color color_on, esphome::Color color_off);
}

