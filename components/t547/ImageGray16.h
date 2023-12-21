#pragma once

#include "esphome/components/image/image.h"
 
namespace esphome {

class ImageGray16 : public image::Image 
{
    public:
        ImageGray16(const uint8_t *data_start, int width, int height,  image::ImageType type);
        void drawInverted(int x, int y, display::Display *display, Color color_on, Color color_off);
};



}