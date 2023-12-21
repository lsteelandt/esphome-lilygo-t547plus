#include "ImageGray16.h"

namespace esphome {

  ImageGray16::ImageGray16(const uint8_t *data_start, int width, int height, image::ImageType type)
  {
    image::Image(data_start,  width,  height,  type);
  }


  void ImageGray16::drawInverted(int x, int y, display::Display *display, Color color_on, Color color_off) {
    switch (type_) {
      case IMAGE_TYPE_BINARY: {
        for (int img_x = 0; img_x < width_; img_x++) {
          for (int img_y = 0; img_y < height_; img_y++) {
            if (this->get_binary_pixel_(img_x, img_y)) {
              display->draw_pixel_at(x + img_x, y + img_y, color_off);
            } else if (!this->transparent_) {
              display->draw_pixel_at(x + img_x, y + img_y, color_on);
            }
          }
        }
        break;
      }
      case IMAGE_TYPE_GRAYSCALE:
        for (int img_x = 0; img_x < width_; img_x++) {
          for (int img_y = 0; img_y < height_; img_y++) {
            auto color = this->get_grayscale_pixel_(img_x, img_y);
            if (color.w >= 0x80) {
              color.r=color.r ^ 0xFF;
              color.g=color.g ^ 0xFF;
              color.b=color.b ^ 0xFF;
              color.w=color.w ^ 0xFF;
              display->draw_pixel_at(x + img_x, y + img_y, color);
            }
          }
        }
        break;
      case IMAGE_TYPE_RGB565:
        break;
      case IMAGE_TYPE_RGB24:
        break;
      case IMAGE_TYPE_RGBA:
        break;
    }
  }

}