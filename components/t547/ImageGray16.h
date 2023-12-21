#pragma once

#include "esphome/components/image/image.h"
 
namespace esphome {
namespace image {

class ImageGray16 : public Image 
{
    public:
        ImageGray16(const uint8_t *data_start, int width, int height,  ImageType type);
        void drawInverted(int x, int y, display::Display *display, Color color_on, Color color_off);
};



}
}