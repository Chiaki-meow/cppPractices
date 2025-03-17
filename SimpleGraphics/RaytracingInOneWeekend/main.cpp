#include <iostream>

int main() {
  int image_width = 256;
  int image_height = 256;

  std::cout << "P3\n" << image_width << " " << image_height << "\n\255\n";
  for (int i = 0; i < image_width; i++) {
    for (int j = 0; j < image_height; j++) {
      auto r = double(i) / (image_width - 1);
      auto g = double(j) / (image_width - 1);
      auto b = 0;

      int ir = int(255.9 * r);
      int ig = int(255.9 * g);
      int ib = int(255.9 * b);

      std::cout << ir << " " << ig << " " << ib << '\n';
    }
  }
}